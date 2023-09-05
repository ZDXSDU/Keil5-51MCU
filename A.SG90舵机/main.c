#include <REGX52.H>
#include "LCD1602.h"
sbit PWM_IO = P2^3;
sbit FAN_IO = P2^5;
unsigned char Counter;
unsigned char PWM_Compare = 1;
bit status = 0; // 是否是反方向旋转
void ChangeDeg(void)
{
	if(status)
	{
		PWM_Compare--;
		if(PWM_Compare == 0)
		{
			status = ~status;
		}
	}
	else
	{
		PWM_Compare++;
		if(PWM_Compare >= 5)
		{
			status = ~status;
		}
	}
}
void Timer0_Routine(void) interrupt 1
{
	static unsigned int iii;
	TH0 = 0xFE;
	TL0 = 0x33;
	Counter++;
	iii++;
	if(iii >= 2000)
	{
		ChangeDeg();
		iii = 0;
	}
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
unsigned char i = 0;
void main(void)
{
	LCD_Init();	
	Timer0_Init();	
	while(1)
	{
		LCD_ShowString(1, 2, "--PWM_Compare");
		LCD_ShowString(2, 2, "--status");
		LCD_ShowNum(1, 1, PWM_Compare, 1);
		LCD_ShowBinNum(2, 1, status, 1);
	}
}