/*******************************************************************************
* File Name: CLKSPL.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_CLKSPL_H)
#define CY_CLOCK_CLKSPL_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void CLKSPL_Start(void) ;
void CLKSPL_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void CLKSPL_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void CLKSPL_StandbyPower(uint8 state) ;
void CLKSPL_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 CLKSPL_GetDividerRegister(void) ;
void CLKSPL_SetModeRegister(uint8 modeBitMask) ;
void CLKSPL_ClearModeRegister(uint8 modeBitMask) ;
uint8 CLKSPL_GetModeRegister(void) ;
void CLKSPL_SetSourceRegister(uint8 clkSource) ;
uint8 CLKSPL_GetSourceRegister(void) ;
#if defined(CLKSPL__CFG3)
void CLKSPL_SetPhaseRegister(uint8 clkPhase) ;
uint8 CLKSPL_GetPhaseRegister(void) ;
#endif /* defined(CLKSPL__CFG3) */

#define CLKSPL_Enable()                       CLKSPL_Start()
#define CLKSPL_Disable()                      CLKSPL_Stop()
#define CLKSPL_SetDivider(clkDivider)         CLKSPL_SetDividerRegister(clkDivider, 1u)
#define CLKSPL_SetDividerValue(clkDivider)    CLKSPL_SetDividerRegister((clkDivider) - 1u, 1u)
#define CLKSPL_SetMode(clkMode)               CLKSPL_SetModeRegister(clkMode)
#define CLKSPL_SetSource(clkSource)           CLKSPL_SetSourceRegister(clkSource)
#if defined(CLKSPL__CFG3)
#define CLKSPL_SetPhase(clkPhase)             CLKSPL_SetPhaseRegister(clkPhase)
#define CLKSPL_SetPhaseValue(clkPhase)        CLKSPL_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(CLKSPL__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define CLKSPL_CLKEN              (* (reg8 *) CLKSPL__PM_ACT_CFG)
#define CLKSPL_CLKEN_PTR          ((reg8 *) CLKSPL__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define CLKSPL_CLKSTBY            (* (reg8 *) CLKSPL__PM_STBY_CFG)
#define CLKSPL_CLKSTBY_PTR        ((reg8 *) CLKSPL__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define CLKSPL_DIV_LSB            (* (reg8 *) CLKSPL__CFG0)
#define CLKSPL_DIV_LSB_PTR        ((reg8 *) CLKSPL__CFG0)
#define CLKSPL_DIV_PTR            ((reg16 *) CLKSPL__CFG0)

/* Clock MSB divider configuration register. */
#define CLKSPL_DIV_MSB            (* (reg8 *) CLKSPL__CFG1)
#define CLKSPL_DIV_MSB_PTR        ((reg8 *) CLKSPL__CFG1)

/* Mode and source configuration register */
#define CLKSPL_MOD_SRC            (* (reg8 *) CLKSPL__CFG2)
#define CLKSPL_MOD_SRC_PTR        ((reg8 *) CLKSPL__CFG2)

#if defined(CLKSPL__CFG3)
/* Analog clock phase configuration register */
#define CLKSPL_PHASE              (* (reg8 *) CLKSPL__CFG3)
#define CLKSPL_PHASE_PTR          ((reg8 *) CLKSPL__CFG3)
#endif /* defined(CLKSPL__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define CLKSPL_CLKEN_MASK         CLKSPL__PM_ACT_MSK
#define CLKSPL_CLKSTBY_MASK       CLKSPL__PM_STBY_MSK

/* CFG2 field masks */
#define CLKSPL_SRC_SEL_MSK        CLKSPL__CFG2_SRC_SEL_MASK
#define CLKSPL_MODE_MASK          (~(CLKSPL_SRC_SEL_MSK))

#if defined(CLKSPL__CFG3)
/* CFG3 phase mask */
#define CLKSPL_PHASE_MASK         CLKSPL__CFG3_PHASE_DLY_MASK
#endif /* defined(CLKSPL__CFG3) */

#endif /* CY_CLOCK_CLKSPL_H */


/* [] END OF FILE */
