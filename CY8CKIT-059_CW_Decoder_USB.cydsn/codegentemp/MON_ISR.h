/*******************************************************************************
* File Name: MON_ISR.h  
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

#if !defined(CY_PINS_MON_ISR_H) /* Pins MON_ISR_H */
#define CY_PINS_MON_ISR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MON_ISR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MON_ISR__PORT == 15 && ((MON_ISR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MON_ISR_Write(uint8 value);
void    MON_ISR_SetDriveMode(uint8 mode);
uint8   MON_ISR_ReadDataReg(void);
uint8   MON_ISR_Read(void);
void    MON_ISR_SetInterruptMode(uint16 position, uint16 mode);
uint8   MON_ISR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MON_ISR_SetDriveMode() function.
     *  @{
     */
        #define MON_ISR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MON_ISR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MON_ISR_DM_RES_UP          PIN_DM_RES_UP
        #define MON_ISR_DM_RES_DWN         PIN_DM_RES_DWN
        #define MON_ISR_DM_OD_LO           PIN_DM_OD_LO
        #define MON_ISR_DM_OD_HI           PIN_DM_OD_HI
        #define MON_ISR_DM_STRONG          PIN_DM_STRONG
        #define MON_ISR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MON_ISR_MASK               MON_ISR__MASK
#define MON_ISR_SHIFT              MON_ISR__SHIFT
#define MON_ISR_WIDTH              1u

/* Interrupt constants */
#if defined(MON_ISR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MON_ISR_SetInterruptMode() function.
     *  @{
     */
        #define MON_ISR_INTR_NONE      (uint16)(0x0000u)
        #define MON_ISR_INTR_RISING    (uint16)(0x0001u)
        #define MON_ISR_INTR_FALLING   (uint16)(0x0002u)
        #define MON_ISR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MON_ISR_INTR_MASK      (0x01u) 
#endif /* (MON_ISR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MON_ISR_PS                     (* (reg8 *) MON_ISR__PS)
/* Data Register */
#define MON_ISR_DR                     (* (reg8 *) MON_ISR__DR)
/* Port Number */
#define MON_ISR_PRT_NUM                (* (reg8 *) MON_ISR__PRT) 
/* Connect to Analog Globals */                                                  
#define MON_ISR_AG                     (* (reg8 *) MON_ISR__AG)                       
/* Analog MUX bux enable */
#define MON_ISR_AMUX                   (* (reg8 *) MON_ISR__AMUX) 
/* Bidirectional Enable */                                                        
#define MON_ISR_BIE                    (* (reg8 *) MON_ISR__BIE)
/* Bit-mask for Aliased Register Access */
#define MON_ISR_BIT_MASK               (* (reg8 *) MON_ISR__BIT_MASK)
/* Bypass Enable */
#define MON_ISR_BYP                    (* (reg8 *) MON_ISR__BYP)
/* Port wide control signals */                                                   
#define MON_ISR_CTL                    (* (reg8 *) MON_ISR__CTL)
/* Drive Modes */
#define MON_ISR_DM0                    (* (reg8 *) MON_ISR__DM0) 
#define MON_ISR_DM1                    (* (reg8 *) MON_ISR__DM1)
#define MON_ISR_DM2                    (* (reg8 *) MON_ISR__DM2) 
/* Input Buffer Disable Override */
#define MON_ISR_INP_DIS                (* (reg8 *) MON_ISR__INP_DIS)
/* LCD Common or Segment Drive */
#define MON_ISR_LCD_COM_SEG            (* (reg8 *) MON_ISR__LCD_COM_SEG)
/* Enable Segment LCD */
#define MON_ISR_LCD_EN                 (* (reg8 *) MON_ISR__LCD_EN)
/* Slew Rate Control */
#define MON_ISR_SLW                    (* (reg8 *) MON_ISR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MON_ISR_PRTDSI__CAPS_SEL       (* (reg8 *) MON_ISR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MON_ISR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MON_ISR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MON_ISR_PRTDSI__OE_SEL0        (* (reg8 *) MON_ISR__PRTDSI__OE_SEL0) 
#define MON_ISR_PRTDSI__OE_SEL1        (* (reg8 *) MON_ISR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MON_ISR_PRTDSI__OUT_SEL0       (* (reg8 *) MON_ISR__PRTDSI__OUT_SEL0) 
#define MON_ISR_PRTDSI__OUT_SEL1       (* (reg8 *) MON_ISR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MON_ISR_PRTDSI__SYNC_OUT       (* (reg8 *) MON_ISR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MON_ISR__SIO_CFG)
    #define MON_ISR_SIO_HYST_EN        (* (reg8 *) MON_ISR__SIO_HYST_EN)
    #define MON_ISR_SIO_REG_HIFREQ     (* (reg8 *) MON_ISR__SIO_REG_HIFREQ)
    #define MON_ISR_SIO_CFG            (* (reg8 *) MON_ISR__SIO_CFG)
    #define MON_ISR_SIO_DIFF           (* (reg8 *) MON_ISR__SIO_DIFF)
#endif /* (MON_ISR__SIO_CFG) */

/* Interrupt Registers */
#if defined(MON_ISR__INTSTAT)
    #define MON_ISR_INTSTAT            (* (reg8 *) MON_ISR__INTSTAT)
    #define MON_ISR_SNAP               (* (reg8 *) MON_ISR__SNAP)
    
	#define MON_ISR_0_INTTYPE_REG 		(* (reg8 *) MON_ISR__0__INTTYPE)
#endif /* (MON_ISR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MON_ISR_H */


/* [] END OF FILE */
