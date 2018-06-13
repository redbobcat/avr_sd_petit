/*
 * spi.h
 * MASTER only for now
 * 
 * Copyright 2018 username <username@zvorikin>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#ifndef _SPI_H
#define _SPI_H

#include <avr/io.h>
#include <util/delay.h>

//defines for speed, mode and phase
// SPCR register
#define SPI_INTERRUPT_EN 0 //enable interrupt for SPI
#define SPI_MASTER_EN 1 //master mode (0 for slave)
#define SPI_ENABLE_EN 1 //enable it
#define SPI_DATA_ORDER 0 //0 MSB first, 1 LSB first
#define SPI_MODE 0b00 // 0b00 Mode 0, 0b01 Mode 1, 0b10 Mode 2, 0b11 Mode 3
#define SPI_CLOCK_FREQ 0b11 // see table below
#define SPI_CLOCK_DOUBLE 0 //doubles SPI speed
/* clock table for SPI
 * 0b00 F_CPU/4
 * 0b01 F_CPU/16
 * 0b10 F_CPU/64
 * 0b11 F_CPU/128
 * SPI2X doubles SPI speed
 */
 

//define for ports and pins
//all on B port in megas

#define SPI_PORT	PORTB
#define SPI_DDR		DDRB
#define SPI_PIN		PINB

//this for diferent megas
#if defined(__AVR_ATmega8__) || defined(__AVR_ATmega48__) || defined(__AVR_ATmega88__) || \
    defined(__AVR_ATmega16__) || defined(__AVR_ATmega32__) || defined(__AVR_ATmega162__) || defined(__AVR_ATmega168__) 

#define SPI_SCK		7
#define SPI_MOSI	5
#define SPI_MISO	6
//#define SPI_CS		4 //chip select must be implemented in other functions

#elif defined(__AVR_ATmega64__)  || defined(__AVR_ATmega128__) 

#define SPI_SCK		1
#define SPI_MOSI	2
#define SPI_MISO	3
//#define SPI_CS		0 //chip select must be implemented in other functions

#else
//
// unsupported type
//
#error "Sorry, this lib didn't supports your controller."
#endif

void spi_init (void);
uint8_t spi_byte(uint8_t byte);
uint8_t spi_read (void);
void spi_write (uint8_t);


#endif
