/*******************************************************************************
* File Name: pwmB.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "pwmB.h"

static pwmB_BACKUP_STRUCT  pwmB_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: pwmB_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet pwmB_SUT.c usage_pwmB_Sleep_Wakeup
*******************************************************************************/
void pwmB_Sleep(void)
{
    #if defined(pwmB__PC)
        pwmB_backup.pcState = pwmB_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            pwmB_backup.usbState = pwmB_CR1_REG;
            pwmB_USB_POWER_REG |= pwmB_USBIO_ENTER_SLEEP;
            pwmB_CR1_REG &= pwmB_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(pwmB__SIO)
        pwmB_backup.sioState = pwmB_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        pwmB_SIO_REG &= (uint32)(~pwmB_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: pwmB_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to pwmB_Sleep() for an example usage.
*******************************************************************************/
void pwmB_Wakeup(void)
{
    #if defined(pwmB__PC)
        pwmB_PC = pwmB_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            pwmB_USB_POWER_REG &= pwmB_USBIO_EXIT_SLEEP_PH1;
            pwmB_CR1_REG = pwmB_backup.usbState;
            pwmB_USB_POWER_REG &= pwmB_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(pwmB__SIO)
        pwmB_SIO_REG = pwmB_backup.sioState;
    #endif
}


/* [] END OF FILE */
