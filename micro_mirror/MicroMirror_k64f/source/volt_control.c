/*
 * volt_control.c
 *
 *  Created on: Jun 8, 2018
 *      Author: ronf
 */
#include "board.h"
#include "fsl_dac.h"
#include "fsl_adc16.h"
#include "fsl_debug_console.h"  // PRINTF is in here

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_DAC_BASEADDR DAC0
#define DEMO_ADC16_BASEADDR ADC0
#define DEMO_ADC16_CHANNEL_GROUP 0U
#define DEMO_ADC16_USER_CHANNEL 12U /* PTB2, ADC0_SE12 */
#define DEMO_ADC16_IRQn ADC0_IRQn
#define DEMO_ADC16_IRQ_HANDLER_FUNC ADC0_IRQHandler
#define VREF_BRD 3.300
#define SE_12BIT 4096.0

/* variables */
extern volatile uint32_t systime; //systime updated very 100 us = 4 days ==> NEED OVERFLOW protection
volatile bool g_Adc16ConversionDoneFlag = false;
volatile uint32_t g_Adc16ConversionValue = 0;
extern adc16_channel_config_t g_adc16ChannelConfigStruct;


float voltRead;

/* interrupt routine */

void DEMO_ADC16_IRQ_HANDLER_FUNC(void)
{
    g_Adc16ConversionDoneFlag = true;
    /* Read conversion result to clear the conversion completed flag. */
    g_Adc16ConversionValue = ADC16_GetChannelConversionValue(DEMO_ADC16_BASEADDR, DEMO_ADC16_CHANNEL_GROUP);
    /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
      exception return operation might vector to incorrect interrupt */
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}

/* do control here in main PIT loop.
 * 1) read voltage level
 * 2) set DAC to needed value to get desired output, e.g. 1000 V
 */
void volt_control()
{
	LED_GREEN_TOGGLE();

	DAC_SetBufferValue(DEMO_DAC_BASEADDR, 0U, (unsigned int) ((systime & 0xffff)>>4));  // 12 bit DAC

	/*if ( (unsigned int)(systime & 0xffff) == 0x0000)
	{
		g_Adc16ConversionDoneFlag = false;
		ADC16_SetChannelConfig(DEMO_ADC16_BASEADDR, DEMO_ADC16_CHANNEL_GROUP, &g_adc16ChannelConfigStruct);

		while (!g_Adc16ConversionDoneFlag) {}  // wait for A/D ready- maybe add timeout?

		PRINTF("\r\n\r\nADC Value: %d\r\n", g_Adc16ConversionValue);
		 Convert ADC value to a voltage based on 3.3V VREFH on board
		voltRead = (float)(g_Adc16ConversionValue * (VREF_BRD / SE_12BIT));
		PRINTF("\r\nADC Voltage: %0.3f\r\n", voltRead);

	}*/
}
