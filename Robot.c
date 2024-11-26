#include<stdio.h>
#include<bcm2835.h>
#include"MotorHat.h"
#include"Robot.h"

extern void _left_speed(int speed){
	if(speed < 0 || speed > 255)
	{
		perror("Speed must be between 0 and 255, inclusive\n");
		return;
	}
	setSpeed(speed, 0);
}
extern void _right_speed(int speed){
	if(speed < 0 || speed > 255)
	{
		perror("Speed must be between 0 and 255, inclusive\n");
		return;
	}
	setSpeed(speed, 1);
}
extern void stop(){
	run(RELEASE, 0);
	run(RELEASE, 1);
}
extern void forward(int speed){
	_left_speed(speed);
	_right_speed(speed);
	run(BACKWARD, 0); // This may need to be changed to FORWARD
	run(FORWARD, 1);  // on your Robi.
}
extern void backward(int speed){
	_left_speed(speed);
	_right_speed(speed);
	run(FORWARD, 0); // This may need to be changed to BACKWARD
	run(BACKWARD, 1);
}
extern void right(int speed){
	_left_speed(speed);
	_right_speed(speed);
	run(BACKWARD, 0); // This may need to be changed to FORWARD
	run(BACKWARD, 1);
}
extern void left(int speed){
	_left_speed(speed);
	_right_speed(speed);
	run(FORWARD, 0);  // This may need to be changed to BACKWARD
	run(FORWARD, 1);
}

