#include <REGX52.H>
#include "Delay.h"

void UART_SendByte(unsigned char Byte)
{
	SBUF = Byte;
	while(TI == 0);
	TI = 0;
}

void UartInit_4800(void)		//4800bps@11.0592MHz
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xF4;			//设置定时初始值
	TH1 = 0xF4;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
}

void main()
{
	void UartInit_4800(void);
	
	while(1){UART_SendByte(0xFF);Delay(1500);};
}

void UART_Routine() interrupt 4
{
	if(RI == 1)					//如果接收标志位为1，接收到了数据
	{
		P2 = ~SBUF;				//读取数据，取反后输出到LED
		UART_SendByte(SBUF);	//将受到的数据发回串口
		RI = 0;					//接收标志位清0
	}
}