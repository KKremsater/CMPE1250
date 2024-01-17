/********************************************************************/
// HC12 Program:  YourProg - MiniExplanation
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        This B. You
// Details:       A more detailed explanation of the program is entered here               
// Date:          Date Created
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/
#define RED_LED 0b10000000
#define GREEN_LED 

/********************************************************************/
// Local Prototypes
/********************************************************************/
void RED(int counter);
void GREEN(int counter);

/********************************************************************/
// Global Variables
/********************************************************************/
unsigned int counter;

/********************************************************************/
// Constants
/********************************************************************/

/********************************************************************/
// Main Entry
/********************************************************************/
void main(void)
{
  //Any main local variables must be declared here

  // main entry point
  _DISABLE_COP();
  //EnableInterrupts;
  
/********************************************************************/
  // one-time initializations
/********************************************************************/
PT1AD1 |= RED_LED;
DDR1AD1 |= RED_LED;

PT1AD1 |= GREEN_LED;
DDR1AD1 |= GREEN_LED;
counter = 0;

/********************************************************************/
  // main program loop
/********************************************************************/
  for (;;)
  {

  }                   
}

/********************************************************************/
// Functions
/********************************************************************/
void RED(int counter)
{
        if(counter < 0x1000)
    {
        PT1AD1 ^= RED_LED;
    }
    else
    {
        PT1AD1 &= 0X7F;
    }
}

void GREEN(int counter)
{
        if(counter < 0x1000)
    {
        PT1AD1 ^= GREEN_LED;
    }
    else
    {
        PT1AD1 &= 0X7F;
    }
}
/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
