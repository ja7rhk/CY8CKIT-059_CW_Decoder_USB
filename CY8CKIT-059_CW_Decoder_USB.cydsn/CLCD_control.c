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

/* PSoC5 */
#include <device.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
/* API */
#include "I2C_CLCD.h"
#include "rot.h"
//#include "key.h"

extern xQueueHandle xQueue_ROT;        /* Queue Data from Task_ROT(ROT_ENC_Handler) */
extern xQueueHandle xQueue_RXD;        /* Queue Data from Task_RADIO */

extern xSemaphoreHandle xMutex_RX_BUF;     /* Mutex for RX Data Buffer */

/***************************************************************************
*	Task_CLCD
****************************************************************************/

const uint8 pga_gain[] = {1u, 2u, 4u, 8u, 16u, 24u, 32u, 48u};

#define GAIN_MAX    sizeof pga_gain / sizeof pga_gain[0]


void Task_CLCD(void *pvParameters)
{
    /* Gain Control */
    int16 gain = 2;     /* init value x04 */
    int8  click;
    char str[20];
    const portTickType xDelay = 100 / portTICK_RATE_MS;
    
    /*                   "0123456789012345" */
    I2C_CLCD_Position(0u, 0u);
    I2C_CLCD_PrintString("PGA Gain        ");
    I2C_CLCD_Position(1u, 0u);
    I2C_CLCD_PrintString("                ");

    /* Init. Gain Control */
    PGA_1_SetGain(pga_gain[gain]);
    I2C_CLCD_Position(1u, 0u);
    sprintf(str, "x%02d     ", pga_gain[gain]);
    I2C_CLCD_PrintString(str);

    while(1)
    {
        /* Get click count of ROT */
        if (uxQueueMessagesWaiting(xQueue_ROT) > 0)
        {
            xQueueReceive(xQueue_ROT, &click, 0);

            /* the target PGA gain */
            gain += click ;
            if (gain < 0)
                gain = 0;
            if ((uint16)gain > (GAIN_MAX - 1))
                gain = GAIN_MAX - 1;
            /*set PGA gain*/
            PGA_1_SetGain(pga_gain[gain]);

            /* PGA Gain */
            I2C_CLCD_Position(1u, 0u);
            sprintf(str, "x%02d     ", pga_gain[gain]);
            I2C_CLCD_PrintString(str);
        }
        /* sleep for 100ms */
        vTaskDelay(xDelay);
    }
}


/* [] END OF FILE */
