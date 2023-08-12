#ifndef __UART_H__
#define __UART_H__

void UART_OnlyTxD_Init();
void UART_Init_4800(void);
void UART_Init_1200(void);
void UART_SendByte(unsigned char Byte);

#endif