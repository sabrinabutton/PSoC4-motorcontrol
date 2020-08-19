/* ========================================
 *
 * Copyright SABRINA BUTTON, 2020
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF SABRINA BUTTON.
 *
 * ========================================*/

#include "project.h"
#ifndef MotorController_h
#define MotorController_h
    
    
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
    
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })  
   
struct MotorController
{
    
    //pulse width modulation (pwm) and direction (dir) inputs for left (L) and right (R) motors
    void(*_pwmL_Write)(uint8); 
    void(*_pwmR_Write)(uint8); 
    void(*_dirL_Write)(uint8); 
    void(*_dirR_Write)(uint8); 
    
    //struct *_pwmL,*_dirL, *_pwmR, *_dirR;
    //current net speed 
    int _currentSpeed;
};

void adjMove(struct MotorController mc, uint8* speed, uint8* dir){
    if(*speed != mc._currentSpeed){
        //if speed changes, update motor speed
        mc._currentSpeed = *speed;
        
        if(speed < 0){
            *dir = 1;
            *speed = min(*speed, 0);
            *speed = max(*speed, -255);
            
            if(*speed > -6) {*speed = 0; dir = 0;}
		    else {*speed = 255 + *speed;}
        }
        
        else{ // fastest speed is 255 which is 255
		    *dir = 0;
            *speed = max(*speed, 0); //70
            *speed = min(*speed, 255);
			//speed = map(speed,0,255,_minPosSpeed,255);
			if(*speed < 6) {*speed = 0; *dir = 0;}
        }
    }
 
}

void move(struct MotorController mc, uint8 speedA, uint8 speedB){
    uint8 dirA, dirB;
    
    //adjust movements for left and right wheel
    adjMove(mc, &speedA, &dirA);
    adjMove(mc, &speedB, &dirB);
    
    //write to the pins via pointer functions on passed mc
    (*mc._dirL_Write)(dirA);
    (*mc._dirR_Write)(dirB);
    (*mc._pwmL_Write)(speedA);
    (*mc._pwmR_Write)(speedB);
}

void stopMoving(struct MotorController mc){
    //write to the pins via pointers
   (*mc._dirL_Write)(1);
   (*mc._dirR_Write)(1);
   (*mc._pwmL_Write)(1);
   (*mc._pwmR_Write)(1);
    
    //reset speed to 0
    mc._currentSpeed = 0;
}

#endif

/* [] END OF FILE */
