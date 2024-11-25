/*******************************************************************************
* File Name: BPF_OUT.h  
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

#if !defined(CY_PINS_BPF_OUT_H) /* Pins BPF_OUT_H */
#define CY_PINS_BPF_OUT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BPF_OUT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BPF_OUT__PORT == 15 && ((BPF_OUT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BPF_OUT_Write(uint8 value);
void    BPF_OUT_SetDriveMode(uint8 mode);
uint8   BPF_OUT_ReadDataReg(void);
uint8   BPF_OUT_Read(void);
void    BPF_OUT_SetInterruptMode(uint16 position, uint16 mode);
uint8   BPF_OUT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BPF_OUT_SetDriveMode() function.
     *  @{
     */
        #define BPF_OUT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BPF_OUT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BPF_OUT_DM_RES_UP          PIN_DM_RES_UP
        #define BPF_OUT_DM_RES_DWN         PIN_DM_RES_DWN
        #define BPF_OUT_DM_OD_LO           PIN_DM_OD_LO
        #define BPF_OUT_DM_OD_HI           PIN_DM_OD_HI
        #define BPF_OUT_DM_STRONG          PIN_DM_STRONG
        #define BPF_OUT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BPF_OUT_MASK               BPF_OUT__MASK
#define BPF_OUT_SHIFT              BPF_OUT__SHIFT
#define BPF_OUT_WIDTH              1u

/* Interrupt constants */
#if defined(BPF_OUT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BPF_OUT_SetInterruptMode() function.
     *  @{
     */
        #define BPF_OUT_INTR_NONE      (uint16)(0x0000u)
        #define BPF_OUT_INTR_RISING    (uint16)(0x0001u)
        #define BPF_OUT_INTR_FALLING   (uint16)(0x0002u)
        #define BPF_OUT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BPF_OUT_INTR_MASK      (0x01u) 
#endif /* (BPF_OUT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BPF_OUT_PS                     (* (reg8 *) BPF_OUT__PS)
/* Data Register */
#define BPF_OUT_DR                     (* (reg8 *) BPF_OUT__DR)
/* Port Number */
#define BPF_OUT_PRT_NUM                (* (reg8 *) BPF_OUT__PRT) 
/* Connect to Analog Globals */                                                  
#define BPF_OUT_AG                     (* (reg8 *) BPF_OUT__AG)                       
/* Analog MUX bux enable */
#define BPF_OUT_AMUX                   (* (reg8 *) BPF_OUT__AMUX) 
/* Bidirectional Enable */                                                        
#define BPF_OUT_BIE                    (* (reg8 *) BPF_OUT__BIE)
/* Bit-mask for Aliased Register Access */
#define BPF_OUT_BIT_MASK               (* (reg8 *) BPF_OUT__BIT_MASK)
/* Bypass Enable */
#define BPF_OUT_BYP                    (* (reg8 *) BPF_OUT__BYP)
/* Port wide control signals */                                                   
#define BPF_OUT_CTL                    (* (reg8 *) BPF_OUT__CTL)
/* Drive Modes */
#define BPF_OUT_DM0                    (* (reg8 *) BPF_OUT__DM0) 
#define BPF_OUT_DM1                    (* (reg8 *) BPF_OUT__DM1)
#define BPF_OUT_DM2                    (* (reg8 *) BPF_OUT__DM2) 
/* Input Buffer Disable Override */
#define BPF_OUT_INP_DIS                (* (reg8 *) BPF_OUT__INP_DIS)
/* LCD Common or Segment Drive */
#define BPF_OUT_LCD_COM_SEG            (* (reg8 *) BPF_OUT__LCD_COM_SEG)
/* Enable Segment LCD */
#define BPF_OUT_LCD_EN                 (* (reg8 *) BPF_OUT__LCD_EN)
/* Slew Rate Control */
#define BPF_OUT_SLW                    (* (reg8 *) BPF_OUT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BPF_OUT_PRTDSI__CAPS_SEL       (* (reg8 *) BPF_OUT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BPF_OUT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BPF_OUT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BPF_OUT_PRTDSI__OE_SEL0        (* (reg8 *) BPF_OUT__PRTDSI__OE_SEL0) 
#define BPF_OUT_PRTDSI__OE_SEL1        (* (reg8 *) BPF_OUT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BPF_OUT_PRTDSI__OUT_SEL0       (* (reg8 *) BPF_OUT__PRTDSI__OUT_SEL0) 
#define BPF_OUT_PRTDSI__OUT_SEL1       (* (reg8 *) BPF_OUT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BPF_OUT_PRTDSI__SYNC_OUT       (* (reg8 *) BPF_OUT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BPF_OUT__SIO_CFG)
    #define BPF_OUT_SIO_HYST_EN        (* (reg8 *) BPF_OUT__SIO_HYST_EN)
    #define BPF_OUT_SIO_REG_HIFREQ     (* (reg8 *) BPF_OUT__SIO_REG_HIFREQ)
    #define BPF_OUT_SIO_CFG            (* (reg8 *) BPF_OUT__SIO_CFG)
    #define BPF_OUT_SIO_DIFF           (* (reg8 *) BPF_OUT__SIO_DIFF)
#endif /* (BPF_OUT__SIO_CFG) */

/* Interrupt Registers */
#if defined(BPF_OUT__INTSTAT)
    #define BPF_OUT_INTSTAT            (* (reg8 *) BPF_OUT__INTSTAT)
    #define BPF_OUT_SNAP               (* (reg8 *) BPF_OUT__SNAP)
    
	#define BPF_OUT_0_INTTYPE_REG 		(* (reg8 *) BPF_OUT__0__INTTYPE)
#endif /* (BPF_OUT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BPF_OUT_H */


/* [] END OF FILE */
