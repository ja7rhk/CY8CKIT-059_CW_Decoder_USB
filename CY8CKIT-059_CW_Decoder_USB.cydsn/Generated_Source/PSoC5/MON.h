/*******************************************************************************
* File Name: MON.h  
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

#if !defined(CY_PINS_MON_H) /* Pins MON_H */
#define CY_PINS_MON_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MON_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MON__PORT == 15 && ((MON__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MON_Write(uint8 value);
void    MON_SetDriveMode(uint8 mode);
uint8   MON_ReadDataReg(void);
uint8   MON_Read(void);
void    MON_SetInterruptMode(uint16 position, uint16 mode);
uint8   MON_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MON_SetDriveMode() function.
     *  @{
     */
        #define MON_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MON_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MON_DM_RES_UP          PIN_DM_RES_UP
        #define MON_DM_RES_DWN         PIN_DM_RES_DWN
        #define MON_DM_OD_LO           PIN_DM_OD_LO
        #define MON_DM_OD_HI           PIN_DM_OD_HI
        #define MON_DM_STRONG          PIN_DM_STRONG
        #define MON_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MON_MASK               MON__MASK
#define MON_SHIFT              MON__SHIFT
#define MON_WIDTH              1u

/* Interrupt constants */
#if defined(MON__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MON_SetInterruptMode() function.
     *  @{
     */
        #define MON_INTR_NONE      (uint16)(0x0000u)
        #define MON_INTR_RISING    (uint16)(0x0001u)
        #define MON_INTR_FALLING   (uint16)(0x0002u)
        #define MON_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MON_INTR_MASK      (0x01u) 
#endif /* (MON__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MON_PS                     (* (reg8 *) MON__PS)
/* Data Register */
#define MON_DR                     (* (reg8 *) MON__DR)
/* Port Number */
#define MON_PRT_NUM                (* (reg8 *) MON__PRT) 
/* Connect to Analog Globals */                                                  
#define MON_AG                     (* (reg8 *) MON__AG)                       
/* Analog MUX bux enable */
#define MON_AMUX                   (* (reg8 *) MON__AMUX) 
/* Bidirectional Enable */                                                        
#define MON_BIE                    (* (reg8 *) MON__BIE)
/* Bit-mask for Aliased Register Access */
#define MON_BIT_MASK               (* (reg8 *) MON__BIT_MASK)
/* Bypass Enable */
#define MON_BYP                    (* (reg8 *) MON__BYP)
/* Port wide control signals */                                                   
#define MON_CTL                    (* (reg8 *) MON__CTL)
/* Drive Modes */
#define MON_DM0                    (* (reg8 *) MON__DM0) 
#define MON_DM1                    (* (reg8 *) MON__DM1)
#define MON_DM2                    (* (reg8 *) MON__DM2) 
/* Input Buffer Disable Override */
#define MON_INP_DIS                (* (reg8 *) MON__INP_DIS)
/* LCD Common or Segment Drive */
#define MON_LCD_COM_SEG            (* (reg8 *) MON__LCD_COM_SEG)
/* Enable Segment LCD */
#define MON_LCD_EN                 (* (reg8 *) MON__LCD_EN)
/* Slew Rate Control */
#define MON_SLW                    (* (reg8 *) MON__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MON_PRTDSI__CAPS_SEL       (* (reg8 *) MON__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MON_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MON__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MON_PRTDSI__OE_SEL0        (* (reg8 *) MON__PRTDSI__OE_SEL0) 
#define MON_PRTDSI__OE_SEL1        (* (reg8 *) MON__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MON_PRTDSI__OUT_SEL0       (* (reg8 *) MON__PRTDSI__OUT_SEL0) 
#define MON_PRTDSI__OUT_SEL1       (* (reg8 *) MON__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MON_PRTDSI__SYNC_OUT       (* (reg8 *) MON__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MON__SIO_CFG)
    #define MON_SIO_HYST_EN        (* (reg8 *) MON__SIO_HYST_EN)
    #define MON_SIO_REG_HIFREQ     (* (reg8 *) MON__SIO_REG_HIFREQ)
    #define MON_SIO_CFG            (* (reg8 *) MON__SIO_CFG)
    #define MON_SIO_DIFF           (* (reg8 *) MON__SIO_DIFF)
#endif /* (MON__SIO_CFG) */

/* Interrupt Registers */
#if defined(MON__INTSTAT)
    #define MON_INTSTAT            (* (reg8 *) MON__INTSTAT)
    #define MON_SNAP               (* (reg8 *) MON__SNAP)
    
	#define MON_0_INTTYPE_REG 		(* (reg8 *) MON__0__INTTYPE)
#endif /* (MON__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MON_H */


/* [] END OF FILE */
