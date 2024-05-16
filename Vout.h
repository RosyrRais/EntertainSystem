#ifndef VANISHOUT
#define VANISHOUT

#include <iostream>

class VanishOut {
	public:
		static bool vanish;
		void out(std::string s) {
			if(!vanish){
				std::cout << s;
			}
		}
};

bool VanishOut::vanish = false;

#endif
