#include <REGX52.H>
#include "Timer0.h"
#include <INTRINS.H>
#include "Delay.h"

unsigned int LED_MODE = 0; // 控制流水灯的显示模式
void main()
{
	P2 = 0x01;
	Timer0_Init();
	
	if(P3_1 == 0) //K1按下控制流水灯的显示模式
	{
		Delay(20);
		while(P3_1 == 0);
		Delay(20);
		LED_MODE++;
		if(LED_MODE >= 2) LED_MODE = 0;
	}
	while(1);
}
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count; // 静态变量用于记录中断次数
	// 每一次中断都将定时器的初始值重新赋值，以保证每次都是1ms中断
	TH0 = 0xFC;
	TL0 = 0x18;
	// 每一次中断（1MS），都将T0Count计数器加一，直到加满1000MS视为一秒钟，此时要将T0Count计数器置0
	T0Count++;
	if(T0Count > 100)
	{
		T0Count = 0;
		/*
		这里是中断处理程序代码区域
		*/
		if(LED_MODE==1) P2 = _crol_(P2,1);
		if(LED_MODE==0) P2 = _cror_(P2,1);
	}
}