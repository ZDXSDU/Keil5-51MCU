#include <STC89C5xRC.H>
void Timer1_PWM_Init(void) // 100微秒@11.0592MHz
{
	TMOD &= 0x0F; // 设置定时器模式
	TMOD |= 0x10; // 设置定时器模式
	TL1 = 0xA4; // 设置定时初始值
	TH1 = 0xFF; // 设置定时初始值
	TF1 = 0; // 清除TF0标志
	TR1 = 1; // 定时器0开始计时
	ET1 = 1; // 中断
	EA = 1; // 总中断使能
	PT1 = 0;// 优先级置于最低
}
/*
void Timer1_Routine() interrupt 3
{	
	TL1 = 0xA4;
	TH1 = 0xFF;
	Counter++;
	Counter %= 100;
	if(Counter < Compare)	
		Motor = 1;	
	else 
		Motor = 0;
}
*/