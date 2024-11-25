/*******************************************************************************
* File Name: ANT.h  
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

#if !defined(CY_PINS_ANT_H) /* Pins ANT_H */
#define CY_PINS_ANT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ANT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ANT__PORT == 15 && ((ANT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ANT_Write(uint8 value);
void    ANT_SetDriveMode(uint8 mode);
uint8   ANT_ReadDataReg(void);
uint8   ANT_Read(void);
void    ANT_SetInterruptMode(uint16 position, uint16 mode);
uint8   ANT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ANT_SetDriveMode() function.
     *  @{
     */
        #define ANT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ANT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ANT_DM_RES_UP          PIN_DM_RES_UP
        #define ANT_DM_RES_DWN         PIN_DM_RES_DWN
        #define ANT_DM_OD_LO           PIN_DM_OD_LO
        #define ANT_DM_OD_HI           PIN_DM_OD_HI
        #define ANT_DM_STRONG          PIN_DM_STRONG
        #define ANT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ANT_MASK               ANT__MASK
#define ANT_SHIFT              ANT__SHIFT
#define ANT_WIDTH              1u

/* Interrupt constants */
#if defined(ANT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ANT_SetInterruptMode() function.
     *  @{
     */
        #define ANT_INTR_NONE      (uint16)(0x0000u)
        #define ANT_INTR_RISING    (uint16)(0x0001u)
        #define ANT_INTR_FALLING   (uint16)(0x0002u)
        #define ANT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ANT_INTR_MASK      (0x01u) 
#endif /* (ANT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ANT_PS                     (* (reg8 *) ANT__PS)
/* Data Register */
#define ANT_DR                     (* (reg8 *) ANT__DR)
/* Port Number */
#define ANT_PRT_NUM                (* (reg8 *) ANT__PRT) 
/* Connect to Analog Globals */                                                  
#define ANT_AG                     (* (reg8 *) ANT__AG)                       
/* Analog MUX bux enable */
#define ANT_AMUX                   (* (reg8 *) ANT__AMUX) 
/* Bidirectional Enable */                                                        
#define ANT_BIE                    (* (reg8 *) ANT__BIE)
/* Bit-mask for Aliased Register Access */
#define ANT_BIT_MASK               (* (reg8 *) ANT__BIT_MASK)
/* Bypass Enable */
#define ANT_BYP                    (* (reg8 *) ANT__BYP)
/* Port wide control signals */                                                   
#define ANT_CTL                    (* (reg8 *) ANT__CTL)
/* Drive Modes */
#define ANT_DM0                    (* (reg8 *) ANT__DM0) 
#define ANT_DM1                    (* (reg8 *) ANT__DM1)
#define ANT_DM2                    (* (reg8 *) ANT__DM2) 
/* Input Buffer Disable Override */
#define ANT_INP_DIS                (* (reg8 *) ANT__INP_DIS)
/* LCD Common or Segment Drive */
#define ANT_LCD_COM_SEG            (* (reg8 *) ANT__LCD_COM_SEG)
/* Enable Segment LCD */
#define ANT_LCD_EN                 (* (reg8 *) ANT__LCD_EN)
/* Slew Rate Control */
#define ANT_SLW                    (* (reg8 *) ANT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ANT_PRTDSI__CAPS_SEL       (* (reg8 *) ANT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ANT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ANT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ANT_PRTDSI__OE_SEL0        (* (reg8 *) ANT__PRTDSI__OE_SEL0) 
#define ANT_PRTDSI__OE_SEL1        (* (reg8 *) ANT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ANT_PRTDSI__OUT_SEL0       (* (reg8 *) ANT__PRTDSI__OUT_SEL0) 
#define ANT_PRTDSI__OUT_SEL1       (* (reg8 *) ANT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ANT_PRTDSI__SYNC_OUT       (* (reg8 *) ANT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ANT__SIO_CFG)
    #define ANT_SIO_HYST_EN        (* (reg8 *) ANT__SIO_HYST_EN)
    #define ANT_SIO_REG_HIFREQ     (* (reg8 *) ANT__SIO_REG_HIFREQ)
    #define ANT_SIO_CFG            (* (reg8 *) ANT__SIO_CFG)
    #define ANT_SIO_DIFF           (* (reg8 *) ANT__SIO_DIFF)
#endif /* (ANT__SIO_CFG) */

/* Interrupt Registers */
#if defined(ANT__INTSTAT)
    #define ANT_INTSTAT            (* (reg8 *) ANT__INTSTAT)
    #define ANT_SNAP               (* (reg8 *) ANT__SNAP)
    
	#define ANT_0_INTTYPE_REG 		(* (reg8 *) ANT__0__INTTYPE)
#endif /* (ANT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ANT_H */


/* [] END OF FILE */
