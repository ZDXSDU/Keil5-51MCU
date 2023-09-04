#include <REGX52.H>
#include "LCD1602.h"
#define PWM_Compare 1
sbit PWM_IO = P2^3;
unsigned char Counter;
void Timer0_Routine(void) interrupt 1
{
	TH0 = 0xFE;
	TL0 = 0x33;
	Counter++;
	if(Counter <= PWM_Compare)
	{
		PWM_IO = 1;
	}
	else
	{
		PWM_IO = 0;
	}
	Counter %= 40;
}
void Timer0_Init(void)
{
	TMOD &= 0xF0;
	TMOD |= 0x01;	
	TF0 = 0;
	TR0 = 1;
	TH0 = 0xFE;
	TL0 = 0x33;
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}
void main(void)
{
	Timer0_Init();
	while(1);
}