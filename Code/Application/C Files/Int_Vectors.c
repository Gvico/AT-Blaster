/*****************************************************
!!!! BEFORE USING INTERRUPTS!!!!
-	Add " #include <avr/interrupt.h> " to main page
-	Add "sei()" instruction before main "while(1)"
	loop to globally allow interrupts
*****************************************************/

#include "../Headers/Globals.h"
#include "../Headers/Defines.h"
#include "../../Drivers/Headers/UART_Config.h"

#include <avr/interrupt.h>
#include <avr/io.h>

/*****************************************************
Function:		ISR INT0, INT1, PCINT0, PCINT1, ...
Receive :		nothing
Send:			nothing
Description:	Interrupt vectors for External Interrupts
*****************************************************/

ISR(USART_RX_vect)
{
	rx_string[rx_i] = UDR0;
	
	if (rx_string[rx_i] == '#')	// RF commands must end with '#'
		rx_i = 0;
	else
		rx_i++;
}