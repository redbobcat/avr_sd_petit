/*
 * HD44780 TEST
 *
 *  Created on: 08.09.2011
 *      Author: red_bobcat
 */
#define set_bit(reg,bit) { reg |= 1 << bit; }
#define unset_bit(reg,bit) { reg &= ~(1 << bit);}

#include <avr/io.h>
//#include <avr/interrupt.h>
#include <util/delay.h>
#include "HD44780/hd44780.h"
#include <stdlib.h>

#include "petitfs/pff.h"

void main(void)
{
	lcd_init();
	lcd_clrscr();
	lcd_puts("  Hello");
	lcd_goto(0x40);
	lcd_puts("SD_test");
	_delay_ms(1000);
	
	FATFS fs;
	DDRD |= 1;
	lcd_clrscr();
	lcd_goto(0x00);
	if (pf_mount(&fs) == FR_OK)
		{
			lcd_puts("Mount OK");
		}
		else {lcd_puts("Mount NO");}
		
	_delay_ms(2000);
	
	lcd_goto(0x40);
	if (pf_open("WR.TXT") == FR_OK)
		{
			lcd_puts("Open OK");
		}
		else {lcd_puts("Open NO");}
	_delay_ms(2000);
		
	uint16_t num=100, bw;
	uint8_t n, buf[4];
	for (n=0; n<100; n++)
		{
			utoa(num, buf, 10);
			if (pf_write(buf, 4, &bw) == FR_OK)
				{
					lcd_clrscr();
					lcd_goto(0x00);
					lcd_puts("Write OK");
					buf[0] = ',';
					pf_write(buf, 1, &bw);
				}
			num++;
		}
	pf_write(0,0,&bw);
	lcd_goto(0x40);
	lcd_puts("DONE");
	
	
	
	_delay_ms(2000);
	
	for(;;)
	{
		_delay_ms(1000);
	}

}
