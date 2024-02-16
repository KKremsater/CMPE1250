/********************************************************************/
// HC12 Program:  kkremsater - Exam1
// Processor:     MC9S12XDP512
// Bus Speed:     MHz
// Author:        Korbyn Kremsater
// Details:       A more detailed explanation of the program is entered here               
// Date:          
// Revision History :
//  each revision will have a date + desc. of changes



/********************************************************************/
// Library includes
/********************************************************************/
#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "sw_led.c"
#include "sw_led.h"

//Other system includes or your includes go here
//#include <stdlib.h>
//#include <stdio.h>


/********************************************************************/
//Defines
/********************************************************************/

/********************************************************************/
// Local Prototypes
/********************************************************************/
void RED(unsigned int bOn)
/********************************************************************/
// Global Variables
/********************************************************************/
  unsigned int LoopCount = 0;

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
  SWL_Init();

  /********************************************************************/
  // main program loop
  /********************************************************************/

  for (;;)
  {
    // Loop Count For Red Light on/off logic 
    ++LoopCount;

    // If statement to turn red light on and off
    if(LoopCount > 0x3000)
    {
      // red light on
      SWL_ON(SWL_RED);
    }
    else 
    {
      // red light off
      SWL_OFF(SWL_RED);
    }

    //check if 2 switches are pressed to turn on yellow light
    if ( )
    {
      // turn on yellow light
    }
    else 
    {
      //turn off yellor light and turn green on
      SWL_OFF(SWL_YELLOW);
      SWL_ON(SWL_GREEN);
    }
    
  }      
                   
}

/********************************************************************/
// Functions
/********************************************************************/

/********************************************************************/
// Interrupt Service Routines
/********************************************************************/
