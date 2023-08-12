#include <REGX52.H>

/**
  * @brief  串口初始化（仅发送 不接收）。12MHz\4800\加倍
  * @param  无
  * @retval 无
  */
void UART_OnlyTxD_Init()
{
	SCON = 0x40; // 0100 0000 [8位UART，波特率可变，不启动RxD接收]
	PCON |= 0x80; // 1000 0000 [开启波特率加倍以提高12MHz时钟下的精度]
	TMOD &= 0x0F; // 1111 0000 [T0和T1在同一个8位寄存器，即保持T0不变并清空T1]
	TMOD |= 0x20; // 0010 0000 [T1使用8位自动重装模式]
	TL1 = 0xF3; // 定时器的初始值[DEC:243]，该值与波特率有关，此处使用的是4800
	TH1 = 0xF3; // 定时器的自动重装值，同上
	ET1 = 0; // 禁止T1产生中断
	TR1 = 1; // 开启T1定时器
}

/**
  * @brief  串口初始化（发送和接收）。12MHz\4800\加倍
  * @param  无
  * @retval 无
  */
void UART_Init_4800(void)
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF3;			//设置定时初始值
	TH1 = 0xF3;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
}

/**
  * @brief  串口初始化（发送和接收）。12MHz\1200\加倍
  * @param  无
  * @retval 无
  */
void UART_Init_1200(void)		//1200bps@12.000MHz
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xCC;			//设置定时初始值
	TH1 = 0xCC;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
}

/**
  * @brief  串口发送一个字节数据
  * @param  Byte 要发送的一个字节数据
  * @retval 无
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF = Byte;
	while(TI == 0);
	TI = 0;
}