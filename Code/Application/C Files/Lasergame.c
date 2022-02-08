/*
 * Lasergame.c
 *
 * Created: 21-05-21 18:41:54
 *  Author: Gilles
 */ 

#include "../Headers/Defines.h"
#include "../Headers/Globals.h"
#include "../Headers/LCD.h"
#include "../../Drivers/Headers/UART_Config.h"

#include <util/delay.h>

/*
	RF data memento:
	----------------
	x being the ID of the unit
	y being the ID of another unit
	
	- Sx : "I am shooting"
	- Hx : "I am hit"
	- By : "I was shot by y"
	- Ey  : Endgame, y won
	- #  : Terminating character
*/

void pistol_hit(void)
{
	if (INCOMING_IR)
	{
		_delay_ms(5);
		if (INCOMING_IR)	// IR signal must be maintained for 5ms to avoid false detections due to ambient light
		{
			lcd_Write_Line("#   Ouille !   #",1);
			
			uart_send('H');
			uart_send(UNIT_ID);
			uart_send('B');
			uart_send(rx_string[1]);	// The ID of the other unit
			uart_send('#');
			
			_delay_ms(2000);	// 2 seconds of immunity when hit
			lcd_Write_Line("#              #",1);
		}
	}
}

void pistol_shoot(void)
{
	char i = 0;
	
	IR_ON;
	//for (i=0;i<3;i++)	// Sends message 3 times to ensure proper transmission (keep?)
	//{
		uart_send('S');
		uart_send(UNIT_ID);
		uart_send('#');
		
		_delay_ms(5);
	//}
	_delay_ms(20);
	IR_OFF;
	
	_delay_ms(1000);	// Automatic shot, max 1/second
}

void pistol_endgame(void)
{
	uart_send('E');
	uart_send(UNIT_ID);
	uart_send('#');
	game_on = 0;
}