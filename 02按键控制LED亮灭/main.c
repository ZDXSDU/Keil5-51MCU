#include <REGX52.H>
#include <INTRINS.H>

void Delay(unsigned int ms)		//@12.000MHz
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
	P2=0x00;
	while(1)		
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			P2=~P2;
		}
	}
}