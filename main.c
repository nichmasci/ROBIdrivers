#include "I2C.h"
#include "PWM.h"
#include "MotorHat.h"
#include "Robot.h"
#include "Sensor.h"
#include "Servo.h"

int main(){
	int demoCounter = 8; // Go through the loop n times

	i2cInit(96); // Initialize the pi first (0x70)
	initHat();   // Then the motor hat
	initMotors();// Then the motors themselves
	initSensor();// Then the sensor
/*
	printf("Looking LEFT\n");
	look_left();

	printf("Looking RIGHT\n"); // Test code for servo
	look_right();		   // Will not work without initServo()

	printf("Recentering\n");
	look_mid();
*/

	double distance;     // Create variable to keep track of distance
	distance = get_distance();
	double distL = -1;   // Start left and right distance as -1
	double distR = -1;   // Just to have them as SOMETHING
	initHat();           // Initialize the motor hat again for good measure
	forward(100);        // Begin moving forward at speed 100

	while(demoCounter > 0){
		distance = get_distance();  // Get the distance
		//delay(50);                // There is a delay built in to this function
		if(distance <= 35){   // When less than 35cm away, turn
			printf("Robi has reached an obstacle!\n");

			stop();
			initServo();	// initServo will disable control of the motors
					// and vice versa
			look_left();
			printf("Robi is looking left...\n");
			distL = get_distance();  // Get distance to the left
			delay(200);

			look_right();
			printf("Robi is looking right...\n");
			distR = get_distance(); // ...and to the right
			delay(200);

			look_mid();	// Then look straight again
			delay(500);

			initHat();	// Regain control of the motor hat

			backward(100);  // Back up a little bit
			delay(500);

			//stop();
			//delay(250);


			if(distL < distR)  // If statements to decide which way to go
			{
				printf("Robi decided to go RIGHT!\n");
				right(80);
			}
			else

			{
				printf("Robi decided to go LEFT!\n");
				left(80);
			}
			delay(500);
			forward(100);  // Continue forward at speed 100

			demoCounter = demoCounter - 1; // Increment counter
			if(demoCounter != 0)       // And notify user of remaining loops
				{ printf("%d more time(s)!\n", demoCounter); }
			else
				{ printf("All done!\n"); }
		}
	}
	stop();    // When demoCounter reaches 0, stop Robi and close the connection
	bcm2835_close();
//*/
}
