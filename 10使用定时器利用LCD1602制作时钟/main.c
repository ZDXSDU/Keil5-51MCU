#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"
unsigned char Time_Sec,Time_Min,Time_Hou;
void main()
{
	LCD_Init();
	Timer0_Init();
	LCD_ShowString(1,1,"Elapsed time is:");
	LCD_ShowString(2,1,"  :  :");
	while(1)
	{
		LCD_ShowNum(2,1,Time_Hou,2);
		LCD_ShowNum(2,4,Time_Min,2);
		LCD_ShowNum(2,7,Time_Sec,2);
	}
}
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count; // 静态变量用于记录中断次数
	// 每一次中断都将定时器的初始值重新赋值，以保证每次都是1ms中断
	TH0 = 0xFC;
	TL0 = 0x18;
	// 每一次中断（1MS），都将T0Count计数器加一，直到加满1000MS视为一秒钟，此时要将T0Count计数器置0
	T0Count++;
	if(T0Count > 1000)
	{
		T0Count = 0;
		Time_Sec++;
		if(Time_Sec>=60)
		{
			Time_Sec=0;		//60秒到，Sec清0，Min自增
			Time_Min++;
			if(Time_Min>=60)
			{
				Time_Min=0;	//60分钟到，Min清0，Hour自增
				Time_Hou++;
				if(Time_Hou>=24)
				{
					Time_Hou=0;	//24小时到，Hour清0
				}
			}
		}
	}
}