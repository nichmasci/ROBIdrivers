main: main.c I2C.c PWM.c MotorHat.c Robot.c Sensor.c Servo.c
	gcc -c I2C.c
	gcc -c PWM.c
	gcc -c MotorHat.c
	gcc -c Robot.c
	gcc -c Sensor.c
	gcc -c Servo.c
	gcc -o main main.c I2C.o PWM.o MotorHat.o Robot.o Sensor.o Servo.o -lbcm2835 -lm
