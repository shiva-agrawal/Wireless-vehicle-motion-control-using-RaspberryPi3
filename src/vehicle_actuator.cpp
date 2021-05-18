/*
 * Author      : Shiva Agrawal
 * Date        : 06.06.2018
 * Version     : 1.0
 * Description : DC motor control driver functions
 */
 
#include <wiringPi.h>
#include <stdio.h>
#include "vehicle_actuator.h"

/*-----------------------------------------------------------------------------------------------------------------------------------
 * header pin number        WiringPi number    function    Motor shield IC pin number        Motor Shield header pin number
 * ----------------------------------------------------------------------------------------------------------------------------------
 *     04                        NA              5V              NA                                  JP3 - 3 (opposite side)
 *     06                        NA              GND             NA                                  GND (near D13)
 *     11                        0               CLOCK           11 (74HCT595N)                      D4  / 4
 *     12                        1               LATCH           12 (74HCT595N)                      D12 / 12
 *     13                        2               DATA (8 bits)   14 (74HCT595N)                      D8  / 8
 *     14                        NA              Enable (GND)    13 (74HCT595N)                      D7  / 7
 *     15                        3               PWM_F_Motor     PWM_0A (M4) (IC2 - L293D)           D6  / 6
 *     16                        4               PWM_R_Motor     PWM_2B (M2) (IC1 - L293D)           D3  / 3
 *     18                        5               PWM_STEER       PWM_0B (M3) (IC2 - L293D)           D5  / 5
 * ---------------------------------------------------------------------------------------------------------------------------------   
 */

vehicle_actuator::vehicle_actuator()
{
	
    
    // setting raspberry pi pin modes ( pins are pre-alloted during hardware configuration)
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT); 
	pinMode(2, OUTPUT);
	pinMode(3, PWM_OUTPUT);
	pinMode(4, PWM_OUTPUT);
	pinMode(5, PWM_OUTPUT);
	
	//assigning default values
	digitalWrite(0, LOW);  
	digitalWrite(1, LOW);
	digitalWrite(2, LOW);   
	
	pwmWrite(3, 1000);  
	pwmWrite(4, 1000);
	pwmWrite(5, 1000);
	

	
}

uint8_t vehicle_actuator::getData(vehicle_motion_t motion)
{
	uint8_t value = 0b00000000;
		
	switch(motion)
	{
		case FORWARD:
		{
			value = 0b00010001;
			break;
		}
		case FORWARD_LEFT:
		{
			value = 0b00110001;
			break;
		}
		
		case FORWARD_RIGHT:
		{
			value = 0b10010001;
			break;
		}
		
		case REVERSE:
		{
			value = 0b01000010;
			break;
		}
		case REVERSE_LEFT:
		{
			value = 0b01100010;
			break;
		}
		
		case REVERSE_RIGHT:
		{
			value = 0b11000010;
			break;
		}
		case STOP:
		{
		    value = 0b00000000;
			break;	
		
		}
		default:
			{}
		
	}
	return value;
}

/* 
 * algorithm to send the selected 8 bit data to serial input parallel output shift register
 * The data from parallel output then drives the corresponding actuator (here DC motors throttle and steer)
 */

void vehicle_actuator::vehicleControl(vehicle_motion_t motion)
{
		uint8_t DATA_BITS = 8;
		uint8_t data = getData(motion);
	    
		digitalWrite(0, LOW); // clock low
		digitalWrite(1, LOW); // latch low
		
	for (uint8_t i = 0; i< DATA_BITS; i++)
		{
			if ((data << i) & 0b10000000)
			{
			   digitalWrite(2, HIGH); 
			   printf("%d -> %d \n",i,1);
			}
			else
			{
				digitalWrite(2, LOW); 
				printf("%d -> %d \n",i,0);
			}
			
		digitalWrite(0, HIGH); // clock high
		digitalWrite(0, LOW); // clock low
		}
	
	digitalWrite(1, HIGH); // latch high
	
	
}
