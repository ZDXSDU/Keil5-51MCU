#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Key.h"
#include "I2C.h"
#include "AT24C02.h"
unsigned char KeyNum;
unsigned int Num;
void main()
{
/*
* K1: 对数字加一
* K2：对数字减一
* K3：将当前数据存储至AT24C02
* K4：从AT24C02中读取存储的数据
*/
	LCD_Init();
	LCD_ShowString(2, 11, "ZDXSDU");
	LCD_ShowNum(2, 1, Num,6);
	while(1)
	{
		KeyNum = Key();
		if(KeyNum == 1) // K1: 对数字加一
		{
			Num++;
			LCD_ShowNum(2, 1, Num,5);
		}
		if(KeyNum == 2) // K2：对数字减一
		{
			Num--;
			LCD_ShowNum(2, 1, Num,5);
		}
		if(KeyNum == 3) // K3：将当前数据存储至AT24C02
		{
			// 由于无符号整形占用16位，两个字节。而AT24C02只能以8位进行数据帧传递，所以这里要给他们分分家，让1地址存Num的高八位，0地址存Num的低八位
			Num--;
			AT24C01_WriteByte(0, Num % 256);
			Delay(5);
			AT24C01_WriteByte(1, Num / 256);
			Delay(5);
			LCD_ShowString(2, 1, "Write Done");
			Delay(2000);
			LCD_ShowString(2, 1, "          ");
		}
		if(KeyNum == 4)
		{
			Num = AT24C02_ReadByte(0); // 读取存储的低八位数据
			Num |= AT24C02_ReadByte(1) << 8; // 读取处处的高八位数据，并将读出的数据赋值给Num的高八位
			LCD_ShowString(1, 1, "Read Done");			
			LCD_ShowNum(1, 10, Num, 5);
			LCD_ShowNum(2, 1, Num, 5);
		}
	}
}