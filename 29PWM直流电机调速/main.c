#include <STC89C5xRC.H>
#include "Timer0.h"
#include "Key.h"
#include "Delay.h"
sbit Motor = P1^0;
void main(void)
{
	while(1)
	{
		
	}
}
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if(T0Count>=20)
	{
		T0Count=0;
		
	}
}