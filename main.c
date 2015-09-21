/*
The MIT License (MIT)

Copyright (c) 2015 mulcmu

ShowerMetronome

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
 */



#include "main.h"

const unsigned int Pattern[][5] = {	{1000, 500, 32767, 3277, 19},
									{250, 125, 32767, 6553, 1},
									{1000, 500, 32767, 3277, 19},
									{250, 125, 32767, 6553, 1},
									{1000, 500, 32767, 3277, 19},
									{250, 125, 32767, 6553, 1},
									{1000, 500, 31129, 3277, 20},
									{250, 125, 31129, 6553, 1},
									{1000, 500, 31129, 3277, 20},
									{250, 125, 31129, 6553, 1},
									{1000, 500, 31129, 3277, 20},
									{250, 125, 31129, 6553, 1},
									{1000, 500, 27852, 3277, 23},
									{250, 125, 27852, 6553, 1},
									{1000, 500, 27852, 3277, 23},
									{250, 125, 27852, 6553, 1},
									{1000, 500, 27852, 3277, 23},
									{250, 125, 27852, 6553, 1},
									{500, 250, 26214, 3277, 24},
									{125, 63, 3277, 3277, 1},
									{250, 125, 3277, 3277, 1},
									{500, 250, 26214, 3277, 24},
									{125, 63, 3277, 3277, 1},
									{250, 125, 3277, 3277, 1},
									{500, 250, 26214, 3277, 24},
									{125, 63, 3277, 3277, 1},
									{250, 125, 3277, 3277, 1},
									{500, 250, 24575, 3277, 26},
									{125, 63, 3277, 3277, 1},
									{250, 125, 3277, 3277, 1},
									{500, 250, 24575, 3277, 26},
									{125, 63, 3277, 3277, 1},
									{250, 125, 3277, 3277, 1},
									{500, 250, 24575, 3277, 26},
									{125, 63, 3277, 3277, 1},
									{250, 125, 3277, 3277, 1},
									{500, 250, 22937, 3277, 29},
									{125, 63, 3277, 3277, 1},
									{250, 125, 3277, 3277, 1},
									{500, 250, 22937, 3277, 29},
									{125, 63, 3277, 3277, 1},
									{250, 125, 3277, 3277, 1},
									{500, 250, 22937, 3277, 29},
									{125, 63, 3277, 3277, 1},
									{250, 125, 3277, 3277, 1}};



int HZ=1000;
int Timer1_A0=0;
int Timer1_A1=0;

unsigned int Cycle = 0;
unsigned int Count = 0;

/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>

/*
 * ======== Grace related includes ========
 */
#include <ti/mcu/msp430/Grace.h>

/*
 *  ======== main ========
 */
int main(void)
{
    Grace_init();                   // Activate Grace-generated configuration
    
	//Load inital Cycle
    TA0CCR0 = Pattern[Cycle][0];
	TA0CCR1 = Pattern[Cycle][1];
	TA1CCR0 = Pattern[Cycle][2];
	TA1CCR1 = Pattern[Cycle][3];
	Count = Pattern[Cycle][4];

	__enable_interrupt();

	while(1)
	{

		Count--;

		if (Count == 0)
		{
			//Turn off both timers
			BitClear(TA0CTL, MC1 + MC0);
			BitClear(TA1CTL, MC1 + MC0);

			//Advance cycle
			Cycle++;

			//Check for roll over
			if (Cycle > 43)
			{
				Cycle = 0;
			}

			//Load timers with new values
			TA0CCR0 = Pattern[Cycle][0];
			TA0CCR1 = Pattern[Cycle][1];
			TA1CCR0 = Pattern[Cycle][2];
			TA1CCR1 = Pattern[Cycle][3];
			Count = Pattern[Cycle][4];
		}

		//Restart the timers
		BitSet(TA0CTL, MC_1 );
		BitSet(TA1CTL, MC_1 );


		/* Entering low power mode 0 */
		__bis_SR_register(LPM0_bits | GIE);

	}

}
