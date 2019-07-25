#include <stdio.h>

extern int print_flag;			/* controls printing of data */
extern double gain[8][16];
char namebuf[80];
FILE *fp, *fopen();

/* prototypes */
extern void read_sensor(int [8][16]);

/*  calculate offset value for sensor array with no pressure */
/* average to get good estimate of mean value */
double offset_array[8][16];
#define NAVERAGE 100
	
/* read array and print offset removed values */


void read_tactile()
{
  int tact_data[8][16];
  int i,j;
  double displacement;		/* change in distance of cap plates */


  read_sensor(tact_data);		/* get sensor data */

   /*  now print out stored array */

   for (i = 0; i < 8; i++)
      {
       if (print_flag&1)
          printf("  \n");
       for( j= 0; j < 8; j++)
        {
	  displacement =  tact_data[i][j];

  	  if (print_flag&1)
	  {
	     printf("%8.2f", 100.0 * displacement);
		/* dump data on serial line */
          }	     

        }
      }
      if (print_flag&1)
         printf("\n");

}






/* grab multiple tactile frames */

void grab_frames()
{
    int count;
    
    
    printf(" Continuous frame grab. Hit any character to quit.\n");
/*    printf(" How many tactile frames?  ");
    scanf(" %d", &count); */
    
    while (!inchar()) {
/*        count--; */
	read_tactile();

        }
    getchar();	/* get rid of extra character in input buffer */
}
