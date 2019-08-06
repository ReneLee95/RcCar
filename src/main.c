#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#if 1
#include "triger.h"
#endif

int main()
{
	setup();

	while(1)
	{
		control();
	}
}
