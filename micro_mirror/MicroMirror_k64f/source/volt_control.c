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
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_DAC_BASEADDR DAC0
#define DEMO_ADC16_BASEADDR ADC0
#define DEMO_ADC16_CHANNEL_GROUP 0U
#define DEMO_ADC16_USER_CHANNEL 12U /* PTB2, ADC0_SE12 */
#define VREF_BRD 3.300
#define SE_12BIT 4096.0
#define MAX_LOG_LENGTH 64

/* variables */
extern volatile uint32_t systime; //systime updated very 100 us = 4 days ==> NEED OVERFLOW protection
extern adc16_channel_config_t g_adc16ChannelConfigStruct;
float voltRead;

/* globals */
volatile bool g_Adc16ConversionDoneFlag = false;
volatile uint32_t g_Adc16ConversionValue = 0;
/* Logger queue handle */
extern QueueHandle_t log_queue;


/* prototypes */
/* Logger API */
extern void log_add(char *);
char print_log[MAX_LOG_LENGTH + 1];

/* do control here in main PIT loop.
 * 1) read voltage level
 * 2) set DAC to needed value to get desired output, e.g. 1000 V
 */
void volt_control()
{
	LED_GREEN_TOGGLE();

	DAC_SetBufferValue(DEMO_DAC_BASEADDR, 0U, (unsigned int) ((systime & 0xffff)>>4));  // 12 bit DAC

	if ( (unsigned int)(systime & 0x7fff) == 0x0000)
	{
	    /*
         When in software trigger mode, each conversion would be launched once calling the "ADC16_ChannelConfigure()"
         function, which works like writing a conversion command and executing it. For another channel's conversion,
         just to change the "channelNumber" field in channel's configuration structure, and call the
         "ADC16_ChannelConfigure() again.
        */
        ADC16_SetChannelConfig(DEMO_ADC16_BASEADDR, DEMO_ADC16_CHANNEL_GROUP, &g_adc16ChannelConfigStruct);
        while (0U == (kADC16_ChannelConversionDoneFlag &
                      ADC16_GetChannelStatusFlags(DEMO_ADC16_BASEADDR, DEMO_ADC16_CHANNEL_GROUP)))
        {        }
        g_Adc16ConversionValue =  ADC16_GetChannelConversionValue(DEMO_ADC16_BASEADDR, DEMO_ADC16_CHANNEL_GROUP);
        PRINTF("ADC Value: %d\r\n", g_Adc16ConversionValue);

		// Convert ADC value to a voltage based on 3.3V VREFH on board
		voltRead = (float)(g_Adc16ConversionValue * (VREF_BRD / SE_12BIT));
		PRINTF("\r\nADC Voltage: %0.3f\r\n", voltRead);
		//sprintf(print_log, "\r\nADC Voltage: %0.3f\r\n", voltRead);
		//log_add(print_log);
		// call here in case log_add is not re-entrant
		// xQueueSendFromISR(log_queue, print_log, 0);  // send data to back of queue,
		    // non-blocking, wait=0 ==> return immediately if the queue is already full.


	}
}
