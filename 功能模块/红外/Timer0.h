#ifndef __Timer0_H__
#define __Timer0_H__
Timer0_Init();
void Timer0_SetCounter(unsigned int Value);
unsigned int Timer0_GetCounter(void);
void Timer0_Run(unsigned char Flag);
#endif