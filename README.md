# DS18B20 temperature for Nuvoton Mini58 MCU
![alt tag](https://user-images.githubusercontent.com/26266974/29377308-0c334206-82ee-11e7-945a-6c186315cb9c.jpeg)

This is a Library for 1-Wire DA18B20 Temperature Sensor setup on Nuvoton Mini58 (ARM Cortex-M0) MCU.
this code will work when you setup only one DS18B20 Sensor on your 1-Wire bus.


# In this repository
In this repository, you will got
1. one Main code named "main.c"
2. one c library code file named "DS18B20LibraryforMini58.c"
3. one Header file for c library named "DS18B20LibraryforMini58.h"


# Setup

1. Put these three things into your project
2. If it's possible, get a USB to TTL module for UART debugging
3. UART0 was chooesn as default,P12 for RX0,P13 for TX0,set your wire and Serial terminal(1) up
![alt tag](https://user-images.githubusercontent.com/26266974/29377247-d3585a48-82ed-11e7-8647-46d2fee6821b.png)
   (Baudrate:115200, Data Bits:8, Parity:None, Stop Bits:1, Floe Control:None)
4. Set DS18B20 VCC,DATA and GND wire up, follow the DATASHEET(2),DATA PIN was P25 on MCU as default
![alt tag](https://user-images.githubusercontent.com/26266974/29377061-24bc80b8-82ed-11e7-9fef-38ba9c08a1a3.jpg)
5. Download your project code to MCU and Run then look at terminal window

# Outcome
You will GET REAL Temperature in Celsius Degree about EVERY 0.3 sce
![alt tag](https://user-images.githubusercontent.com/26266974/29377028-107733dc-82ed-11e7-9048-65d22ece3b82.PNG)
![alt tag](https://user-images.githubusercontent.com/26266974/29377031-1158d080-82ed-11e7-8c37-bab78bb77bb0.PNG)

# USE AT YOUR OWN RISK

# Reference
(1)e.g. RealTerm(Windows), CoolTerm(Windows/Mac/Linux)
(2)https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf

Maxim Integrated and the Maxim Integrated logo are trademarks of Maxim Integrated Products, Inc.
Nuvoton® is a registered trademark of Nuvoton Technology Corporation
# MIT License
Copyright (C) <2017> <KEVIN-WANG>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
