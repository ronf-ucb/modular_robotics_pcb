/* 
 * Copyright (c) 1984 by Ron Fearing
 * rehacked for nsc 10/16/85
 */
 

#include <stdio.h>
extern short *piobase;



/* uses Analog Devices RTI-711 board number 1 */




/* wait for sync pulse from tactile array */
/* a/d is 0 to 10 V = 12 bits */
#define LOGIC_HIGH  0x400	/* 2.5 v when a to d is + 10 v full scale */
#define LOGIC_LOW   0x100	/* 0.6 v when a to d is + 10 v full scale */
#define T_DATA      00		/* tactile data channel */
#define T_CLOCK     01		/* tactile array element advance clock */
#define T_SYNC	    02		/* sync channel, active high */
#define NEXT_TACTEL 0x02        /* tactile array element advance clock */
                                /* data should be sampled on rising edge */
#define NEXT_FRAME  0x01        /* sync channel, active high */
                                /* start of new frame on rising edge */
#define VDIODE	    244		/* .6v drop from detector */
#define VOFFSET 0       /* offset in tactile interface, 0 in 1993 box */
                        /* 1993 box has 0v-10v output range */

/* need to wait for rising edge on on NEXT_FRAME bit, the throw out first
   cell */

sync_tact_scan()
{ int time_out;
 error:
    time_out = 100000;

    while( frame_clk() );       /* and wait for low again */
  while( frame_clk() );       /* and wait for low again */
  {  if (time_out-- < 0)
       { printf("Frame_CLK stuck high\n");
                  exit(-1);
       }
   }

   time_out = 100000;
    while( ! (frame_clk()) )    /* wait for high */
      {  if (time_out-- < 0)
	   { printf("Frame_CLK stuck low\n");
                  exit(-1);
	   }
       }
  if (! frame_clk() )
    {   fprintf(stderr, " momentary glitch on frame_clk ! \n");
        goto error;
      }
/* frame clock overlaps scan clock: return whenever frame clock
goes low again. First rising sync_scan_clock resets counter */

/* throw away first rising edge on tactel_clk : it is extra non-existent
   cell */
/*      while( (piobase[1] & NEXT_TACTEL)); */
/*then will be in middle of a cell*/
      while( (!(piobase[0] & NEXT_TACTEL)));
        /* wait for scan_clock to go high
                                   before returning, to get correct edge */

}



/* read tactile element through a/d channel. A to D switches channel on
   rising clock, so wait for clock to go low again to to read data.
   This avoids switching transients on the tactile data */
   

read_tactel()

{

       while( !tactel_clk() ); /* wait for low and high */
       while( tactel_clk() );  /* then will be in the middle of a cell */

       
       return(read_chan());

}
    
    

read_sensor(tact_array)		/* read  tactile array */
int tact_array[8][16];
{
    int i, j;
    int time_out;
    
    sync_tact_scan();	/* wait for start of array in scan */
    
/* this gets ugly, but need to run this thing at high speed about 100 us
   per cell */

/* row is scanned first */
    for (j = 0; j < 8; j++)
      for(i= 0; i < 8; i++)
      {   
#ifdef DEBUG
      fprintf(stderr, "read_sensor: i = %d j = %d \n", i,j);
#endif
/* channel switches on rising edge, so sample on falling edge */  
/* 2/1/94:  input switches on falling edge, so sample on rising edge */
       time_out = 100000;
       while(  ( piobase[0] & NEXT_TACTEL ) )
	{  if (time_out-- < 0) 
		{ printf("Tactel_CLK stuck high\n");
		  exit(-1);
		}
 	}
 /* wait for low and high */
       time_out = 100000;
       while(! (piobase[0] & NEXT_TACTEL)) 
 /* then will be in middle of a cell */
	{  if (time_out-- < 0) 
		{ printf("Tactel_CLK stuck low\n");
		  exit(-1);
		}
 	}
	  tact_array[i][j]= read_chan() + VOFFSET ; 	/* read one element */
/* can't print it here, takes too much time */
       }    
/* fill rest with zero's: not connected yet */
    for (j = 8; j < 16; j++)
      for(i= 0; i < 8; i++)
            tact_array[i][j] = 0;

}



