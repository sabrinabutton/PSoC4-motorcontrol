/*******************************************************************************
* File Name: dirA.h  
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

#if !defined(CY_PINS_dirA_H) /* Pins dirA_H */
#define CY_PINS_dirA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "dirA_aliases.h"


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
} dirA_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   dirA_Read(void);
void    dirA_Write(uint8 value);
uint8   dirA_ReadDataReg(void);
#if defined(dirA__PC) || (CY_PSOC4_4200L) 
    void    dirA_SetDriveMode(uint8 mode);
#endif
void    dirA_SetInterruptMode(uint16 position, uint16 mode);
uint8   dirA_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void dirA_Sleep(void); 
void dirA_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(dirA__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define dirA_DRIVE_MODE_BITS        (3)
    #define dirA_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - dirA_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the dirA_SetDriveMode() function.
         *  @{
         */
        #define dirA_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define dirA_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define dirA_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define dirA_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define dirA_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define dirA_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define dirA_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define dirA_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define dirA_MASK               dirA__MASK
#define dirA_SHIFT              dirA__SHIFT
#define dirA_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in dirA_SetInterruptMode() function.
     *  @{
     */
        #define dirA_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define dirA_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define dirA_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define dirA_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(dirA__SIO)
    #define dirA_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(dirA__PC) && (CY_PSOC4_4200L)
    #define dirA_USBIO_ENABLE               ((uint32)0x80000000u)
    #define dirA_USBIO_DISABLE              ((uint32)(~dirA_USBIO_ENABLE))
    #define dirA_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define dirA_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define dirA_USBIO_ENTER_SLEEP          ((uint32)((1u << dirA_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << dirA_USBIO_SUSPEND_DEL_SHIFT)))
    #define dirA_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << dirA_USBIO_SUSPEND_SHIFT)))
    #define dirA_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << dirA_USBIO_SUSPEND_DEL_SHIFT)))
    #define dirA_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(dirA__PC)
    /* Port Configuration */
    #define dirA_PC                 (* (reg32 *) dirA__PC)
#endif
/* Pin State */
#define dirA_PS                     (* (reg32 *) dirA__PS)
/* Data Register */
#define dirA_DR                     (* (reg32 *) dirA__DR)
/* Input Buffer Disable Override */
#define dirA_INP_DIS                (* (reg32 *) dirA__PC2)

/* Interrupt configuration Registers */
#define dirA_INTCFG                 (* (reg32 *) dirA__INTCFG)
#define dirA_INTSTAT                (* (reg32 *) dirA__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define dirA_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(dirA__SIO)
    #define dirA_SIO_REG            (* (reg32 *) dirA__SIO)
#endif /* (dirA__SIO_CFG) */

/* USBIO registers */
#if !defined(dirA__PC) && (CY_PSOC4_4200L)
    #define dirA_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define dirA_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define dirA_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define dirA_DRIVE_MODE_SHIFT       (0x00u)
#define dirA_DRIVE_MODE_MASK        (0x07u << dirA_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins dirA_H */


/* [] END OF FILE */
