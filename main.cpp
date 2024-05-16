#include "Device.cpp"
#include "Staff.cpp"
#include "Log.cpp"
#include "RootSystem.cpp"

#include <iostream>
#include <map>
using namespace std; 

bool vanishOut = false;

map<int, string> Status = {
	{0, "@root>>"},
	{1, "@device>>"},
	{2, "@staff>>"},
	{3, "@log>>"},
};

void vout(string s) {
	if(!vanishOut) cout << s;
}

int main() {
	
	Device device;
	Staff staff;
	Log log;
	
	int run = 0;
	string code;
	
	while(1) {
		cout << Status[run];
		cin >> code;
		if(run == 0) {
			if(!rootSystem(code, &run, &vanishOut)) break;
		} else if(run == 1) { //Device
			if(code == "add") {
				string deviceName, deviceId;
				vout("Device id: ");
				cin >> deviceId;
				vout("Device name: ");
				cin >> deviceName;
				if(!device.add(deviceId, deviceName)) {
					cout << "Error: device already exist or database error." << endl;	
				}
				cout << endl;
			} else if(code == "delete") {
				if(device.empty()) {
					cout << "Database empty." << endl << endl;
					continue;
				}
				string deviceName;
				vout("input delete device id: ");
				cin >> deviceName;
				if(!device.del(deviceName))
					cout << "Error: device not exist or database error." << endl;
				else
					cout << "Success: " << deviceName << " had been deleted." << endl;
				cout << endl;
			} else if(code == "check") {
				cout << endl;
				device.print();
				if(device.empty()) cout << "Its empty." << endl;
				cout << endl;
			} else if(code == "quit") {
				run = 0;
				cout << endl;
			} else {
				cout << "Invalid code." << endl 
				<< "(input check/add/delete to manage, or input quit to quit)" << endl << endl;
			}
		} else if(run == 2) { //Staff
			if(code == "check") {
				cout << endl;
				staff.print();
				if(staff.empty()) cout << "Its empty." << endl;
				cout << endl;
			} else if(code == "add") {
				vout("input name of the staff: ");
				string name;
				cin >> name;
				if(staff.add(name))
					cout << "Success: " << name << " had been added in staff." << endl; 
				else 
					cout << "Error: " << name << " already exist or database error." << endl;
				cout << endl;
			} else if(code == "delete") {
				if(staff.empty()) cout << "Its empty." << endl; 
				vout("input id of the staff who to be delete: ");
				int id;
				cin >> id;
				if(staff.del(id))
					cout << "Success: Staff remove success." << endl;
				else
					cout << "Error: Invalid id or database error." << endl;
				cout << endl;
			} else if(code == "quit") {
				run = 0;
				cout << endl;
			} else {
				cout << "Invalid code." << endl 
				<< "(input check/add/delete to manage, or input quit to quit)" << endl << endl;
			}
		} else if(run == 3) { //Log 
			if(code == "check") {
				cout << endl;
				log.check();
				cout << endl;
			} else if(code == "add") {
				string d,s,v,da;
				device.print();
				while(1) {
					vout("input the device id: ");
					cin >> d;
					d = device.idToName(d);
					if(d != "None") {
						cout << endl;
						break;
					}
					cout << "Invalid id it is." << endl << endl;
				}
				staff.print();
				while(1) {
					vout("input the staff id: ");
					int ss;
					cin >> ss;
					s = staff.idToName(ss);
					if(s != "None") {
						cout << endl;
						break;
					}
					cout << "Invalid id it is." << endl << endl;
				}
				vout("input the revanue: ");
				cin >> v;
				vout("input the date: ");
				cin >> da;
				log.add(d, s, v, da);
				cout << endl;
			} else if(code == "delete") {
				int id;
				vout("input id of the log you delete: ");
				cin >> id;
				if(log.del(id)) cout << "Success: delete success." << endl;
				else cout << "Error: log not exist or database error." << endl;
				cout << endl;
			} else if(code == "quit") {
				run = 0;
				cout << endl;
			} else {
				cout << "Invalid code." << endl 
				<< "(input check/add/delete to manage, or input quit to quit)" << endl << endl;
			}
		} else {
			cout << "Invalid code." << endl 
			<< "(input device/staff/log to manage, or input quit to quit)" << endl << endl;
		}
	}
	
	return 0;
}
