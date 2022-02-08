/*
 * HC_12.c
 *
 * Created: 03-05-21 08:27:29
 *  Author: Gilles
 */ 

#include "../Headers/Defines.h"
#include "../../Drivers/Headers/UART_Config.h"

#include <avr/io.h>
#include <util/delay.h>

/*
Initial configuration of the HC-12.
Does not have to be called at each boot: settings are stored in an EEPROM inside the HC-12 unit.
*/
void	HC12_init(void)
{
	PORTD &= 0b11111011;	// HC-12 SET to 0 (config mode)
	
	_delay_ms(50);
	uart_send_string("AT+DEFAULT\r\n");	// Settings to default
	_delay_ms(50);
	uart_send_string("AT+C012\r\n");	// Setting channel to 12
	_delay_ms(50);
	
	PORTD |= 0b00000100;	// HC-12 SET to 1 (transmitting mode)
	_delay_ms(50);
}