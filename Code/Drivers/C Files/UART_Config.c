/*
 * UART_Config.c
 *
 * Created: 17-03-20 14:59:21
 *  Author: Caro et Fred
 */

#include <avr/io.h>

void uart_config(void)
{
	UCSR0A = 0x00;				//single speed - multiprocessor off
	UCSR0B = 0b10011000;		//RX int ON - TX int OFF - RX enable - TX enable
	UCSR0C = 0b00000110;		//Asynchronous - No Parity - 8 Data bits - 1 Stop bit
	
	UBRR0 = 103;				//9600bps
}

char uart_receive(void)
{
	while (!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

void uart_send(char data)
{
	while (!(UCSR0A & (1<<UDRE0)));
	
	UDR0 = data;
}

void uart_send_string(char *data)
{
	while (*data)
		uart_send(*data++);
}