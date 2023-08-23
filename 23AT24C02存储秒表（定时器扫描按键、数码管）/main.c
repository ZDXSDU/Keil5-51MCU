#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "Nixie.h"
#include "Key.h"
void main()
{
	Timer0_Init();
	while(1)
	{
		
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
		P2 = ~P2;
	}
}