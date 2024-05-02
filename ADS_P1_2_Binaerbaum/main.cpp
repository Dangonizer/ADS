/*************************************************
 * ADS Praktikum 1.2
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>
#include <fstream>

using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:

/***************************
 ** Vorgegebene  Funktion **
 ***************************
   "mainscreen_addTreeCSV" 
 
Importiert CSV Datei in bestehenden Baum.
Bei Aufruf in der main() Methode, muss der Pointer auf den Anker des Baums, als Parameter übergeben werden.
Es wird die im gleichen Verzeichnis liegende Datei "ExportZielanalyse.csv" geladen.
****************************/

void mainscreen_addTreeCSV(Tree* ref)
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
    cout << " ADS - ELK - Stack v1.9, by 25th Bam" << endl;
    cout << "=========================================" << endl;
    cout << "1) Datensatz einfuegen, manuell" << endl;
    cout << "2) Datensatz einfuegen, CSV Datei" << endl;
    cout << "3) Datensatz loeschen" << endl;
    cout << "4) Suchen" << endl;
    cout << "5) Datenstruktur anzeigen (pre/post/in)" << endl;
    cout << "6) Level-Order Ausgabe" << endl;
    cout << "7) Beenden" << endl;
}
//
///////////////////////////////////////
int main()
{

    int result = Catch::Session().run();
    Tree t1;
    Tree* tref = &t1;
    bool running = true;
    while (running){
        printMenu();
        int choice;
        cin >> choice;
        string name;
        int age;
        double income;
        int postcode;
        int id;
        switch (choice)
        {
        case 1:
            cout << "Name: ";
            cin >> name;
            cout << "Alter: ";
            cin >> age;
            cout << "Einkommen: ";
            cin >> income;
            cout << "PLZ: ";
            cin >> postcode;
            t1.addNode(name, age, income, postcode);
            cout << "Datensatz hinzugefuegt" << endl;
            break;
        case 2:
            mainscreen_addTreeCSV(&t1);
            break;
        case 3:
            cout << "NodeOrderID: ";
            cin >> id;
            if (t1.deleteNode(id))
            {
                cout << "Datensatz geloescht" << endl;
            }
            else
            {
                cout << "Datensatz nicht gefunden" << endl;
            }
            break;
        case 4:
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
        case 5:
            t1.printAll();
            break;
        case 6:
            cout << "Level-Order: " << endl;
            t1.levelOrder();
            break;
        case 7:
            cout << "Programm beenden" << endl;
            running = false;
            break;
        default:
            break;
        }
    }

    return 0;
}
