#ifndef VOUT
#define VOUT

#include <iostream>

class VanishOut {
	public:
		static bool vanish;
		void vout(std::string s) {
			if(!vanish) std::cout << s;
		}
};

VanishOut v;
bool VanishOut::vanish = false;

#endif
