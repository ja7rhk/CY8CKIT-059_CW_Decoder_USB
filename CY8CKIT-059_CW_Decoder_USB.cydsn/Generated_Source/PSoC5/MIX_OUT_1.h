/*******************************************************************************
* File Name: MIX_OUT_1.h  
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

#if !defined(CY_PINS_MIX_OUT_1_H) /* Pins MIX_OUT_1_H */
#define CY_PINS_MIX_OUT_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MIX_OUT_1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MIX_OUT_1__PORT == 15 && ((MIX_OUT_1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MIX_OUT_1_Write(uint8 value);
void    MIX_OUT_1_SetDriveMode(uint8 mode);
uint8   MIX_OUT_1_ReadDataReg(void);
uint8   MIX_OUT_1_Read(void);
void    MIX_OUT_1_SetInterruptMode(uint16 position, uint16 mode);
uint8   MIX_OUT_1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MIX_OUT_1_SetDriveMode() function.
     *  @{
     */
        #define MIX_OUT_1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MIX_OUT_1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MIX_OUT_1_DM_RES_UP          PIN_DM_RES_UP
        #define MIX_OUT_1_DM_RES_DWN         PIN_DM_RES_DWN
        #define MIX_OUT_1_DM_OD_LO           PIN_DM_OD_LO
        #define MIX_OUT_1_DM_OD_HI           PIN_DM_OD_HI
        #define MIX_OUT_1_DM_STRONG          PIN_DM_STRONG
        #define MIX_OUT_1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MIX_OUT_1_MASK               MIX_OUT_1__MASK
#define MIX_OUT_1_SHIFT              MIX_OUT_1__SHIFT
#define MIX_OUT_1_WIDTH              1u

/* Interrupt constants */
#if defined(MIX_OUT_1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MIX_OUT_1_SetInterruptMode() function.
     *  @{
     */
        #define MIX_OUT_1_INTR_NONE      (uint16)(0x0000u)
        #define MIX_OUT_1_INTR_RISING    (uint16)(0x0001u)
        #define MIX_OUT_1_INTR_FALLING   (uint16)(0x0002u)
        #define MIX_OUT_1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MIX_OUT_1_INTR_MASK      (0x01u) 
#endif /* (MIX_OUT_1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MIX_OUT_1_PS                     (* (reg8 *) MIX_OUT_1__PS)
/* Data Register */
#define MIX_OUT_1_DR                     (* (reg8 *) MIX_OUT_1__DR)
/* Port Number */
#define MIX_OUT_1_PRT_NUM                (* (reg8 *) MIX_OUT_1__PRT) 
/* Connect to Analog Globals */                                                  
#define MIX_OUT_1_AG                     (* (reg8 *) MIX_OUT_1__AG)                       
/* Analog MUX bux enable */
#define MIX_OUT_1_AMUX                   (* (reg8 *) MIX_OUT_1__AMUX) 
/* Bidirectional Enable */                                                        
#define MIX_OUT_1_BIE                    (* (reg8 *) MIX_OUT_1__BIE)
/* Bit-mask for Aliased Register Access */
#define MIX_OUT_1_BIT_MASK               (* (reg8 *) MIX_OUT_1__BIT_MASK)
/* Bypass Enable */
#define MIX_OUT_1_BYP                    (* (reg8 *) MIX_OUT_1__BYP)
/* Port wide control signals */                                                   
#define MIX_OUT_1_CTL                    (* (reg8 *) MIX_OUT_1__CTL)
/* Drive Modes */
#define MIX_OUT_1_DM0                    (* (reg8 *) MIX_OUT_1__DM0) 
#define MIX_OUT_1_DM1                    (* (reg8 *) MIX_OUT_1__DM1)
#define MIX_OUT_1_DM2                    (* (reg8 *) MIX_OUT_1__DM2) 
/* Input Buffer Disable Override */
#define MIX_OUT_1_INP_DIS                (* (reg8 *) MIX_OUT_1__INP_DIS)
/* LCD Common or Segment Drive */
#define MIX_OUT_1_LCD_COM_SEG            (* (reg8 *) MIX_OUT_1__LCD_COM_SEG)
/* Enable Segment LCD */
#define MIX_OUT_1_LCD_EN                 (* (reg8 *) MIX_OUT_1__LCD_EN)
/* Slew Rate Control */
#define MIX_OUT_1_SLW                    (* (reg8 *) MIX_OUT_1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MIX_OUT_1_PRTDSI__CAPS_SEL       (* (reg8 *) MIX_OUT_1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MIX_OUT_1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MIX_OUT_1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MIX_OUT_1_PRTDSI__OE_SEL0        (* (reg8 *) MIX_OUT_1__PRTDSI__OE_SEL0) 
#define MIX_OUT_1_PRTDSI__OE_SEL1        (* (reg8 *) MIX_OUT_1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MIX_OUT_1_PRTDSI__OUT_SEL0       (* (reg8 *) MIX_OUT_1__PRTDSI__OUT_SEL0) 
#define MIX_OUT_1_PRTDSI__OUT_SEL1       (* (reg8 *) MIX_OUT_1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MIX_OUT_1_PRTDSI__SYNC_OUT       (* (reg8 *) MIX_OUT_1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MIX_OUT_1__SIO_CFG)
    #define MIX_OUT_1_SIO_HYST_EN        (* (reg8 *) MIX_OUT_1__SIO_HYST_EN)
    #define MIX_OUT_1_SIO_REG_HIFREQ     (* (reg8 *) MIX_OUT_1__SIO_REG_HIFREQ)
    #define MIX_OUT_1_SIO_CFG            (* (reg8 *) MIX_OUT_1__SIO_CFG)
    #define MIX_OUT_1_SIO_DIFF           (* (reg8 *) MIX_OUT_1__SIO_DIFF)
#endif /* (MIX_OUT_1__SIO_CFG) */

/* Interrupt Registers */
#if defined(MIX_OUT_1__INTSTAT)
    #define MIX_OUT_1_INTSTAT            (* (reg8 *) MIX_OUT_1__INTSTAT)
    #define MIX_OUT_1_SNAP               (* (reg8 *) MIX_OUT_1__SNAP)
    
	#define MIX_OUT_1_0_INTTYPE_REG 		(* (reg8 *) MIX_OUT_1__0__INTTYPE)
#endif /* (MIX_OUT_1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MIX_OUT_1_H */


/* [] END OF FILE */
