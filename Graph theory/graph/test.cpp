#include <set>
#include <iostream>
#include <list>
#include "Graph.h"
#include "Vertex.h"
#include "WorkingGraph.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	/*
	WorkingGraph *g = new WorkingGraph(true);
	g->readGraphTxt("input_I_a_11.txt");
	g->printGraphConsole();
	g->printLoops();
	*/

	/*
	WorkingGraph *g = new WorkingGraph(true);
	g->readGraphTxt("input_I_a_16.txt");
	g->printGraphConsole();
	int u, v;
	cout << "������� ������� u: ";
	cin >> u;
	cout << "������� ������� v: ";
	cin >> v;
	int vertex = g->isWay(u, v);
	if ( vertex != -1 )
		cout << "����� ������� �� ������� u � ������� v ����� ������� " << vertex;
	else
		cout << "������ ������� �� ������� u � ������� v ����� ����� ���� �������";
	cout << endl;
	*/
	//// 1_�_10
	/*WorkingGraph *g = new WorkingGraph(true);
	g->readGraphTxt("input_I_�_10.txt");
	g->printGraphConsole();

	WorkingGraph *g2 = new WorkingGraph(true);
	*g2 = g;
	g2->delArcs();
	g2->printGraphConsole();*/
	
	/*WorkingGraph *g = new WorkingGraph(false);
	g->readGraphTxt("input_II_18.txt");
	g->printGraphConsole();

	if ( !g->isAcyclic() )
		cout << "���� ���������";
	else
		cout << "���� ����������";*/
	/*
	WorkingGraph *g = new WorkingGraph(false);
	g->readGraphTxt("input_II_21.txt");
	g->printGraphConsole();

	int x = g->checkOnNewTree();
	switch( x )
	{
	case -1:
		{
			cout << "������ �� ���������"; 
			break;
		}
	case 0:
		{
			list <int> l = g->listOfLeaf();
			cout << "���� ��� ������ => ����� ������� ����� ����.\n������ ������ ������: "; 
			for (list <int> :: iterator i = l.begin(); i != l.end(); i++)
			{
				cout << (*i) << " "; 
			}
			break;
		}
	default:
		{
			cout << "������ ��������� ��� �������� ������� " << x;
		}
	}*/
	
	cout << endl;
	system("pause");
	return 0;
}