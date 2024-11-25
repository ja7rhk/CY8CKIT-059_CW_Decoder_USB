/*******************************************************************************
* File Name: KEY.h  
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

#if !defined(CY_PINS_KEY_H) /* Pins KEY_H */
#define CY_PINS_KEY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "KEY_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 KEY__PORT == 15 && ((KEY__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    KEY_Write(uint8 value);
void    KEY_SetDriveMode(uint8 mode);
uint8   KEY_ReadDataReg(void);
uint8   KEY_Read(void);
void    KEY_SetInterruptMode(uint16 position, uint16 mode);
uint8   KEY_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the KEY_SetDriveMode() function.
     *  @{
     */
        #define KEY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define KEY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define KEY_DM_RES_UP          PIN_DM_RES_UP
        #define KEY_DM_RES_DWN         PIN_DM_RES_DWN
        #define KEY_DM_OD_LO           PIN_DM_OD_LO
        #define KEY_DM_OD_HI           PIN_DM_OD_HI
        #define KEY_DM_STRONG          PIN_DM_STRONG
        #define KEY_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define KEY_MASK               KEY__MASK
#define KEY_SHIFT              KEY__SHIFT
#define KEY_WIDTH              1u

/* Interrupt constants */
#if defined(KEY__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in KEY_SetInterruptMode() function.
     *  @{
     */
        #define KEY_INTR_NONE      (uint16)(0x0000u)
        #define KEY_INTR_RISING    (uint16)(0x0001u)
        #define KEY_INTR_FALLING   (uint16)(0x0002u)
        #define KEY_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define KEY_INTR_MASK      (0x01u) 
#endif /* (KEY__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define KEY_PS                     (* (reg8 *) KEY__PS)
/* Data Register */
#define KEY_DR                     (* (reg8 *) KEY__DR)
/* Port Number */
#define KEY_PRT_NUM                (* (reg8 *) KEY__PRT) 
/* Connect to Analog Globals */                                                  
#define KEY_AG                     (* (reg8 *) KEY__AG)                       
/* Analog MUX bux enable */
#define KEY_AMUX                   (* (reg8 *) KEY__AMUX) 
/* Bidirectional Enable */                                                        
#define KEY_BIE                    (* (reg8 *) KEY__BIE)
/* Bit-mask for Aliased Register Access */
#define KEY_BIT_MASK               (* (reg8 *) KEY__BIT_MASK)
/* Bypass Enable */
#define KEY_BYP                    (* (reg8 *) KEY__BYP)
/* Port wide control signals */                                                   
#define KEY_CTL                    (* (reg8 *) KEY__CTL)
/* Drive Modes */
#define KEY_DM0                    (* (reg8 *) KEY__DM0) 
#define KEY_DM1                    (* (reg8 *) KEY__DM1)
#define KEY_DM2                    (* (reg8 *) KEY__DM2) 
/* Input Buffer Disable Override */
#define KEY_INP_DIS                (* (reg8 *) KEY__INP_DIS)
/* LCD Common or Segment Drive */
#define KEY_LCD_COM_SEG            (* (reg8 *) KEY__LCD_COM_SEG)
/* Enable Segment LCD */
#define KEY_LCD_EN                 (* (reg8 *) KEY__LCD_EN)
/* Slew Rate Control */
#define KEY_SLW                    (* (reg8 *) KEY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define KEY_PRTDSI__CAPS_SEL       (* (reg8 *) KEY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define KEY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) KEY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define KEY_PRTDSI__OE_SEL0        (* (reg8 *) KEY__PRTDSI__OE_SEL0) 
#define KEY_PRTDSI__OE_SEL1        (* (reg8 *) KEY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define KEY_PRTDSI__OUT_SEL0       (* (reg8 *) KEY__PRTDSI__OUT_SEL0) 
#define KEY_PRTDSI__OUT_SEL1       (* (reg8 *) KEY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define KEY_PRTDSI__SYNC_OUT       (* (reg8 *) KEY__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(KEY__SIO_CFG)
    #define KEY_SIO_HYST_EN        (* (reg8 *) KEY__SIO_HYST_EN)
    #define KEY_SIO_REG_HIFREQ     (* (reg8 *) KEY__SIO_REG_HIFREQ)
    #define KEY_SIO_CFG            (* (reg8 *) KEY__SIO_CFG)
    #define KEY_SIO_DIFF           (* (reg8 *) KEY__SIO_DIFF)
#endif /* (KEY__SIO_CFG) */

/* Interrupt Registers */
#if defined(KEY__INTSTAT)
    #define KEY_INTSTAT            (* (reg8 *) KEY__INTSTAT)
    #define KEY_SNAP               (* (reg8 *) KEY__SNAP)
    
	#define KEY_0_INTTYPE_REG 		(* (reg8 *) KEY__0__INTTYPE)
#endif /* (KEY__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_KEY_H */


/* [] END OF FILE */
