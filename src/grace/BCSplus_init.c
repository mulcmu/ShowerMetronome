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
 *      C:/ti/grace_3_00_02_64/packages/ti/mcu/msp430/csl/clock/BCSplus_init.xdt
 */

#include <msp430.h>
#include "_Grace.h"

/* USER CODE START (section: BCSplus_init_c_prologue) */
/* User defined includes, defines, global variables and functions */
/* USER CODE END (section: BCSplus_init_c_prologue) */

/*
 *  ======== BCSplus_graceInit ========
 *  Initialize MSP430 Basic Clock System
 */
void BCSplus_graceInit(void)
{
    /* USER CODE START (section: BCSplus_graceInit_prologue) */
    /* User initialization code */
    /* USER CODE END (section: BCSplus_graceInit_prologue) */

    /* 
     * Basic Clock System Control 2
     * 
     * SELM_0 -- DCOCLK
     * DIVM_0 -- Divide by 1
     * ~SELS -- DCOCLK
     * DIVS_0 -- Divide by 1
     * ~DCOR -- DCO uses internal resistor
     * 
     * Note: ~<BIT> indicates that <BIT> has value zero
     */
    BCSCTL2 = SELM_0 | DIVM_0 | DIVS_0;

    if (CALBC1_1MHZ != 0xFF) {
        /* Follow recommended flow. First, clear all DCOx and MODx bits. Then
         * apply new RSELx values. Finally, apply new DCOx and MODx bit values.
         */
        DCOCTL = 0x00;
        BCSCTL1 = CALBC1_1MHZ;      /* Set DCO to 1MHz */
        DCOCTL = CALDCO_1MHZ;
    }

    /* 
     * Basic Clock System Control 1
     * 
     * XT2OFF -- Disable XT2CLK
     * ~XTS -- Low Frequency
     * DIVA_0 -- Divide by 1
     * 
     * Note: ~XTS indicates that XTS has value zero
     */
    BCSCTL1 |= XT2OFF | DIVA_0;

    /* 
     * Basic Clock System Control 3
     * 
     * XT2S_0 -- 0.4 - 1 MHz
     * LFXT1S_2 -- If XTS = 0, XT1 = VLOCLK ; If XTS = 1, XT1 = 3 - 16-MHz crystal or resonator
     * XCAP_1 -- ~6 pF
     */
    BCSCTL3 = XT2S_0 | LFXT1S_2 | XCAP_1;

    /* USER CODE START (section: BCSplus_graceInit_epilogue) */
    /* User code */
    /* USER CODE END (section: BCSplus_graceInit_epilogue) */
}
