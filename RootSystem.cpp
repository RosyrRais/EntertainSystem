#ifndef ROOTSYSTEM
#define ROOTSYSTEM

#include <iostream>
namespace {
	bool rootSystem(std::string code, int *run, bool *vanish) {
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
			std::cout << "helps" << std::endl;
			std::cout << std::endl;
		} else if(code == "clearMode") {
			*vanish = !*vanish;
			if(*vanish) std::cout << "Clear mode on." << std::endl << std::endl;
			else std::cout << "Clear mode off." << std::endl << std::endl;
		} else {
			std::cout << "Invalid code." << std::endl
			<< "(input help for help, input quit to quit.)" << std::endl << std::endl;
		}
		return true;
	}
}

#endif
