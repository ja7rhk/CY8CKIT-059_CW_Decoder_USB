/*******************************************************************************
* File Name: Status_PHASE_1.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_Status_PHASE_1_H) /* CY_STATUS_REG_Status_PHASE_1_H */
#define CY_STATUS_REG_Status_PHASE_1_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} Status_PHASE_1_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 Status_PHASE_1_Read(void) ;
void Status_PHASE_1_InterruptEnable(void) ;
void Status_PHASE_1_InterruptDisable(void) ;
void Status_PHASE_1_WriteMask(uint8 mask) ;
uint8 Status_PHASE_1_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define Status_PHASE_1_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define Status_PHASE_1_INPUTS              1


/***************************************
*             Registers
***************************************/

/* Status Register */
#define Status_PHASE_1_Status             (* (reg8 *) Status_PHASE_1_sts_sts_reg__STATUS_REG )
#define Status_PHASE_1_Status_PTR         (  (reg8 *) Status_PHASE_1_sts_sts_reg__STATUS_REG )
#define Status_PHASE_1_Status_Mask        (* (reg8 *) Status_PHASE_1_sts_sts_reg__MASK_REG )
#define Status_PHASE_1_Status_Aux_Ctrl    (* (reg8 *) Status_PHASE_1_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_Status_PHASE_1_H */


/* [] END OF FILE */
