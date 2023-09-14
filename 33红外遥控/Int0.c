#include <STC89C5xRC.H>
void Int0_Init(void)
{
	IT0 = 1; // 中断0 下降沿触发
	IE0 = 0; // 清空中断标志位
	EX0 = 1; // 打开中断
	EA = 1;  // 打开总中断
	PX0 = 1; // 给个高优先级，他能中断别的中断以进行嵌套
}
/**
* @brief 外部中断寄存器中断函数
* @param  无
* @retval 无
* @interpretation  描述
*/
//void Int0_Rountine(void)  interrupt 0
//{
//	Num++;
//}