#include "KruskalMST.h"
#include <iostream>
/**
 * Erstellt einen MST zum Graph G mit dem Kruskal Algorithmus
 *
 * \param[in]  G		Kantengewichteter-Graph
 */
KruskalMST::KruskalMST(EdgeWeightedGraph G)
{
	treeID.resize(G.getV());
	for (int i = 0; i < G.getV(); i++)
	{
		treeID[i] = i;
	}
	std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
	for (Edge e : G.edges())
	{
		pq.push(e);
	}

	std::cout << "Kante";
	for (int i = 0; i < G.getV(); i++)
	{
		std::cout << " | " << i;
	}
	std::cout << std::endl;

	while (!pq.empty())
	{
		Edge e = pq.top();
		pq.pop();
		int v = e.either();
		int w = e.other(v);
		if (treeID[v] == treeID[w])
		{
			continue;
		}
		mst.push_back(e);
		int oldID = treeID[w];
		int newID = treeID[v];
		for (int i = 0; i < G.getV(); i++)
		{
			if (treeID[i] == oldID)
			{
				treeID[i] = newID;
			}
		}

		std::cout << "(" << e.either() << ", " << e.other(e.either()) << ", " << e.weight() << ")";
		for (int i = 0; i < G.getV(); i++)
		{
			std::cout << " | " << treeID[i];
		}
		std::cout << std::endl;
	}

	std::vector<int> partialWeight(G.getV(), 0);
	for (Edge e : mst)
	{
		partialWeight[treeID[e.either()]] += e.weight();
	}
	for (int i = 0; i < G.getV(); i++)
	{
		if (partialWeight[i] != 0)
			std::cout << "Gewicht Teilbaum " << i << ": " << partialWeight[i] << std::endl;
	}
}

/**
 * Gibt alle Kanten vom MST zurueck
 *
 * \return Vektor mit Kanten des MST
 */
std::vector<Edge> KruskalMST::edges() const
{
	return mst;
}

/**
 * Gibt die Summe aller Gewichte im MST zurueck
 *
 * \return Summe der Gewichte im MST
 */
double KruskalMST::weight() const
{
	double sum = 0.0;
	for (Edge e : mst)
	{
		sum += e.weight();
	}
	return sum;
}
