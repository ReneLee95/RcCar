#include <stdio.h>
#include "wiringPi.h"
#include "softPwm.h"

#define M1_L 26
#define M1_R 28
#define M2_L 23
#define M2_R 29
#define EA 22
#define EB 25
#define S1 2
#define S2 3

int setup();

int setup()
{
	char data;

	if(wiringPiSetup() == -1)
	{
		return 1;
	}
	pinMode(M1_L, OUTPUT);
	pinMode(M1_R, OUTPUT);
	pinMode(M2_L, OUTPUT);
	pinMode(M2_R, OUTPUT);
	pinMode(EA,OUTPUT);
	pinMode(EB,OUTPUT);
	softPwmCreate(EA,0,200);
	softPwmCreate(EB,0,200);
	softPwmCreate(S1,0,3000);
	softPwmCreate(S2,0,3000);
}
