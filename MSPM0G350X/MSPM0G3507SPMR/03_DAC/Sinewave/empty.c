/*
 * Copyright (c) 2021, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <ti/driverlib/m0p/dl_interrupt.h>
#include "ti_msp_dl_config.h"

// uint32_t DAC_value = 2048;

volatile uint8_t i = 0;

const uint16_t sineTable[32] = {
 2048, 2447, 2831, 3185, 3495, 3750, 3939, 4056,
 4095, 4056, 3939, 3750, 3495, 3185, 2831, 2447,
 2048, 1648, 1264,  911,  600,  345,  156,   39,
    0,   39,  156,  345,  600,  911, 1264, 1648
};

// const uint16_t sineTable[64] = {
//  0,
//  128, 256, 384, 512, 640, 768, 896, 1024, 1152, 1280, 1408, 1536, 
//  1664, 1792, 1920, 2048, 2176, 2304, 2432, 2560, 2688, 2816,
//  2944, 3072, 3200, 3328, 3456, 3584, 3712, 3840, 3968,
//  4095,

//  4095,
// 3968, 3840, 3712, 3584,3456, 3328, 3200, 3072, 2944,
// 2816, 2688,2560, 2432, 2304, 2176, 2048, 1920, 1792, 1664,
// 1536, 1408, 1280,1152, 1024, 896, 768, 640, 512, 384, 256, 128,
//  0, 

// };


 

int main(void)
{
    SYSCFG_DL_init();

    NVIC_EnableIRQ(TIMER_0_INST_INT_IRQN);

    DL_TimerA_startCounter(TIMER_0_INST);

    while (1) {
    //      DL_DAC12_output12(DAC0, DAC_value);
    // DL_DAC12_enable(DAC0);
    }
}


void TIMER_0_INST_IRQHandler(void)
{
    // switch (DL_TimerA_getPendingInterrupt(TIMER_0_INST)) {
    //     case DL_TIMERA_IIDX_REPEAT_COUNT:
            // DL_GPIO_togglePins(GPIO_LEDS_PORT,
            //     GPIO_LEDS_USER_LED_1_PIN | GPIO_LEDS_USER_TEST_PIN);

                //  DL_DAC12_output12(DAC0, DAC_value);
    // DL_DAC12_enable(DAC0);


     DL_Timer_clearInterruptStatus(TIMER_0_INST,TIMER_0_INST_INT_IRQN);

    // Write next sine sample to DAC
    DL_DAC12_output12(DAC0, sineTable[i]);

    i++;
    if (i >= 32)
        i = 0;


    //         break;
    //     default:
    //         break;
    // }
}
