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
#include "LPF_2.h"

#define LPF_2_CR_MASK (LPF_2__LPF_15KHZ | LPF_2__LPF_30KHZ | LPF_2__LPF_76KHZ | LPF_2__LPF_153KHZ)

void LPF_2_Start() {
    LPF_2_SetCutoffFreq((enum LPF_2_CUTOFF_FREQ)0);
}

void LPF_2_SetCutoffFreq(const enum LPF_2_CUTOFF_FREQ cutoff) {
    const void CYFAR *pCR = (void CYFAR*)LPF_2_lpf_1__CR0;
    const uint8 nextCR = (CY_GET_XTND_REG8(pCR) & ~LPF_2_CR_MASK) | cutoff;
    CY_SET_XTND_REG8(pCR, nextCR);
}
/* [] END OF FILE */
