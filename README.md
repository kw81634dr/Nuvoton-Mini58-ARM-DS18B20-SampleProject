# DS18B20 Temperature Sensor project for Nuvoton Mini58
![alt tag](https://user-images.githubusercontent.com/26266974/29377308-0c334206-82ee-11e7-945a-6c186315cb9c.jpeg)
  
This is a Library for 1-Wire DS18B20 Temperature Sensor setup on Nuvoton Mini58 (ARM Cortex-M0) MCU.  
version 1.0 - This code will work when you setup only one DS18B20 Sensor on your 1-Wire bus.  
You'll need other official library provide by Novoton on their website(1)    


# In this repository
In this repository, you will got  
1. one Main code named "main.c"
2. one C library code file named "DS18B20LibraryforMini58.c"  
3. one Header file for c library named "DS18B20LibraryforMini58.h"  


# Setup

1. Include .c & .h file in your project or create a project with these 3 things. 
2. If it's possible, get a USB to TTL module for UART debugging. 
3. UART0 was chooesn as default,P12 for RX0,P13 for TX0,set your wire and Serial terminal(2) up.   
(Baudrate:115200, Data Bits:8, Parity:None, Stop Bits:1, Flow Control:None). 
![alt tag](https://user-images.githubusercontent.com/26266974/29377247-d3585a48-82ed-11e7-8647-46d2fee6821b.png)
   
4. Set DS18B20 VCC,DATA and GND wire up, follow the DataSheet(3),DATA PIN was P25 as default.   
  PIN definition was defined in Header file.       
![alt tag](https://user-images.githubusercontent.com/26266974/29377061-24bc80b8-82ed-11e7-9fef-38ba9c08a1a3.jpg)

5. Download your project code to MCU and Run then look at terminal window.   

# Outcome
You will GET REAL Temperature in Celsius Degrees for about every 0.3 sceonds.  

![alt tag](https://user-images.githubusercontent.com/26266974/29394670-6a50c1e2-833e-11e7-8dbb-be15804a5c09.PNG)    

# # USE AT YOUR OWN RISK # #

# Reference
(1)OfficialLibrary http://www.nuvoton.com/opencms/resource-download.jsp?tp_GUID=SW0120150612160851   
![alt tag](https://user-images.githubusercontent.com/26266974/29394558-b88bf17a-833d-11e7-8eb3-a757f11ed60d.png)      
(2)e.g. AccessPort,RealTerm(Windows), CoolTerm(Windows/Mac/Linux)   
(3)DataSheethttps://datasheets.maximintegrated.com/en/ds/DS18B20.pdf   

// Maxim Integrated and the Maxim Integrated logo are trademarks of Maxim Integrated Products, Inc.  
// Nuvoton® is a registered trademark of Nuvoton Technology Corporation  
/*
AMBA, Arm, Arm7, Arm7TDMI, Arm9, Arm11, Artisan, big.LITTLE, Cordio, CoreLink, CoreSight, Cortex, DesignStart, DynamIQ, Jazelle, Keil, Mali, Mbed, Mbed Enabled, NEON, POP, RealView, SecurCore, Socrates, Thumb, TrustZone, ULINK, ULINK2, ULINK-ME, ULINK-PLUS, ULINKpro, µVision, Versatile are trademarks or registered trademarks of Arm Limited (or its subsidiaries) in the US and/or elsewhere. The related technology may be protected by any or all of patents, copyrights, designs and trade secrets. All rights reserved.

All other brands or product names are the property of their respective holders.

Copyright © 1995-2017 Arm Limited (or its affiliates).
*/

# MIT License
Copyright (C) <2017> <KEVIN-WANG>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
