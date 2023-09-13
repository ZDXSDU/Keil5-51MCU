#include <STC89C5xRC.H>
#include "Timer0.h"
#include "Key.h"
#include "Delay.h"
#include "Nixie.h"
#include "PWM.h"
sbit Motor = P1^0;
unsigned char Counter, Compare; // 定义计数器和比较值
unsigned char KeyNum, Speed; // 按键键码和电机转速
void main(void)
{
	Timer0_PWM_Init();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum == 1)
		{
			Speed++;
			Speed %= 5;
			if(Speed == 0) Compare = 0;
			if(Speed == 1) Compare = 25;
			if(Speed == 2) Compare = 50;
			if(Speed == 3) Compare = 75;
			if(Speed == 4) Compare = 100;
		}
		Nixie(1, Speed);
	}
}
void Timer0_Routine() interrupt 1
{	
	TL0 = 0xA4;
	TH0 = 0xFF;
	Counter++;
	Counter %= 100;
	if(Counter < Compare)	
		Motor = 1;	
	else 
		Motor = 0;
}