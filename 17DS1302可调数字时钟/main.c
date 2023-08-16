#include <REGX52.H>
#include "Delay.h"
#include "DS1302.h"
#include "LCD1602.h"
void main()
{
	LCD_Init();
	DS1302_Init();
	// 2023-08-16 Week3
	// 13:20:35  ZDXSDU
	LCD_ShowString(1, 1, "20  -  -   Week");
	LCD_ShowString(2, 1, "  :  :    ZDXSDU");
	DS1302_SetTime();
	while(1)
	{
		DS1302_GetTime();
		LCD_ShowNum(1,3,DS1302_Time[0],2); // 年
		LCD_ShowNum(1,6,DS1302_Time[1],2); // 月
		LCD_ShowNum(1,9,DS1302_Time[2],2); // 日
		LCD_ShowNum(2,1,DS1302_Time[3],2); // 时
		LCD_ShowNum(2,4,DS1302_Time[4],2); // 分
		LCD_ShowNum(2,7,DS1302_Time[5],2); // 秒
		LCD_ShowNum(1,16,DS1302_Time[6],1); // 周
		Delay(300);
	}
}