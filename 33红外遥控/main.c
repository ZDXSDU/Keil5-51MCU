#include <STC89C5xRC.H>
#include "Delay.h"
#include "LCD1602.h"
#include "IR.h"
unsigned char Num;
unsigned char Address, Command;
void main(void)
{
	LCD_Init();
	IR_Init();
	LCD_ShowString(1, 1, "Add:");
	LCD_ShowString(1, 11, "Com:");
	LCD_ShowString(2, 1, "Speed:");
	LCD_ShowNum(2, 7, Num, 3);
	while(1)
	{
		if(IR_GetDataFalg() || IR_GetRepeatFlag())
		{
			Address = IR_GetAddress();
			Command = IR_GetCommand();
			LCD_ShowHexNum(1, 5, Address, 2);
			LCD_ShowHexNum(1, 15, Command, 2);
			if(Command == IRRC_VOL_MINISH)
				Num--;
			if(Command == IRRC_VOL_ENLARGE)
				Num++;
			LCD_ShowNum(2, 7, Num, 3);
		}
	}
}