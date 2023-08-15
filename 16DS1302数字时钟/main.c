#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"
unsigned char Seconds, Minutes, Hour, Date, Month, Day, Year;
void main()
{
	LCD_Init();
	DS1302_Init();
	DS1302_WriteByte(0x8E, 0x00); // 解除DS1302芯片的写保护
	DS1302_WriteByte(0x80, 0x01);
	LCD_ShowString(1, 1, "ZDXSDU");	
	while(1)
	{
		Seconds = DS1302_ReadByte(0x81);
		LCD_ShowNum(2, 1, Seconds, 4);
		Delay(100);
	}
}