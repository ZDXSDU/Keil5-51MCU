#include <STC89C5xRC.H>
void Timer0_PWM_Init(void) // 100微秒@11.0592MHz
{
	TMOD &= 0xF0; // 设置定时器模式
	TMOD |= 0x01; // 设置定时器模式
	TL0 = 0xA4; // 设置定时初始值
	TH0 = 0xFF; // 设置定时初始值
	TF0 = 0; // 清除TF0标志
	TR0 = 1; // 定时器0开始计时
	ET0 = 1; // 中断
	EA = 1; // 总中断使能
	PT0 = 0;// 优先级置于最低
}
