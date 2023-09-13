#include <STC89C5xRC.H>
#include "Delay.h"
sbit XPT2046_CS = P3^5; // 片选
sbit XPT2046_DCLK = P3^6; // 时钟
sbit XPT2046_Dout = P3^7; // 输出
sbit XPT2046_Din = P3^4; // 输入
/**
* @brief XPT2046的SPI总线时序函数
* @param[Command] 控制字
* @retval 无
* @interpretation  描述
*/
unsigned int XPT2046_Read(unsigned char Command)
{
	unsigned int AD_Value = 0;
	unsigned char i;
	XPT2046_DCLK = 0;
	XPT2046_CS = 0;
	for(i = 0; i < 8; i++)
	{
		XPT2046_Din = Command & (0x80 >> i);
		XPT2046_DCLK = 1;
		XPT2046_DCLK = 0;
	}
	Delay(1);	
	for(i = 0; i < 16; i++)
	{
		XPT2046_DCLK = 1;
		XPT2046_DCLK = 0;
		if(XPT2046_Dout)
			AD_Value |= (0x8000 >> i); 
	}
	XPT2046_CS = 1;
	if(Command & 0x08)
		// 八位控制字
		return AD_Value >> 8;
	else
		// 十二位控制字
		return AD_Value >> 4;
}