#pragma once
#include <fstream>
#include <list>


using namespace std;

class Database
{

private:
	fstream file;
	list<string> loadedDB;

public:
	Database(const char*, unsigned int);
	~Database();
	
	void getAllPets(void);


};

