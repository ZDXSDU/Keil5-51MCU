#include <STC89C5xRC.H>
#include <INTRINS.H>
sbit LCD_RS = P2^6; // 数据/指令选择IO口  1:数据 0:指令
sbit LCD_RW = P2^5; // 读/写选择IO口  1:读 0:写
sbit LCD_E = P2^7; // 使能  1:数据有效 下降沿执行命令
sfr LCD_DataPort = 0x80; // LCD1602 D0~D7数据IO口
void LCD_Delay(); // Delay1ms
void LCD_WriteCommand(unsigned char Command); // 时序结构-写指令
void LCD_WriteData(unsigned char Data); // 时序结构-写数据
void LCD_Init(void); // LCD初始化
void LCD_SetCursor(unsigned char Row, unsigned char Column); // 设置光标位置
unsigned int LCD_Power(unsigned int X, Y); // 乘方运算
void LCD_ShowChar(unsigned char Row, unsigned char Column, unsigned char Char); // LCD显示字符
void LCD_ShowString(unsigned char Row, unsigned char Column, unsigned char *String); // LCD显示字符串
void LCD_ShowUnsignedDECNumber(unsigned char Row, unsigned char Column, unsigned int Number, unsigned char Length); // LCD显示无符号十进制整数
void LCD_ShowSignedDECNumber(unsigned char Row, unsigned char Column, unsigned int Number, unsigned char Length); // LCD显示有符号十进制整数
void LCD_ShowHexNum(unsigned char Row, unsigned char Column, unsigned int Number, unsigned char Length); // LCD显示十六进制数字
void LCD_ShowBinNumber(unsigned char Row, unsigned char Column, unsigned int Number, unsigned char Length); // LCD显示二进制数字
void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_DataPort = Command;
	LCD_E = 1;
	LCD_Delay();
	LCD_E = 0;
	LCD_Delay();
}
void LCD_WriteData(unsigned char Data)
{
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_DataPort = Data;
	LCD_E = 1;
	LCD_Delay();
	LCD_E = 0;
	LCD_Delay();
}
void LCD_Delay() 
{ // @11.0592MHz Delay1ms:防止芯片使能E置高再给下降沿时指令执行时间不够
	unsigned char data i, j;
	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}
void LCD_Init(void)
{
	LCD_WriteCommand(0x38); // 八位数据接口，两行显示，5*7点阵
	LCD_WriteCommand(0x0C); // 显示开，光标关，闪烁关
	LCD_WriteCommand(0x06); // 数据读写操作后，光标自动加一，画面不变
	LCD_WriteCommand(0x01); // 清屏
}
void LCD_SetCursor(unsigned char Row, unsigned char Column)
{
	if(Row == 1) LCD_WriteCommand(0x80 | (Column - 1));
	else LCD_WriteCommand(0x80 | (0x40 + (Column - 1)));
}
void LCD_ShowChar(unsigned char Row, unsigned char Column, unsigned char Char)
{
	LCD_SetCursor(Row, Column);
	LCD_WriteData(Char);
}
void LCD_ShowString(unsigned char Row, unsigned char Column, unsigned char *String)
{

	unsigned char i;
	LCD_SetCursor(Row, Column);	
	for(i = 0; String[i] != '\0'; i++)
	{ // 遍历字符串数组，并依次输出字符串中的每一个字符，直到遇见字符串结尾标志
		LCD_WriteData(String[i]);
	}
}
void LCD_ShowUnsignedDECNumber(unsigned char Row, unsigned char Column, unsigned int Number, unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Row, Column);
	for(i = Length; i > 0; i--)
	{
		LCD_WriteData(((Number / LCD_Power(10, i -1)) % 10) + 0x30);
	}
}
unsigned int LCD_Power(unsigned int X, Y)
{
	unsigned char i;
	unsigned int Result = 1;
	for(i = 0; i < Y; i++)
	{
		Result *= X;
	}
	return Result;
}
void LCD_ShowSignedDECNumber(unsigned char Row, unsigned char Column, int Number, unsigned char Length)
{
	unsigned char i;
	unsigned int Num;
	LCD_SetCursor(Row, Column);
	if(Number < 0)
	{
		LCD_WriteData('-');
		Num = -Number;
	}
	for(i = Length; i > 0; i--)
	{
		LCD_WriteData(((Num / LCD_Power(10, i -1)) % 10) + 0x30);
	}
}
void LCD_ShowHexNum(unsigned char Row, unsigned char Column, unsigned int Number, unsigned char Length)
{
	unsigned char i, SingleNumber;
	LCD_SetCursor(Row, Column);
	for(i = Length; i > 0; i--)
	{
		SingleNumber = (Number / LCD_Power(16, i -1)) % 16;
		// 将 11 12 13 14 15 转换成A B C D E F
		if(SingleNumber > 9) LCD_WriteData(SingleNumber - 10 + 'A');
		else LCD_WriteData(SingleNumber + 0x30);		
	}
}
void LCD_ShowBinNumber(unsigned char Row, unsigned char Column, unsigned int Number, unsigned char Length)
{
	unsigned char i;
	LCD_SetCursor(Row, Column);
	for(i = Length; i > 0; i--)
	{
		LCD_WriteData('0' + (Number / LCD_Power(2, i - 1)) % 2);
	}
}