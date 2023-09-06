#include <STC89C5xRC.H>
#include "LCD1602OUEN.H"
void main(void)
{
	LCD_Init();
	LCD_ShowChar(1, 1, 0x41); // A
	LCD_ShowString(1, 3, "Zdx"); // ZDXsdu
	LCD_ShowUnsignedDECNumber(1, 7, 543, 4); // 0543
	LCD_ShowSignedDECNumber(1, 12, -7193, 4); // -7193
	LCD_ShowHexNum(2, 1, 220, 2); // DC
	while(1)
	{
		
	}
}