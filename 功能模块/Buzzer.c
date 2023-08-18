#include <REGX52.H>
#include <INTRINS.H>
#include "Delay.h" // 延时
sbit Buzzer = P2^5;
void Buzzer_Delay500us();
unsigned int i;
/**
* @brief 以500Hz的频率播放提示音
* @param  unsigned int ms 蜂鸣时长
* @retval 无
* @interpretation  描述
*/
void Buzzer500Hz(unsigned int ms)
{
	for(i = 0; i < ms; i++)
	{
		Buzzer = !Buzzer;
		Delay(1);
		/*delay 1ms ：高电平1毫秒、低电平1毫秒，周期是2毫秒（0.002秒），频率是1 / 0.002 = 500Hz*/
	}
}
/**
* @brief 以500Hz的频率播放提示音<标准的提示音>
* @param  unsigned int ms 蜂鸣时长
* @retval 无
* @interpretation  描述
*/
void Buzzer1000Hz(unsigned int ms)
{
	for(i = 0; i < ms; i++)
	{
		Buzzer = !Buzzer;
		Buzzer_Delay500us();
		/*delay 1ms ：高电平1毫秒、低电平1毫秒，周期是2毫秒（0.002秒），频率是1 / 0.002 = 500Hz*/
	}
}
/**
* @brief 以1000Hz的频率播放俺家按提示音
* @param  无
* @retval 无
* @interpretation  描述
*/
void Buzzer_Delay500us()
{
	unsigned char data i;
	_nop_();
	i = 227;
	while (--i);
}
