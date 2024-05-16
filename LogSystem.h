#ifndef LOGSYSTEM
#define LOGSYSTEM

#include "Log.cpp"
#include "Device.cpp"
#include "Staff.cpp"
#include "Vout.h"

#include <iostream>

void LogSystem(std::string code, int *run) {
	Log log;
	Device device;
	Staff staff;
	VanishOut v;
	if(code == "check") {
		std::cout << std::endl;
		log.check();
		std::cout << std::endl;
	} else if(code == "add") {
		std::string d,s,r,da;
		device.print();
		while(1) {
			v.out("input the device id: ");
			std::cin >> d;
			d = device.idToName(d);
			if(d != "None") {
				std::cout << std::endl;
				break;
			}
			std::cout << "Invalid id it is." << std::endl << std::endl;
		}
		staff.print();
		while(1) {
			v.out("input the staff id: ");
			int ss;
			std::cin >> ss;
			s = staff.idToName(ss);
			if(s != "None") {
				std::cout << std::endl;
				break;
			}
			std::cout << "Invalid id it is." << std::endl << std::endl;
		}
		v.out("input the revanue: ");
		std::cin >> r;
		v.out("input the date: ");
		std::cin >> da;
		log.add(d, s, r, da);
		std::cout << std::endl;
	} else if(code == "delete") {
		int id;
		v.out("input id of the log you delete: ");
		std::cin >> id;
		if(log.del(id)) std::cout << "Success: delete success." << std::endl;
		else std::cout << "Error: log not exist or database error." << std::endl;
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
