#include <STC89C5xRC.H>
#include "Delay.h"
#include "LCD1602.h"
void main(void)
{
	LCD_Init();
	LCD_ShowString(1, 1, "ADB:");
	while(1)
	{
		
	}
}