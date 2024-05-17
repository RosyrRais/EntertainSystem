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
		if(log.empty()) std::cout << "Its empty." << std::endl;
		std::cout << std::endl;
	} else if(code == "add") {
		std::string d,s,r,da;
		if(device.empty()) {
			std::cout << "Error: There is no device in database." << std::endl;
			return;
		}
		if(staff.empty()) {
			std::cout << "Error: There is no Staff in database." << std::endl;
			return;
		}
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
		if(log.empty()) {
			std::cout << "Error: There is no log in database." << std::endl;
			return;
		}
		int id;
		v.out("input id of the log you delete: ");
		std::cin >> id;
		if(log.del(id)) std::cout << "Success: delete success." << std::endl;
		else std::cout << "Error: log not exist or database error." << std::endl;
		std::cout << std::endl;
	} else if(code == "change") {
		if(log.empty()) {
			std::cout << "Error: There is no log in database." << std::endl;
			return;
		}
		int id;
		std::string deviceName, staffName, revenue, date;
		v.out("input id of the log you change: ");
		std:: cin >> id;
		if(!log.getLogData(id, &deviceName, &staffName, &revenue, &date)){
			std::cout << "Error: Id invalid." << std::endl << std::endl;
			return;
		}
		std::cout << "id\tdevice\tstaff\trevenue\tdate\n"
			<< id << "\t" << deviceName << "\t" << staffName << "\t" << revenue << "\t" << date << std::endl << std::endl;
		std::string ans;
		while(1){
			std::cout << "input device id(if no change, fill *): "; std::cin >> ans;
			if(ans == "*") break;
			std::string d = device.idToName(ans);
			if(d == "None") {
				std::cout << "Error: Invalid id\n\n";
			} else {
				deviceName = d;
				break;
			}
		}
		while(1){
			int i;
			std::cout << "input staff id(if no change, fill *): "; std::cin >> i;
			if(ans == "*") break;
			std::string s = staff.idToName(i);
			if(s == "None") {
				std::cout << "Error: Invalid id\n\n";
			} else {
				staffName = s;
				break;
			}
		}
		std::cout << "input revenue(if no change, fill *): "; std::cin >> ans;
		if(ans != "*") revenue = ans;
		std::cout << "input date(if no change, fill *): "; std::cin >> ans;
		if(ans != "*") date = ans;
		log.change(id, deviceName, staffName, revenue, date);
		std::cout << "Success: log had been change.\n\n"; 
	} else if(code == "quit") {
		*run = 0;
		std::cout << std::endl;
	} else {
		std::cout << "Invalid code." << std::endl 
		<< "(input check/add/delete to manage, or input quit to quit)" << std::endl << std::endl;
	}
}

#endif
