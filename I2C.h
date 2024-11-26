#include<stdio.h>
#include<regex.h>
#include<fcntl.h>
#include<unistd.h>
#include<bcm2835.h>

#ifndef I2C

#define I2C

int i2cInit(int address);
/*==============================================================
* This function is needed to initialize the communication with
* the i2c bus.  This function should be the first function that
* is called within your project. Only the address is needed for
* this function.
\*============================================================*/

void write8(unsigned char reg, unsigned char value);
/*==============================================================
* This function is needed to write data to the hat, and is
* used by many other functions in the program. This will likely
* never be called directly.
\*============================================================*/

unsigned int readU8(unsigned char reg);
/*==============================================================
* This function is needed to read data from the hat, and is
* likewise used by many other functions in this project. It will
* likely never be called directly.
\*============================================================*/

#endif
