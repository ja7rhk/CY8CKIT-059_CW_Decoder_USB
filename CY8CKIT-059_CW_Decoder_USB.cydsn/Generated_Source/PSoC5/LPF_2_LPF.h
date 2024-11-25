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
#ifndef LPF_LPF_2_H
#define LPF_LPF_2_H

#include "cytypes.h"
#include "cyfitter.h"

#define LPF_2__LPF_15KHZ 48
#define LPF_2__LPF_30KHZ 16
#define LPF_2__LPF_76KHZ 32
#define LPF_2__LPF_153KHZ 0

enum LPF_2_CUTOFF_FREQ {
    LPF_2_15kHz = LPF_2__LPF_15KHZ,
    LPF_2_30kHz = LPF_2__LPF_30KHZ,
    LPF_2_76kHz = LPF_2__LPF_76KHZ,
    LPF_2_153kHz = LPF_2__LPF_153KHZ
};

void LPF_2_Start();
void LPF_2_SetCutoffFreq(enum LPF_2_CUTOFF_FREQ);

#endif // LPF_LPF_2_H

/* [] END OF FILE */
