/*******************************************************************************
* File Name: SPCLK.h
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

#if !defined(CY_CLOCK_SPCLK_H)
#define CY_CLOCK_SPCLK_H

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

void SPCLK_Start(void) ;
void SPCLK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void SPCLK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void SPCLK_StandbyPower(uint8 state) ;
void SPCLK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 SPCLK_GetDividerRegister(void) ;
void SPCLK_SetModeRegister(uint8 modeBitMask) ;
void SPCLK_ClearModeRegister(uint8 modeBitMask) ;
uint8 SPCLK_GetModeRegister(void) ;
void SPCLK_SetSourceRegister(uint8 clkSource) ;
uint8 SPCLK_GetSourceRegister(void) ;
#if defined(SPCLK__CFG3)
void SPCLK_SetPhaseRegister(uint8 clkPhase) ;
uint8 SPCLK_GetPhaseRegister(void) ;
#endif /* defined(SPCLK__CFG3) */

#define SPCLK_Enable()                       SPCLK_Start()
#define SPCLK_Disable()                      SPCLK_Stop()
#define SPCLK_SetDivider(clkDivider)         SPCLK_SetDividerRegister(clkDivider, 1u)
#define SPCLK_SetDividerValue(clkDivider)    SPCLK_SetDividerRegister((clkDivider) - 1u, 1u)
#define SPCLK_SetMode(clkMode)               SPCLK_SetModeRegister(clkMode)
#define SPCLK_SetSource(clkSource)           SPCLK_SetSourceRegister(clkSource)
#if defined(SPCLK__CFG3)
#define SPCLK_SetPhase(clkPhase)             SPCLK_SetPhaseRegister(clkPhase)
#define SPCLK_SetPhaseValue(clkPhase)        SPCLK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(SPCLK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define SPCLK_CLKEN              (* (reg8 *) SPCLK__PM_ACT_CFG)
#define SPCLK_CLKEN_PTR          ((reg8 *) SPCLK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define SPCLK_CLKSTBY            (* (reg8 *) SPCLK__PM_STBY_CFG)
#define SPCLK_CLKSTBY_PTR        ((reg8 *) SPCLK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define SPCLK_DIV_LSB            (* (reg8 *) SPCLK__CFG0)
#define SPCLK_DIV_LSB_PTR        ((reg8 *) SPCLK__CFG0)
#define SPCLK_DIV_PTR            ((reg16 *) SPCLK__CFG0)

/* Clock MSB divider configuration register. */
#define SPCLK_DIV_MSB            (* (reg8 *) SPCLK__CFG1)
#define SPCLK_DIV_MSB_PTR        ((reg8 *) SPCLK__CFG1)

/* Mode and source configuration register */
#define SPCLK_MOD_SRC            (* (reg8 *) SPCLK__CFG2)
#define SPCLK_MOD_SRC_PTR        ((reg8 *) SPCLK__CFG2)

#if defined(SPCLK__CFG3)
/* Analog clock phase configuration register */
#define SPCLK_PHASE              (* (reg8 *) SPCLK__CFG3)
#define SPCLK_PHASE_PTR          ((reg8 *) SPCLK__CFG3)
#endif /* defined(SPCLK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define SPCLK_CLKEN_MASK         SPCLK__PM_ACT_MSK
#define SPCLK_CLKSTBY_MASK       SPCLK__PM_STBY_MSK

/* CFG2 field masks */
#define SPCLK_SRC_SEL_MSK        SPCLK__CFG2_SRC_SEL_MASK
#define SPCLK_MODE_MASK          (~(SPCLK_SRC_SEL_MSK))

#if defined(SPCLK__CFG3)
/* CFG3 phase mask */
#define SPCLK_PHASE_MASK         SPCLK__CFG3_PHASE_DLY_MASK
#endif /* defined(SPCLK__CFG3) */

#endif /* CY_CLOCK_SPCLK_H */


/* [] END OF FILE */
