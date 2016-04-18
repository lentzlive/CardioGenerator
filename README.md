# CardioGenerator

<br>
Tratto dal seguente link: https://learn.adafruit.com/mcp4725-12-bit-dac-tutorial/wiring

<br><br>
FIrst, connect VDD (power) to a 3-5V power supply, and GND to ground.
<br><br>
The DAC uses I2C, a two-pin interface that can have up to 127 unique sensors attached (each must have a different ADDRESS). 
<br><br>
- SDA to I2C Data (on the Uno, this is A4 on the Mega it is 20 and on the Leonardo digital 2)
<br>
- SCL  to I2C Clock(on the Uno, this is A5 on the Mega it is 21 and on the Leonardo digital 3)
<br><br>
There's two other pins remaining.
<br><br>
- A0 allow you to change the I2C address. By default (nothing attached to A0) the address is hex 0x62. If A0 is connected to VDD the address is 0x63. This lets you have two DAC boards connected to the same SDA/SCL I2C bus pins.
<br>
- VOUT is the voltage out from the DAC! The voltage will range from 0V (when the DAC value is 0) to VDD (when the DAC 'value' is the max 12-bit number: 0xFFF)
<br><br>
<h1>Schema</h1>
<img width="400" src="https://github.com/lentzlive/CardioGenerator/blob/master/MCP4725_Arduino_bb.png" />
