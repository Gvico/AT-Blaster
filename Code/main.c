#include "Drivers/Headers/IO_Config.h"
//#include "Drivers/Headers/ExtInt_Config.h"
#include "Drivers/Headers/UART_Config.h"
//#include "Drivers/Headers/Timer_Config.h"

#include "Application/Headers/Globals.h"
#include "Application/Headers/Defines.h"
#include "Application/Headers/LCD.h"
#include "Application/Headers/HC-12.h"
#include "Application/Headers/Lasergame.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdlib.h>

/*****************************************************
Function:		main
Receive :		nothing 
Send:			nothing
Description:	Main program function

PROGRAM ALWAYS STARTS BY THIS FUNCTION
*****************************************************/

int main(void)
{
	io_config();
	lcd_init();
	uart_config();
	
	sei();
	
	lcd_Write_String("#  AT-BLASTER  #","# HW1.0  SW1.0 #");
	_delay_ms(2000);
	if (TRIGGER_PULLED)
		HC12_init();	// Only initializes the HC-12 when the trigger is pulled on boot
	lcd_clear();

	lcd_Write_Line("# Score :      #",2);
	while (game_on)
	{
		if (rx_string[0] == 'S')
			pistol_hit();
		else if (rx_string[0] == 'H' && rx_string[3] == UNIT_ID)
		{
			points_i += 50;
			lcd_Set_Cursor(2, 10);
			lcd_Write(itoa(points_i,points_a,10));
		}
		else if (rx_string[0] == 'E')	// Endgame if someone reaches 1000 points (20 successful shots)
			game_on = 0;
		rx_string[0] = 0;
		
		if (TRIGGER_PULLED)
		{
			pistol_shoot();
		}
		
		if (points_i == 1000)
			pistol_endgame();
	}
	
	while (1)
	{
		if (points_i == 1000)
			lcd_Write_Line("#  Victoire !  #", 1);
		else
			lcd_Write_Line("#  Game Over   #", 1);

		_delay_ms(1000);
		lcd_Write_Line("#              #", 1);
		_delay_ms(500);
	}
}