#include<stdio.h>
#include<bcm2835.h>
#include"MotorHat.h"

#ifndef ROBOT
#define ROBOT

void _left_speed(int speed);
/*==============================================================
* This function acts as a wrapper for the setSpeed function,
* to be used on the left motor. It ensures that the speed is
* between 0 and 255, inclusive, and sets the left motor's speed
* using setSpeed(). This function will not be called directly,
* and is instead used in the forward, backward, left, and right
* functions.
\*============================================================*/

void _right_speed(int speed);
/*==============================================================
* This function is similar to the _left_speed function, but
* as the name would imply, it is to be used on the right motor.
* Similarly, it will not be called directly.
\*============================================================*/

void stop();
/*==============================================================
* This function simply sends a RELEASE command to both motors.
* This function should be called whenever you want Robi to stop.
\*============================================================*/

/*==============================================================
* The following four functions should be used with delay(x),
* where x is the amount of time, in milliseconds, you want
* the command to take place.
* For example:
* 		forward(128);
*		delay(1000);
* will make Robi move forward at speed 128 for 1 second.
\*============================================================*/

void forward(int speed);
/*==============================================================
* This function will make Robi move forward at the given speed.
* My Robi's left wheel is backwards, so motors[0] receives the
* opposite instruction, BACKWARD. If this code does not work
* properly on your Robi, you may need to swap the instruction
* being given to motors[0] for this function and all the others
* within this file.
* For example, in this function, you would change...
*        run(BACKWARD, 0) -> run(FORWARD, 0)
* This function should be called when you want Robi to go
* forward.
\*============================================================*/

void backward(int speed);
/*==============================================================
* This function will make Robi move backward at the given speed.
* This function has the same problem with the wheel (as do all
* the others), so you may again need to change the instruction
* sent to the left wheel (motors[0]).
* This function should be called when you want Robi to go
* backward.
\*============================================================*/

void right(int speed);
/*==============================================================
* This function will make Robi rotate clockwise (turn right)
* It should be called when you want Robi to face to the right.
* The speed and delay used with this function will affect
* how far to the right Robi will turn.
\*============================================================*/

void left(int speed);
/*==============================================================
* This function will make Robi rotate counterclockwise (left)
* It should be called when you want Robi to face to the left.
* The speed and delay used with this function will affect
* how far to the left Robi will turn.
\*============================================================*/


#endif

