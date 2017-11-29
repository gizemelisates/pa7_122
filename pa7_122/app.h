#ifndef APP_H
#define APP_H
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

#include "List.h"

using std::ifstream;
using std::ofstream;
using std::ios;
using std::vector;
using std::reverse;

class App
{
public:
	App(); 
	~App();

			
	int printMenu();
	int printSubMenu();
	void runApp();
	void storeMaster();
	void markAbsent();
	void saveDates();
	void readDates();
	void reportAll();
	void reportAbsences(const int absence);
	void generateReport();
	void editAbsences();
	string generateDate() const;
private:
	List mList;
	ifstream mInFile;
	ifstream mInMaster;
};

ifstream &operator >> (ifstream &lhs, List &rhs);
ifstream &operator > (ifstream &lhs, List &rhs);
ifstream &operator >> (ifstream &lhs, Stack &rhs);
ofstream &operator << (ofstream &lhs, List &rhs);
ofstream &operator << (ofstream &lhs, Stack &rhs);

#endif