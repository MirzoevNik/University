#pragma once

#include "Graph.h"
#include <vector>

class WorkingGraph : public Graph
{
public:
	WorkingGraph(void);
	WorkingGraph(bool d);
	~WorkingGraph(void);

	typedef pair < int, list <int> > leader; // лидер
	typedef pair < int, pair < int, int > > save_edge; // безопасное ребро

	WorkingGraph* operator = (WorkingGraph *g);
	
	void mstBoruvki(WorkingGraph *g); // алгоритм Борувки
	int dfs(list < leader > &leaders); // обход в глубину (нерекурсивный)
	list < save_edge > findSaveEdges(WorkingGraph *g, list< leader > leaders);

	vector < pair < int, int > > fordBellman(int v); // алгоритм Форда-Беллмана
	list <int> shortWay( int v, vector < pair < int, int > > d ); // кратчайший путь до вершины v
};

