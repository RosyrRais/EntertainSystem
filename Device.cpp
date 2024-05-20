#ifndef DEVICE
#define DEVICE

#include <iostream>
#include <fstream>
#include <queue>

#include "log.cpp"

class Device {
	const std::string Database = "DeviceData.txt";
public:
	Device() {
		std::ifstream ifile(Database);
		if(!ifile.is_open()) {
			std::cout << "There is no DeviceDatabase, creating..." << std::endl;
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
		if(!file.is_open()) { std::cout << "Error: cannot open device database." << std::endl; return;}
		std::cout << "Device:" << std::endl;
		std::string id, dvc;
		while(file >> id >> dvc)  std::cout << id << ": " << dvc << std::endl;
	}
	bool add(std::string i, std::string d) {
		std::ifstream ifile(Database);
		if(!ifile.is_open()) return false;
		std::string id, dvc;
		while(ifile >> id >> dvc) if(dvc == d) return false;
		ifile.close();
		std::ofstream ofile(Database, std::ios::app);
		if(!ofile.is_open()) return false;
		ofile << i << "\t" << d << "\t";
		return true;
	}
	bool del(std::string i) {
		std::ifstream file(Database);
		if(!file.is_open()) return false;
		std::string id, dvc;
		std::queue<std::string> delQueue;
		while(file >> id >> dvc)
			if(id != i) {
				delQueue.push(id);
				delQueue.push(dvc);
			}
		file.close();
		std::ofstream ofile(Database);
		while(!delQueue.empty()){
			ofile << delQueue.front() << "\t";
			delQueue.pop();
		}
		return true;
	}
	std::string idToName(std::string i) {
		std::ifstream file(Database);
		std::string id, name;
		while(file >> id >> name)
			if(id == i)
				return name;
		return "None";
	}
	void printLog() {
		std::ifstream file(Database);
		std::string id, name;
		Log log;
		while(file >> id >> name) {
			std::cout << name << ": " << log.checkDevice(name) << std::endl;
		}
	}
	void printStream() {
		std::ifstream file(Database);
		std::string id, name;
		Log log;
		while(file >> id >> name) {
			std::cout << name << ": " << log.checkDevice(name, true) << std::endl;
		}
	}
};


#endif
