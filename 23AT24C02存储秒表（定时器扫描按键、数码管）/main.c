#include <REGX52.H>
#include "Timer0.h"
#include "Nixie.h"
#include "Key.h"
#include "I2C.h"
#include "AT24C02.h"
#include "Delay.h"
unsigned char Key_Number, RunFlag; // 按键键码, 启动暂停的标识位
unsigned char Min, Sec, MiniSec; // 分别定义分、秒、小迷你秒（计到100就秒加1的伪毫秒）
void main()
{
	/*
	* K1: 启动/暂停秒表
	* K2：重置
	* K3：存储结果至AT24C02
	* K4：读取结果自AT24C02
	*/
	Timer0_Init();
	while(1)
	{
		Key_Number = Key();
		if(Key_Number == 1)
		{
			RunFlag = !RunFlag;
		}
		if(Key_Number == 2)
		{
			Min = 0;
			Sec = 0;
			MiniSec = 0;
		}
		if(Key_Number == 3)
		{
			AT24C01_WriteByte(0, Min);
			Delay(6);
			AT24C01_WriteByte(1, Sec);
			Delay(6);
			AT24C01_WriteByte(2, MiniSec);
			Delay(6);
		}
		if(Key_Number == 4)
		{
			Min = AT24C02_ReadByte(0);
			Sec = AT24C02_ReadByte(1);
			MiniSec = AT24C02_ReadByte(2);
		}
		Nixie_SetBuf(1, Min / 10); // 分钟的高位
		Nixie_SetBuf(2, Min % 10); // 分钟的低位
		Nixie_SetBuf(3, 11); // 断码数组NixieTable[11]是个短横线
		Nixie_SetBuf(4, Sec / 10);
		Nixie_SetBuf(5, Sec % 10);
		Nixie_SetBuf(6, 11);
		Nixie_SetBuf(7, MiniSec / 10);
		Nixie_SetBuf(8, MiniSec % 10);				
	}
}
/**
* @brief 由定时器的中断函数调用的控制秒增加的函数
* @param  无
* @retval 无
* @interpretation  描述
*/
void Sec_loop(void)	
{
	if(RunFlag)
	{
		MiniSec++;
		if(MiniSec >= 100)
		{
			MiniSec = 0;
			Sec++;
			if(Sec >= 60)
			{
				Sec = 0;
				Min++;
				if(Min >= 60)
				{
					Min = 0;
				}
			}
		}
	}
}
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count1, T0Count2;
	TH0 = 0xFC;
	TL0 = 0x66;
	T0Count1++;
	T0Count2++;
	if(T0Count1 > 20)
	{ // 这个地方每隔20ms调用一次，是为了消除按键的抖动
		T0Count1 = 0;
		Key_Loop();
	}
	Nixie_Loop();
	if(T0Count2 >= 10)
	{
		T0Count2 = 0;
		Sec_loop();
	}
}