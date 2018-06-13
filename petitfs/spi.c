/*
 * spi.c
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

#include "spi.h"

void spi_init (void)
{
	//config control register
	SPCR = (SPI_INTERRUPT_EN << SPIE) | (SPI_ENABLE_EN << SPE) | \
	(SPI_DATA_ORDER << DORD) | (SPI_MASTER_EN << MSTR) | \
	(SPI_MODE << CPHA) | (SPI_CLOCK_FREQ);
	SPSR |= (SPI_CLOCK_DOUBLE);
	//set DDR for MOSI and SCK
	SPI_DDR |= (1 << SPI_MOSI) | (1 << SPI_SCK);
	
	
}

uint8_t spi_byte(uint8_t byte)
{
	SPDR = byte;
	while(!(SPSR & (1<<SPIF)))
	{}
	return SPDR;
}

uint8_t spi_read (void)
{
	return spi_byte (0xFF);
}

void spi_write (uint8_t byte)
{
	spi_byte(byte);
}
