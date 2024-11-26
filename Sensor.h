#include<bcm2835.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

#ifndef SENSOR_H
#define SENSOR_H

#define ECHO RPI_V2_GPIO_P1_18
#define TRIG RPI_V2_GPIO_P1_16

int initSensor();
/*==============================================================
* This function simply called bcm2835_init(). It was originally
* called in get_distance, which eventually caused segmentation
* faults when running the program for too long. It should
* just be called once after all other initializations have
* taken place.
\*============================================================*/

double get_time();
/*==============================================================
* This function returns the current time. It is used by
* get_distance in order to measure the distance from the sensor.
* It will not be called directly.
\*============================================================*/

void gpio_reset();
/*==============================================================
* This function sets pulldowns for the two middle pins of the
* sensor, and selects them to be used as inputs to the pi.
* it is used at the end of get_distance, but will not be called
* directly.
\*============================================================*/

double get_distance();
/*==============================================================
* This function will use the sensor to get Robi's distance from
* the obstacle in front of him. It measures the amount of time
* it takes for sound from the sensor to return, and uses that
* value to determine the distance. It should be called on a loop
* periodically in main in order to make sure Robi does not crash
* Sometimes, very high or very low (negative) values will be
* returned by this function. The high values are ignored
* altogether, and low values are changed to instead be 500cm
* (And then are ignored)
\*============================================================*/

#endif
