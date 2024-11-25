/*******************************************************************************
* File Name: REF_2.h  
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

#if !defined(CY_PINS_REF_2_H) /* Pins REF_2_H */
#define CY_PINS_REF_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "REF_2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 REF_2__PORT == 15 && ((REF_2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    REF_2_Write(uint8 value);
void    REF_2_SetDriveMode(uint8 mode);
uint8   REF_2_ReadDataReg(void);
uint8   REF_2_Read(void);
void    REF_2_SetInterruptMode(uint16 position, uint16 mode);
uint8   REF_2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the REF_2_SetDriveMode() function.
     *  @{
     */
        #define REF_2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define REF_2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define REF_2_DM_RES_UP          PIN_DM_RES_UP
        #define REF_2_DM_RES_DWN         PIN_DM_RES_DWN
        #define REF_2_DM_OD_LO           PIN_DM_OD_LO
        #define REF_2_DM_OD_HI           PIN_DM_OD_HI
        #define REF_2_DM_STRONG          PIN_DM_STRONG
        #define REF_2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define REF_2_MASK               REF_2__MASK
#define REF_2_SHIFT              REF_2__SHIFT
#define REF_2_WIDTH              1u

/* Interrupt constants */
#if defined(REF_2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in REF_2_SetInterruptMode() function.
     *  @{
     */
        #define REF_2_INTR_NONE      (uint16)(0x0000u)
        #define REF_2_INTR_RISING    (uint16)(0x0001u)
        #define REF_2_INTR_FALLING   (uint16)(0x0002u)
        #define REF_2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define REF_2_INTR_MASK      (0x01u) 
#endif /* (REF_2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define REF_2_PS                     (* (reg8 *) REF_2__PS)
/* Data Register */
#define REF_2_DR                     (* (reg8 *) REF_2__DR)
/* Port Number */
#define REF_2_PRT_NUM                (* (reg8 *) REF_2__PRT) 
/* Connect to Analog Globals */                                                  
#define REF_2_AG                     (* (reg8 *) REF_2__AG)                       
/* Analog MUX bux enable */
#define REF_2_AMUX                   (* (reg8 *) REF_2__AMUX) 
/* Bidirectional Enable */                                                        
#define REF_2_BIE                    (* (reg8 *) REF_2__BIE)
/* Bit-mask for Aliased Register Access */
#define REF_2_BIT_MASK               (* (reg8 *) REF_2__BIT_MASK)
/* Bypass Enable */
#define REF_2_BYP                    (* (reg8 *) REF_2__BYP)
/* Port wide control signals */                                                   
#define REF_2_CTL                    (* (reg8 *) REF_2__CTL)
/* Drive Modes */
#define REF_2_DM0                    (* (reg8 *) REF_2__DM0) 
#define REF_2_DM1                    (* (reg8 *) REF_2__DM1)
#define REF_2_DM2                    (* (reg8 *) REF_2__DM2) 
/* Input Buffer Disable Override */
#define REF_2_INP_DIS                (* (reg8 *) REF_2__INP_DIS)
/* LCD Common or Segment Drive */
#define REF_2_LCD_COM_SEG            (* (reg8 *) REF_2__LCD_COM_SEG)
/* Enable Segment LCD */
#define REF_2_LCD_EN                 (* (reg8 *) REF_2__LCD_EN)
/* Slew Rate Control */
#define REF_2_SLW                    (* (reg8 *) REF_2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define REF_2_PRTDSI__CAPS_SEL       (* (reg8 *) REF_2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define REF_2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) REF_2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define REF_2_PRTDSI__OE_SEL0        (* (reg8 *) REF_2__PRTDSI__OE_SEL0) 
#define REF_2_PRTDSI__OE_SEL1        (* (reg8 *) REF_2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define REF_2_PRTDSI__OUT_SEL0       (* (reg8 *) REF_2__PRTDSI__OUT_SEL0) 
#define REF_2_PRTDSI__OUT_SEL1       (* (reg8 *) REF_2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define REF_2_PRTDSI__SYNC_OUT       (* (reg8 *) REF_2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(REF_2__SIO_CFG)
    #define REF_2_SIO_HYST_EN        (* (reg8 *) REF_2__SIO_HYST_EN)
    #define REF_2_SIO_REG_HIFREQ     (* (reg8 *) REF_2__SIO_REG_HIFREQ)
    #define REF_2_SIO_CFG            (* (reg8 *) REF_2__SIO_CFG)
    #define REF_2_SIO_DIFF           (* (reg8 *) REF_2__SIO_DIFF)
#endif /* (REF_2__SIO_CFG) */

/* Interrupt Registers */
#if defined(REF_2__INTSTAT)
    #define REF_2_INTSTAT            (* (reg8 *) REF_2__INTSTAT)
    #define REF_2_SNAP               (* (reg8 *) REF_2__SNAP)
    
	#define REF_2_0_INTTYPE_REG 		(* (reg8 *) REF_2__0__INTTYPE)
#endif /* (REF_2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_REF_2_H */


/* [] END OF FILE */
