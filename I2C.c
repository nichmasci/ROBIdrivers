#include<stdio.h>
#include<regex.h>
#include<fcntl.h>
#include<unistd.h>
#include<bcm2835.h>
#include"I2C.h"

#define BUFFERSIZE 4096

extern int i2cInit(int address){

	//i2c initialization should also go here.

	//Initialize the GPIO headers
	if (!bcm2835_init())
    	{
     		printf("bcm2835_init failed. Are you running as root??\n");
      		return 1;
    	}//if bcm_init

	//Prepare the hat for i2c communication
	if (!bcm2835_i2c_begin())
    	{
		printf("bcm2835_i2c_begin failed. Are you running as root??\n");
		return 1;
	}//if i2c_begin

	//Set the address of the hat you are communicating with
	bcm2835_i2c_setSlaveAddress(address); //set HAT address to 0x41 for servo
	return 0;


}

/*
Each student should be using the i2c write function within
the bcm2835 library.  The documentation on this function
can be found on the Internet.
*/
extern void write8(unsigned char reg, unsigned char value){
	//code for this function is left to the student.
	unsigned char buff[2];
	uint8_t reason;

	buff[0] = reg;
	buff[1] = value;
	reason = bcm2835_i2c_write(buff, 2);

//	if(reason == BCM2835_I2C_REASON_OK)
//	{ printf("Write successful.\n"); }

	/*else*/ if(reason == BCM2835_I2C_REASON_ERROR_NACK)
	{ printf("Write unsuccessful; received Negative Acknowledgement.\n"); }

	else if(reason == BCM2835_I2C_REASON_ERROR_CLKT)
	{ printf("Write unsuccessful; received Clock Stretch Timeout.\n"); }

	else if(reason == BCM2835_I2C_REASON_ERROR_DATA)
	{ printf("Write unsuccessful; not all data was properly read.\n"); }

	else if(reason != BCM2835_I2C_REASON_OK)
	{ printf("Write unsuccessful for unknown reason.\n"); }

	//error checking should be done for the completion of this
	//function.
}

/*
Each student should be using the i2c read function within
the bcm2835 library.  The documentation on this function
can be found on the Internet.
*/

unsigned int readU8(unsigned char reg){
	//Code for this function is left to the student.
	unsigned char buff[2];
	uint8_t reason;

	buff[0] = reg;
	reason = bcm2835_i2c_read(buff, 1);
//	if(reason == BCM2835_I2C_REASON_OK)
//	{ printf("Read successful.\n"); }

	/*else*/ if(reason == BCM2835_I2C_REASON_ERROR_NACK)
	{ printf("Read unsuccessful; received Negative Acknowledgement.\n"); }

	else if(reason == BCM2835_I2C_REASON_ERROR_CLKT)
	{ printf("Read unsuccessful; received Clock Stretch Timeout.\n"); }

	else if(reason == BCM2835_I2C_REASON_ERROR_DATA)
	{ printf("Read unsuccessful; not all data was properly written.\n"); }

	else if(reason != BCM2835_I2C_REASON_OK)
	{ printf("Read unsuccessful for unknown reason.\n"); }


	//Error checking should be done for the completion of this function.
	return buff[0];
}

