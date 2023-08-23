#include <REGX52.H>
#include <INTRINS.H>
#define LCD_DataPort P0
sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
sbit LCD_EN=P2^7;
sbit FAN_IN1 = P1^5;
sbit FAN_IN2 = P1^4;
sbit FAN_OPEN = P3^1;
sbit FAN_STOP = P3^0;
sbit FAN_Switch = P3^2;
void Delay(unsigned int xms);
void LCD_Delay();
void LCD_WriteCommand(unsigned char Command);
void LCD_WriteData(unsigned char Data);
void LCD_SetCursor(unsigned char Line,unsigned char Column);
void LCD_Init();
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String);
int LCD_Pow(int X,int Y);
void LCD_ShowNum(unsigned char Line,unsigned char Column,unsigned int Number,unsigned char Length);
void main()
{
	LCD_Init();
	FAN_IN1 = 0;
	FAN_IN2 = 0;
	LCD_ShowString(1, 1, "Fan         XXLW");
	while(1)
	{
		if(FAN_OPEN == 0)
		{
			Delay(20);
			while(FAN_OPEN == 0);
			Delay(20);
			LCD_ShowString(1, 5, "open");
			FAN_IN1 = 1;
			FAN_IN2 = 0;
			LCD_ShowString(2, 1, "Zheng Zhuan");
		}
		if(FAN_STOP == 0)
		{
			Delay(20);
			while(FAN_STOP == 0);
			Delay(20);
			LCD_ShowString(1, 5, "stop");
			FAN_IN1 = 1;
			FAN_IN2 = 1;
		}
		if(FAN_Switch == 0)
		{
			Delay(20);
			while(FAN_Switch == 0);
			Delay(20);
			FAN_IN1 = ~FAN_IN1;
			FAN_IN2 = ~FAN_IN2;
			LCD_ShowString(2, 1, "Fan Zhuan");
		}
	}
}
void Delay(unsigned int xms)
{
	unsigned char data i, j;
	while(xms--)
	{
		_nop_();
		_nop_();
		_nop_();
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
	}
}
void LCD_Delay()
{
	unsigned char i, j;
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}
void LCD_WriteCommand(unsigned char Command)
{
	LCD_RS=0;
	LCD_RW=0;
	LCD_DataPort=Command;
	LCD_EN=1;
	LCD_Delay();
	LCD_EN=0;
	LCD_Delay();
}
void LCD_WriteData(unsigned char Data)
{
	LCD_RS=1;
	LCD_RW=0;
	LCD_DataPort=Data;
	LCD_EN=1;
	LCD_Delay();
	LCD_EN=0;
	LCD_Delay();
}
void LCD_SetCursor(unsigned char Line,unsigned char Column)
{
	if(Line==1)
	{
		LCD_WriteCommand(0x80|(Column-1));
	}
	else if(Line==2)
	{
		LCD_WriteCommand(0x80|(Column-1+0x40));
	}
}
void LCD_Init()
{
	LCD_WriteCommand(0x38);
	LCD_WriteCommand(0x0c);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x01);
}
void LCD_ShowString(unsigned char Line,unsigned char Column,char *String)
{
	unsigned char i;
	LCD_SetCursor(Line,Column);
	for(i=0;String[i]!='\0';i++)
	{
		LCD_WriteData(String[i]);
	}
}