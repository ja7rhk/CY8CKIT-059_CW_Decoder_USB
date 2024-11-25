/*******************************************************************************
* File Name: MONITOR2.h  
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

#if !defined(CY_PINS_MONITOR2_H) /* Pins MONITOR2_H */
#define CY_PINS_MONITOR2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MONITOR2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MONITOR2__PORT == 15 && ((MONITOR2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MONITOR2_Write(uint8 value);
void    MONITOR2_SetDriveMode(uint8 mode);
uint8   MONITOR2_ReadDataReg(void);
uint8   MONITOR2_Read(void);
void    MONITOR2_SetInterruptMode(uint16 position, uint16 mode);
uint8   MONITOR2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MONITOR2_SetDriveMode() function.
     *  @{
     */
        #define MONITOR2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MONITOR2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MONITOR2_DM_RES_UP          PIN_DM_RES_UP
        #define MONITOR2_DM_RES_DWN         PIN_DM_RES_DWN
        #define MONITOR2_DM_OD_LO           PIN_DM_OD_LO
        #define MONITOR2_DM_OD_HI           PIN_DM_OD_HI
        #define MONITOR2_DM_STRONG          PIN_DM_STRONG
        #define MONITOR2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MONITOR2_MASK               MONITOR2__MASK
#define MONITOR2_SHIFT              MONITOR2__SHIFT
#define MONITOR2_WIDTH              1u

/* Interrupt constants */
#if defined(MONITOR2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MONITOR2_SetInterruptMode() function.
     *  @{
     */
        #define MONITOR2_INTR_NONE      (uint16)(0x0000u)
        #define MONITOR2_INTR_RISING    (uint16)(0x0001u)
        #define MONITOR2_INTR_FALLING   (uint16)(0x0002u)
        #define MONITOR2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MONITOR2_INTR_MASK      (0x01u) 
#endif /* (MONITOR2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MONITOR2_PS                     (* (reg8 *) MONITOR2__PS)
/* Data Register */
#define MONITOR2_DR                     (* (reg8 *) MONITOR2__DR)
/* Port Number */
#define MONITOR2_PRT_NUM                (* (reg8 *) MONITOR2__PRT) 
/* Connect to Analog Globals */                                                  
#define MONITOR2_AG                     (* (reg8 *) MONITOR2__AG)                       
/* Analog MUX bux enable */
#define MONITOR2_AMUX                   (* (reg8 *) MONITOR2__AMUX) 
/* Bidirectional Enable */                                                        
#define MONITOR2_BIE                    (* (reg8 *) MONITOR2__BIE)
/* Bit-mask for Aliased Register Access */
#define MONITOR2_BIT_MASK               (* (reg8 *) MONITOR2__BIT_MASK)
/* Bypass Enable */
#define MONITOR2_BYP                    (* (reg8 *) MONITOR2__BYP)
/* Port wide control signals */                                                   
#define MONITOR2_CTL                    (* (reg8 *) MONITOR2__CTL)
/* Drive Modes */
#define MONITOR2_DM0                    (* (reg8 *) MONITOR2__DM0) 
#define MONITOR2_DM1                    (* (reg8 *) MONITOR2__DM1)
#define MONITOR2_DM2                    (* (reg8 *) MONITOR2__DM2) 
/* Input Buffer Disable Override */
#define MONITOR2_INP_DIS                (* (reg8 *) MONITOR2__INP_DIS)
/* LCD Common or Segment Drive */
#define MONITOR2_LCD_COM_SEG            (* (reg8 *) MONITOR2__LCD_COM_SEG)
/* Enable Segment LCD */
#define MONITOR2_LCD_EN                 (* (reg8 *) MONITOR2__LCD_EN)
/* Slew Rate Control */
#define MONITOR2_SLW                    (* (reg8 *) MONITOR2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MONITOR2_PRTDSI__CAPS_SEL       (* (reg8 *) MONITOR2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MONITOR2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MONITOR2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MONITOR2_PRTDSI__OE_SEL0        (* (reg8 *) MONITOR2__PRTDSI__OE_SEL0) 
#define MONITOR2_PRTDSI__OE_SEL1        (* (reg8 *) MONITOR2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MONITOR2_PRTDSI__OUT_SEL0       (* (reg8 *) MONITOR2__PRTDSI__OUT_SEL0) 
#define MONITOR2_PRTDSI__OUT_SEL1       (* (reg8 *) MONITOR2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MONITOR2_PRTDSI__SYNC_OUT       (* (reg8 *) MONITOR2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MONITOR2__SIO_CFG)
    #define MONITOR2_SIO_HYST_EN        (* (reg8 *) MONITOR2__SIO_HYST_EN)
    #define MONITOR2_SIO_REG_HIFREQ     (* (reg8 *) MONITOR2__SIO_REG_HIFREQ)
    #define MONITOR2_SIO_CFG            (* (reg8 *) MONITOR2__SIO_CFG)
    #define MONITOR2_SIO_DIFF           (* (reg8 *) MONITOR2__SIO_DIFF)
#endif /* (MONITOR2__SIO_CFG) */

/* Interrupt Registers */
#if defined(MONITOR2__INTSTAT)
    #define MONITOR2_INTSTAT            (* (reg8 *) MONITOR2__INTSTAT)
    #define MONITOR2_SNAP               (* (reg8 *) MONITOR2__SNAP)
    
	#define MONITOR2_0_INTTYPE_REG 		(* (reg8 *) MONITOR2__0__INTTYPE)
#endif /* (MONITOR2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MONITOR2_H */


/* [] END OF FILE */
