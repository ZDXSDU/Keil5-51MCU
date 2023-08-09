#include <REGX52.H>
#include "MatrixKey.h"
#include "LCD1602.h"
unsigned char num = 0;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"keypress is :");
	LCD_ShowString(2,11,"ZDXSDU");	
	while(1)
	{		
		num = GetMatrixKey();
		if(num)
			LCD_ShowNum(2,1,num,2);
	}
}