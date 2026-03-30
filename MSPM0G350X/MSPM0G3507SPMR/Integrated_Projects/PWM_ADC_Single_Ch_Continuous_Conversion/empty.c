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

// volatile bool gCheckADC;
// volatile uint16_t gAdcResult;

#define SAMPLE_COUNT 40

volatile uint16_t adcBuffer[SAMPLE_COUNT];
volatile uint8_t sampleIndex = 0;
volatile bool bufferReady = false;

int main(void)
{
    SYSCFG_DL_init();


    // DL_TimerA_startCounter(PWM_0_INST);

    //         NVIC_EnableIRQ(ADC12_0_INST_INT_IRQN);
    // gCheckADC = false;

        DL_TimerA_startCounter(PWM_0_INST);

    NVIC_EnableIRQ(ADC12_0_INST_INT_IRQN);

    // No need to manually start conversion
    DL_ADC12_enableConversions(ADC12_0_INST);

    while (1) {

             /*    DL_ADC12_startConversion(ADC12_0_INST);

        while (false == gCheckADC) {
            __WFE();
        }
         gAdcResult = DL_ADC12_getMemResult(ADC12_0_INST, DL_ADC12_MEM_IDX_0);

 gCheckADC = false;
        DL_ADC12_enableConversions(ADC12_0_INST);
    */

            if (bufferReady)
        {
            bufferReady = false;

            // 👉 Here you will process 40 samples
            // (I/Q calculation later)
        }
    }
}

void ADC12_0_INST_IRQHandler(void)
{
    switch (DL_ADC12_getPendingInterrupt(ADC12_0_INST)) {
        case DL_ADC12_IIDX_MEM0_RESULT_LOADED:
            // gCheckADC = true;
            adcBuffer[sampleIndex++] =
                DL_ADC12_getMemResult(ADC12_0_INST, DL_ADC12_MEM_IDX_0);
               // __BKPT(0);

            if (sampleIndex >= SAMPLE_COUNT)
            {
                sampleIndex = 0;
                bufferReady = true;   // 40 samples collected
            }

            break;
        default:
            break;
    }
}
