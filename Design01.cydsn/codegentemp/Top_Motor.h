/*******************************************************************************
* File Name: Top_Motor.h  
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

#if !defined(CY_PINS_Top_Motor_H) /* Pins Top_Motor_H */
#define CY_PINS_Top_Motor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Top_Motor_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Top_Motor__PORT == 15 && ((Top_Motor__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Top_Motor_Write(uint8 value);
void    Top_Motor_SetDriveMode(uint8 mode);
uint8   Top_Motor_ReadDataReg(void);
uint8   Top_Motor_Read(void);
void    Top_Motor_SetInterruptMode(uint16 position, uint16 mode);
uint8   Top_Motor_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Top_Motor_SetDriveMode() function.
     *  @{
     */
        #define Top_Motor_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Top_Motor_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Top_Motor_DM_RES_UP          PIN_DM_RES_UP
        #define Top_Motor_DM_RES_DWN         PIN_DM_RES_DWN
        #define Top_Motor_DM_OD_LO           PIN_DM_OD_LO
        #define Top_Motor_DM_OD_HI           PIN_DM_OD_HI
        #define Top_Motor_DM_STRONG          PIN_DM_STRONG
        #define Top_Motor_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Top_Motor_MASK               Top_Motor__MASK
#define Top_Motor_SHIFT              Top_Motor__SHIFT
#define Top_Motor_WIDTH              1u

/* Interrupt constants */
#if defined(Top_Motor__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Top_Motor_SetInterruptMode() function.
     *  @{
     */
        #define Top_Motor_INTR_NONE      (uint16)(0x0000u)
        #define Top_Motor_INTR_RISING    (uint16)(0x0001u)
        #define Top_Motor_INTR_FALLING   (uint16)(0x0002u)
        #define Top_Motor_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Top_Motor_INTR_MASK      (0x01u) 
#endif /* (Top_Motor__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Top_Motor_PS                     (* (reg8 *) Top_Motor__PS)
/* Data Register */
#define Top_Motor_DR                     (* (reg8 *) Top_Motor__DR)
/* Port Number */
#define Top_Motor_PRT_NUM                (* (reg8 *) Top_Motor__PRT) 
/* Connect to Analog Globals */                                                  
#define Top_Motor_AG                     (* (reg8 *) Top_Motor__AG)                       
/* Analog MUX bux enable */
#define Top_Motor_AMUX                   (* (reg8 *) Top_Motor__AMUX) 
/* Bidirectional Enable */                                                        
#define Top_Motor_BIE                    (* (reg8 *) Top_Motor__BIE)
/* Bit-mask for Aliased Register Access */
#define Top_Motor_BIT_MASK               (* (reg8 *) Top_Motor__BIT_MASK)
/* Bypass Enable */
#define Top_Motor_BYP                    (* (reg8 *) Top_Motor__BYP)
/* Port wide control signals */                                                   
#define Top_Motor_CTL                    (* (reg8 *) Top_Motor__CTL)
/* Drive Modes */
#define Top_Motor_DM0                    (* (reg8 *) Top_Motor__DM0) 
#define Top_Motor_DM1                    (* (reg8 *) Top_Motor__DM1)
#define Top_Motor_DM2                    (* (reg8 *) Top_Motor__DM2) 
/* Input Buffer Disable Override */
#define Top_Motor_INP_DIS                (* (reg8 *) Top_Motor__INP_DIS)
/* LCD Common or Segment Drive */
#define Top_Motor_LCD_COM_SEG            (* (reg8 *) Top_Motor__LCD_COM_SEG)
/* Enable Segment LCD */
#define Top_Motor_LCD_EN                 (* (reg8 *) Top_Motor__LCD_EN)
/* Slew Rate Control */
#define Top_Motor_SLW                    (* (reg8 *) Top_Motor__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Top_Motor_PRTDSI__CAPS_SEL       (* (reg8 *) Top_Motor__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Top_Motor_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Top_Motor__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Top_Motor_PRTDSI__OE_SEL0        (* (reg8 *) Top_Motor__PRTDSI__OE_SEL0) 
#define Top_Motor_PRTDSI__OE_SEL1        (* (reg8 *) Top_Motor__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Top_Motor_PRTDSI__OUT_SEL0       (* (reg8 *) Top_Motor__PRTDSI__OUT_SEL0) 
#define Top_Motor_PRTDSI__OUT_SEL1       (* (reg8 *) Top_Motor__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Top_Motor_PRTDSI__SYNC_OUT       (* (reg8 *) Top_Motor__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Top_Motor__SIO_CFG)
    #define Top_Motor_SIO_HYST_EN        (* (reg8 *) Top_Motor__SIO_HYST_EN)
    #define Top_Motor_SIO_REG_HIFREQ     (* (reg8 *) Top_Motor__SIO_REG_HIFREQ)
    #define Top_Motor_SIO_CFG            (* (reg8 *) Top_Motor__SIO_CFG)
    #define Top_Motor_SIO_DIFF           (* (reg8 *) Top_Motor__SIO_DIFF)
#endif /* (Top_Motor__SIO_CFG) */

/* Interrupt Registers */
#if defined(Top_Motor__INTSTAT)
    #define Top_Motor_INTSTAT            (* (reg8 *) Top_Motor__INTSTAT)
    #define Top_Motor_SNAP               (* (reg8 *) Top_Motor__SNAP)
    
	#define Top_Motor_0_INTTYPE_REG 		(* (reg8 *) Top_Motor__0__INTTYPE)
#endif /* (Top_Motor__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Top_Motor_H */


/* [] END OF FILE */
