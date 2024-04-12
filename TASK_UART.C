#include <LPC21xx.H>
#include"header.h"

void uart0_init(unsigned int b_rate)
{
int a[]={15,30,60,15,15};
unsigned int pclk=a[VPBDIV]*1000000;
unsigned int RESULT=0;
RESULT=(pclk/(16*b_rate));
PINSEL0|=0X05;
U0LCR=0X83;
U0DLL=RESULT&0XFF;
U0DLM=(RESULT>>8)&0XFF;
U0LCR=0X03;
}
#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data)
{
U0THR=data;
while(THRE==0);
}
void uart0_tx_string(char*ptr)
{

	while(*ptr)
{
U0THR=*ptr;
while(THRE==0);
ptr++;
}

}
#define RDR (U0LSR&1)
unsigned char uart0_rx(void)
{
while(RDR==0);
return U0RBR;
}
void uart0_rx_string(char *ptr ,signed int max_byte)
{
signed int i;
int count1=0;
static int x;	
	for(i=0;i< max_byte-1;i++)
{
//	if(x==1000)
//	{
//		uart0_tx_string("data resived");
//		 flag=0;
//	}
while(RDR==0);
ptr[i]=U0RBR;
if(ptr[i]==' '||ptr[i]=='\r')
break;
count1++;
x++;
}
ptr[i++]=' ';
count1++;
x++;

ptr[i]='\0';
}
