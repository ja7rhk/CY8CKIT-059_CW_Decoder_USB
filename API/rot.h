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

#ifndef __ROT_H__
#define __ROT_H__

/* PSoC5 */
#include <project.h>

/* freeRTOS */
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "task.h"

/***********************
 *  Prototypes         *
 ***********************/
void Init_ROT (void);
void Task_ROT (void *pvParameters);



#endif /* __ROT_H__ */

