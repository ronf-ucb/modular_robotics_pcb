/*
 * task2.c
 *
 *  Created on: Dec 31, 2017
 *      Author: ronf
 */

/*System includes.*/
#include <stdio.h>
#include <math.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "fsl_pit.h"  /* periodic interrupt timer */

#include "pin_mux.h"
#include "clock_config.h"

/* globals */
extern volatile uint32_t systime; //systime updated very 100 us = 4 days ==> NEED OVERFLOW protection
extern float sqrt_array[1000]; // to hold results

/*******************************************************************************
 * Definitions
 ******************************************************************************/

//#define MAX_LOG_LENGTH 20
#define MAX_LOG_LENGTH 64
//sizeof("Task1 Message 1, ticks 655535, z=3.14159  \n\r    ")

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/* Application API */
void tactile_task(void *pvParameters);
void show_help(void);

extern void analog_test();

/* Logger API */
extern void log_add(char *log);
extern void log_task(void *pvParameters);


/*!
 * @brief write_task_2 function
 */
void tactile_task(void *pvParameters)
{   TickType_t tick_start, tick_now;
	const TickType_t xDelay700ms = pdMS_TO_TICKS( 700 );
    char log[MAX_LOG_LENGTH + 1];
    uint32_t i = 0, j=0;
    // double z;
    char c;
    PRINTF("Capacitive Array Processing Program\n");
    show_help();

    c = ' ';
    while(c != 'q')
    {	printf("\n*");
    	while ((c = GETCHAR())==' ' || c == '\n');
       	switch (c)
    	{
        	case '?': show_help();
       	    break;

        	case 'a': analog_test();
        	break;

       	    default: putchar('?');
       	    break;
       	}
     }
           printf("QUIT\n");
    tick_start = xTaskGetTickCount();
    for (i = 0; i < 10; i++)
    {   tick_now = xTaskGetTickCount();
    /* deliberately conflict writing to array between 2 tasks */

   		sprintf(log, "Task2 Mess %d, tick_now %d \n\r",
    		(int)i, (int)(tick_now));

        log_add(log);
        //vTaskDelay(xDelay700ms); // relative delay in ticks
        vTaskDelayUntil( &tick_start, xDelay700ms );  // unblocks at absolute time- needed for periodic functions
        LED_BLUE_TOGGLE();
        taskYIELD();
    }
    tick_now = xTaskGetTickCount();
    sprintf(log, "Task2 done. tick_start %d tick_now %d\n\r",
        		(int)i, (int)tick_now);
    log_add(log); // add message to print queue
    vTaskSuspend(NULL);
}

void show_help()
{
    PRINTF("\n?     show this message\n");
    PRINTF("a  read a/d channel 1               s  scan sensor\n");
    printf("c  continuous frame grab            t  save touch pattern\n");
    printf("d  save multiple elements response  v  average responses\n");
    printf("f  store mult. frames               w  set wait interval\n");
    printf("g  get gain matrix                  x  find max pressure\n");
    printf("m  find mean and variance           y  dump to memory \n");
    printf("o  get static offset of array       1  get multiple centers \n");
    printf("p  toggle print flag                l  locate platform\n");
    printf("q quit \n");
    printf("r  read and store offset\n");

}



