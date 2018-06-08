/*
 * volt_control.c
 *
 *  Created on: Jun 8, 2018
 *      Author: ronf
 */
#include "board.h"
#include "fsl_dac.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_DAC_BASEADDR DAC0

extern volatile uint32_t systime; //systime updated very 100 us = 4 days ==> NEED OVERFLOW protection


/* do control here in main PIT loop.
 * 1) read voltage level
 * 2) set DAC to needed value to get desired output, e.g. 1000 V
 */
void volt_control()
{
	LED_GREEN_TOGGLE();

	DAC_SetBufferValue(DEMO_DAC_BASEADDR, 0U, (unsigned int) (systime & 0xfff));  // 12 bit DAC
}
