#include <STC89C5xRC.H>
#include "PWM.h"
sbit Motor = P1^0;
unsigned char Counter, Compare; // 定义计数器和比较值
/**
* @brief 定时器1 中断执行函数，处理PWM方波输出
* @param  无
* @retval 无
* @interpretation  描述
*/
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
/**
* @brief 电机初始化函数
* @param  无
* @retval 无
* @interpretation  描述
*/
void Motor_Init(void)
{
	Timer1_PWM_Init();
}
/**
* @brief 设置速度
* @param  无
* @retval 无
* @interpretation  描述
*/
void Motor_SetSpeed(unsigned char Speed)
{
	Compare = Speed;
}