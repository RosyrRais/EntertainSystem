#ifndef STAFF
#define STAFF

#include <iostream>
#include <fstream>
#include <queue>

class Staff {
	const std::string Database = "StaffData.txt";
public:
	Staff() {
		std::ifstream ifile(Database);
		if(!ifile.is_open()) {
			std::cout << "There is no StaffDatabase, creating..." << std::endl;
			std::ofstream file(Database);
		}
	}
	bool empty() {
		std::ifstream file(Database);
		std::string s;
		while(file >> s) return false;
		return true;
	}
	void print() {
		std::ifstream file(Database);
		if(!file.is_open()) { std::cout << "Error: cannot open staff database." << std::endl; return;}
		std::cout << "Staff:" << std::endl;
		std::string s;
		int i = 0;
		while(file >> s)  std::cout << ++i << ": " << s << std::endl;
	}
	bool add(std::string n) {
		std::ifstream ifile(Database);
		if(!ifile.is_open()) return false;
		std::string name;
		while(ifile >> name) if(name == n) return false;
		ifile.close();
		std::ofstream ofile(Database, std::ios::app);
		if(!ofile.is_open()) return false;
		ofile << n << "\t";
		return true;
	}
	bool del(int i) {
		std::ifstream file(Database);
		if(!file.is_open()) return false;
		std::string name;
		int id = 0;
		std::queue<std::string> delQueue;
		while(file >> name) {
			id++;
			if(id != i) {
				delQueue.push(name);
			}
		}
		file.close();
		std::ofstream ofile(Database);
		while(!delQueue.empty()){
			ofile << delQueue.front() << "\t";
			delQueue.pop();
		}
		return true;
	}
	std::string idToName(int i) {
		std::ifstream file(Database);
		std::string name;
		int id = 0;
		while(file >> name)
			if(++id == i)
				return name;
		return "None";
	}
};

#endif
