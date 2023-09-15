#include <STC89C5xRC.H>
#include "Nixie.h"
#include "IR.h"
#include "Motor.h"
unsigned char ICommand, DisplayNum;
void main(void)
{
	Motor_Init();
	IR_Init();
	while(1)
	{
		if(IR_GetDataFalg())
		{
			ICommand = IR_GetCommand();
			if(ICommand == IRRC_0) 
			{
				Motor_SetSpeed(0);
				DisplayNum = 0;
			}
			if(ICommand == IRRC_1)
			{
				Motor_SetSpeed(25);
				DisplayNum = 1;
			}
			if(ICommand == IRRC_2) 
			{
				Motor_SetSpeed(50);
				DisplayNum = 2;
			}
			if(ICommand == IRRC_3)
			{
				Motor_SetSpeed(75);
				DisplayNum = 3;
			}
			if(ICommand == IRRC_4)
			{
				Motor_SetSpeed(100);
				DisplayNum = 4;
			}
		}
		Nixie(1, DisplayNum);		
	}
}