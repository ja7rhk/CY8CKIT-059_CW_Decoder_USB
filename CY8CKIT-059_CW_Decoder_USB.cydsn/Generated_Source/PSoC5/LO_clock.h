/*******************************************************************************
* File Name: LO_clock.h
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

#if !defined(CY_CLOCK_LO_clock_H)
#define CY_CLOCK_LO_clock_H

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

void LO_clock_Start(void) ;
void LO_clock_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void LO_clock_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void LO_clock_StandbyPower(uint8 state) ;
void LO_clock_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 LO_clock_GetDividerRegister(void) ;
void LO_clock_SetModeRegister(uint8 modeBitMask) ;
void LO_clock_ClearModeRegister(uint8 modeBitMask) ;
uint8 LO_clock_GetModeRegister(void) ;
void LO_clock_SetSourceRegister(uint8 clkSource) ;
uint8 LO_clock_GetSourceRegister(void) ;
#if defined(LO_clock__CFG3)
void LO_clock_SetPhaseRegister(uint8 clkPhase) ;
uint8 LO_clock_GetPhaseRegister(void) ;
#endif /* defined(LO_clock__CFG3) */

#define LO_clock_Enable()                       LO_clock_Start()
#define LO_clock_Disable()                      LO_clock_Stop()
#define LO_clock_SetDivider(clkDivider)         LO_clock_SetDividerRegister(clkDivider, 1u)
#define LO_clock_SetDividerValue(clkDivider)    LO_clock_SetDividerRegister((clkDivider) - 1u, 1u)
#define LO_clock_SetMode(clkMode)               LO_clock_SetModeRegister(clkMode)
#define LO_clock_SetSource(clkSource)           LO_clock_SetSourceRegister(clkSource)
#if defined(LO_clock__CFG3)
#define LO_clock_SetPhase(clkPhase)             LO_clock_SetPhaseRegister(clkPhase)
#define LO_clock_SetPhaseValue(clkPhase)        LO_clock_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(LO_clock__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define LO_clock_CLKEN              (* (reg8 *) LO_clock__PM_ACT_CFG)
#define LO_clock_CLKEN_PTR          ((reg8 *) LO_clock__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define LO_clock_CLKSTBY            (* (reg8 *) LO_clock__PM_STBY_CFG)
#define LO_clock_CLKSTBY_PTR        ((reg8 *) LO_clock__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define LO_clock_DIV_LSB            (* (reg8 *) LO_clock__CFG0)
#define LO_clock_DIV_LSB_PTR        ((reg8 *) LO_clock__CFG0)
#define LO_clock_DIV_PTR            ((reg16 *) LO_clock__CFG0)

/* Clock MSB divider configuration register. */
#define LO_clock_DIV_MSB            (* (reg8 *) LO_clock__CFG1)
#define LO_clock_DIV_MSB_PTR        ((reg8 *) LO_clock__CFG1)

/* Mode and source configuration register */
#define LO_clock_MOD_SRC            (* (reg8 *) LO_clock__CFG2)
#define LO_clock_MOD_SRC_PTR        ((reg8 *) LO_clock__CFG2)

#if defined(LO_clock__CFG3)
/* Analog clock phase configuration register */
#define LO_clock_PHASE              (* (reg8 *) LO_clock__CFG3)
#define LO_clock_PHASE_PTR          ((reg8 *) LO_clock__CFG3)
#endif /* defined(LO_clock__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define LO_clock_CLKEN_MASK         LO_clock__PM_ACT_MSK
#define LO_clock_CLKSTBY_MASK       LO_clock__PM_STBY_MSK

/* CFG2 field masks */
#define LO_clock_SRC_SEL_MSK        LO_clock__CFG2_SRC_SEL_MASK
#define LO_clock_MODE_MASK          (~(LO_clock_SRC_SEL_MSK))

#if defined(LO_clock__CFG3)
/* CFG3 phase mask */
#define LO_clock_PHASE_MASK         LO_clock__CFG3_PHASE_DLY_MASK
#endif /* defined(LO_clock__CFG3) */

#endif /* CY_CLOCK_LO_clock_H */


/* [] END OF FILE */
