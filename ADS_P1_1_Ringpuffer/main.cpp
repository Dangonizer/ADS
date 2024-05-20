/*************************************************
* ADS Praktikum 1.1
* main.cpp
* 
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.h"

using namespace std;

void print_menu()
{
    cout << "====================================" << endl
        << " SuperBackUp-Organizer over 9000, by. Son Goku" << endl
        << "====================================" << endl
        << "1) Backup anlegen" << endl
        << "2) Backup suchen" << endl
        << "3) Alle Backups ausgeben" << endl
        << "4) Programm beenden" << endl
        << "?> ";
}

int main()
{
	int result = Catch::Session().run();
	// Ihr Code hier:
    Ring r1;
    bool running = true;
    while (running){
        print_menu();
        int choice;
        cin >> choice;
        cin.clear();
		cin.ignore();
        string description;
        string data;
        string search;
        switch (choice)
        {
        case 1:
            cout << "Backup anlegen" << endl;
            cout << "Beschreibung: ";
            getline(cin, description);
            cout << "Daten: ";
            getline(cin, data);
            r1.addNewNode(description, data);
            break;
        case 2:
            cout << "Backup suchen" << endl;
            cout << "Suche: ";
            getline(cin, search);
            if (r1.search(search))
            {
                cout << "Backup gefunden" << endl;
            }
            else
            {
                cout << "Backup nicht gefunden" << endl;
            }
            break;
        case 3:
            cout << "Alle Backups ausgeben" << endl;
            r1.print();
            break;
        case 4:
            cout << "Programm beenden" << endl;
            running = false;
            break;
        
        default:
            break;
        }
    }
    
	//
	///////////////////////////////////////
	return result;
}