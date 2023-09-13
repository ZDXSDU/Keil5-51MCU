#include <STC89C5xRC.H>
#include "Delay.h"
#include "LCD1602.h"
#include "XPT2046.h"
unsigned int AD_Value;
void main(void)
{
	LCD_Init();
	LCD_ShowString(1, 1, "ADJ NTC GR  PT");
	while(1)
	{
		AD_Value = XPT2046_Read(XPT2046_XP_8);
		LCD_ShowNum(2, 1, AD_Value, 3);		
		AD_Value = XPT2046_Read(XPT2046_YP_8);	//读取AIN1，热敏电阻
		LCD_ShowNum(2, 5, AD_Value, 3);
		AD_Value=XPT2046_Read(XPT2046_VBAT_8);	//读取AIN2，光敏电阻
		LCD_ShowNum(2, 9, AD_Value, 3);
		AD_Value=XPT2046_Read(XPT2046_AUX_8);	//读取AIN3(AUX)，PT1000
		LCD_ShowNum(2, 13, AD_Value, 3);
		Delay(100);
	}
}