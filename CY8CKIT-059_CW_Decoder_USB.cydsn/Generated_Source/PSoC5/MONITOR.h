/*******************************************************************************
* File Name: MONITOR.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MONITOR_H) /* Pins MONITOR_H */
#define CY_PINS_MONITOR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MONITOR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MONITOR__PORT == 15 && ((MONITOR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MONITOR_Write(uint8 value);
void    MONITOR_SetDriveMode(uint8 mode);
uint8   MONITOR_ReadDataReg(void);
uint8   MONITOR_Read(void);
void    MONITOR_SetInterruptMode(uint16 position, uint16 mode);
uint8   MONITOR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MONITOR_SetDriveMode() function.
     *  @{
     */
        #define MONITOR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MONITOR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MONITOR_DM_RES_UP          PIN_DM_RES_UP
        #define MONITOR_DM_RES_DWN         PIN_DM_RES_DWN
        #define MONITOR_DM_OD_LO           PIN_DM_OD_LO
        #define MONITOR_DM_OD_HI           PIN_DM_OD_HI
        #define MONITOR_DM_STRONG          PIN_DM_STRONG
        #define MONITOR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MONITOR_MASK               MONITOR__MASK
#define MONITOR_SHIFT              MONITOR__SHIFT
#define MONITOR_WIDTH              1u

/* Interrupt constants */
#if defined(MONITOR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MONITOR_SetInterruptMode() function.
     *  @{
     */
        #define MONITOR_INTR_NONE      (uint16)(0x0000u)
        #define MONITOR_INTR_RISING    (uint16)(0x0001u)
        #define MONITOR_INTR_FALLING   (uint16)(0x0002u)
        #define MONITOR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MONITOR_INTR_MASK      (0x01u) 
#endif /* (MONITOR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MONITOR_PS                     (* (reg8 *) MONITOR__PS)
/* Data Register */
#define MONITOR_DR                     (* (reg8 *) MONITOR__DR)
/* Port Number */
#define MONITOR_PRT_NUM                (* (reg8 *) MONITOR__PRT) 
/* Connect to Analog Globals */                                                  
#define MONITOR_AG                     (* (reg8 *) MONITOR__AG)                       
/* Analog MUX bux enable */
#define MONITOR_AMUX                   (* (reg8 *) MONITOR__AMUX) 
/* Bidirectional Enable */                                                        
#define MONITOR_BIE                    (* (reg8 *) MONITOR__BIE)
/* Bit-mask for Aliased Register Access */
#define MONITOR_BIT_MASK               (* (reg8 *) MONITOR__BIT_MASK)
/* Bypass Enable */
#define MONITOR_BYP                    (* (reg8 *) MONITOR__BYP)
/* Port wide control signals */                                                   
#define MONITOR_CTL                    (* (reg8 *) MONITOR__CTL)
/* Drive Modes */
#define MONITOR_DM0                    (* (reg8 *) MONITOR__DM0) 
#define MONITOR_DM1                    (* (reg8 *) MONITOR__DM1)
#define MONITOR_DM2                    (* (reg8 *) MONITOR__DM2) 
/* Input Buffer Disable Override */
#define MONITOR_INP_DIS                (* (reg8 *) MONITOR__INP_DIS)
/* LCD Common or Segment Drive */
#define MONITOR_LCD_COM_SEG            (* (reg8 *) MONITOR__LCD_COM_SEG)
/* Enable Segment LCD */
#define MONITOR_LCD_EN                 (* (reg8 *) MONITOR__LCD_EN)
/* Slew Rate Control */
#define MONITOR_SLW                    (* (reg8 *) MONITOR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MONITOR_PRTDSI__CAPS_SEL       (* (reg8 *) MONITOR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MONITOR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MONITOR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MONITOR_PRTDSI__OE_SEL0        (* (reg8 *) MONITOR__PRTDSI__OE_SEL0) 
#define MONITOR_PRTDSI__OE_SEL1        (* (reg8 *) MONITOR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MONITOR_PRTDSI__OUT_SEL0       (* (reg8 *) MONITOR__PRTDSI__OUT_SEL0) 
#define MONITOR_PRTDSI__OUT_SEL1       (* (reg8 *) MONITOR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MONITOR_PRTDSI__SYNC_OUT       (* (reg8 *) MONITOR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MONITOR__SIO_CFG)
    #define MONITOR_SIO_HYST_EN        (* (reg8 *) MONITOR__SIO_HYST_EN)
    #define MONITOR_SIO_REG_HIFREQ     (* (reg8 *) MONITOR__SIO_REG_HIFREQ)
    #define MONITOR_SIO_CFG            (* (reg8 *) MONITOR__SIO_CFG)
    #define MONITOR_SIO_DIFF           (* (reg8 *) MONITOR__SIO_DIFF)
#endif /* (MONITOR__SIO_CFG) */

/* Interrupt Registers */
#if defined(MONITOR__INTSTAT)
    #define MONITOR_INTSTAT            (* (reg8 *) MONITOR__INTSTAT)
    #define MONITOR_SNAP               (* (reg8 *) MONITOR__SNAP)
    
	#define MONITOR_0_INTTYPE_REG 		(* (reg8 *) MONITOR__0__INTTYPE)
#endif /* (MONITOR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MONITOR_H */


/* [] END OF FILE */
