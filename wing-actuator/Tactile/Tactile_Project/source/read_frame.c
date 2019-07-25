/*
 * read_frame.c

* called by interrupt on SyncOut, reads 1 frame, prints and returns *
 *  Created on: Jul 25, 2019
 *      Author: ronf
 */
#include <stdio.h>
/* Freescale includes. */
#include "fsl_debug_console.h"

static int sensor_frame[8][8];

extern int read_chan(void);


void read_frame()
{ int i,j;


/* row is scanned first */
    for (j = 0; j < 8; j++)
      for(i= 0; i < 8; i++)
      {
 /* 2/1/94:  input switches on falling edge, so sample on rising edge */
    	  sensor_frame[i][j]= read_chan(); 	/* read one element */
      }

    /* now print read array */
    for (j = 0; j < 8; j++)
    {     for(i= 0; i < 8; i++)
          {
         	PRINTF("%5d", sensor_frame[i][j]);
          }
    	PRINTF("\n\r");
    }
}
