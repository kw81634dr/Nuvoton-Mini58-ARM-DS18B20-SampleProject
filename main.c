/******************************************************************************
 * @file     DS18B20LibraryforMini58.c
 * @version  V1.00
 * $Revision:
 * $Date: 2017/08/17 00:33
 * @brief    Main code of Single DS18B20
 *					 Temperature Sensor project for Mini58 MCU.
 * @note
 *  				 Default DATA pin was set at P25 (GPIO_PIN_ADDR(2,5))
 * @notice   Use AT YOUR OWN RISK
*****************************************************************************/
#include <stdio.h>
#include "Mini58Series.h"
#include "DS18B20LibraryforMini58.h"



void SYS_Init(void)
{
    /* Unlock protected registers */
    SYS_UnlockReg();

    // Enable UART clock
    CLK_EnableModuleClock(UART0_MODULE);

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock and cyclesPerUs automatically. */
    SystemCoreClockUpdate();

    /* Set P1 multi-function pins for UART RXD, TXD */
    SYS->P1_MFP = SYS_MFP_P12_UART0_RXD | SYS_MFP_P13_UART0_TXD;

    /* Lock protected registers */
    SYS_LockReg();
}

int main()
{
    float myTemperature;

    SYS_Init();
    UART_Open(UART0, 115200);	//P12 for RX0, P13 for TX0
    GPIO_SetMode(P2, BIT5, GPIO_MODE_QUASI);

    while(1)
    {
        myTemperature = read_Temperature();
        printf("Temperature = %.2f\n", myTemperature);
        CLK_SysTickDelay(300000);	//just a simple delay
    }

}

