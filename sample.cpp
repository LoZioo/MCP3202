#include <Arduino.h>
#include <MCP3202.h>

#define ACD_CHIP_SELECT D8

MCP3202 adc(ACD_CHIP_SELECT);

void setup(){
	Serial.begin(115200);
}

void loop() {
	Serial.printf("CH0: %d, CH1: %d\n", adc.read(0), adc.read(1));
	delay(1000);
}
