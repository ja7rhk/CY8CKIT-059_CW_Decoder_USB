/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "LPF_1.h"

#define LPF_1_CR_MASK (LPF_1__LPF_15KHZ | LPF_1__LPF_30KHZ | LPF_1__LPF_76KHZ | LPF_1__LPF_153KHZ)

void LPF_1_Start() {
    LPF_1_SetCutoffFreq((enum LPF_1_CUTOFF_FREQ)0);
}

void LPF_1_SetCutoffFreq(const enum LPF_1_CUTOFF_FREQ cutoff) {
    const void CYFAR *pCR = (void CYFAR*)LPF_1_lpf_1__CR0;
    const uint8 nextCR = (CY_GET_XTND_REG8(pCR) & ~LPF_1_CR_MASK) | cutoff;
    CY_SET_XTND_REG8(pCR, nextCR);
}

/* [] END OF FILE */
