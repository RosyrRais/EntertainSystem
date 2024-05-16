#ifndef STAFFSYSTEM
#define STAFFSYSTEM

#include "Staff.cpp"
#include "Vout.h"

#include <iostream>

void StaffSystem(std::string code, int *run) {
	Staff staff;
	VanishOut v;
	if(code == "check") {
		std::cout << std::endl;
		staff.print();
		if(staff.empty()) std::cout << "Its empty." << std::endl;
		std::cout << std::endl;
	} else if(code == "add") {
		v.out("input name of the staff: ");
		std::string name;
		std::cin >> name;
		if(staff.add(name))
			std::cout << "Success: " << name << " had been added in staff." << std::endl; 
		else 
			std::cout << "Error: " << name << " already exist or database error." << std::endl;
		std::cout << std::endl;
	} else if(code == "delete") {
		if(staff.empty()) std::cout << "Its empty." << std::endl; 
		v.out("input id of the staff who to be delete: ");
		int id;
		std::cin >> id;
		if(staff.del(id))
			std::cout << "Success: Staff remove success." << std::endl;
		else
			std::cout << "Error: Invalid id or database error." << std::endl;
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
