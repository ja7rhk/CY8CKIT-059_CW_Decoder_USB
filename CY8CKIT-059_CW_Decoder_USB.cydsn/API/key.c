//=========================================================
// PSoC5LP Project
//=========================================================
// File Name : key.c
// Function  : Key/Switch Control
//---------------------------------------------------------
// Rev.01 2012.09.01 Munetomo Maruyama
//---------------------------------------------------------
// Copyright (C) 2012-2013 Munetomo Maruyama
//=========================================================
// ---- License Information -------------------------------
// Anyone can FREELY use this code fully or partially
// under conditions shown below.
// 1. You may use this code only for individual purpose,
//    and educational purpose.
//    Do not use this code for business even if partially.
// 2. You can copy, modify and distribute this code.
// 3. You should remain this header text in your codes
//   including Copyright credit and License Information.
// 4. Your codes should inherit this license information.
//=========================================================
// ---- Patent Notice -------------------------------------
// I have not cared whether this system (hw + sw) causes
// infringement on the patent, copyright, trademark,
// or trade secret rights of others. You have all
// responsibilities for determining if your designs
// and products infringe on the intellectual property
// rights of others, when you use technical information
// included in this system for your business.
//=========================================================
// ---- Disclaimers ---------------------------------------
// The function and reliability of this system are not
// guaranteed. They may cause any damages to loss of
// properties, data, money, profits, life, or business.
// By adopting this system even partially, you assume
// all responsibility for its use.
//=========================================================

#include "key.h"

//---------------------------
// RTOS Includes
//---------------------------
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "task.h"

//---------------------
// Define Queue
//---------------------
extern xQueueHandle xQueue_KEY[2];

//---------------------
// Key Detection Status
//---------------------
enum KEY_DETECT_STATUS {KEY_IDLE, KEY_DETECT, KEY_CONFIRM, KEY_PUSH, KEY_PUSH_COUNT, KEY_PUSH_LONG};

//---------------------
// Globals
//---------------------
uint8 gKey[MAX_KEY];

//======================
// Initialize Key
//======================
void Init_Key(void)
{
    uint32 i;    
    // Initialize State
    for (i = 0; i < MAX_KEY; i++) gKey[i]  = 0;
}

//=========================
// Get Key Status
//=========================
uint8 Check_Key_Status(uint8 key)
{
    uint8 status;
    status = (key == KEY_0)? (~PI_KEY_0_Read()) & 0x01 :
             (key == KEY_1)? (~PI_KEY_1_Read()) & 0x01 :
             0;
    return status;
}

//=========================
// Task KEY
//=========================
void Task_KEY(void *pvParameters)
{
    static uint32 i;
    static uint8 key;
    static uint32 push_count[MAX_KEY];
    static uint8 qmsg = 1;
    
    // Block for 10ms
    const portTickType xDelay = 10 / portTICK_RATE_MS;
    
    // Task Loop
    while(1)
    {   
        // State Machine for Key Detection
        for (i = 0; i < MAX_KEY; i++)
        {
            key = Check_Key_Status(i);
            //
            switch(gKey[i])
            {
                case KEY_IDLE:
                {
                    gKey[i] = (key)? KEY_DETECT : KEY_IDLE;
                    break;
                }
                case KEY_DETECT:
                {
                    gKey[i] = (key)? KEY_CONFIRM : KEY_IDLE;
                    break;
                }
                case KEY_CONFIRM:
                {
                    gKey[i] = (key)? KEY_PUSH : KEY_IDLE;
                    break;
                }
                case KEY_PUSH:
                {
                    xQueueSend(xQueue_KEY[i], &qmsg, 0);
                    push_count[i] = 0;
                    gKey[i] = (key)? KEY_PUSH_COUNT : KEY_IDLE;
                    break;
                }
                case KEY_PUSH_COUNT:
                {
                    if (key)
                    {
                        gKey[i] = (push_count[i] > KEY_PUSH_LONG_TICKS)? KEY_PUSH_LONG : KEY_PUSH_COUNT;
                        push_count[i]++;
                    }
                    else
                    {
                        gKey[i] = KEY_IDLE;
                    }
                    break;
                }
                case KEY_PUSH_LONG:
                {
                    xQueueSend(xQueue_KEY[i], &qmsg, 0);
                    gKey[i] = (key)? KEY_PUSH_LONG : KEY_IDLE;
                    break;
                }
                default:
                {
                    break; // do nothing
                }
            }
        }
        // Blocking Task
        vTaskDelay(xDelay);
    }
}

//=========================================================
// End of Program
//=========================================================
