#include "PWM.h"
#ifndef SERVO_H
#define SERVO_H

#define SERVOMIN	500
#define SERVOMAX	2500
#define SERVOMID	(SERVOMIN + SERVOMAX) / 2

void initServo();
/*==============================================================
* This function prepares the servo to be controlled by the pi.
* It must be called every time you want to control the servo,
* after you have been controlling the motors. Control has to be
* passed between the motor hat and the servo hat, they cannot
* both be initialized at the same time.
\*============================================================*/

void setServoPulse(int channel, int pulse);
/*==============================================================
* This function is not directly called, but it is used in the
* following three functions. The given channel, that the servo
* is plugged into, will be sent a pulse, which will cause the
* servo to move to that position. 500 is the minimum, turning
* the servo all the way to the right, and 2500 is the maximum,
* turning the servo all the way to the left.
\*============================================================*/

void look_left();
/*==============================================================
* This function will be called when you want Robi to look left.
* it uses setServoPulse in order to make the servo move to its
* maximum actuation.
\*============================================================*/

void look_right();
/*==============================================================
* This function will be called when you want Robi to look right.
* it uses setServoPulse in order to make the servo move to its
* minimum actuation.
\*============================================================*/

void look_mid();
/*==============================================================
* This function will be called when you want Robi to look
* straight ahead. It uses setServoPulse in order to make the
* servo move to the middle, which is the average of the maximum
* and minimum actuation values.
\*============================================================*/


#endif
