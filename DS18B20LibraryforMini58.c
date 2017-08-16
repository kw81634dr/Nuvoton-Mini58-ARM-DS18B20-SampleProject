/******************************************************************************
 * @file     DS18B20LibraryforMini58.c
 * @version  V1.00
 * $Revision:
 * $Date:    2017/08/17 00:33
 * @brief    C Library code of Single DS18B20
 *			 Temperature Sensor project for Mini58 MCU.
 * @note
 *  		 Default DATA pin was set at P25 (GPIO_PIN_ADDR(2,5))
 * @notice   Use AT YOUR OWN RISK
*****************************************************************************/
#include <stdio.h>
#include "Mini58Series.h"
#include "DS18B20LibraryforMini58.h"

unsigned char init_DS18B20(void)
{
    unsigned int ret = 1;

    GPIO_PIN_ADDR(PINPORT, PORTBIT) = 1;
    GPIO_PIN_ADDR(PINPORT, PORTBIT) = 0;

    CLK_SysTickDelay(480); //us
    GPIO_PIN_ADDR(PINPORT, PORTBIT) = 1;	//release bus
    ret = GPIO_PIN_ADDR(PINPORT, PORTBIT);
    CLK_SysTickDelay(400); //us

    /*Uncomment next line for debug information*/
    //printf("Init called, ret = %d\n",ret);

    return ret;
}

void wirteByteToDS18B20(uint8_t data)
{
    unsigned char i = 0;
    for (i = 0; i < 8; i++)
    {
        GPIO_PIN_ADDR(PINPORT, PORTBIT) = 1;
        CLK_SysTickDelay(2);	//short delay for changeing state
        GPIO_PIN_ADDR(PINPORT, PORTBIT) = 0;
        CLK_SysTickDelay(2); //short delay for changeing state
        if (data & 0x01)
        {
            GPIO_PIN_ADDR(PINPORT, PORTBIT) = 1;	//set high voltage level
        }
        else
        {
            GPIO_PIN_ADDR(PINPORT, PORTBIT) = 0;
        }
        CLK_SysTickDelay(50); //delay for wirting bit (voltage level) to DS18B20
        GPIO_PIN_ADDR(PINPORT, PORTBIT) = 1;	//release bus
        CLK_SysTickDelay(45); //delay for release bus
        data >>= 1;

    }
    CLK_SysTickDelay(10); //us
}

unsigned char readByteFromDS18B20(void)
{
    unsigned char i;
    unsigned char data = 0x0;
    for (i = 0; i < 8; i++)
    {
        GPIO_PIN_ADDR(PINPORT, PORTBIT) = 1;
        CLK_SysTickDelay(2); //short delay for changeing state
        GPIO_PIN_ADDR(PINPORT, PORTBIT) = 0;
        CLK_SysTickDelay(2); //short delay for changeing state

        GPIO_PIN_ADDR(PINPORT, PORTBIT) = 1;	//release bus
        data >>= 1 ;
        if (GPIO_PIN_ADDR(PINPORT, PORTBIT))	//if get high voltage level
        {
            /*Uncomment next line for debug information*/
            //printf("GPIO_PIN_ADDR(PINPORT,PORTBIT) = %d\n",GPIO_PIN_ADDR(PINPORT,PORTBIT));
            data |= 0x80;	//save Raw Data from High bit
        }
        GPIO_PIN_ADDR(PINPORT, PORTBIT) = 1;	//release bus
        CLK_SysTickDelay(70);
    }
    return data;
}


float read_Temperature()
{
    int n;
    float output;
    uint8_t rawDataFromDS18B20Arr[9] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

    init_DS18B20();
    wirteByteToDS18B20(0xCC); //command for Jump over ROM for single (only one) DS18B20 working mode
    wirteByteToDS18B20(0x44);	//command for start conversion enviroment Temperature and save in 9Byte RAM in DS18B20
    CLK_SysTickDelay(780);	//wait conversion done

    init_DS18B20();
    wirteByteToDS18B20(0xCC);	//command for Jump over ROM for single (only one) DS18B20 working mode
    wirteByteToDS18B20(0xBE);	//command for read Temperature Raw Data from DS18B20

    /*get 9Byte Raw Data*/
    for( n = 0; n < 9; n++)
    {
        /*get a Byte from RAM in DS18B20*/
        rawDataFromDS18B20Arr[n] = readByteFromDS18B20();
    }

    /*send Raw Data to conversion function and convet to real Celsius degree*/
    output = convertTempData(rawDataFromDS18B20Arr[0], rawDataFromDS18B20Arr[1]);
    return output;
}

float convertTempData(uint8_t tempLS, uint8_t tempMS)
{
    uint16_t rawDataMerge;
    uint16_t reverseRawDataMerge;
    float fianlTemperature;

    /* Judge Positive(+) or Negative(-) Temperature */
    if (tempMS & 0xF8)
    {
        //Negative
        rawDataMerge = tempMS;
        rawDataMerge <<= 8;
        rawDataMerge += tempLS;
        reverseRawDataMerge = ~rawDataMerge;
        fianlTemperature = -(reverseRawDataMerge + 1) * 0.0625;
    }
    else
    {
        //Positive
        rawDataMerge = tempMS;
        rawDataMerge <<= 8;
        rawDataMerge += tempLS;
        fianlTemperature = rawDataMerge * 0.0625;
    }
    return fianlTemperature;
}

