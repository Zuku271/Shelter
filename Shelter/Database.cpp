#include <fstream>
#include <vector>
#include <iostream>
#include "Database.h"

using namespace std;

Database::Database(const char *db_file, unsigned int _Mode)
{
	/**
	*  
	*/

	try
	{
		file.open(db_file, _Mode);
		if (!file.is_open())
		{
			throw new exception("No such file");
		}

		/**
		* £adujemy ca³y plik do pamiêci
		*/
		file.seekg(0); // Ustawiamy siê na poczatku pliku
		char line[16];


		while(!file.eof())
		{
			file.getline(line, 16);
			loadedDB.push_back(line);
		}
	}
	catch (const char* err)
	{
		cout << "Error: " << err << endl;
	}


}


Database::~Database()
{
	file.clear();
	file.close();
}

void Database::getAllPets(void)
{
	for (list<string>::iterator i = loadedDB.begin(); i != loadedDB.end(); ++i)
	{
		//cout << loadedDB. << endl;
	}
}