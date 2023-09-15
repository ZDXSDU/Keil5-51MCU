#include <STC89C5xRC.H>
sbit D1 = P1^0; //定义步进电机连接端口
sbit C1 = P1^1; //定义步进电机连接端口
sbit B1 = P1^2; //定义步进电机连接端口
sbit A1 = P1^3; //定义步进电机连接端口 
#define Coil_AB {A1 = 1; B1 = 1; C1 = 0; D1 = 0;}//AB相通电，其他相断电
#define Coil_BC {A1 = 0; B1 = 1; C1 = 1; D1 = 0;}//BC相通电，其他相断电
#define Coil_CD {A1 = 0; B1 = 0; C1 = 1; D1 = 1;}//CD相通电，其他相断电
#define Coil_DA {A1 = 1; B1 = 0; C1 = 0; D1 = 1;}//DA相通电，其他相断电
#define Coil_OFF {A1 = 0; B1 = 0; C1 = 0; D1 = 0;}//全部断电
unsigned char Speed;
void DelayMs(unsigned char ms);
void main(void)
{
	Speed = 5; //调整转动速度，速度不可以调节的过快，不然就没有力矩转动了
	while(1)  
	{         
		Coil_AB;
		DelayMs(Speed);
		Coil_BC;
		DelayMs(Speed);
		Coil_CD;
		DelayMs(Speed);
		Coil_DA;
		DelayMs(Speed);
	}
}
void DelayMs(unsigned char ms)
{
	unsigned char data i, j;
	while(ms--)
	{
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}