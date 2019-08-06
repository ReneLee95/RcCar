#include <stdio.h>
#include "wiringPi.h" 
#include "softPwm.h" 

#define ObstaclePin 24  //BCM16    if you need Analog pin then use the arduino AnalogPin anything no problem
#define ObstaclePin2 27 //BCM19
#define M1_L 26 //BCM12 
#define M1_R 28 //BCM20 
#define M2_L 23 //BCM13 
#define M2_R 29 //BMC21 
#define EA 22   // BCM6 
#define EB 25  //BCM26 
#define S1 2 // use servo motor
#define S2 3 // use servo motor

int main(void)
{
	if(wiringPiSetup() == -1){ // Wiringpi initialization failed print error
	printf(" Wiripin initialization failed!");
	return 1;
	}
        /* Set pinMode gpio and PWM */
        pinMode(ObstaclePin,INPUT); //you don't setting OUTPUT if you set the OUTPUT , you can see a reverse result
        pinMode(ObstaclePin2,INPUT);

        pinMode(M1_L, OUTPUT); 
        pinMode(M1_R, OUTPUT); 
        pinMode(M2_L, OUTPUT); 
        pinMode(M2_R, OUTPUT); 
        pinMode(EA,OUTPUT); 
        pinMode(EB,OUTPUT); 
        softPwmCreate(EA,0,200); 
        softPwmCreate(EB,0,200);

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

return 0;

}
