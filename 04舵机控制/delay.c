#include <reg52.h>
#include "delay.h"
#include "intrins.h"

//��ʱԼ1ms
void delay_ms(unsigned int ms)               
{
	unsigned int a,b;
	for(a=ms;a>0;a--)
		for(b=114;b>0;b--);
}
