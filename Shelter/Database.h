#pragma once
#include <fstream>
#include <vector>

using namespace std;

class Database
{

private:
	fstream file;
	vector<string> *loadedDB;

public:
	Database(const char*, unsigned int);
	~Database();


};

