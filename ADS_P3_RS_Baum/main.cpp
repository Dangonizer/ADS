/*************************************************
 * ADS Praktikum 3
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Tree.h"
#include "catch.h"

using namespace std;

void mainscreen_addTreeCSV(Tree *&ref)
{
	char j;
	cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
			"importieren(j / n) ? >";
	cin >> j;
	if (j == 'j')
	{
		ifstream csvread;
		csvread.open("ExportZielanalyse.csv", ios::in);
		if (!csvread.is_open())
		{
			cout << "Fehler beim Lesen!" << endl;
			return;
		}
		else
		{
			string name, age, postcode, income;

			while (!csvread.eof())
			{
				getline(csvread, name, ';');
				getline(csvread, age, ';');
				getline(csvread, income, ';');
				getline(csvread, postcode, '\n');
				if (name == "" || age == "" || income == "" || postcode == "")
				{
					continue;
				}
				ref->addNode(name, stoi(age), stod(income), stoi(postcode));
			}
			csvread.close();
		}
		cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
	}
}

int main()
{

	int result = Catch::Session().run();

	///////////////////////////////////////
	// Ihr Code hier:

	//
	///////////////////////////////////////
	system("PAUSE");

	return result;
}
