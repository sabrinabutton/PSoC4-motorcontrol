/*******************************************************************************
* File Name: dirB.h  
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

#if !defined(CY_PINS_dirB_ALIASES_H) /* Pins dirB_ALIASES_H */
#define CY_PINS_dirB_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define dirB_0			(dirB__0__PC)
#define dirB_0_PS		(dirB__0__PS)
#define dirB_0_PC		(dirB__0__PC)
#define dirB_0_DR		(dirB__0__DR)
#define dirB_0_SHIFT	(dirB__0__SHIFT)
#define dirB_0_INTR	((uint16)((uint16)0x0003u << (dirB__0__SHIFT*2u)))

#define dirB_INTR_ALL	 ((uint16)(dirB_0_INTR))


#endif /* End Pins dirB_ALIASES_H */


/* [] END OF FILE */
