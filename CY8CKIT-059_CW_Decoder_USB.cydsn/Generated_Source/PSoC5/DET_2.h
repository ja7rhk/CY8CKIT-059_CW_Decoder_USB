/*******************************************************************************
* File Name: DET_2.h  
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

#if !defined(CY_PINS_DET_2_H) /* Pins DET_2_H */
#define CY_PINS_DET_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DET_2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DET_2__PORT == 15 && ((DET_2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DET_2_Write(uint8 value);
void    DET_2_SetDriveMode(uint8 mode);
uint8   DET_2_ReadDataReg(void);
uint8   DET_2_Read(void);
void    DET_2_SetInterruptMode(uint16 position, uint16 mode);
uint8   DET_2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DET_2_SetDriveMode() function.
     *  @{
     */
        #define DET_2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DET_2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DET_2_DM_RES_UP          PIN_DM_RES_UP
        #define DET_2_DM_RES_DWN         PIN_DM_RES_DWN
        #define DET_2_DM_OD_LO           PIN_DM_OD_LO
        #define DET_2_DM_OD_HI           PIN_DM_OD_HI
        #define DET_2_DM_STRONG          PIN_DM_STRONG
        #define DET_2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DET_2_MASK               DET_2__MASK
#define DET_2_SHIFT              DET_2__SHIFT
#define DET_2_WIDTH              1u

/* Interrupt constants */
#if defined(DET_2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DET_2_SetInterruptMode() function.
     *  @{
     */
        #define DET_2_INTR_NONE      (uint16)(0x0000u)
        #define DET_2_INTR_RISING    (uint16)(0x0001u)
        #define DET_2_INTR_FALLING   (uint16)(0x0002u)
        #define DET_2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DET_2_INTR_MASK      (0x01u) 
#endif /* (DET_2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DET_2_PS                     (* (reg8 *) DET_2__PS)
/* Data Register */
#define DET_2_DR                     (* (reg8 *) DET_2__DR)
/* Port Number */
#define DET_2_PRT_NUM                (* (reg8 *) DET_2__PRT) 
/* Connect to Analog Globals */                                                  
#define DET_2_AG                     (* (reg8 *) DET_2__AG)                       
/* Analog MUX bux enable */
#define DET_2_AMUX                   (* (reg8 *) DET_2__AMUX) 
/* Bidirectional Enable */                                                        
#define DET_2_BIE                    (* (reg8 *) DET_2__BIE)
/* Bit-mask for Aliased Register Access */
#define DET_2_BIT_MASK               (* (reg8 *) DET_2__BIT_MASK)
/* Bypass Enable */
#define DET_2_BYP                    (* (reg8 *) DET_2__BYP)
/* Port wide control signals */                                                   
#define DET_2_CTL                    (* (reg8 *) DET_2__CTL)
/* Drive Modes */
#define DET_2_DM0                    (* (reg8 *) DET_2__DM0) 
#define DET_2_DM1                    (* (reg8 *) DET_2__DM1)
#define DET_2_DM2                    (* (reg8 *) DET_2__DM2) 
/* Input Buffer Disable Override */
#define DET_2_INP_DIS                (* (reg8 *) DET_2__INP_DIS)
/* LCD Common or Segment Drive */
#define DET_2_LCD_COM_SEG            (* (reg8 *) DET_2__LCD_COM_SEG)
/* Enable Segment LCD */
#define DET_2_LCD_EN                 (* (reg8 *) DET_2__LCD_EN)
/* Slew Rate Control */
#define DET_2_SLW                    (* (reg8 *) DET_2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DET_2_PRTDSI__CAPS_SEL       (* (reg8 *) DET_2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DET_2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DET_2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DET_2_PRTDSI__OE_SEL0        (* (reg8 *) DET_2__PRTDSI__OE_SEL0) 
#define DET_2_PRTDSI__OE_SEL1        (* (reg8 *) DET_2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DET_2_PRTDSI__OUT_SEL0       (* (reg8 *) DET_2__PRTDSI__OUT_SEL0) 
#define DET_2_PRTDSI__OUT_SEL1       (* (reg8 *) DET_2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DET_2_PRTDSI__SYNC_OUT       (* (reg8 *) DET_2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DET_2__SIO_CFG)
    #define DET_2_SIO_HYST_EN        (* (reg8 *) DET_2__SIO_HYST_EN)
    #define DET_2_SIO_REG_HIFREQ     (* (reg8 *) DET_2__SIO_REG_HIFREQ)
    #define DET_2_SIO_CFG            (* (reg8 *) DET_2__SIO_CFG)
    #define DET_2_SIO_DIFF           (* (reg8 *) DET_2__SIO_DIFF)
#endif /* (DET_2__SIO_CFG) */

/* Interrupt Registers */
#if defined(DET_2__INTSTAT)
    #define DET_2_INTSTAT            (* (reg8 *) DET_2__INTSTAT)
    #define DET_2_SNAP               (* (reg8 *) DET_2__SNAP)
    
	#define DET_2_0_INTTYPE_REG 		(* (reg8 *) DET_2__0__INTTYPE)
#endif /* (DET_2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DET_2_H */


/* [] END OF FILE */
