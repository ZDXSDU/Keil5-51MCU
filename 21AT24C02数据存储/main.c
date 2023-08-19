#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Key.h"
#include "I2C.h"
#include "AT24C02.h"
unsigned char Data;
void main()
{
	LCD_Init();
	LCD_ShowString(1, 1, "Data is:");
	LCD_ShowString(2, 11, "ZDXSDU");
	AT24C01_WriteByte(1, 99); // 向AT24C02的0x01写入数据
	Delay(15); // ROM写入数据需要时间，根据AT24C02的芯片手册，该芯片的写周期为5MS，因此此处需要延时5毫秒以等待其完全写入才能读	
	Data = AT24C02_ReadByte(1); // 读取AT24C02地址0x01的数据
	LCD_ShowNum(1, 10, Data, 4);
	while(1)
	{
		
	}
}