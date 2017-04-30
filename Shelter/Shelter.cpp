// Shelter.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "stdafx.h"
#include "Database.h"
#include "s_list.h"

using namespace std;

void ShowPetList(vector<string>);

int main()
{
	int MaxSlot;
	vector<string> PetList;
	string Action;
	string PetName;
	string End = "n";
	fstream file;

	s_list lista("A");
	lista.append(&lista,"B");
	lista.showAll(&lista);
	//lista.~s_list();

	Database db("data.txt", ios::in | ios::out);
	db.getAllPets();
	cout << "Max. number of pets:" << endl;
	cin >> MaxSlot;

	if (MaxSlot == 0)
	{
		return 1;
	}

	do
	{
		cout << "Add/Remove pet ?" << endl;
		cin >> Action;

		if (Action == "Add")
		{
			if (PetList.size() == MaxSlot)
			{
				cout << "Error: Shelter is full" << endl;
			}
			else
			{
				file.open("data.txt", ios::out | ios::app);
				if (file.is_open())
				{
					cout << "Type name:" << endl;
					cin >> PetName;
					PetList.push_back(PetName);
					file << PetName << endl;
					file.clear();
					file.close();
					cout << "Pet added." << endl;
				}
				else
				{
					cout << "Couldn't open file for write." << endl;
				}
			}
		}
		else if (Action == "Remove")
		{
			//file.open(db_file, ios::out);
			if (PetList.size() == 0)
			{
				cout << "Error: Shelter is empty" << endl;
				break;
			}
			
			cout << "Type name:" << endl;
			cin >> PetName;
			char SuccessFlag = 0;

			for (unsigned int i = 0; i < PetList.size(); i++)
			{
				if (PetList.at(i) == PetName)
				{
					cout << "Pet found. Removing from db." << endl;
					PetList.erase(PetList.begin() + i);
					SuccessFlag = 1;
					break;
				}
			}
			if (SuccessFlag == 0)
			{
				cout << "Pet not found." << endl;
			}
		}
		cout << "Want to quit ? Type y/n." << endl;
		cin >> End;
	}
	while (End == "n");

    return 0;
}

void ShowPetList(vector<string> PetList)
{
	cout << "List of pets:" << endl;
}