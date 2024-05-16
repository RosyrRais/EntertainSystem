#ifndef LOG
#define LOG

#include <iostream>
#include <fstream>
#include <queue>

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
				std::cout << ++id << "\t" << line << std::endl;
			}
		}
	}
	bool add(std::string d, std::string s, std::string r, std::string da) {
		std::ofstream ofile(Database, std::ios::app);
		if(!ofile.is_open()) return false;
		ofile << d << "\t" << s << "\t" << r << "\t" << da << std::endl;
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
	bool getLogData(std::string id, std::string *deviceName, std::string *staffName, std::string *revenue, std::string *date) {
		std::ifstream file(Database);
		std::string line;
		while(file >> line) {
			int start = 0, end = line.find(' ');
			if(id == line.substr(start, end)) {
				start = end+1; end = line.find(' ', start);
				*deviceName = line.substr(start, end);
				start = end+1; end = line.find(' ', start);
				*staffName = line.substr(start, end);
				start = end+1; end = line.find(' ', start);
				*revenue = line.substr(start, end);
				start = end+1; end = line.find(' ', start);
				*date = line.substr(start, end);
				return true;
			}
		}
		return false;
	}
	bool change(std::string id, std::string deviceName, std::string staffName, std::string revenue, std::string date) {
		
		return false;
	}
};

#endif
