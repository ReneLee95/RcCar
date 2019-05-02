#include <stdio.h>
#include "wiringPi.h"
#include "softPwm.h"
#define M1_L 26 //BCM12
#define M1_R 28 //BCM20
#define M2_L 23 //BCM13
#define M2_R 29 //BMC21
#define EA 22   // BCM6
#define EB 25  //BCM26
#define S1 2
#define S2 3

int main()
{
	char data;
	if(wiringPiSetup () == -1)
	return 1;

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


	while(1)
	{
		scanf("%s", &data);
		
		switch(data)
		{	
			case 'w':
		digitalWrite(M1_R, 1);
		digitalWrite(M1_L, 0);
		digitalWrite(M2_R, 0);
		digitalWrite(M2_L, 1);
		digitalWrite(EA,1);
		digitalWrite(EB,1);
		softPwmWrite(EA,190);
		softPwmWrite(EB,200);
		delay(2000);
		printf("Forward");
		break;

		case 'd':
		digitalWrite(M1_L,0);
		digitalWrite(M1_R,1);
		digitalWrite(M2_L,0);
		digitalWrite(M2_R,0);
		digitalWrite(EA,1);
		digitalWrite(EB,1);
		softPwmWrite(EA,200);
		softPwmWrite(EB,200);
		printf("Right");
		break;

		case 'a':
		digitalWrite(M1_L, 0);
		digitalWrite(M1_R, 0);
		digitalWrite(M2_L, 1);
		digitalWrite(M2_R, 0);
		digitalWrite(EA, 1);
		digitalWrite(EB, 1);
		softPwmWrite(EA,200);
		softPwmWrite(EB,200);
		printf("Left");
		break;

		case 'x':
		digitalWrite(M1_L,1);
		digitalWrite(M1_R,0);
		digitalWrite(M2_L,0);
		digitalWrite(M2_R,1);
		digitalWrite(EA,1);
		digitalWrite(EB,1);
		softPwmWrite(EA,190);
		softPwmWrite(EB,200);
		printf("Reverse");
		break;

		case 's':
		digitalWrite(M1_L,0);
		digitalWrite(M1_R,0);
		digitalWrite(M2_L,0);
		digitalWrite(M2_R,0);
		digitalWrite(EA,1);
		digitalWrite(EB,1);
		softPwmWrite(EA,0);
		softPwmWrite(EB,0);
		printf("Stop");
		break;
	
		case 'z':
		softPwmWrite(S1,25);
		printf("S1 Down");
		break;

		case 'c':
		softPwmWrite(S1,5);
		printf("S1 Up");
		break;

		case 'q':
		softPwmWrite(S2,25);
		printf("S2 Left");
		break;

		case 'e':
		softPwmWrite(S2,5);
		printf("S2 Right");
		break;

		case 't':
		softPwmWrite(S1,0);
		softPwmWrite(S2,0);
		printf("S1, S2  Stop");
		break;

		default :
		printf("No");
		break;
		}
	}
	return 0;
}






