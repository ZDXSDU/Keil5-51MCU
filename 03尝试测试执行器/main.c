#include <REGX52.H>
#include "LCD1602.H"

void Delay(unsigned int ms)
{
	unsigned char data i, j;
	while(ms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}
void main()
{
	//初始化
	LCD_Init();
	P1_5=0;
	P1_4=0;
	/*屏幕：
		1.正在开阀：Opening；
		2.正在关阀：Closing；
		3.阀门开到位：Open；
		4.阀门关到位：Close；
	按键：
		1.K1:电机正转；
		2.K2:电机反转；*/
	while(1)
	{
		if(P3_1==0)//K1 开阀
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			LCD_ShowString(1,1,"        ");
			LCD_ShowString(2,1,"        ");
			LCD_ShowString(1,1,"Opening");
			while(P1_7)
			{
				P1_5=0;
				P1_4=1;
			}
			P1_5=1;
			P1_4=1;
			LCD_ShowString(1,1,"        ");
			LCD_ShowString(2,1,"        ");
			LCD_ShowString(2,1,"Open");
		}
		if(P3_0==0)//K2 关阀
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			LCD_ShowString(1,1,"        ");
			LCD_ShowString(2,1,"        ");
			LCD_ShowString(1,1,"Closing");
			while(P1_6)
			{
				P1_5=1;
				P1_4=0;
			}
			P1_5=1;
			P1_4=1;
			LCD_ShowString(1,1,"        ");
			LCD_ShowString(2,1,"        ");
			LCD_ShowString(2,1,"Close");
		}
	}
}