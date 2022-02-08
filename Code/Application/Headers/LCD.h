#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>

#define RS_SET              PORTD |= 0b00001000
#define RS_CLR              PORTD &= 0b11110111
#define EN_SET              PORTD |= 0b00100000
#define EN_CLR              PORTD &= 0b11011111
#define Data_PORT_CLR       PORTC &= 0b11110000
#define Data_PORT           PORTC

extern void lcd_wait(void);

extern void lcd_init(void);

extern void lcd_cmd(char);

extern void lcd_data(char);

extern void lcd_clear(void);

extern void lcd_Set_Cursor(char, char);

extern void lcd_Write_String(char *,char *);

extern void lcd_Write_Line(char *,char);

extern void lcd_Write(char *);

extern void lcd_digit(char);

extern void lcd_number(int);

#endif /* LCD_H_ */