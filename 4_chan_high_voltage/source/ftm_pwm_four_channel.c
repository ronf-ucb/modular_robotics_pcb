// Modified example from two channel pwm; updated 8/30/18 Loren Jiang

/*
 * The Clear BSD License
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted (subject to the limitations in the disclaimer below) provided
 * that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY THIS LICENSE.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_debug_console.h"
#include "board.h"
#include "fsl_ftm.h"

#include "pin_mux.h"
#include "clock_config.h"
#include "math.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* The Flextimer instance/channel used for board */
#define BOARD_FTM_BASEADDR FTM0

#define BOARD_FTM_CHAN_0 0U
#define BOARD_FTM_CHAN_1 1U
#define BOARD_FTM_CHAN_2 2U
#define BOARD_FTM_CHAN_3 3U

/* Interrupt number and interrupt handler for the FTM instance used */
#define BOARD_FTM_IRQ_NUM FTM0_IRQn
#define BOARD_FTM_HANDLER FTM0_IRQHandler

/* Get source clock for FTM driver */
#define FTM_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_BusClk)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief delay a while.
 */
void delay(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile bool ftmIsrFlag = false;
double pi = 3.14159;
volatile uint16_t ct = 0;
uint8_t  sine_wave[256] = {
		50,51,52,54,55,56,57,59,
		60,61,62,63,65,66,67,68,
		69,70,71,72,74,75,76,77,
		78,79,80,81,82,83,84,84,
		85,86,87,88,89,89,90,91,
		92,92,93,94,94,95,95,96,
		96,97,97,97,98,98,99,99,
		99,99,99,100,100,100,100,100,
		100,100,100,100,100,100,99,99,
		99,99,99,98,98,97,97,97,
		96,96,95,95,94,94,93,92,
		92,91,90,89,89,88,87,86,
		85,84,84,83,82,81,80,79,
		78,77,76,75,74,72,71,70,
		69,68,67,66,65,63,62,61,
		60,59,57,56,55,54,52,51,
		50,49,48,46,45,44,43,41,
		40,39,38,37,35,34,33,32,
		31,30,29,28,26,25,24,23,
		22,21,20,19,18,17,16,16,
		15,14,13,12,11,11,10,9,
		8,8,7,6,6,5,5,4,
		4,3,3,3,2,2,1,1,
		1,1,1,0,0,0,0,0,
		0,0,0,0,0,0,1,1,
		1,1,1,2,2,3,3,3,
		4,4,5,5,6,6,7,8,
		8,9,10,11,11,12,13,14,
		15,16,16,17,18,19,20,21,
		22,23,24,25,26,28,29,30,
		31,32,33,34,35,37,38,39,
		40,41,43,44,45,46,48,49
};
/*******************************************************************************
 * Code
 ******************************************************************************/
void delay(void)
{
    volatile uint32_t i = 0U;
    for (i = 0U; i < 80000U; ++i)
    {
        __asm("NOP"); /* delay */
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    bool brightnessUp = true; /* Indicate LEDs are brighter or dimmer */

    ftm_config_t ftmInfo;

    uint8_t updatedDutycycle_0 = 0U; /*duty cycles for chan 0-3*/
    uint8_t updatedDutycycle_1 = 0U;
    uint8_t updatedDutycycle_2 = 0U;
    uint8_t updatedDutycycle_3 = 0U;

    ftm_chnl_pwm_signal_param_t ftmParam[4];

    /* Configure ftm params with frequency 24kHZ */
    ftmParam[0].chnlNumber = (ftm_chnl_t)BOARD_FTM_CHAN_0;
    ftmParam[0].level = kFTM_LowTrue;
    ftmParam[0].dutyCyclePercent = 0U;
    ftmParam[0].firstEdgeDelayPercent = 0U;

    ftmParam[1].chnlNumber = (ftm_chnl_t)BOARD_FTM_CHAN_1;
    ftmParam[1].level = kFTM_LowTrue;
    ftmParam[1].dutyCyclePercent = 0U;
    ftmParam[1].firstEdgeDelayPercent = 0U;

    ftmParam[2].chnlNumber = (ftm_chnl_t)BOARD_FTM_CHAN_2;
	ftmParam[2].level = kFTM_LowTrue;
	ftmParam[2].dutyCyclePercent = 0U;
	ftmParam[2].firstEdgeDelayPercent = 0U;

	ftmParam[3].chnlNumber = (ftm_chnl_t)BOARD_FTM_CHAN_3;
	ftmParam[3].level = kFTM_LowTrue;
	ftmParam[3].dutyCyclePercent = 0U;
	ftmParam[3].firstEdgeDelayPercent = 0U;

	// signal parameters
    uint8_t mod_freq = 1; //in hz
    double mod_period, pwm_period;
    mod_period = 1.0/mod_freq; // in sec
    uint16_t pwm_freq = 10000; //in hz
    pwm_period = 1.0/pwm_freq; // in sec
    uint16_t num_samp_in_period = (uint16_t)(mod_period * pwm_freq);

    /* Board pin, clock, debug console init */
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /* Print a note to terminal */
    PRINTF("\r\nFTM example to output PWM on 4 channels\r\n");
//    PRINTF("\r\nYou will see a change in LED brightness if an LED is connected to the FTM pin");
//    PRINTF("\r\nIf no LED is connected to the FTM pin, then probe the signal using an oscilloscope");

    /*
     * ftmInfo.prescale = kFTM_Prescale_Divide_1;
     * ftmInfo.bdmMode = kFTM_BdmMode_0;
     * ftmInfo.pwmSyncMode = kFTM_SoftwareTrigger;
     * ftmInfo.reloadPoints = 0;
     * ftmInfo.faultMode = kFTM_Fault_Disable;
     * ftmInfo.faultFilterValue = 0;
     * ftmInfo.deadTimePrescale = kFTM_Deadtime_Prescale_1;
     * ftmInfo.deadTimeValue = 0;
     * ftmInfo.extTriggers = 0;
     * ftmInfo.chnlInitState = 0;
     * ftmInfo.chnlPolarity = 0;
     * ftmInfo.useGlobalTimeBase = false;
     */
    FTM_GetDefaultConfig(&ftmInfo);

//    /* Divide FTM clock by 8 */
    ftmInfo.prescale = kFTM_Prescale_Divide_8;

    /* Initialize FTM module */
    FTM_Init(BOARD_FTM_BASEADDR, &ftmInfo);

    FTM_SetupPwm(BOARD_FTM_BASEADDR, ftmParam, 4U, kFTM_CenterAlignedPwm, pwm_freq, FTM_SOURCE_CLOCK);

    /*
	 * Set timer period.
	*/
    uint64_t usec_per;
    usec_per = (uint64_t) 1000000 * pwm_period;
	FTM_SetTimerPeriod(BOARD_FTM_BASEADDR, USEC_TO_COUNT(usec_per/8, FTM_SOURCE_CLOCK)); // Example 200/8 us --> 5000 Hz; divide by 8 from prescaler

	FTM_EnableInterrupts(BOARD_FTM_BASEADDR, kFTM_TimeOverflowInterruptEnable);

	EnableIRQ(BOARD_FTM_IRQ_NUM);

    FTM_StartTimer(BOARD_FTM_BASEADDR, kFTM_SystemClock);


    while (1)
    {
//        /* Delay to see the change of LEDs brightness */
//        delay();
//
//        if (brightnessUp)
//        {
//            /* Increase duty cycle until it reach limited value */
//            if (++updatedDutycycle_0 == 80U)
//            {
//                brightnessUp = false;
//            }
//        }
//        else
//        {
//            /* Decrease duty cycle until it reach limited value */
//            if (--updatedDutycycle_0 == 0U)
//            {
//                brightnessUp = true;
//            }
//        }

    	if (ftmIsrFlag) {
    		if (ct ==num_samp_in_period) {
    			ct = 0;
    		}

            /* Start PWM mode with updated duty cycle */

    		updatedDutycycle_0 = (uint8_t) (50 + 45*sin(2.0*pi*ct/num_samp_in_period));

			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FTM_CHAN_0, kFTM_CenterAlignedPwm, updatedDutycycle_0);

			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FTM_CHAN_1, kFTM_CenterAlignedPwm, sine_wave[ct]);

			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FTM_CHAN_2, kFTM_CenterAlignedPwm, sine_wave[ct]);

			FTM_UpdatePwmDutycycle(BOARD_FTM_BASEADDR, (ftm_chnl_t)BOARD_FTM_CHAN_3, kFTM_CenterAlignedPwm, sine_wave[ct]);

            /* Software trigger to update registers */
            FTM_SetSoftwareTrigger(BOARD_FTM_BASEADDR, true);

            ftmIsrFlag = false;
            ct++;
    	}

    }
}

void BOARD_FTM_HANDLER(void)
{
    /* Clear interrupt flag.*/
    FTM_ClearStatusFlags(BOARD_FTM_BASEADDR, kFTM_TimeOverflowFlag);
    ftmIsrFlag = true;
//    PRINTF("interrupt!\n");

}
