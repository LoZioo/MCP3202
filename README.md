# MCP3202
Cross-platform Arduino library for controlling the `MCP3202` SPI ADC!

`SoftSPI` library provided by [MajenkoLibraries](https://github.com/MajenkoLibraries/SoftSPI "MajenkoLibraries").

## How to use
Simply attach you MCP3202 to the 4-Wire SPI interface of your MCU and use the `adc.read(int channel)` method to read the 12 bit value from the selected channel like that:

```cpp
#include <Arduino.h>
#include <MCP3202.h>

MCP3202 adc(D8);

void setup(){
	Serial.begin(115200);
}

void loop() {
	Serial.printf("CH0: %d, CH1: %d\n", adc.read(0), adc.read(1));
	delay(1000);
}
```
