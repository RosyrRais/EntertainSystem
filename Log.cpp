#ifndef LOG
#define LOG

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include "tools.h"

class Log{
	const std::string Database = "LogData.txt";
public:
	Log() {
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
	void check() {
		std::ifstream file(Database);
		if(!file.is_open()) {
			std::cout << "Error: cannot open Database." << std::endl;
		} else {
			std::string line;
			std::cout << "id\tdevice\tstaff\trevenue\tdate" << std::endl;
			int id = 0;
			while(std::getline(file, line)) {
				std::cout << ++id;
				std::string word = "";
				for(unsigned int i=0; i<line.length(); i++) {
					if(line[i] == '|') {
						std::cout << "\t" << word;
						word = "";
					} else {
						word = word + line[i];
					}
				}
				std::cout << std::endl;
			}
		}
	}
	void checkDevice(std::string dvc) {
		int rvn = 0;
		std::ifstream file(Database);
		std::string line;
		while(getline(file, line)) {
			std::string d = line.substr(0, line.find('|'));
			if(d == dvc) {
				rvn += std::stoi( line.substr(findNthOccurrence(line, '|', 2)+1, findNthOccurrence(line, '|', 3)) );
			}
		}
		std::cout << dvc << ": " << rvn << std::endl;
	}
	bool add(std::string d, std::string s, std::string r, std::string da) {
		std::ofstream ofile(Database, std::ios::app);
		if(!ofile.is_open()) return false;
		ofile << d << "|" << s << "|" << r << "|" << da << "|" << std::endl;
		return true;
	}
	bool del(int i) {
		std::ifstream ifile(Database);
		if(!ifile.is_open()) return false;
		int id = 0;
		std::string line;
		std::queue<std::string> delQueue;
		while(std::getline(ifile, line)) {
			if(++id != i) {
				delQueue.push(line);
			}
		}
		ifile.close();
		std::ofstream ofile(Database);
		while(!delQueue.empty()) {
			ofile << delQueue.front() << std::endl;
			delQueue.pop();
		}
		return true;
	}
	bool getLogData(int id, std::string *deviceName, std::string *staffName, std::string *revenue, std::string *date) {
		std::ifstream file(Database);
		std::string line;
		int i = 0;
		while(file >> line) {
			if(++i == id) { // there is a bug 全部读成第一个了 
				std::string word;
				int i = 0;
				while(line[i] != '|') word = word + line[i++];
				*deviceName = word; word = ""; i++;
				while(line[i] != '|') word = word + line[i++];
				*staffName = word; word = ""; i++;
				while(line[i] != '|') word = word + line[i++];
				*revenue = word; word = ""; i++;
				while(line[i] != '|') word = word + line[i++];
				*date = word; word = ""; i++;
				return true;
			}
		}
		return false;
	}
	void change(int id, std::string deviceName, std::string staffName, std::string revenue, std::string date) {
		std::ifstream ifile(Database);
		std::string line;
		std::queue<std::string> chgQueue;
		int i = 0;
		while(std::getline(ifile, line)){
			if(++i == id) {
				line = deviceName + "|" + staffName + "|" + revenue + "|" + date + "|";
			}
			chgQueue.push(line);
		}
		ifile.close();
		std::ofstream ofile(Database);
		while(!chgQueue.empty()) {
			ofile << chgQueue.front() << std::endl;
			chgQueue.pop();
		}
	}
};

#endif
