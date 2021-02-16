
/********************************/
/* Program Name: checksum.c     */
/* Author: Jaztin Tabunda       */
/* Date: 2/12/2021              */
/********************************/
/* Description:                 */
/*  Checksum program but in c   */
/*  and computes the running    */
/*  complement of 1s like in the*/ 
/*  excel sheet                 */
/* Validation Checks:           */
/*  If statement to make sure   */
/*  value is in bounds          */
/* Enhancements:                */
/*  N/A                         */
/********************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define max_int (255)
#define byte unsigned char

int main (int argc, char * argv[], char ** envp)
{

  const char SIXTHVALUE = 5; //added constant variable
  
  int count = 10; //starter variable
  int sum = 0;    //starter variable
  int value = 0;    //added variable
  int overflow = 0; //added variable
  
  byte checksum = 0;  //starter variable
  byte complement = 0; //starter variable
  byte header[10];      //added variable/array
  
  short readReturn = 0; //added variable

  /* the following is the prototype for the read system call */
    printf("Please enter 10 Numbers between 0 - 255:\n");

    readReturn = read(0, (void*) &header, 10);
    
    for(int counter = 0; counter < count; counter++)
    {
        
        value = header[counter];
        if(value < 0 || value > max_int)
        {   
           printf("Invalid Value. \n");
           return 0;
        }

        if(counter == SIXTHVALUE)
        {
            checksum = value;
            value = 0;
        }
        sum = sum + value;
        if(sum > max_int)
        {
            overflow = sum / max_int;
            sum = sum - (max_int + 1);
            sum = sum + overflow;
        }
        printf("Numbers Entered: %d \n", value);
    }
    complement = max_int - sum;


    fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
    if (checksum != complement )
    {
      fprintf(stderr, "Error Detected!\n");
      return 1;
    }
      return 0;
}

