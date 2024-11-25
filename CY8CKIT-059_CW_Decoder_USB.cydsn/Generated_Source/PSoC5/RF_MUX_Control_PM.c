/*******************************************************************************
* File Name: RF_MUX_Control_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "RF_MUX_Control.h"

/* Check for removal by optimization */
#if !defined(RF_MUX_Control_Sync_ctrl_reg__REMOVED)

static RF_MUX_Control_BACKUP_STRUCT  RF_MUX_Control_backup = {0u};

    
/*******************************************************************************
* Function Name: RF_MUX_Control_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void RF_MUX_Control_SaveConfig(void) 
{
    RF_MUX_Control_backup.controlState = RF_MUX_Control_Control;
}


/*******************************************************************************
* Function Name: RF_MUX_Control_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void RF_MUX_Control_RestoreConfig(void) 
{
     RF_MUX_Control_Control = RF_MUX_Control_backup.controlState;
}


/*******************************************************************************
* Function Name: RF_MUX_Control_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void RF_MUX_Control_Sleep(void) 
{
    RF_MUX_Control_SaveConfig();
}


/*******************************************************************************
* Function Name: RF_MUX_Control_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void RF_MUX_Control_Wakeup(void)  
{
    RF_MUX_Control_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
