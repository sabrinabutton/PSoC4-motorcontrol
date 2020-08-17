/*******************************************************************************
* File Name: pwmA.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_pwmA_ALIASES_H) /* Pins pwmA_ALIASES_H */
#define CY_PINS_pwmA_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define pwmA_0			(pwmA__0__PC)
#define pwmA_0_PS		(pwmA__0__PS)
#define pwmA_0_PC		(pwmA__0__PC)
#define pwmA_0_DR		(pwmA__0__DR)
#define pwmA_0_SHIFT	(pwmA__0__SHIFT)
#define pwmA_0_INTR	((uint16)((uint16)0x0003u << (pwmA__0__SHIFT*2u)))

#define pwmA_INTR_ALL	 ((uint16)(pwmA_0_INTR))


#endif /* End Pins pwmA_ALIASES_H */


/* [] END OF FILE */
