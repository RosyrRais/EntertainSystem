#ifndef DEVICESYSTEM
#define DEVICESYSTEM

#include "Device.cpp"
#include "Vout.h"

#include <iostream>

Device device;
VanishOut v;

void DeviceSystem(std::string code, int *run) {
	if(code == "add") {
		std::string deviceName, deviceId;
		v.out("Device id: ");
		std::cin >> deviceId;
		v.out("Device name: ");
		std::cin >> deviceName;
		if(!device.add(deviceId, deviceName)) {
			std::cout << "Error: device already exist or database error." << std::endl;	
		}
		std::cout << std::endl;
	} else if(code == "delete") {
		if(device.empty()) {
			std::cout << "Database empty." << std::endl << std::endl;
			return;
		}
		std::string deviceName;
		v.out("input delete device id: ");
		std::cin >> deviceName;
		if(!device.del(deviceName))
			std::cout << "Error: device not exist or database error." << std::endl;
		else
			std::cout << "Success: " << deviceName << " had been deleted." << std::endl;
		std::cout << std::endl;
	} else if(code == "check") {
		std::cout << std::endl;
		device.print();
		if(device.empty()) std::cout << "Its empty." << std::endl;
		std::cout << std::endl;
	} else if(code == "quit") {
		*run = 0;
		std::cout << std::endl;
	} else {
		std::cout << "Invalid code." << std::endl 
		<< "(input check/add/delete to manage, or input quit to quit)" << std::endl << std::endl;
	}
}

#endif
