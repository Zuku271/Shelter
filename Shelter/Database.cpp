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

		while(!file.eof())
		{
			file.getline(loadedDB, 16);
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
