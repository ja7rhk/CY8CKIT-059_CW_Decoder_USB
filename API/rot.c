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

/* API */
#include "rot.h"

/* Definitions of FreeRTOS related Resource */
extern xQueueHandle xQueue_ROT;

/***********************
 *  Initialize ROT     *
 ***********************/
void Init_ROT(void)
{
    /* initialize the rotary encoder */    
}


#define QUEUE_INTERVAL 50

/***********************
 *  Task ROT           *
 ***********************/
void Task_ROT(void *pvParameters)
{
    /* Block for 3ms */
    const portTickType xDelay = 3 / portTICK_RATE_MS;

    uint8 new = 0;  /* current state of ROT */
    uint8 prev = 0; /* previous state of ROT */
    int8 count = 0; /* click count */
    uint16 cntTask = 0;   /* task count */

    /* Task Loop */
    while(1)
    {
        /*****************************************
		*	Rotary Encoder
		******************************************/

        /* click detect */
        new = (ROT_A_Read() << 1) + ROT_B_Read();
        if (new != prev)
        {
            /* click CW ? */
            if ((new == 0x03u) && (prev == 0x02u))
                count++;
            /* click CCW ? */
            if ((new == 0x03u) && (prev == 0x01u))
                count--;
            /* update the ROT state */
            prev = new;
        }

        cntTask++;
        if (cntTask >= QUEUE_INTERVAL)
        {
            if (count != 0)
            {
                xQueueSend(xQueue_ROT, &count, 0);
                count = 0;
            }
            cntTask = 0;
        }

        /* Blocking Task */
        vTaskDelay(xDelay);
    }
}

