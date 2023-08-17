#include <REGX52.H>
#include "Delay.h"
#include "DS1302.h"
#include "LCD1602.h"
#include "Timer0.h"
#include "Key.h"
unsigned char KeyNum; // 独立键盘键码值
unsigned char MODE;// 时钟模式[显示<=>设置]
unsigned char TimeSetSelect;// 时钟设置选择位[0~5]用于确定要设置年还是月
unsigned char TimeSetFlashFlag;// 时钟设置闪烁标志位
void TimeShow(void); // 时钟显示模fn
void TimeSet(void); // 时钟切换模式fn
/* 《按键调时》
* K1: 切换时钟模式[显示<=>设置]。按键将改变MODE值，根据MODE值调用不同的函数[TimeShow()<=>TimeSet()]
* K2: 时钟设置选择位[Y<=>M<=>D<=>H<=>M<=>S]
* K3: 加
* K4: 减
*/
void main()
{
	Timer0_Init();
	LCD_Init();
	DS1302_Init();
	// 2023-08-16 Week3
	// 13:20:35  ZDXSDU
	LCD_ShowString(1, 1, "20  -  -   Week");
	LCD_ShowString(2, 1, "  :  :    ZDXSDU");
	DS1302_SetTime();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum == 1)
		{			
			if(MODE == 0) MODE = 1;
			else if(MODE == 1)
			{
				MODE = 0;
				DS1302_SetTime();
			}				
		}		
		switch(MODE)
		{
			case 0 : 
				TimeShow(); 
				LCD_ShowString(1, 12, "week");
				break;
			case 1 : 
				TimeSet();
				LCD_ShowString(1, 12, " set");
				break;
		}
	}
}
/**
* @brief 读取DS1302的时间，并显示在LCD1602上
* @param  无
* @retval 无
* @interpretation  描述
*/
void TimeShow(void)
{
	DS1302_GetTime();
	LCD_ShowNum(1,3,DS1302_Time[0],2); // 年
	LCD_ShowNum(1,6,DS1302_Time[1],2); // 月
	LCD_ShowNum(1,9,DS1302_Time[2],2); // 日
	LCD_ShowNum(2,1,DS1302_Time[3],2); // 时
	LCD_ShowNum(2,4,DS1302_Time[4],2); // 分
	LCD_ShowNum(2,7,DS1302_Time[5],2); // 秒
	LCD_ShowNum(1,16,DS1302_Time[6],1); // 周
}
/**
* @brief 设置时钟
* @param  无
* @retval 无
* @interpretation  描述
*/
void TimeSet(void)
{
	if(KeyNum == 2) // 选择要调整的项目，0~5依次分别对应年月日时分秒同时对应DS1302_Time的index
	{
		TimeSetSelect++;
		TimeSetSelect %= 7; // 越界清零相当于if(TimeSetSelect > 6) TimeSetSelect = 0;
	}
	if(KeyNum == 3) // 对选中的值进行加1
	{
		DS1302_Time[TimeSetSelect]++;
		// 合法性判断
		if(DS1302_Time[0] > 99) DS1302_Time[0] = 0;
		if(DS1302_Time[1] > 12) DS1302_Time[1] = 1;
		if(DS1302_Time[1] == 1 || DS1302_Time[1] == 3 || DS1302_Time[1] == 5 || DS1302_Time[1] == 7 || DS1302_Time[1] == 8 || DS1302_Time[1] == 10 || DS1302_Time[1] == 12)
		{
			if(DS1302_Time[2] > 31) DS1302_Time[2] = 1;
		}
		else if(DS1302_Time[1] == 4 || DS1302_Time[1] == 6 || DS1302_Time[1] == 9 || DS1302_Time[1] == 11)
		{
			if(DS1302_Time[2] > 30) DS1302_Time[2] = 1;
		}
		else if(DS1302_Time[1] == 2)
		{
			if(DS1302_Time[0] % 4 == 0)
			{ 
				if(DS1302_Time[2] > 29) DS1302_Time[2] = 1;
			}
			else
			{
				if(DS1302_Time[2] > 28) DS1302_Time[2] = 1;
			}
		}
		if(DS1302_Time[3] > 23) DS1302_Time[3] = 0;
		if(DS1302_Time[4] > 59) DS1302_Time[4] = 0;
		if(DS1302_Time[5] > 59) DS1302_Time[5] = 0;
		if(DS1302_Time[6] > 7) DS1302_Time[6] = 1;
	}
	if(KeyNum == 4) // 队选中的值进行减1
	{
		DS1302_Time[TimeSetSelect]--;
		// 合法性判断，由于使用的是无符号的数据类型 因此当减到0再减1时 结果不是-1 而是255，所以这里要用>100来判断
		if(DS1302_Time[0] > 100) DS1302_Time[0] = 99;
		// 月份的合法性判断中还需要包含对日期的切换
		if(DS1302_Time[1] == 0) DS1302_Time[1] = 12;		
		if(DS1302_Time[1] == 1 || DS1302_Time[1] == 3 || DS1302_Time[1] == 5 || DS1302_Time[1] == 7 || DS1302_Time[1] == 8 || DS1302_Time[1] == 10 || DS1302_Time[1] == 12)
		{
			if(DS1302_Time[2] == 0) DS1302_Time[2] = 31;
			if(DS1302_Time[2] > 31) DS1302_Time[2] = 1;
		}
		else if(DS1302_Time[1] == 4 || DS1302_Time[1] == 6 || DS1302_Time[1] == 9 || DS1302_Time[1] == 11)
		{
			if(DS1302_Time[2] == 0) DS1302_Time[2] = 30;
			if(DS1302_Time[2] > 30) DS1302_Time[2] = 1;
		}
		else if(DS1302_Time[1] == 2)
		{
			if(DS1302_Time[0] % 4 == 0)
			{ 
				if(DS1302_Time[2] == 0) DS1302_Time[2] = 29;
				if(DS1302_Time[2] > 29) DS1302_Time[2] = 1;
			}
			else
			{
				if(DS1302_Time[2] == 0) DS1302_Time[2] = 28;
				if(DS1302_Time[2] > 28) DS1302_Time[2] = 1;
			}
		}
		if(DS1302_Time[3] > 100) DS1302_Time[3] = 23;
		if(DS1302_Time[4] > 100) DS1302_Time[4] = 59;
		if(DS1302_Time[5] > 100) DS1302_Time[5] = 59;
		if(DS1302_Time[6] == 0) DS1302_Time[6] = 7;
	}
	// 加减完成后需要对LCD进行重新显示但不重新请求DS1302
	// 如果当前的被选中了，并且数字闪烁的标识位为真，则不显示该数字，反之则显示
	if(TimeSetSelect == 0 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(1, 3, "  ");
	}
	else
	{
		LCD_ShowNum(1,3,DS1302_Time[0],2); // 年
	}	
	if(TimeSetSelect == 1 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(1, 6, "  ");
	}
	else
	{
		LCD_ShowNum(1,6,DS1302_Time[1],2); // 月
	}
	if(TimeSetSelect == 2 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(1, 9, "  ");
	}
	else
	{
		LCD_ShowNum(1,9,DS1302_Time[2],2); // 日
	}
	if(TimeSetSelect == 3 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(2, 1, "  ");
	}
	else
	{
		LCD_ShowNum(2,1,DS1302_Time[3],2); // 时
	}
	if(TimeSetSelect == 4 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(2, 4, "  ");
	}
	else
	{
		LCD_ShowNum(2,4,DS1302_Time[4],2); // 分
	}
	if(TimeSetSelect == 5 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(2, 7, "  ");
	}
	else
	{
		LCD_ShowNum(2,7,DS1302_Time[5],2); // 秒
	}
	if(TimeSetSelect == 6 && TimeSetFlashFlag == 1)
	{
		LCD_ShowString(1, 16, "  ");
	}
	else
	{
		LCD_ShowNum(1,16,DS1302_Time[6],1); // 周
	}
}
/**
* @brief 定时器0的中断函数
* @param  无
* @retval 无
* @interpretation  描述
*/
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count; // 静态变量用于记录中断次数
	// 每一次中断都将定时器的初始值重新赋值，以保证每次都是1ms中断
	TH0 = 0xFC;
	TL0 = 0x18;
	// 每一次中断（1MS），都将T0Count计数器加一，直到加满1000MS视为一秒钟，此时要将T0Count计数器置0
	T0Count++;
	if(T0Count >= 500)
	{
		T0Count = 0;
		TimeSetFlashFlag = !TimeSetFlashFlag; // 通过控制闪烁标志位来实现对应的数字闪烁
	}
}