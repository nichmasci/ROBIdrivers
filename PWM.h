/******************************************************************
 * This should be the second set of files that each student should
 * work with.  I have provided the function prototypes (may not have
 * all of them) and students are responsible for creating the .c file
 * for this .h
 * 
 * Students should have completed the i2c.h and i2c.c file prior
 * to starting this file.
 * 
 * Again, students should be viewing the Python library as a guide
 * to writing this one.
 * 
 * This library will be needed by the MotorHat.h library.
******************************************************************/
#include<stdio.h>
#include<bcm2835.h>
#include<math.h>
#include"I2C.h"

#ifndef PWM
#define PWM

//Registers

#define __MODE1			0x00
#define __MODE2 		0x01
#define __SUBADR1 		0x02
#define __SUBADR2		0x03
#define __SUBADR3		0x04
#define __PRESCALE		0xFE
#define __LED0_ON_L		0x06
#define __LED0_ON_H		0x07
#define __LED0_OFF_L	0x08
#define __LED0_OFF_H	0x09
#define __ALL_LED_ON_L	0xFA
#define __ALL_LED_ON_H	0xFB
#define __ALL_LED_OFF_L	0XFC
#define __ALL_LED_OFF_H 0xFD

// Bits

#define __RESTART		0x80
#define __SLEEP			0x10
#define __ALLCALL		0x01
#define __INVRT			0x10
#define __OUTDRV		0x04


void setAllPWM(int on, int off);
/*==============================================================
* This function will send a command to all channels at once
* on ROBI. It is useful for sending a RELEASE to all motors,
* but I preferred to set them all individually.
\*============================================================*/

void PWMInit(unsigned int address);
/*==============================================================
* This function initializes an I2C connection on the given
* address and prepares it to receive PWM communications. This
* is used by initHat in MotorHat.c, and initServo in Servo.c.
* It will likely not need to be called directly.
\*============================================================*/

void setPWMFreq(int freq);
/*==============================================================
* This function sets the PWM frequency to the frequency given
* to it. This is important, as the motors and the servo both
* use different frequencies to communicate with the Pi. It is
* not called directly, but instead used by the various init
* functions.
\*============================================================*/

void setPWM(int channel, int on, int off);
/*==============================================================
* This function sends a command to a specific PWM channel,
* which is helpful for controlling Robi's motors individually.
* It will not be called directly, but is instead used in other
* functions to streamline control of Robi.
\*============================================================*/

#endif
