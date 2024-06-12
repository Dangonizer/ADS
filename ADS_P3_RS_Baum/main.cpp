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

void printMenu()
{
	cout << "=========================================" << endl;
	cout << " ADS-Rot-Schwarz-Baum Praktikum" << endl;
	cout << "=========================================" << endl;
	cout << "1) Datensatz einfuegen, manuell" << endl;
	cout << "2) Datensatz einfuegen, CSV Datei" << endl;
	cout << "3) Suchen" << endl;
	cout << "4) Ausgabe in Levelorder" << endl;
	cout << "5) Ausgabe in Levelorder (mit Niveauauswahl)" << endl;
	cout << "6) Beenden" << endl;
}

int main()
{

	int result = Catch::Session().run();

	Tree t1;
	Tree *tref = &t1;
	bool running = true;
	while (running)
	{
		printMenu();
		int choice;
		cin >> choice;
		string name;
		int age;
		double income;
		int postcode;
		int niveau;
		switch (choice)
		{
		case 1:
			cout << "Name: ";
			cin >> name;
			cout << "Alter: ";
			if (!(cin >> age))
			{
				cout << "Ungültige Eingabe für Alter." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			cout << "Einkommen: ";
			if (!(cin >> income))
			{
				cout << "Ungültige Eingabe für Einkommen." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			cout << "PLZ: ";
			if (!(cin >> postcode))
			{
				cout << "Ungültige Eingabe für PLZ." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			t1.addNode(name, age, income, postcode);
			cout << "Datensatz hinzugefuegt" << endl;
			break;
		case 2:
			mainscreen_addTreeCSV(tref);
			break;
		case 3:
			cout << "Name: ";
			cin >> name;
			if (t1.searchNode(name))
			{
				cout << "Datensatz gefunden" << endl;
			}
			else
			{
				cout << "Datensatz nicht gefunden" << endl;
			}
			break;
		case 4:
			cout << "Levelorder als BST: " << endl;
			t1.printAll();
			cout << "Levelorder als 2-3-4 Baum: " << endl;
			t1.printLevelOrder();
			break;
		case 5:
			cout << "Niveau: ";
			if (!(cin >> niveau))
			{
				cout << "Ungültige Eingabe für Niveau." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			t1.printLevelOrder(niveau);
			break;
		case 6:
			cout << "Programm beenden" << endl;
			running = false;
			break;
		default:
			break;
		}
	}

	return 0;

	return result;
}
