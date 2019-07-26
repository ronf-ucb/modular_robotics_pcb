/*
 * read_frame.c

* called by interrupt on SyncOut, reads 1 frame, prints and returns *
 *  Created on: Jul 25, 2019
 *      Author: ronf
 */
#include <stdio.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_debug_console.h"
#include "board.h"

static int sensor_frame[8][8];
#define MAX_LOG_LENGTH 64
static char log[MAX_LOG_LENGTH + 1];

extern int read_chan(void);
/*prototypes */
void read_frame(void);
void wait_edge(void);
extern void log_add(char *);

void read_frame()
{ int i,j;
	double frame_time;

	LED_RED_ON(); // reading frame
	log_add("In Readframe\n\r");
	frame_time = (double)(xTaskGetTickCountFromISR()/10000.0); // with ticks at 100 us, convert to sec

	sprintf(log, "Frame at %10.3f sec\n\r", frame_time);
	log_add(log);

/* row is scanned first */
/* 2/1/94:  input switches on falling edge, so sample on rising edge */
    for (j = 0; j < 8; j++)
      for(i= 0; i < 8; i++)
      {
     	  wait_edge();
    	  sensor_frame[i][j]= read_chan(); 	/* read one element */
      }

    /* now print read array */;
    PRINTF("Frame at %10.3f sec\n\r", frame_time);
    for (j = 0; j < 8; j++)
    {     for(i= 0; i < 8; i++)
          {
         	PRINTF("%5d", sensor_frame[i][j]);
          }
    	PRINTF("\n\r");
    }
    LED_RED_OFF();
}

/* poll on ScanClk for rising edge */
void wait_edge(void)
{ }
