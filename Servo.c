#include "Servo.h"

extern void initServo(){
	PWMInit(0x40);
	setPWMFreq(60);
}

extern void setServoPulse(int channel, int pulse){
	int pulseLength = 1000000;
	pulseLength = pulseLength / 60;
	pulseLength = pulseLength / 4096;
	int newPulse = pulse / pulseLength;
	setPWM(channel, 0, newPulse);
}

extern void look_left(){
	setServoPulse(0, SERVOMAX);
	delay(500);
}

extern void look_right(){
	setServoPulse(0, SERVOMIN);
	delay(500);
}

extern void look_mid(){
	setServoPulse(0, SERVOMID);
	delay(500);
}

