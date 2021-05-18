/*
 * Author      : Shiva Agrawal
 * Date        : 06.06.2018
 * Version     : 1.0
 * Description : Define the header and functions for DC motor driver. The driver is written by considering predefined hardware
 *               interface of motor shield (L293D and serial shift register) with raspberry pi 3 model B.
 */
 
#ifndef _VEHICLE_ACTUATOR_H
#define _VEHICLE_ACTUATOR_H

#include "std_int.h"

/*-----------------------------------------------------------------------------------------------------------------------------------
 * pi header pin number        WiringPi number    function    Motor shield IC pin number        Motor Shield header pin number
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

/*--------------------------------------------------------------------------------------
 * LOOK UP TABLE FOR MOTOR AND STEER DIRECTION CONTROL
 * -------------------------------------------------------------------------------------
 * FUCNTION               BIT SET (0b00000000)   
 * -------------------------------------------------------------------------------------
 * Steer right               1 (0b00000001)
 * Front Motor reverse       2 (0b00000010)
 * Steer left                3 (0b00000100)
 * Rear Motor Forward        4 (0b00001000)
 * NA for this project       5 (0b00010000)              
 * NA for this project       6 (0b00100000)
 * Rear Motor reverse        7 (0b01000000)
 * Front Motor Forward       8 (0b10000000)
 * -------------------------------------------------------------------------------------
 * Depending on the requirement of the motion, multiple bits are set as per 
 * above lookup table.
 * -------------------------------------------------------------------------------------
 */
 
 
typedef enum {FORWARD, FORWARD_LEFT, FORWARD_RIGHT, REVERSE, REVERSE_LEFT, REVERSE_RIGHT, STOP } vehicle_motion_t;

class vehicle_actuator
{
	private:
	
	uint8_t data;
	uint8_t clock;
	uint8_t latch;
	
	uint8_t getData(vehicle_motion_t);
	
	public:
	
    vehicle_actuator();
	void vehicleControl(vehicle_motion_t);
	
	};

#endif
