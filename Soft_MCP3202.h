/**
 * @file Soft_MCP3202.h
 * @author Davide Scalisi
 * @brief 
 * @version 1.0
 * @date 2022-03-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SOFT_MCP3202_H
#define SOFT_MCP3202_H

#include <Arduino.h>
#include <SoftSPI.h>

class Soft_MCP3202{
	private:
		uint8_t CS;			//Chip select.
		SoftSPI *link;	//SPI interface wired to the ADC.

	public:
		Soft_MCP3202(uint8_t MOSI, uint8_t MISO, uint8_t SCK, uint8_t CS);
		~Soft_MCP3202();

		//ch:	Channel (0, 1).
		uint16_t read(uint8_t ch = 0);
};

#endif
