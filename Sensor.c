#include"Sensor.h"

extern int initSensor()
{
	if (!bcm2835_init())
		return 1;
	else
		return 0;
}

extern double get_time()
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return t.tv_usec;
}

extern void gpio_reset()
{
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_18, BCM2835_GPIO_PUD_OFF);
	bcm2835_gpio_set_pud(RPI_V2_GPIO_P1_16, BCM2835_GPIO_PUD_OFF);

	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_18, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(RPI_V2_GPIO_P1_16, BCM2835_GPIO_FSEL_INPT);
}

extern double get_distance()
{
	double pulse_start, pulse_end, pulse_duration;
	double distance;

	bcm2835_gpio_fsel(ECHO, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(TRIG, BCM2835_GPIO_FSEL_OUTP);

	bcm2835_gpio_write(TRIG,LOW);

//	printf("Waiting for sensor to settle\n");

//	bcm2835_delay(2000);
	bcm2835_delay(200); 			// Delay built-in to this function.
//	printf("Set TRIG to true\n");

	bcm2835_gpio_write(TRIG,HIGH);

//	printf("Sleep\n");

	bcm2835_delayMicroseconds(10);

//	printf("Set TRIG to false\n");

	bcm2835_gpio_write(TRIG,LOW);

//	printf("First while loop\n");

	while (bcm2835_gpio_lev(ECHO)==0)
		pulse_start = get_time();//get the time in microseconds

//	printf("pulse start: %Lf\n",pulse_start);

//	printf("Second while loop\n");

	while(bcm2835_gpio_lev(ECHO)==1)
		pulse_end = get_time();//get the time in micorseconds

//	printf("pulse end:%Lf\n",pulse_end);

	//pulse_duration = (double)(pulse_end - pulse_start)/CLOCKS_PER_SEC;
	//CLOCKS_PER_SEC is equal to 1000000 on the raspberry pi.
	//in order for this to work, you have to get the time in micro seconds.

	pulse_duration = (pulse_end - pulse_start)/1000000;

//	printf("pulse duration:%Lf\n",pulse_duration);

	distance = pulse_duration * 17150;

//	printf("Distance:%.2f cm\n",distance);

	if(distance > 0)   // Print distance from obstacle
		{ printf("Robi is %.2f cm from an obstacle\n",distance); }
	else{   	   // but also handle errors (negative distance)
		printf("Robi's sensor had some trouble. Ignoring current distance value. (%.2f cm)\n", distance);
		distance = 500;  // I decided to just say 500cm if this error occurs.
	}

	gpio_reset();


	//bcm2835_close();
	return distance;

}
