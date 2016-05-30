#pragma once

#include "Graph.h"

class WorkingGraph : public Graph
{
public:
	WorkingGraph(void);
	WorkingGraph(bool d);
	~WorkingGraph(void);

	WorkingGraph* operator = (WorkingGraph *g);

	void printLoops(); // 1_a_11

	int isWay(int u, int v); // 1_a_16

	void setOfDegs(set< pair< int, bool > > &d); // множество степеней вершин графа
	void delArcs(); // 1_б_10

	void dfs(); // обход в глубину (нерекурсивный)
	bool isAcyclic(); // 2_18

	int allCycles( list < list <int> > &cs ); // подсчёт всех циклов графа, возвращает количество компонент связности
	bool checkOnTree(); //проверка на дерево
	int checkOnNewTree(); // 2_21
	list < int > listOfLeaf();
};

