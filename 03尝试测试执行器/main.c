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
	//��ʼ��
	LCD_Init();
	P1_5=0;
	P1_4=0;
	/*��Ļ��
		1.���ڿ�����Opening��
		2.���ڹط���Closing��
		3.���ſ���λ��Open��
		4.���Źص�λ��Close��
	������
		1.K1:�����ת��
		2.K2:�����ת��*/
	while(1)
	{
		if(P3_1==0)//K1 ����
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
		if(P3_0==0)//K2 �ط�
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