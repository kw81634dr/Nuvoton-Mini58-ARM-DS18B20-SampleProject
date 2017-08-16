/******************************************************************************
 * @file     DS18B20LibraryforMini58.h
 * @version  V1.00
 * $Revision:
 * $Date: 2017/08/17 00:33
 * @brief    Header file of Single DS18B20
 *					 Temperature Sensor project for Mini58 MCU.
 * @note
 *  				 Default DATA pin was set at P25 (GPIO_PIN_ADDR(2,5))
 * @notice   Use AT YOUR OWN RISK
*****************************************************************************/

#define PINPORT 2
#define PORTBIT 5

#include <stdio.h>

//return '1' if initial DS18B20 successfully
unsigned char init_DS18B20(void);

//write a Byte as logic level to DS18B20
void wirteByteToDS18B20(uint8_t data);

//get logic level as Raw data from DS18B20
unsigned char readByteFromDS18B20(void);

//return Temperature in float format
float read_Temperature(void);

//convert Raw data to Real Temperature and return in float format(Celsius degree)
float convertTempData(uint8_t temp1, uint8_t temp2);

