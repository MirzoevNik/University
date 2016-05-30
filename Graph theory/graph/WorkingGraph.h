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

	void setOfDegs(set< pair< int, bool > > &d); // ��������� �������� ������ �����
	void delArcs(); // 1_�_10

	void dfs(); // ����� � ������� (�������������)
	bool isAcyclic(); // 2_18

	int allCycles( list < list <int> > &cs ); // ������� ���� ������ �����, ���������� ���������� ��������� ���������
	bool checkOnTree(); //�������� �� ������
	int checkOnNewTree(); // 2_21
	list < int > listOfLeaf();
};

