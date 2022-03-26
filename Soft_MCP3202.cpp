/**
 * @file Soft_MCP3202.cpp
 * @author Davide Scalisi
 * @brief 
 * @version 1.0
 * @date 2022-03-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Soft_MCP3202.h>

Soft_MCP3202::Soft_MCP3202(uint8_t MOSI, uint8_t MISO, uint8_t SCK, uint8_t CS){
	this->CS = CS;
	this->link = new SoftSPI(MOSI, MISO, SCK);

	pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);

	link->begin();

	/*
		From the datasheet:
			Supply voltage:			2.7V		5V
			Max. clock freq.:		0.9MHz	1.8MHz
		
		Let's use 1MHz, so that both at 5V and 3.3V there will be no communication errors.
	*/
	link->setClockDivider(SPI_CLOCK_DIV2);
	link->setBitOrder(MSBFIRST);
	link->setDataMode(SPI_MODE0);
}

Soft_MCP3202::~Soft_MCP3202(){
	link->end();

	delete link;
}

uint16_t Soft_MCP3202::read(uint8_t ch){
	/*
		MCU PIN:
		Dout	X X X X X X X A			B C D X X X   X   X  X			X  X  X  X  X  X  X  X
		Din		X X X X X X X X			X X X X 0 B11 B10 B9 B8			B7 B6 B5 B4 B3 B2 B1 B0
		A:	Start bit.
		B:	1: Single mode, 0: Differential mode.
		C:
			Single mode.:
				0:	Read from CH0.
				1:	Read from CH1.

			Differential mode:
				0: CH0: IN+, CH1: IN-.
				1: CH0: IN-, CH1: IN+.
		D:	1: MSB First, 0: LSB First (for the LSB, please refer to the datasheet).
	*/

  uint8_t msb, lsb, command = B10100000;

  if(ch == 1)
		command = B11100000;
	
	digitalWrite(CS, LOW);

		link->transfer(1);		//Start bit.
		msb = link->transfer(command) & 0x0F;
		lsb = link->transfer(0);

	digitalWrite(CS, HIGH);

  return ((int16_t) msb) << 8 | lsb;
}
