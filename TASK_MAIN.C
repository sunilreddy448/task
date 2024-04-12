#include <LPC21xx.H>
#include"header.h"
int main()
{ 
extern int y; 
	char arr[300];
	 int flag;
	flag=1;
	
	 
uart0_init(2400);
 
	while(flag)
	{ 	
		uart0_rx_string(arr,268);
		EEPROM_write(arr,0);
	
	 		
	}
}

