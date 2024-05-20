#ifndef DEVICESYSTEM
#define DEVICESYSTEM

#include "Device.cpp"
#include "Vout.h"

#include <iostream>

void DeviceSystem(std::string code, int *run) {
	Device device;
	VanishOut v;
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
	} else if(code == "stream") {
		std::cout << std::endl;
		device.printStream();
		if(device.empty()) std::cout << "Its empty." << std::endl;
		std::cout << std::endl;
	} else if(code == "rank") {
		std::string date;
		v.out("input date:");
		std::cin >> date;
		std::cout << std::endl;
		device.rank(date);
		if(device.empty()) std::cout << "Its empty." << std::endl;
		std::cout << std::endl;
	} else if(code == "quit") {
		*run = 0;
		std::cout << std::endl;
	} else if(code == "help") {
		std::cout << "\ninput check/add/delete to manage device.\n"
		<< "input stream, you can know the total foot traffic for each device.\n"
		<< "input rank, you can check the rank of each device.\n"
		<< "and input quit to quit.\n\n";
	} else {
		std::cout << "Invalid code." << std::endl 
		<< "(input help for help, or input quit to quit)" << std::endl << std::endl;
	}
}

#endif
