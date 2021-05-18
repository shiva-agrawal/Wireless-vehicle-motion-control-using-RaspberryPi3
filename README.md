
# Wireless vehicle motion control using Raspberry pi 3 and Ubuntu (Linux OS)

This project is more hardware oriented as compared to software. The aim of the project is to understand, build and test the hardware for the autonomous driving / mobile robots. 

For the project, I have selected a RC car which has DC motors for throttle and steering. These motors are then connected to motor shield circuit which consist of L293D (direction control H-bridge IC) and serial to parallel shift register. Further the motor shield is connected to Raspberry pi 3 Model B development board.

I have installed Ubuntu Mint OS on the pi and written the DC motor drivers in embedded C++ for the vehicle motion control using Geany IDE (open source) in Ubuntu. Further to run the application, the pi OS is accessed remotely using VNC server-client mode from PC.

This project is one of the basic foundation to work towards the autonomous driving / autonomous robotics.

## Project Folder structure

1. docs 
    * Project details.pdf - detailed project report covering hardware and software description
    * Motor_Shield_Schematic.jpg - Layout of motor shield used to do hardware connections
    * Mounted RC car.jpg - Photo of the final RC car mounted with required hardware
    * Power bank with USB cable.jpg - image of the small power bank used to power the raspberry pi
2. src
    * std_int.h - datatype declaration
    * vehicle_actuator.h, vehicle_actuator.cpp - driver files for DC motor control 
3. test
    * main.cpp - test file of the project
