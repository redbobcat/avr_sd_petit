/*
 * HD44780 TEST
 *
 *  Created on: 08.09.2011
 *      Author: red_bobcat
 */
#define set_bit(reg,bit) { reg |= 1 << bit; }
#define unset_bit(reg,bit) { reg &= ~(1 << bit);}
#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "hd44780.h"

void main(void)
{
	unsigned char i;

	lcd_init();
	lcd_clrscr();
	lcd_puts("  Hello");
	lcd_goto(0x40);
	lcd_puts("Easy Electronics");
	_delay_ms(1000);
	for(;;)
{
	for (i=1;i<11;i++)
	{
	_delay_ms(500);
	lcd_command(_BV(LCD_MOVE) | _BV(LCD_MOVE_DISP));
	}
	lcd_command(_BV(LCD_DISPLAYMODE));
	for (i=1;i<11;i++)
	{
	lcd_command(_BV(LCD_MOVE) | _BV(LCD_MOVE_DISP) | _BV(LCD_MOVE_RIGHT));
	}
	lcd_command(_BV(LCD_DISPLAYMODE) | _BV(LCD_DISPLAYMODE_ON));
}
}
