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
		ָʾ�ƣ�
			1.������ڹ�����D1��D2������˸��
			2.���ſ���λ��D2������
			3.���Źص�λ��D1
	������
			4.������D1~D8Ϩ��
		������
			1.K1:�����ͨ�磻
			2.RSTK1:��������������ݹ�����ʹ��λ�����ɿ���
	*/
	
	P2=0xFF;
	P1_0=0;
	while(1)
	{
		if(P3_1==0)//K1 �����ͨ��
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			while(1)
			{
				if(P3_7==0)//�ص�λ
				{
					P1_0=0;
					P2=0xFE;
					break;
				}
				if(P3_6==0)//����λ
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