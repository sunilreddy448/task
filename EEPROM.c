#include <LPC21xx.H>
#include"header.h"
void EEPROM_write(char *data,int adders);
void EEPROM_read(char *data,int adders);
//void EEPROM_init(void);
void EEPROM_write(char *data, int adders)
{
int i = 0;
float speed_bit = 0.0;  
int j = 0;
static int k =00;
char arr[100];

for (j = 0; data[j]; j++, k++)
{
arr[k] = data[j];
}



if ((k - 1 - j) != 0)   
{
speed_bit = 1.0 / ((k - 1) - j);  //bit rate calculation
}

i = speed_bit; //assigning to "i"variable
if(i==266)
i=0;
 if(k>=100)
 {
uart0_tx((k/10)+48);
uart0_tx((k%10)+48);
uart0_tx_string("DATA RESIVED......\n\r");
	 uart0_tx_string(arr);// loop back
}
 
}
