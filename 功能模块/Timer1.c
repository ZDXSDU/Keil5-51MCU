#include <STC89C5xRC.H>
/**
  * @brief 定时器1的1毫秒*1000=1秒定时器通用初始化函数
  * @param  无
  * @retval 无
  */
void Timer1_Init()
{
	TMOD &= 0x0F;
	TMOD |= 0x10;
	TF1 = 0;
	TR1 = 1;
	TH1 = 0xFC; // DEC[(65535-1000)/16^2]=>HEX 取出高位
	TL1 = 0x18; // DEC[(65535-1000)%16^2]=>HEX 取出低位
	ET1 = 1;
	EA = 1;
	PT1 = 0;
}
/*
void Timer1_Routine() interrupt 3
{	
	TL0 = 0xA4;
	TH0 = 0xFF;
	Counter++;
	Counter %= 100;
	if(Counter < Compare)	
		Motor = 1;	
	else 
		Motor = 0;
}
*/