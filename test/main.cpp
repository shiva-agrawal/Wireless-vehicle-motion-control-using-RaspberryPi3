/* 
 * Author : Shiva Agrawal
 * Date   : 06.06.2018
 * Version: 1.0
 * Description : Configuartion to test the vehicle control using DC motor driver 
 */
 
 
#include <wiringPi.h>
#include "vehicle_actuator.h"

int main()
{
	// to activate the wiringPi based pin convention
	wiringPiSetup();
    
    // object of the class is created. this also leads to initilization
    // of the pins
    vehicle_actuator my_vehicle;
    
	// simple testing of the vehicle motion
	my_vehicle.vehicleControl(FORWARD);
	delay(1000);
	my_vehicle.vehicleControl(REVERSE_RIGHT);
	delay(1000);
	my_vehicle.vehicleControl(FORWARD_RIGHT);
	delay(1000);
	my_vehicle.vehicleControl(REVERSE);
	delay(1000);
	my_vehicle.vehicleControl(STOP);
	delay(1000);
	
	return 0;
}

	
	
	
    
	
