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
#ifndef LPF_LPF_1_H
#define LPF_LPF_1_H

#include "cytypes.h"
#include "cyfitter.h"

#define LPF_1__LPF_15KHZ 48
#define LPF_1__LPF_30KHZ 16
#define LPF_1__LPF_76KHZ 32
#define LPF_1__LPF_153KHZ 0

enum LPF_1_CUTOFF_FREQ {
    LPF_1_15kHz = LPF_1__LPF_15KHZ,
    LPF_1_30kHz = LPF_1__LPF_30KHZ,
    LPF_1_76kHz = LPF_1__LPF_76KHZ,
    LPF_1_153kHz = LPF_1__LPF_153KHZ
};

void LPF_1_Start();
void LPF_1_SetCutoffFreq(enum LPF_1_CUTOFF_FREQ);

#endif // LPF_LPF_1_H

/* [] END OF FILE */
