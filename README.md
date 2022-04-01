# MCP3202
Cross-platform Arduino library for controlling the `MCP3202` SPI ADC!

`SoftSPI` library provided by [MajenkoLibraries](https://github.com/MajenkoLibraries/SoftSPI "MajenkoLibraries").

## How to use
-	Attach you MCP3202 to the 4-Wire SPI interface of your MCU.
-	Create a new instance of `MCP3202` object and pass the choosed chip select pin to the constructor.
-	Use the `adc.read(int channel)` method to read the 12 bit value from the selected channel (0 or 1).

## Example of code

Here is an example of reading from both channels and with the chip select on the D8 pin:

```cpp
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
```
