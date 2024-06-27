#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
#include "EdgeWeightedGraph.h"
#include "PrimMST.h"
#include "Graphsearch.h"
#include "KruskalMST.h"
#include "DijkstraSP.h"

using namespace std;

void printMenu()
{
	cout << "Praktikum 5: Graphenalgorithem:" << endl;
	cout << "1) Graph einlesen" << endl;
	cout << "2) Tiefensuche" << endl;
	cout << "3) Breitensuche" << endl;
	cout << "4) MST nach Prim (Eingabe: Startknoten)" << endl;
	cout << "5) MST nach Kruskal" << endl;
	cout << "6) Kürzeste Wege nach Dijkstra (Eingabe: Startknoten)" << endl;
	cout << "7) Ausgabe der Adjazenzliste" << endl;
	cout << "8) Kante löschen" << endl;
	cout << "9) Kante hinzufügen" << endl;
	cout << "10)Programm beenden" << endl;
	cout << " Weiter mit beliebiger Eingabe ..." << endl;
	cout << "?>" << endl;
}

int main()
{
	// Starte Unit-Tests
	Catch::Session().run();

	//------------------------------------------------------------------------
	// 1. Ausgabe eines Graphen als Adjazenzliste implementieren
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// 2. Suche in Graphen
	//------------------------------------------------------------------------
	// Verwenden Sie hierf�r die Vorlagen in Graphsearch.h
	//
	// Beispielaufruf der Tiefensuche:
	// std::vector<bool> marked;
	// std::vector<int>  edgeTo;
	// bool connected = Graphsearch::DFS(G1, start, marked, edgeTo);

	//------------------------------------------------------------------------
	// 3. Minimaler Spannbaum mit Prim und Kruskal
	//------------------------------------------------------------------------
	// Vorlage f�r Prim ist die Klasse PrimMST (PrimMST.h + PrimMST.cpp)
	// Vorlage f�r Kruskal ist die Klasse KruskalMST (KruskalMST.h + KruskalMST.cpp)
	//
	// Beispielaufruf von Prim:
	// PrimMST prim(G, 0);

	//------------------------------------------------------------------------
	// 4. Kuerzeste Wege mit Dijkstra
	//------------------------------------------------------------------------
	// Beispielaufruf von Dijkstra
	//
	// EdgeWeightedDigraph G1_directed("graph1.txt");
	// Dijkstra dijkstra(G1_directed, start);
	// path = dijkstra.pathTo(target);

	//------------------------------------------------------------------------
	// 5. Men� f�r Benutzereingaben
	//------------------------------------------------------------------------
	// Alle Funktionalit�ten aus der Aufgabenstellung muessen umgesetzt werden

	EdgeWeightedGraph *G1 = nullptr;
	EdgeWeightedDigraph *G1_directed = nullptr;

	bool running = true;
	while (running)
	{
		printMenu();
		int choice;
		cin >> choice;

		string name;

		switch (choice)
		{
		case 1:
			cout << "Graphnummer:";
			int graph;
			if (!(cin >> graph))
			{
				cout << "Ungültige Eingabe" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			G1 = new EdgeWeightedGraph("graph" + to_string(graph) + ".txt");
			G1_directed = new EdgeWeightedDigraph("graph" + to_string(graph) + ".txt");
			break;
		case 2:
			if (G1 == nullptr)
			{
				cout << "Kein Graph eingelesen." << endl;
				break;
			}
			cout << "Startknoten: ";
			int start;
			if (!(cin >> start))
			{
				cout << "Ungültige Eingabe für Startknoten." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			std::vector<bool> *marked;
			std::vector<int> *edgeTo;
			marked = new std::vector<bool>();
			edgeTo = new std::vector<int>();
			Graphsearch::DFS(*G1, start, *marked, *edgeTo);
			break;
		case 3:
			if (G1 == nullptr)
			{
				cout << "Kein Graph eingelesen." << endl;
				break;
			}
			cout << "Startknoten: ";
			if (!(cin >> start))
			{
				cout << "Ungültige Eingabe für Startknoten." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			marked = new std::vector<bool>();
			edgeTo = new std::vector<int>();
			Graphsearch::BFS(*G1, start, *marked, *edgeTo);
			break;
		case 4:

			break;
		case 5:

			break;
		case 6:
			if (G1 == nullptr)
			{
				cout << "Kein Graph eingelesen." << endl;
				break;
			}
			cout << "Startknoten: ";
			// int start;
			if (!(cin >> start))
			{
				cout << "Ungültige Eingabe für Startknoten." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			DijkstraSP *dijkstra;
			dijkstra = new DijkstraSP(*G1_directed, start);
			for (int i = 0; i < G1_directed->getV(); i++)
			{
				if (dijkstra->hasPathTo(i))
				{
					cout << "Kürzester Weg von " << start << " nach " << i << ": " << dijkstra->distTo(i) << endl;
					cout << "Pfad: ";
					for (DirectedEdge e : dijkstra->pathTo(i))
					{
						cout << e.from() << "->" << e.to() << " [" << e.weight() << "] ";
					}
					cout << endl;
				}
			}
			break;
		case 7:
			if (G1 == nullptr)
			{
				cout << "Kein Graph eingelesen." << endl;
				break;
			}
			cout << "Adjazenzliste (undirected):" << endl;
			for (int i = 0; i < G1->getV(); i++)
			{
				cout << i << ": ";
				for (Edge e : (*G1)[i])
				{
					cout << "->" << e.other(i) << " [" << e.weight() << "] ";
				}
				cout << endl;
			}
			cout << "Adjazenzliste (directed):" << endl;
			for (int i = 0; i < G1_directed->getV(); i++)
			{
				cout << i << ": ";
				for (DirectedEdge e : (*G1_directed)[i])
				{
					cout << "->" << e.to() << " [" << e.weight() << "] ";
				}
				cout << endl;
			}
			break;
		case 8:
			if (G1 == nullptr)
			{
				cout << "Kein Graph eingelesen." << endl;
				break;
			}
			cout << "Kante löschen" << endl;
			cout << "Startknoten: ";
			int from;
			if (!(cin >> from))
			{
				cout << "Ungültige Eingabe für Startknoten." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			cout << "Endknoten: ";
			int to;
			if (!(cin >> to))
			{
				cout << "Ungültige Eingabe für Endknoten." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			cout << "Gewicht: ";
			double weight;
			if (!(cin >> weight))
			{
				cout << "Ungültige Eingabe für Gewicht." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			G1->del_Edge(Edge(from, to, weight));
			G1_directed->del_Edge(DirectedEdge(from, to, weight));
			break;
		case 9:
			if (G1 == nullptr)
			{
				cout << "Kein Graph eingelesen." << endl;
				break;
			}
			cout << "Kante hinzufügen" << endl;
			cout << "Startknoten: ";
			// int from;
			if (!(cin >> from))
			{
				cout << "Ungültige Eingabe für Startknoten." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			cout << "Endknoten: ";
			// int to;
			if (!(cin >> to))
			{
				cout << "Ungültige Eingabe für Endknoten." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			cout << "Gewicht: ";
			// double weight;
			if (!(cin >> weight))
			{
				cout << "Ungültige Eingabe für Gewicht." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			G1->add(Edge(from, to, weight));
			G1_directed->add(DirectedEdge(from, to, weight));
			break;
		case 10:
			cout << "Programm beenden" << endl;
			running = false;
			break;
		default:
			break;
		}
	}

	return 0;
}