// _nop_()��ʱһ����������
#include <reg52.h>
#include <intrins.h>
sbit PWM = P0^0;  //�趨PWM�����I/O�˿�
unsigned char count = 0;
unsigned char timer1 ;
/*
����180����
t = 0.5ms������������-�����ת�� 0 �� 
t = 1.0ms������������-�����ת�� 45��
t = 1.5ms������������-�����ת�� 90��
t = 2.0ms������������-�����ת�� 135��
t = 2.5ms������������-�����ת��180
*/
 
 
 
/*��ʱ����*/
void delay1s(void)   //��� 0us
{
    unsigned char a,b,c;
    for(c=167;c>0;c--)
        for(b=171;b>0;b--)
            for(a=16;a>0;a--);
    _nop_();  //if Keil,require use intrins.h
}
 
/*��ʱ��T0��ʼ��*/
void Timer0_Init()           
{
    TMOD &= 0x00;
    TMOD |= 0x01; //��ʱ��T0���óɷ�ʽ1
 
    TH0 = 0xff;   //��ʱ���� 0.1ms ����Ϊ11.0592MHz
    TL0 = 0xa4;
 
    ET0 = 1;      
    TR0 = 1; 
	EA=1; 
	}
	
/*T0�жϳ�ʼ��*/
void Time0_Init() interrupt 1 
{
	TR0 = 0; 
	TH0 = 0xff; // 0.1ms
	TL0 = 0xa4;
	
	if(count <= timer1) //5==0�� 15==90��
	{ 
		PWM = 1; 
	}
	else 
	{ 
		PWM = 0; 
	}
	count++;
	if (count >= 200) //T = 20ms����
	{ 
		count = 0; 
	}
	TR0 = 1; //����T0
}
void main()
{
	Timer0_Init();
	while(1)
	{
		
		timer1 =5;//����ָ���0���λ��
		count=0;//�ö�ʱ�����¼���
		delay1s();
		timer1 =10;
		count=0;
		delay1s();
	}
}
