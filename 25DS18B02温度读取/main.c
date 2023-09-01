#include <REGX52.H>
#include "DS18B20.h"
#include "Delay.h"
#include "LCD1602.h"
#include "OneWire.h"
float Temperature;
void main(void)
{

	LCD_Init();
	LCD_ShowString(1, 1, "temperature:");
	while(1)
	{
		DS18B20_ConvertT();
		Temperature = DS18B20_ReadT();
		if(Temperature < 0) 
		{
			LCD_ShowChar(2, 1, '-');
			Temperature = -Temperature;
		}
		else
		{
			LCD_ShowChar(2, 1, '+');
		}
		// 将温度显示在LCD屏幕上的这一过程比较绕，因为LCD1602不具备显示浮点数和负数的能力；
		// 首先判断当前的温度是否是负数，如果是，就显示一个‘-’字符，否则显示‘+’
		// 之后显示温度的整数部分，可以直接调用LCD_ShowNum(),自动舍去浮点部分
		// 再显示一个‘.’
		// 再显示温度的小数部分，思路是先乘以一万，然后强制类型转换成long，之后再对long类型的值和一万取余，得出小数部分并显示
		LCD_ShowNum(2, 2, Temperature, 3);
		LCD_ShowChar(2, 5, '.');
		LCD_ShowNum(2, 6, (unsigned long)(Temperature * 10000) % 10000, 3);
		Delay(1000);
	}
}