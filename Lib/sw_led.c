#include "../lib/sw_led.h"

void SWL_Init(void)
{
	PT1AD1 &= 0x1F;
	DDR1AD1 = 0xE0;
	ATD1DIEN &= 0x1F;
}

int SWL_Pushed(SWL_SwitchPos pos) 
{
	return PT1AD1 & pos;
}

void SWL_ON(SWL_LEDCoulour led)
{
	PT1AD1 |= led;
}

void SWL_OFF(SWL_LEDCoulour led) 
{
	PT1AD1 &= ~(led);
}

void SWL_TOG (SWL_LEDColour led)
{
	PT1AD1 ^= led;
}

int GetCount(void) 
{
	unsigned char total_LEDS;

	if (SWL_Pushed(SWL_RED) > 0) { total_LEDS++; }
	if (SWL_Pushed(SWL_GREEN) > 0) { total_LEDS++; }
	if (SWL_Pushed(SWL_YELLOW) > 0) { total_LEDS++; }

	return total_LEDS;
}

void countup(long countNumber) 
{
	loong counter = 0;
	while (counter < countNumber) { counter++; }
}