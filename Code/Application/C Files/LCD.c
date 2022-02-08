#include "../Headers/LCD.h"
#include "../Headers/Globals.h"
#include "../Headers/Defines.h"

#include <util/delay.h>

/*****************************************************
LCD USEFUL INFORMATIONS:

1 Clear display screen
2 Return home
4 Decrement cursor (shift cursor to left)
6 Increment cursor (shift cursor to right)
5 Shift display right
7 Shift display left
8 Display off, cursor off
A Display off, cursor on
C Display on, cursor off
E Display on, cursor on
F Display on, cursor blinking
10 Shift cursor position to left
14 Shift cursor position to right
18 Shift the entire display to the left
1C Shift the entire display to the right
80 Force cursor to beginning to 1st line
C0 Force cursor to beginning to 2nd line
90 Force cursor to beginning to 3rd line
D0 Force cursor to beginning to 4th line
38 2 lines and 5×7 matrix (8-bit mode)
28 2 lines and 5×7 matrix (4-bit mode)
n Next line
t Tab
r enter

*****************************************************/



void lcd_wait(void)
{
	PORTD |= 0b00010000;	// Set RW to 1 to read from LCD
	// Check Ben Eater video for more information
	PORTD &= 0b11101111;	// Set RW back to 0 to write to LCD
}

/*****************************************************
Function:		lcd_init
Receive :		nothing
Send:			nothing
Description:	LCD initialization

!! SHALL BE CALLED ONCE BEFORE USING LCD TO CONFIGURE
IT PROPERLY !!
*****************************************************/

void lcd_init(void)
{
	RS_CLR;
	Data_PORT_CLR;
	
	_delay_ms(5);
	Data_PORT |= 0x20 >> 4;
	EN_SET;
	_delay_ms(5);
	EN_CLR;
	
	lcd_cmd(0x28);       // 4-bit mode - 2 line - 5x7 font.
	lcd_cmd(0x01);       // Clear display
	lcd_cmd(0x0c);       // Display no cursor - no blink.
	lcd_cmd(0x06);       // Automatic Increment - No Display shift.
	lcd_cmd(0x80);       // Address DDRAM with 0 offset 80h.
}

/*****************************************************
Function:		lcd_cmd
Receive :		command to send to LCD
Send:			nothing
Description:	used to send commands to LCD.

SHOULD ONLY BE USED IN LCD.C
*****************************************************/

void lcd_cmd(char cmd)
{
	RS_CLR;
	Data_PORT_CLR;
	//Data_PORT |= (cmd & 0xf0);
	Data_PORT |= (cmd & 0xf0)>>4;
	EN_SET;
	_delay_ms(5);
	EN_CLR;
	Data_PORT_CLR;
	//Data_PORT |= ((cmd<<4) & 0xf0);
	Data_PORT |= ((cmd<<4) & 0xf0)>>4;
	EN_SET;
	_delay_ms(5);
	EN_CLR;
}

/*****************************************************
Function:		lcd_data
Receive :		data to send to LCD
Send:			nothing
Description:	used to send data to LCD in 4bits mode

CAN BE USED OUTSIDE LCD.C TO SEND 8bits DATA TO LCD
*****************************************************/

void lcd_data(char data)
{
	RS_SET;
	Data_PORT_CLR;
	Data_PORT |= (data & 0xf0)>>4;
	EN_SET;
	_delay_ms(5);
	EN_CLR;
	Data_PORT_CLR;
	Data_PORT |= ((data<<4) & 0xf0)>>4;
	EN_SET;
	_delay_ms(5);
	EN_CLR;
}

/*****************************************************
Function:		lcd_clear
Receive :		nothing 
Send:			nothing
Description:	used to clear LCD screen

CAN BE USED OUTSIDE LCD.C TO CLEAR LCD SCREEN
*****************************************************/

void lcd_clear(void)
{
	lcd_cmd(0x01);       // Clear display
}

/*****************************************************
Function:		lcd_Set_Cursor
Receive :		a, position on first LCD line
				b, position on second LCD line
Send:			nothing
Description:	used position cursor on LCD screen

CAN BE USED OUTSIDE LCD.C TO POSITION CURSOR ON SCREEN
*****************************************************/

void lcd_Set_Cursor(char a, char b)
{
	if(a == 1)lcd_cmd(0x80 + b);
	else if(a == 2)lcd_cmd(0xC0 + b);
}

/*****************************************************
Function:		lcd_Write_String
Receive :		a, text on first LCD line
				b, text on second LCD line
Send:			nothing
Description:	used to write text on LCD screen

USED OUTSIDE LCD.C TO POSITION CURSOR ON SCREEN
*****************************************************/

void lcd_Write_String(char *a,char *b)
{
	int i;
	
	lcd_clear();
	
	lcd_Set_Cursor(1,0);
	for(i=0;a[i]!='\0';i++)	lcd_data(a[i]);
	
	lcd_Set_Cursor(2,0);
	for(i=0;b[i]!='\0';i++) lcd_data(b[i]);
}

/*****************************************************
Function:		lcd_Write_Line
Receive :		s, text on LCD line
				b, LCD line select
Send:			nothing
Description:	used to write text on one line of the LCD screen without clearing it
*****************************************************/

void lcd_Write_Line(char *s,char l)
{
	int i;

	lcd_Set_Cursor(l,0);
	for(i=0;s[i]!='\0';i++)	lcd_data(s[i]);
}

/*****************************************************
Function:		lcd_Write
Receive :		s, text on LCD line
Send:			nothing
Description:	used to write text when cursor position is already defined
*****************************************************/

void lcd_Write(char *s)
{
	int i;
	for(i=0;s[i]!='\0';i++)	lcd_data(s[i]);
}

/*****************************************************
Function:		lcd_digit
Receive :		d, digit to send
Send:			nothing
Description:	used to write a digit on the LCD
*****************************************************/

void lcd_digit(char d)
{
	lcd_data(d + 48);
}