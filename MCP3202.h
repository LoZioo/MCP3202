/**
 * @file MCP3202.h
 * @author Davide Scalisi
 * @brief 
 * @version 1.0
 * @date 2022-03-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MCP3202_H
#define MCP3202_H

#include <Arduino.h>
#include <SPI.h>

class MCP3202{
	private:
		uint8_t CS;			//Chip select.
		SPIClass link;	//SPI interface wired to the ADC.

	public:
		MCP3202(uint8_t CS, SPIClass mySPI = SPI);

		//ch:	Channel (0, 1).
		uint16_t read(uint8_t ch = 0);
};

#endif
