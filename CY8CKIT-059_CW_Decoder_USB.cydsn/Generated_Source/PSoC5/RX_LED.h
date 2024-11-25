/*******************************************************************************
* File Name: RX_LED.h  
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

#if !defined(CY_PINS_RX_LED_H) /* Pins RX_LED_H */
#define CY_PINS_RX_LED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RX_LED_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RX_LED__PORT == 15 && ((RX_LED__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RX_LED_Write(uint8 value);
void    RX_LED_SetDriveMode(uint8 mode);
uint8   RX_LED_ReadDataReg(void);
uint8   RX_LED_Read(void);
void    RX_LED_SetInterruptMode(uint16 position, uint16 mode);
uint8   RX_LED_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RX_LED_SetDriveMode() function.
     *  @{
     */
        #define RX_LED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RX_LED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RX_LED_DM_RES_UP          PIN_DM_RES_UP
        #define RX_LED_DM_RES_DWN         PIN_DM_RES_DWN
        #define RX_LED_DM_OD_LO           PIN_DM_OD_LO
        #define RX_LED_DM_OD_HI           PIN_DM_OD_HI
        #define RX_LED_DM_STRONG          PIN_DM_STRONG
        #define RX_LED_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RX_LED_MASK               RX_LED__MASK
#define RX_LED_SHIFT              RX_LED__SHIFT
#define RX_LED_WIDTH              1u

/* Interrupt constants */
#if defined(RX_LED__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RX_LED_SetInterruptMode() function.
     *  @{
     */
        #define RX_LED_INTR_NONE      (uint16)(0x0000u)
        #define RX_LED_INTR_RISING    (uint16)(0x0001u)
        #define RX_LED_INTR_FALLING   (uint16)(0x0002u)
        #define RX_LED_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RX_LED_INTR_MASK      (0x01u) 
#endif /* (RX_LED__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RX_LED_PS                     (* (reg8 *) RX_LED__PS)
/* Data Register */
#define RX_LED_DR                     (* (reg8 *) RX_LED__DR)
/* Port Number */
#define RX_LED_PRT_NUM                (* (reg8 *) RX_LED__PRT) 
/* Connect to Analog Globals */                                                  
#define RX_LED_AG                     (* (reg8 *) RX_LED__AG)                       
/* Analog MUX bux enable */
#define RX_LED_AMUX                   (* (reg8 *) RX_LED__AMUX) 
/* Bidirectional Enable */                                                        
#define RX_LED_BIE                    (* (reg8 *) RX_LED__BIE)
/* Bit-mask for Aliased Register Access */
#define RX_LED_BIT_MASK               (* (reg8 *) RX_LED__BIT_MASK)
/* Bypass Enable */
#define RX_LED_BYP                    (* (reg8 *) RX_LED__BYP)
/* Port wide control signals */                                                   
#define RX_LED_CTL                    (* (reg8 *) RX_LED__CTL)
/* Drive Modes */
#define RX_LED_DM0                    (* (reg8 *) RX_LED__DM0) 
#define RX_LED_DM1                    (* (reg8 *) RX_LED__DM1)
#define RX_LED_DM2                    (* (reg8 *) RX_LED__DM2) 
/* Input Buffer Disable Override */
#define RX_LED_INP_DIS                (* (reg8 *) RX_LED__INP_DIS)
/* LCD Common or Segment Drive */
#define RX_LED_LCD_COM_SEG            (* (reg8 *) RX_LED__LCD_COM_SEG)
/* Enable Segment LCD */
#define RX_LED_LCD_EN                 (* (reg8 *) RX_LED__LCD_EN)
/* Slew Rate Control */
#define RX_LED_SLW                    (* (reg8 *) RX_LED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RX_LED_PRTDSI__CAPS_SEL       (* (reg8 *) RX_LED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RX_LED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RX_LED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RX_LED_PRTDSI__OE_SEL0        (* (reg8 *) RX_LED__PRTDSI__OE_SEL0) 
#define RX_LED_PRTDSI__OE_SEL1        (* (reg8 *) RX_LED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RX_LED_PRTDSI__OUT_SEL0       (* (reg8 *) RX_LED__PRTDSI__OUT_SEL0) 
#define RX_LED_PRTDSI__OUT_SEL1       (* (reg8 *) RX_LED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RX_LED_PRTDSI__SYNC_OUT       (* (reg8 *) RX_LED__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RX_LED__SIO_CFG)
    #define RX_LED_SIO_HYST_EN        (* (reg8 *) RX_LED__SIO_HYST_EN)
    #define RX_LED_SIO_REG_HIFREQ     (* (reg8 *) RX_LED__SIO_REG_HIFREQ)
    #define RX_LED_SIO_CFG            (* (reg8 *) RX_LED__SIO_CFG)
    #define RX_LED_SIO_DIFF           (* (reg8 *) RX_LED__SIO_DIFF)
#endif /* (RX_LED__SIO_CFG) */

/* Interrupt Registers */
#if defined(RX_LED__INTSTAT)
    #define RX_LED_INTSTAT            (* (reg8 *) RX_LED__INTSTAT)
    #define RX_LED_SNAP               (* (reg8 *) RX_LED__SNAP)
    
	#define RX_LED_0_INTTYPE_REG 		(* (reg8 *) RX_LED__0__INTTYPE)
#endif /* (RX_LED__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RX_LED_H */


/* [] END OF FILE */
