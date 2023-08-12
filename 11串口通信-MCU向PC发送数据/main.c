#include <REGX52.H>
#include "UART.h"

void main()
{
	
	UART_Init_1200();
	UART_SendByte(250);
	while(1)
	{
//		UART_SendByte(0x06);
//		Delay(2000);
	};
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