//=========================================================
// PSoC5LP Project
//=========================================================
// File Name : key.h
// Function  : Key/Switch Control Header
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

#ifndef __KEY_H__
#define __KEY_H__

//---------------------------
// PSoC5 Includes
//---------------------------
#include <project.h>
//---------------------------
// RTOS Includes
//---------------------------
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "task.h"

//===================
// Key Switch Name
//===================
#define MAX_KEY 2
enum KEY_NAME {KEY_0 = 0, KEY_1};

//=================
// Key Push Status
//=================
enum KEY_STATUS {KEY_STATUS_NOP = 0, KEY_STATUS_PUSH, KEY_STATUS_PUSH_LONG}; 

//=================================
// Detection Period of Push Long
//=================================
#define KEY_PUSH_LONG_TICKS 50 // 500ms

//===============
// Prototypes
//===============
void Init_Key(void);
uint8 Check_Key_Status(uint8 key);
//
void Task_Key_Push(void *pvParameters);

#endif // __KEY_H__

//=========================================================
// End of Program
//=========================================================
