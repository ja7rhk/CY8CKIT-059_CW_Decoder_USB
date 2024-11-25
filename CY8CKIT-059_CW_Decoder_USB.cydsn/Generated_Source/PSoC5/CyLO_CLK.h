/*******************************************************************************
* File Name: CyLO_CLK.h
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

#if !defined(CY_CLOCK_CyLO_CLK_H)
#define CY_CLOCK_CyLO_CLK_H

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

void CyLO_CLK_Start(void) ;
void CyLO_CLK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void CyLO_CLK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void CyLO_CLK_StandbyPower(uint8 state) ;
void CyLO_CLK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 CyLO_CLK_GetDividerRegister(void) ;
void CyLO_CLK_SetModeRegister(uint8 modeBitMask) ;
void CyLO_CLK_ClearModeRegister(uint8 modeBitMask) ;
uint8 CyLO_CLK_GetModeRegister(void) ;
void CyLO_CLK_SetSourceRegister(uint8 clkSource) ;
uint8 CyLO_CLK_GetSourceRegister(void) ;
#if defined(CyLO_CLK__CFG3)
void CyLO_CLK_SetPhaseRegister(uint8 clkPhase) ;
uint8 CyLO_CLK_GetPhaseRegister(void) ;
#endif /* defined(CyLO_CLK__CFG3) */

#define CyLO_CLK_Enable()                       CyLO_CLK_Start()
#define CyLO_CLK_Disable()                      CyLO_CLK_Stop()
#define CyLO_CLK_SetDivider(clkDivider)         CyLO_CLK_SetDividerRegister(clkDivider, 1u)
#define CyLO_CLK_SetDividerValue(clkDivider)    CyLO_CLK_SetDividerRegister((clkDivider) - 1u, 1u)
#define CyLO_CLK_SetMode(clkMode)               CyLO_CLK_SetModeRegister(clkMode)
#define CyLO_CLK_SetSource(clkSource)           CyLO_CLK_SetSourceRegister(clkSource)
#if defined(CyLO_CLK__CFG3)
#define CyLO_CLK_SetPhase(clkPhase)             CyLO_CLK_SetPhaseRegister(clkPhase)
#define CyLO_CLK_SetPhaseValue(clkPhase)        CyLO_CLK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(CyLO_CLK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define CyLO_CLK_CLKEN              (* (reg8 *) CyLO_CLK__PM_ACT_CFG)
#define CyLO_CLK_CLKEN_PTR          ((reg8 *) CyLO_CLK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define CyLO_CLK_CLKSTBY            (* (reg8 *) CyLO_CLK__PM_STBY_CFG)
#define CyLO_CLK_CLKSTBY_PTR        ((reg8 *) CyLO_CLK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define CyLO_CLK_DIV_LSB            (* (reg8 *) CyLO_CLK__CFG0)
#define CyLO_CLK_DIV_LSB_PTR        ((reg8 *) CyLO_CLK__CFG0)
#define CyLO_CLK_DIV_PTR            ((reg16 *) CyLO_CLK__CFG0)

/* Clock MSB divider configuration register. */
#define CyLO_CLK_DIV_MSB            (* (reg8 *) CyLO_CLK__CFG1)
#define CyLO_CLK_DIV_MSB_PTR        ((reg8 *) CyLO_CLK__CFG1)

/* Mode and source configuration register */
#define CyLO_CLK_MOD_SRC            (* (reg8 *) CyLO_CLK__CFG2)
#define CyLO_CLK_MOD_SRC_PTR        ((reg8 *) CyLO_CLK__CFG2)

#if defined(CyLO_CLK__CFG3)
/* Analog clock phase configuration register */
#define CyLO_CLK_PHASE              (* (reg8 *) CyLO_CLK__CFG3)
#define CyLO_CLK_PHASE_PTR          ((reg8 *) CyLO_CLK__CFG3)
#endif /* defined(CyLO_CLK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define CyLO_CLK_CLKEN_MASK         CyLO_CLK__PM_ACT_MSK
#define CyLO_CLK_CLKSTBY_MASK       CyLO_CLK__PM_STBY_MSK

/* CFG2 field masks */
#define CyLO_CLK_SRC_SEL_MSK        CyLO_CLK__CFG2_SRC_SEL_MASK
#define CyLO_CLK_MODE_MASK          (~(CyLO_CLK_SRC_SEL_MSK))

#if defined(CyLO_CLK__CFG3)
/* CFG3 phase mask */
#define CyLO_CLK_PHASE_MASK         CyLO_CLK__CFG3_PHASE_DLY_MASK
#endif /* defined(CyLO_CLK__CFG3) */

#endif /* CY_CLOCK_CyLO_CLK_H */


/* [] END OF FILE */
