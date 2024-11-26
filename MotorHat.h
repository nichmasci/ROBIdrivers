#include<stdio.h>
#include<bcm2835.h>
#include"PWM.h"

#ifndef MOTOR_HAT
#define MOTOR_HAT

typedef struct MOTOR{
	int pwm;
	int in2;
	int in1;
}motor;

motor motors[2];

#define FORWARD 	1
#define BACKWARD 	2
#define BRAKE		3
#define RELEASE		4

#define SINGLE		1
#define	DOUBLE		2
#define INTERLEAVE	3
#define MICROSTEP	4

void initMotors();
/*==============================================================
* This function initializes each of the motors with their
* proper in1, in2, and pwm pins. There are 2 motors used in
* this project, motors[0] is the left motor, and motors[1] is
* the right motor. This function only needs to be called once,
* and should usually be the second function called, after
* i2cInit().
\*============================================================*/

void initHat();
/*==============================================================
* This function initializes the motor hat itself, setting it
* as the current slave to the pi and setting the proper PWM
* frequency for the motors. It needs to be called every time
* you want to control the motors instead of the servo, and
* will probably be the third function you call in main. You
* must set the motor hat as the current slave when you want to
* control the motors, and the servo hat as the slave when you
* want to control the servo.
\*============================================================*/

void run(unsigned char command, unsigned char motorID);
/*==============================================================
* This function is used by Robot.c in order to give Robi
* commands. It handles the actual motors' movements using setPin
* and will likely not need to be called directly.
\*============================================================*/

void setSpeed(int speed, unsigned char motorID);
/*==============================================================
* This function sets the speed of the specified motor. It is
* also used in the functions of Robot.c in order to control Robi
* and will likely not need to be called directly.
\*============================================================*/

void setPin(unsigned char pin, unsigned char value);
/*==============================================================
* This function uses PWM.c's setPWM in order to make one of
* Robi's motors move. The aforementioned run function uses this
* function in order to smoothly handle commands to be sent to
* Robi's motors. It will likely not need to be called directly.
\*============================================================*/


#endif
