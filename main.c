/* ========================================
 *
 * Copyright SABRINA BUTTON, 2020
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF SABRINA BUTTON.
 *
 * ========================================
*/
#include "project.h"
#include "control.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
   struct  MotorController mc;
    
   mc._pwmL_Write = &pwmA_Write;
   mc._pwmR_Write = &pwmB_Write;
   mc._dirL_Write = &dirA_Write;
   mc._dirR_Write = &dirB_Write;
    
    
    for(;;)
    {
        /* Place your application code here. */
        BlueLED_Write(1);
        moveTog(mc, 255);
        CyDelay(5000);
        
        BlueLED_Write(0);
        stopMoving(mc);
        CyDelay(5000);
    }
}

/* [] END OF FILE */
