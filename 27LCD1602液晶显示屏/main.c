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
	LCD_ShowBinNumber(2, 4, 106, 8); // 0110 1010
	LCD_ShowChar(2, 13, 0xDF); // ℃
	LCD_ShowChar(2, 14, 0x43); // ℃
	while(1)
	{
		
	}
}