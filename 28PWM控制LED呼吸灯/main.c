#include <STC89C5xRC.H>
#include "Timer0.h"
sbit LED = P2^0;
void Delay(unsigned char t);
void main(void)
{
	unsigned char Time, i;
	while(1)
	{
		for(Time = 0; Time < 100; Time++)
		{
			for(i = 0; i < 20; i++)
			{
				LED = 0;
				Delay(Time);
				LED = 1;
				Delay(100 - Time);
			}
		}
		for(Time = 100; Time > 0; Time--)
		{
			for(i = 0; i < 20; i++)
			{
				LED = 0;
				Delay(Time);
				LED = 1;
				Delay(100 - Time);
			}
		}
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
		
	}
}
void Delay(unsigned char t)
{
	while(t--);
}