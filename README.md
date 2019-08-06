# RcCar
Project

AlphaBot RcCar README

<<Basic Control>>

compile command

gcc -o main control.c main.c function.c -lwiringPi

download wiringPi

>git clone git://git.drogon.net/wiringPi

check wiringPi install version

> gpio -v
> gpio realall (gpio pin header check)
![test](https://user-images.githubusercontent.com/42111518/57056485-d9410500-6cdd-11e9-96a8-fa2148925547.png)



<<Obstacle Avoidence>>

i made in folder Obstacle Avoidence code with Infrared Proximity sensor

update main.c how can use each other control code and obstacle avoidence code

compile command

> gcc -o main control.c main.c function.c -lwiringPi