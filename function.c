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

void control();

void control()
{
	char data;
	scanf("%s",&data);

	switch(data)
	{
		case 'w':
		digitalWrite(M1_R,1);
		digitalWrite(M1_L,0);
		digitalWrite(M2_R,0);
		digitalWrite(M2_L,1);
		softPwmWrite(EA,190);
		softPwmWrite(EB,200);
		printf("Foward");
		break;

		case 'd':
		digitalWrite(M1_R,0);
		digitalWrite(M1_L,1);
		digitalWrite(M2_R,0);
		digitalWrite(M2_L,0);
		softPwmWrite(EA,200);
		softPwmWrite(EB,200);
		printf("Right");
		break;

		case 'a':
		digitalWrite(M1_R,0);
		digitalWrite(M1_L,0);
		digitalWrite(M2_R,1);
		digitalWrite(M2_L,0);
		softPwmWrite(EA,200);
		softPwmWrite(EB,200);
		printf("Left");
		break;

		case 'x':
		digitalWrite(M1_R,1);
		digitalWrite(M1_L,0);
		digitalWrite(M2_R,0);
		digitalWrite(M2_L,1);
		softPwmWrite(EA,200);
		softPwmWrite(EB,200);
		printf("Reverse");
		break;

		case 's':
		digitalWrite(M1_R,0);
		digitalWrite(M1_L,0);
		digitalWrite(M2_R,0);
		digitalWrite(M2_L,0);
		softPwmWrite(EA,200);
		softPwmWrite(EB,200);
		printf("Stop");
		break;

		default:
		printf("None");
		break;
	}
}
