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

#define STOP 0
#define WAIT_STOP 1
#define FORWARD 2
#define MOVE_FORWARD 3
#define LEFT 4
#define TURN_LEFT 5
#define RIGHT 6
#define TURN_RIGHT 7

uint8 state;
int move_cnt;

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
    CyDelay(50);
    switch (state)
       {
        case STOP:  //Statements to execute
          move_cnt = 100;
          move(mc, 0,0);
          state = WAIT_STOP;

          break;
        case WAIT_STOP:
          move_cnt--;
          if(move_cnt == 0) {
             state = FORWARD;
          }
          break;
        case FORWARD:   //Statements to execute
          move_cnt = 100;
          move(mc, 255,255);
          state = MOVE_FORWARD;

          break;
        case MOVE_FORWARD:   //Statements to execute
          move_cnt--;
          // if == zero - then go forward
          if(move_cnt == 0) {
             state = LEFT;
          }
          break;
        case LEFT:
          move_cnt = 100;
          move(mc, 255,0);
          state = TURN_LEFT;

          break;
        case TURN_LEFT:
          // decrement turn counter
          move_cnt--;
          // if == zero - then go forward
          if(move_cnt == 0) {
             state = RIGHT;
          } 
         break;
        case RIGHT:
          move_cnt = 100;
          move(mc, 0,255);
          state = TURN_RIGHT;

          break;
        case TURN_RIGHT:
          // decrement turn counter
          move_cnt--;
          // if == zero - then go forward
          if(move_cnt == 0) {
             state = FORWARD;
          } 
         break;
       default:
         break;
      }
        
    }
}

/* [] END OF FILE */
