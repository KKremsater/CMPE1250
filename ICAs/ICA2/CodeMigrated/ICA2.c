/********************************************************************/
// HC12 Program:  ICA2
// Processor:     MC9S12XDP512
// Bus Speed:     12 MHz
// Author:        Korbyn Kremsater
// Details:       Created for IAC2               
// Date:          Jan 19 , 2024
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

/********************************************************************/
// Local Prototypes
/********************************************************************/
void RED(unsigned int bOn)
void GREEN(unsigned int bOn)

/********************************************************************/
// Global Variables
/********************************************************************/
unsigned int uiMainLoopCount = 0;

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
PT1AD1 &= 0x1F;
DDR1AD1 = 0xE0;

/********************************************************************/
  // main program loop
/********************************************************************/
  for (;;)
  {
    ++uiMainLoopCount;
    RED(uiMainLoopCount < 0x1000);
    GREEN(uiMainLoopCount >= 0x1000);
  }                   
}

/********************************************************************/
// Functions
/********************************************************************/
void RED(unsigned int bOn)
{
  if (bOn < 0x1000)
      PT1AD1 |= 1 << (7);
  else
  {
      PT1AD1 &= 0x7F;
  }

}

void GREEN(unsigned int bOn)
{
  if(bOn >= 0x1000)
  {
      PT1AD1 |= 0x20;
  }
  else
  {
      PT1AD1 &= 0b1101111;
  }
}
/********************************************************************/
// Interrupt Service Routines
/********************************************************************/