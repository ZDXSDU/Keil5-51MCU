#include <STC89C5xRC.H>
/**
  * @brief 定时器0的1毫秒*1000=1秒定时器通用初始化函数
  * @param  无
  * @retval 无
  */
void Timer0_Init()
{
	// 在不改变定时器1的前提下配置定时器0的模式寄存器TMOD（不可位寻址）
	TMOD &= 0xF0;
	TMOD |= 0x01;	
	// 配置定时器的初始值（高4位+低4位）
	TH0 = 0xFC; // DEC[(65535-1000)/16^2]=>HEX 取出高位
	TL0 = 0x18; // DEC[(65535-1000)%16^2]=>HEX 取出低位
	// 配置定时器0的控制寄存器TCON（可位寻址）
	TF0 = 0; // 溢出中断标志置于0，防止定时器刚一启动就中断
	TR0 = 0; // 运行控制位，初始化时不允许T0计时
}
/**
* @brief 将定时器改装成计时器
* @param  Value 要计时的时间
* @retval 无
* @interpretation  描述
*/
void Timer0_SetCounter(unsigned int Value)
{
	TH0 = Value / 256;
	TL0 = Value % 256;
}
/**
* @brief 取出定时器的值
* @param  无
* @retval 定时器的值
* @interpretation  描述
*/
unsigned int Timer0_GetCounter(void)
{
	return (TH0 << 8) | TL0;
}
/**
* @brief 控制定时器启停
* @param  Flag 定时器运行的标识位，为真时运行
* @retval 定时器的值
* @interpretation  描述
*/
void Timer0_Run(unsigned char Flag)
{
	TR0 = Flag;
}