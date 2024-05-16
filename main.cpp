#include "Device.cpp"
#include "Staff.cpp"
#include "Log.cpp"
#include "RootSystem.h"
#include "DeviceSystem.h"
#include "StaffSystem.h"
#include "LogSystem.h"

#include <iostream>
#include <map>
using namespace std;

map<int, string> Status = {
	{0, "@root>>"},
	{1, "@device>>"},
	{2, "@staff>>"},
	{3, "@log>>"},
};

int main() {
	
	int run = 0;
	string code;
	
	while(1) {
		cout << Status[run];
		cin >> code;
		if(run == 0) {
			if(!rootSystem(code, &run)) break;
		} else if(run == 1) {
			DeviceSystem(code, &run);
		} else if(run == 2) {
			StaffSystem(code, &run);
		} else if(run == 3) {
			LogSystem(code, &run);
		} else {
			cout << "Invalid code." << endl
			<< "(input device/staff/log to manage, or input quit to quit)" << endl << endl;
		}
	}
	
	return 0;
}
