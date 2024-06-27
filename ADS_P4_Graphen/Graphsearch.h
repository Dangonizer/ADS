#pragma once
#include "EdgeWeightedDigraph.h"
#include "EdgeWeightedGraph.h"
#include <iostream>

namespace Graphsearch
{

	/**
	 * Fuehrt eine rekursive Tiefensuche im Graphen G,
	 * ab dem Knoten v aus und markiert alle besuchten
	 * Knoten in marked.
	 * Alle besuchten Knoten werden ausgegeben.
	 *
	 * \param[in]	 G			Graph
	 * \param[in]	 v			Startknoten
	 * \param[in/out] marked		Bereits besuchte Knoten
	 * \param[in/out] edgeTo		Vektor mit dem Nachfolgeknoten zu jedem Knoten
	 */
	void DFS_recursive(const EdgeWeightedGraph &G, int v, std::vector<bool> &marked, std::vector<int> &edgeTo)
	{
		std::cout << v << " -> ";
		marked[v] = true;
		for (Edge e : G.getAdj(v))
		{
			int w = e.other(v);
			if (!marked[w])
			{
				edgeTo[w] = v;
				DFS_recursive(G, w, marked, edgeTo);
			}
		}
	}

	/**
	 * Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus.
	 * Alle besuchten Knoten werden ausgegeben.
	 * Starterfunktion zu DFS_recursive(EdgeWeigtedGraph, int, std::vector<bool>, std::vector<int>)
	 *
	 * \param[in]  G			Graph
	 * \param[out] marked	Bereits besuchte Knoten
	 * \param[out] edgeTo	Vektor mit dem Nachfolgeknoten zu jedem Knoten
	 * \param[in]  v			Startknoten
	 * \return	  true		Graph ist zusammenhaengend
	 *			  false		Graph ist nicht zusammenhaengend
	 */

	bool DFS(const EdgeWeightedGraph &G, int v, std::vector<bool> &marked, std::vector<int> &edgeTo)
	{
		// marked.resize(G.getV(), false);
		// edgeTo.resize(G.getV(), -1);
		std::cout << "Tiefensuche (Depth-First-Search (DFS)) - Startknoten: " << v << std::endl;
		std::cout << "Besuchsreihenfolge:" << std::endl;

		marked = std::vector<bool>(G.getV(), false);
		edgeTo = std::vector<int>(G.getV(), -1);
		DFS_recursive(G, v, marked, edgeTo);
		bool connected = true;
		for (int i = 0; i < G.getV(); i++)
		{
			if (!marked[i])
			{
				connected = false;
				break;
			}
		}

		std::cout << std::endl;
		std::cout << "EdgeToArray:" << std::endl;
		for (int i = 0; i < G.getV(); i++)
		{
			std::cout << i << " -> " << edgeTo[i] << std::endl;
		}

		std::cout << "Marked:" << std::endl;
		for (int i = 0; i < G.getV(); i++)
		{
			std::cout << i << " -> " << marked[i] << std::endl;
		}

		if (connected)
		{
			std::cout << "Der Graph ist zusammenhaengend." << std::endl;
		}
		else
		{
			std::cout << "Der Graph ist nicht zusammenhaengend." << std::endl;
		}

		return connected;
	}

	/**
	 * Fuehrt eine iterative Breitensuche im Graphen g, ab dem Knoten v aus.
	 * Alle besuchten Knoten werden ausgegeben.
	 *
	 * \param[in]  G			Graph
	 * \param[in]  v			Startknoten
	 * \param[out] marked	Gibt an welche Knoten besucht wurden bei der Suche
	 * \param[out] edgeTo	Gibt den Nachfolgerknoten eines Knoten an
	 * \return	  true		Graph ist zusammenhaengend
	 *			  false		Graph ist nicht zusammenhaengend
	 */
	bool BFS(const EdgeWeightedGraph &G, int v, std::vector<bool> &marked, std::vector<int> &edgeTo)
	{
		// marked.resize(G.getV(), false);
		// edgeTo.resize(G.getV(), -1);

		std::cout << "Breitensuche (Breadth-First-Search (BFS)) - Startknoten: " << v << std::endl;
		std::cout << "Besuchsreihenfolge:" << std::endl;

		marked = std::vector<bool>(G.getV(), false);
		edgeTo = std::vector<int>(G.getV(), -1);
		std::queue<int> q;
		q.push(v);

		std::cout << v << " -> ";

		marked[v] = true;
		while (!q.empty())
		{
			int w = q.front();
			q.pop();
			for (Edge e : G.getAdj(w))
			{
				int x = e.other(w);
				if (!marked[x])
				{
					edgeTo[x] = w;
					marked[x] = true;

					std::cout << x << " -> ";

					q.push(x);
				}
			}
		}
		bool connected = true;
		for (int i = 0; i < G.getV(); i++)
		{
			if (!marked[i])
			{
				connected = false;
				break;
			}
		}

		std::cout << std::endl;
		std::cout << "EdgeToArray:" << std::endl;
		for (int i = 0; i < G.getV(); i++)
		{
			std::cout << i << " -> " << edgeTo[i] << std::endl;
		}

		std::cout << "Marked:" << std::endl;
		for (int i = 0; i < G.getV(); i++)
		{
			std::cout << i << " -> " << marked[i] << std::endl;
		}

		if (connected)
		{
			std::cout << "Der Graph ist zusammenhaengend." << std::endl;
		}
		else
		{
			std::cout << "Der Graph ist nicht zusammenhaengend." << std::endl;
		}

		return connected;
	}
}
