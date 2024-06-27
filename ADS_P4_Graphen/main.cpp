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
	cout << "Weiter mit beliebiger Eingabe ..." << endl;
	cout << "?>" << endl;
}

int main()
{
	// Starte Unit-Tests
	Catch::Session().run();

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
			PrimMST *prim;
			prim = new PrimMST(*G1, start);
			cout << "Minimaler Spannbaum (MST) nach Prim:" << endl;
			cout << "Gewicht: " << prim->weight() << endl;
			cout << "Adjazenzliste:" << endl;

			for (int v = 0; v < G1->getV(); v++)
			{
				cout << v << " ";
				for (Edge e : prim->edges())
				{
					if (e.either() == v /* || e.other(e.either()) == v */)
					{
						int w = e.other(v);
						cout << "->" << w << " [" << e.weight() << "] ";
					}
				}
				cout << endl;
			}
			break;
		case 5:
			if (G1 == nullptr)
			{
				cout << "Kein Graph eingelesen." << endl;
				break;
			}
			KruskalMST *kruskal;
			cout << "Minimaler Spannbaum (MST) nach Kruskal:" << endl;
			kruskal = new KruskalMST(*G1);
			cout << "Gesamtgewicht: " << kruskal->weight() << endl;

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
			cout << "Wähle Zielknoten: ";
			int ziel;
			if (!(cin >> ziel))
			{
				cout << "Ungültige Eingabe für Zielknoten." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
			cout << "Kürzeste Wege nach Dijkstra:" << endl;
			cout << "Start: " << start << endl;
			cout << "Ziel: " << ziel << endl;
			cout << "Pfad: ";
			for (DirectedEdge e : dijkstra->pathTo(ziel))
			{
				if (e == dijkstra->pathTo(ziel).front())
					cout << e.from();
				cout << " [" << e.weight() << "] " << "-> " << e.to();
			}
			cout << endl;
			cout << "Kosten: " << dijkstra->distTo(ziel) << endl;
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