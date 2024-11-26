#include<stdio.h>
#include<bcm2835.h>
#include"PWM.h"
#include"MotorHat.h"

extern void initMotors(){
	motors[0].pwm = 8;
	motors[0].in2 = 9;
	motors[0].in1 = 10;

	motors[1].pwm = 13;
	motors[1].in2 = 12;
	motors[1].in1 = 11;
}

extern void initHat(){
	//int _i2caddr = 0x60;
	//int _frequency = 1600;
	i2cInit(96);
	PWMInit(0x60);
	setPWMFreq(1600);
}

extern void run(unsigned char command, unsigned char motorID){
//	if(!MC)
//	{ return; }
	if(command == FORWARD){
		setPin(motors[motorID].in1, 0);
		setPin(motors[motorID].in2, 1);
	}
	if(command == BACKWARD){
		setPin(motors[motorID].in1, 1);
		setPin(motors[motorID].in2, 0);
	}
	if(command == RELEASE){
		setPin(motors[motorID].in1, 0);
		setPin(motors[motorID].in2, 0);
	}
}

extern void setSpeed(int speed, unsigned char motorID){
	if(speed < 0)
	{ speed = 0; }
	if(speed > 255)
	{ speed = 255; }
	int newSpeed = speed * 16;
	setPWM(motors[motorID].pwm, 0, newSpeed);
}

extern void setPin(unsigned char pin, unsigned char value){
	if(pin < 0 || pin > 15){
		perror("PWM pin must be between 0 and 15, inclusive.\n");
		return;
	}
	if(value != 0 && value != 1){
		perror("Pin value must be 0 or 1.\n");
		return;
	}
	if(value == 0){
		setPWM(pin, 0, 4096);
	}
	if(value == 1){
		setPWM(pin, 4096, 0);
	}
}

