/*******************************************************************************
* File Name: pwmB.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_pwmB_H) /* Pins pwmB_H */
#define CY_PINS_pwmB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pwmB_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} pwmB_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   pwmB_Read(void);
void    pwmB_Write(uint8 value);
uint8   pwmB_ReadDataReg(void);
#if defined(pwmB__PC) || (CY_PSOC4_4200L) 
    void    pwmB_SetDriveMode(uint8 mode);
#endif
void    pwmB_SetInterruptMode(uint16 position, uint16 mode);
uint8   pwmB_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void pwmB_Sleep(void); 
void pwmB_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(pwmB__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define pwmB_DRIVE_MODE_BITS        (3)
    #define pwmB_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pwmB_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the pwmB_SetDriveMode() function.
         *  @{
         */
        #define pwmB_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define pwmB_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define pwmB_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define pwmB_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define pwmB_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define pwmB_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define pwmB_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define pwmB_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define pwmB_MASK               pwmB__MASK
#define pwmB_SHIFT              pwmB__SHIFT
#define pwmB_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pwmB_SetInterruptMode() function.
     *  @{
     */
        #define pwmB_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define pwmB_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define pwmB_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define pwmB_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(pwmB__SIO)
    #define pwmB_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(pwmB__PC) && (CY_PSOC4_4200L)
    #define pwmB_USBIO_ENABLE               ((uint32)0x80000000u)
    #define pwmB_USBIO_DISABLE              ((uint32)(~pwmB_USBIO_ENABLE))
    #define pwmB_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define pwmB_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define pwmB_USBIO_ENTER_SLEEP          ((uint32)((1u << pwmB_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << pwmB_USBIO_SUSPEND_DEL_SHIFT)))
    #define pwmB_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << pwmB_USBIO_SUSPEND_SHIFT)))
    #define pwmB_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << pwmB_USBIO_SUSPEND_DEL_SHIFT)))
    #define pwmB_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(pwmB__PC)
    /* Port Configuration */
    #define pwmB_PC                 (* (reg32 *) pwmB__PC)
#endif
/* Pin State */
#define pwmB_PS                     (* (reg32 *) pwmB__PS)
/* Data Register */
#define pwmB_DR                     (* (reg32 *) pwmB__DR)
/* Input Buffer Disable Override */
#define pwmB_INP_DIS                (* (reg32 *) pwmB__PC2)

/* Interrupt configuration Registers */
#define pwmB_INTCFG                 (* (reg32 *) pwmB__INTCFG)
#define pwmB_INTSTAT                (* (reg32 *) pwmB__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define pwmB_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(pwmB__SIO)
    #define pwmB_SIO_REG            (* (reg32 *) pwmB__SIO)
#endif /* (pwmB__SIO_CFG) */

/* USBIO registers */
#if !defined(pwmB__PC) && (CY_PSOC4_4200L)
    #define pwmB_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define pwmB_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define pwmB_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define pwmB_DRIVE_MODE_SHIFT       (0x00u)
#define pwmB_DRIVE_MODE_MASK        (0x07u << pwmB_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins pwmB_H */


/* [] END OF FILE */
