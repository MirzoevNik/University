#pragma once

#include "Graph.h"
#include <vector>

class WorkingGraph : public Graph
{
public:
	WorkingGraph(void);
	WorkingGraph(bool d);
	~WorkingGraph(void);

	typedef pair < int, list <int> > leader; // �����
	typedef pair < int, pair < int, int > > save_edge; // ���������� �����

	WorkingGraph* operator = (WorkingGraph *g);
	
	void mstBoruvki(WorkingGraph *g); // �������� �������
	int dfs(list < leader > &leaders); // ����� � ������� (�������������)
	list < save_edge > findSaveEdges(WorkingGraph *g, list< leader > leaders);

	vector < pair < int, int > > fordBellman(int v); // �������� �����-��������
	list <int> shortWay( int v, vector < pair < int, int > > d ); // ���������� ���� �� ������� v
};

