#ifndef __LCD1602OUEN_H__
#define __LCD1602OUEN_H__
void LCD_Init(void); // LCD初始化
void LCD_ShowChar(unsigned char Row, unsigned char Column, unsigned char Char); // LCD显示字符
void LCD_ShowString(unsigned char Row, unsigned char Column, unsigned char *String); // LCD显示字符串
void LCD_ShowUnsignedDECNumber(unsigned char Row, unsigned char Column, unsigned int Number, unsigned char Length); // LCD显示无符号整数
void LCD_ShowSignedDECNumber(unsigned char Row, unsigned char Column, unsigned int Number, unsigned char Length); // LCD显示有符号整数
void LCD_ShowHexNum(unsigned char Row, unsigned char Column, unsigned int Number, unsigned char Length); // LCD显示十六进制数字
#endif