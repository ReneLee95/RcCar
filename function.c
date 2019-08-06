#include <stdio.h>
#include "wiringPi.h"
#include "softPwm.h"
#include "triger.h"
void control();

void control()
{
	char data;
	printf(" w : Foward /s : Stop /d: Right /a: Left /x: Reverse /u:InfraredObstacle");
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
		digitalWrite(M1_R,0);
		digitalWrite(M1_L,1);
		digitalWrite(M2_R,1);
		digitalWrite(M2_L,0);
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
		
		case 'u':
		while(1)  // control loop
		{
		int a = digitalRead(ObstaclePin);
		int b = digitalRead(ObstaclePin2);
		
		if(a==HIGH&&b==HIGH) {
                	digitalWrite(M1_R, 0);
                	digitalWrite(M1_L, 1);
                	digitalWrite(M2_R, 1);
                	digitalWrite(M2_L, 0);
                	softPwmWrite(EA,200);
                	softPwmWrite(EB,200);
                	printf("Foward\n");
			}

		else if(a==LOW&&b==HIGH) {
                	digitalWrite(M1_R,1);
                	digitalWrite(M1_L,0);
                	digitalWrite(M2_R,0);
                	digitalWrite(M2_L,1);
                	softPwmWrite(EA,200);
                	softPwmWrite(EB,200);
                	delay(1000);
                	digitalWrite(M1_R,1);
                	digitalWrite(M1_L,0);
                	digitalWrite(M2_R,0);
                	digitalWrite(M2_L,0);
                	softPwmWrite(EA,200);
                	softPwmWrite(EB,200);
                	printf("Right\n");
			}

		else if(a==HIGH&&b==LOW) {
                	digitalWrite(M1_R,1);
                	digitalWrite(M1_L,0);
                	digitalWrite(M2_R,0);
                	digitalWrite(M2_L,1);
                	softPwmWrite(EA,200);
                	softPwmWrite(EB,200);
                	delay(1000);
                	digitalWrite(M1_R,0);
                	digitalWrite(M1_L,0);
                	digitalWrite(M2_R,0);
                	digitalWrite(M2_L,1);
                	softPwmWrite(EA,200);
                	softPwmWrite(EB,200);
                	printf("Left\n");
			}

		else if(a==LOW&&b==LOW) {
                	digitalWrite(M1_R,1);
                	digitalWrite(M1_L,0);
               		digitalWrite(M2_R,0);
             		digitalWrite(M2_L,1);
                	softPwmWrite(EA,200);
        	        softPwmWrite(EB,200);
	                printf("Backward\n");
			}

		else {
                	break;
			}
		}
		break;
		
		default:
		printf("None");
		break;
	}
}
