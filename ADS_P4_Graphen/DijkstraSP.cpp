#include <assert.h>
#include "DijkstraSP.h"

/**
 * F�ge eine Kante mit minimalen Kosten hinzu, die von einem
 * Baumknoten zu einem Nicht-Baumknoten verl�uft und deren
 * Ziel w dem Startknoten s am n�chsten ist.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  v		Zielknoten
 */
void DijkstraSP::relax(EdgeWeightedDigraph G, int v)
{
	for (DirectedEdge e : G.getAdj(v))
	{
		int w = e.to();
		if (distToVect[w] > distToVect[v] + e.weight())
		{
			distToVect[w] = distToVect[v] + e.weight();
			edgeTo[w] = e;
			if (pq.contains(w))
			{
				pq.change(w, distToVect[w]);
			}
			else
			{
				pq.push(w, distToVect[w]);
			}
		}
	}
}

/**
 * Fuert den Dijkstra Algorithmus von s, im Graph G aus.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  s		Startknoten
 */
DijkstraSP::DijkstraSP(EdgeWeightedDigraph G, int s)
{
	distToVect.resize(G.getV(), __DBL_MAX__);
	distToVect[s] = 0.0;
	pq.push(s, 0.0);
	while (!pq.empty())
	{
		int v = pq.top().value;
		pq.pop();
		relax(G, v);
	}
}

/**
 * Gibt die Distanz von s zum Knoten v zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Summe der Gewichte auf dem Pfad zu v
 */
double DijkstraSP::distTo(int v) const
{
	return distToVect[v];
}

/**
 * Gibt zurueck ob es einen Pfad zu v von s aus gibt
 *
 * \param[in]  v		Zielknoten
 * \return true, wenn es einen Pfad von s nach v gibt, sonst false
 */
bool DijkstraSP::hasPathTo(int v) const
{
	if (distToVect[v] < __DBL_MAX__)
	{
		return true;
	}
	return false;
}

/**
 * Gibt den Pfad von s nach v als Vektor zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Vektor mit allen Kanten des Pfades von s nach v
 */
std::vector<DirectedEdge> DijkstraSP::pathTo(int v)
{
	if (hasPathTo(v))
	{
		std::vector<DirectedEdge> path;
		DirectedEdge e = edgeTo[v];
		// for (DirectedEdge e = edgeTo[v]; edgeTo.count(e.to()) > 0; e = edgeTo[e.from()])
		while (true)
		{
			path.push_back(e);
			if (edgeTo.count(e.from()) == 0)
			{
				break;
			}
			e = edgeTo[e.from()];
		}
		std::reverse(path.begin(), path.end());
		return path;
	}
	return std::vector<DirectedEdge>();
}
