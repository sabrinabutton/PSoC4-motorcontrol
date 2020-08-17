/*******************************************************************************
* File Name: dirA.h  
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

#if !defined(CY_PINS_dirA_ALIASES_H) /* Pins dirA_ALIASES_H */
#define CY_PINS_dirA_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define dirA_0			(dirA__0__PC)
#define dirA_0_PS		(dirA__0__PS)
#define dirA_0_PC		(dirA__0__PC)
#define dirA_0_DR		(dirA__0__DR)
#define dirA_0_SHIFT	(dirA__0__SHIFT)
#define dirA_0_INTR	((uint16)((uint16)0x0003u << (dirA__0__SHIFT*2u)))

#define dirA_INTR_ALL	 ((uint16)(dirA_0_INTR))


#endif /* End Pins dirA_ALIASES_H */


/* [] END OF FILE */
