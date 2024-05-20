#ifndef ROOTSYSTEM
#define ROOTSYSTEM

#include "Vout.h"

#include <iostream>

bool rootSystem(std::string code, int *run) {
	if(code == "quit") {
		std::cout << "system stop. ( ¡ä ¨Œ ` )";
		return false;
	} else if(code == "device") {
		*run = 1;
		std::cout << std::endl;
	} else if(code == "staff") {
		*run = 2;
		std::cout << std::endl;
	} else if(code == "log") {
		*run = 3;
		std::cout << std::endl;
	} else if(code == "help") {
		std::cout << "\ninput device/staff/log into their system. \n input clearMode to open mode, it can helps you skip some output.\n\n";
	} else if(code == "clearMode") {
		VanishOut::vanish = !(VanishOut::vanish);
		if(VanishOut::vanish) std::cout << "Clear mode on." << std::endl << std::endl;
		else std::cout << "Clear mode off." << std::endl << std::endl;
	} else {
		std::cout << "Invalid code." << std::endl
		<< "(input help for help, input quit to quit.)" << std::endl << std::endl;
	}
	return true;
}

#endif
