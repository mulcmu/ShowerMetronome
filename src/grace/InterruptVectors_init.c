/*
 *  This file is automatically generated and does not require a license
 *
 *  ==== WARNING: CHANGES TO THIS GENERATED FILE WILL BE OVERWRITTEN ====
 *
 *  To make changes to the generated code, use the space between existing
 *      "USER CODE START (section: <name>)"
 *  and
 *      "USER CODE END (section: <name>)"
 *  comments, where <name> is a single word identifying the section.
 *  Only these sections will be preserved.
 *
 *  Do not move these sections within this file or change the START and
 *  END comments in any way.
 *  ==== ALL OTHER CHANGES WILL BE OVERWRITTEN WHEN IT IS REGENERATED ====
 *
 *  This file was generated from
 *      C:/ti/grace_3_00_02_64/packages/ti/mcu/msp430/csl/interrupt_vectors/InterruptVectors_init.xdt
 */
#include <msp430.h>
#include "_Grace.h"

/* USER CODE START (section: InterruptVectors_init_c_prologue) */

#include "..\..\main.h"

extern int HZ;
extern int oscFaulted;
extern int Timer1_A0;
extern int Timer1_A1;

/* USER CODE END (section: InterruptVectors_init_c_prologue) */

/*
 *  ======== InterruptVectors_graceInit ========
 */
void InterruptVectors_graceInit(void)
{
}


/* Interrupt Function Prototypes */





/*
 *  ======== Timer1_A3 Interrupt Service Routine ======== 
 */
#pragma vector=TIMER1_A0_VECTOR
__interrupt void TIMER1_A0_ISR_HOOK(void)
{
    /* USER CODE START (section: TIMER1_A0_ISR_HOOK) */

	//Timer1 CC0 - Start the Timer0 PWM for audio output

	//TA0CTL |= MC_1;
	//BitSet(TA0CTL, MC_1);

	//Debug Value
	Timer1_A0++;

	//Wakeup
	__bic_SR_register_on_exit(LPM4_bits);

    /* USER CODE END (section: TIMER1_A0_ISR_HOOK) */
}

/*
 *  ======== Timer1_A3 Interrupt Service Routine ======== 
 */
#pragma vector=TIMER1_A1_VECTOR
__interrupt void TIMER1_A1_ISR_HOOK(void)
{
    /* USER CODE START (section: TIMER1_A1_ISR_HOOK) */

	//Timer1 CC1 is only interrupt enabled in this ISR
	//Turn off audio for chirp

	//TA0CTL &= ~(MC1 + MC0);
	BitClear(TA0CTL, MC1 + MC0);
	//TA1CCTL1 &= ~CCIFG;

	//Reset the ISR flag
	BitClear(TA1CCTL1, CCIFG);

	//Debug Value
	Timer1_A1++;

    /* USER CODE END (section: TIMER1_A1_ISR_HOOK) */
}
/*
 * ======== Preserved user code snippets ========
 */
#if 0
    /* USER CODE START (section: WDT_ISR_HOOK) */

	//P2.0 to P2.3 configured with pull up resistors

	static unsigned int debounce;

	if (!BitTest(P2IN,BIT0) && BitTest(debounce,BIT0))
	{
		//Enable timer 1 to start chirps
		TA1CTL |= MC_1;
	}

	if (!BitTest(P2IN,BIT1) && BitTest(debounce,BIT1))
	{

		//Disable timer 1 to stop chirps
		TA1CTL &= ~(MC1 + MC0);
	}

	if (!BitTest(P2IN,BIT2) && BitTest(debounce,BIT2))
	{
		//Increse Frequency
		if (HZ>100)
		{
			HZ += 100;
		}
		else
		{
			HZ +=5;
		}
	}

	if (!BitTest(P2IN,BIT3) && BitTest(debounce,BIT3))
	{
		//Decrease Frequency
		if (HZ>100)
		{
			HZ -= 100;
		}
		else
		{
			HZ -=5;
		}
	}

	if (HZ < 10 )
	{
		HZ = 10;
	}

	if(HZ > 30000)
	{
		HZ = 30000;
	}

	TA0CCR0 = 1000000 / HZ;

	debounce=P2IN;

	/* USER CODE END (section: WDT_ISR_HOOK) */
#endif
