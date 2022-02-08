#include "../Headers/IO_Config.h"
#include <avr/io.h>

void io_config(void)
{
	/* IO direction definition - 1 for output*/
	DDRB = 0b00001000;
	DDRC = 0b00101111;
	DDRD = 0b01111110;
	
	/* Input pull-up control - 0 to disable*/
	/* Output value control - pull-up always disabled in this case*/
	PORTB = 0b00110011;
	PORTC = 0b00010000;
	PORTD = 0b00000100;
	
	/* Input value */
	/* Writing a 1 toggle PORTx value (pull-up ctrl if input or output value)*/
	PINB = 0x00;
	PINC = 0x00;
	PIND = 0x00;
	
	/* Global pull-up control on inputs - 1 to disable*/
	MCUCR = 0x00;
}