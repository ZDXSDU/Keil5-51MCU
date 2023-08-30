#include <REGX52.H>
sbit Sg90_com = P1^0;

unsigned char compare = 0, count = 0; //compare比较值控制占空比大小，控制舵机转动的角度

void Delay1ms(unsigned int num) //@11.0592MHz
{
	unsigned char i, j;
	while(num--)
	{
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}
void Init_Timer0()
{
	TMOD = 0x01;
	TL0 = 0x33; //设置定时初值
	TH0 = 0xFE; //设置定时初值
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	PT0 = 1;
	TF0=0;
}
void main()
{
	Init_Timer0();
	while(1)
	{
		compare = 1; //0度
		Delay1ms(1000);
		compare = 2; //45度
		Delay1ms(1000);
		compare = 3; //90度
		Delay1ms(1000);
		compare = 4; //135度
		Delay1ms(1000);
		compare = 5; //180度
		Delay1ms(1000);
	}
}
void Timer0_Rountine() interrupt 1 //每次定时器溢出时是0.5ms
{
	TL0 = 0x33; //设置定时初值
	TH0 = 0xFE; //设置定时初值
	count++;
	//PWM控制
	if(count < 40) //每一个0.5mscount都会++，加了40次就20ms，是舵机控制的一个周期
	{
		if(count < compare) //通过比较值控制高电平占据周期的时间，也就是占空比大小
		{
		Sg90_com = 1;
		}
		else
		{
		Sg90_com = 0;
		}
	}
	else //count加到40后清零
	{
		count = 0;
		Sg90_com = 1;
	}
}