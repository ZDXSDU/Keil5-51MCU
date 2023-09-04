#include <REGX52.H>
#include "Timer0.h"
#include "OneWire.h"
#include "DS18B20.h"
#include "LCD1602.h"
#include "Delay.h"
#include "Buzzer.h"
#include "Key.h"
#include "AT24C02.h"
#include "I2C.h"
void LCD_ShowFloat(float F, unsigned char Row, Clo);
void LCD_ShowThTl(void);
void ChangeThTl_Compare(void);
void Compare(void);
char Tem_MIN, Tem_MAX; // 温度上限和下限
float Temperature;
void main(void)
{
	Timer0_Init();
	LCD_Init();
	LCD_ShowString(1, 1, "T:          OV:");
	LCD_ShowString(2, 1, "TL:      TH:");
	DS18B20_ConvertT();
	Tem_MAX = AT24C02_ReadByte(0);	//读取温度阈值数据
	Tem_MIN = AT24C02_ReadByte(1);
	if(Tem_MAX > 125 || Tem_MIN < -55 || Tem_MAX <= Tem_MIN)
	{
		Tem_MAX = 35;			//如果阈值非法，则设为默认值
		Tem_MIN = 28;
	}
	while(1)
	{
		DS18B20_ConvertT();
		Delay(500);
		Temperature = DS18B20_ReadT();
		LCD_ShowFloat(Temperature, 1, 3);
		ChangeThTl_Compare();
		LCD_ShowThTl();
		//Compare();
	}
}
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TH0 = 0xD4;
	TL0 = 0xCD;
	T0Count++;
	if(T0Count > 20)
	{
		T0Count = 0;
		Key_Loop();
	}
}
/**
* @brief 将DS18B20的温度显示在LCD1602上
* @param  float F：DB18B20返回的浮点温度； Row, Clo ：在LCD1602的几行几列显示
* @retval 无
* @interpretation  描述
*/
void LCD_ShowFloat(float F, unsigned char Row, Clo) // 浮点，行，列
{
	if(F < 0)
	{
		F = -F;
		LCD_ShowChar(Row, Clo, '-');
	}
	else
	{
		LCD_ShowChar(Row, Clo, '+');
	}
	LCD_ShowNum(Row, Clo + 1, F, 3); // 整数部分
	LCD_ShowChar(Row, Clo + 1 + 3, '.'); // 小数点
	LCD_ShowNum(Row, Clo + 1 + 3 + 1, (unsigned long)(F * 10000) % 10000, 3); // 小数部分
}
/**
* @brief 用LCD1602显示报警温度的上下阈值
* @param  无
* @retval 无
* @interpretation  描述
*/
void LCD_ShowThTl(void)
{	
	LCD_ShowSignedNum(2, 4, Tem_MIN, 3);
	LCD_ShowSignedNum(2, 13, Tem_MAX, 3);
}
/**
* @brief 独立按键控制温度报警阈值的上下限
* @param  无
* @retval 无
* @interpretation  描述
*/
void ChangeThTl_Compare(void)
{
	unsigned char KeyNum = 0;
	KeyNum = Key();
	if(KeyNum > 0)
	{
		if(KeyNum == 1)
		{
			Tem_MIN++;
			if(Tem_MIN > 125) Tem_MIN = 125;
			if(Tem_MIN > Tem_MAX) Tem_MIN = Tem_MAX;
		}
		if(KeyNum == 2)
		{
			Tem_MIN--;
			if(Tem_MIN < -55) Tem_MIN = -55;
			if(Tem_MIN > Tem_MAX) Tem_MIN = Tem_MAX;
		}
		if(KeyNum == 3)
		{
			Tem_MAX++;
			if(Tem_MAX > 125) Tem_MAX = 125;
			if(Tem_MAX < Tem_MIN) Tem_MAX = Tem_MIN;
		}
		if(KeyNum == 4)
		{
			Tem_MAX--;
			if(Tem_MAX < -55) Tem_MAX = -55;
			if(Tem_MAX < Tem_MIN) Tem_MAX = Tem_MIN;
		}
		Buzzer1000Hz(100);
		AT24C01_WriteByte(0, Tem_MAX);		//写入到At24C02中保存
		Delay(5);
		AT24C01_WriteByte(1, Tem_MIN);
		Delay(5);
		if(Temperature > Tem_MAX) 
		{
			LCD_ShowChar(1, 16, 'H');
		}
		if(Temperature < Tem_MIN) 
		{
			LCD_ShowChar(1, 16, 'L');
		}
		if(Temperature < Tem_MAX && Temperature > Tem_MIN) 
		{
			LCD_ShowString(1, 16, ' ');
		}
	}
}
/**
* @brief 越界判断
* @param  无
* @retval 无
* @interpretation  描述
*/
void Compare(void)
{
	if(Temperature > Tem_MAX) 
	{
		LCD_ShowChar(1, 16, 'H');
	}
	if(Temperature < Tem_MIN) 
	{
		LCD_ShowChar(1, 16, 'L');
	}
	if(Temperature < Tem_MAX && Temperature > Tem_MIN) 
	{
		LCD_ShowString(1, 16, ' ');
	}
}