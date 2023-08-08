#include <REGX52.H>
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

void end()
{
	P2=0xFF;
	Delay(200);
	P2=0x00;
	Delay(200);
}

void main()
{
	/*
		指示灯：
			1.电机正在工作：D1、D2交替闪烁；
			2.阀门开到位：D2常亮；
			3.阀门关到位：D1
	常亮；
			4.待机：D1~D8熄灭；
		按键：
			1.K1:给电机通电；
			2.RSTK1:重启并给电机短暂供电以使限位开关松开；
	*/
	
	P2=0xFF;
	P1_0=0;
	while(1)
	{
		if(P3_1==0)//K1 给电机通电
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			while(1)
			{
				if(P3_7==0)//关到位
				{
					P1_0=0;
					P2=0xFE;
					break;
				}
				if(P3_6==0)//开到位
				{
					P1_0=0;
					P2=0xFD;
					break;
				}
				P1_0=1;
				P2=0xFE;
				Delay(200);
				P2=0xFD;
				Delay(200);
			}
		}
	}
}