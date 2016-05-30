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
	cout << "Введите вершину u: ";
	cin >> u;
	cout << "Введите вершину v: ";
	cin >> v;
	int vertex = g->isWay(u, v);
	if ( vertex != -1 )
		cout << "Можно попасть из вершины u в вершину v через вершину " << vertex;
	else
		cout << "Нельзя попасть из вершины u в вершину v ровно через одну вершину";
	cout << endl;
	*/
	//// 1_б_10
	/*WorkingGraph *g = new WorkingGraph(true);
	g->readGraphTxt("input_I_б_10.txt");
	g->printGraphConsole();

	WorkingGraph *g2 = new WorkingGraph(true);
	*g2 = g;
	g2->delArcs();
	g2->printGraphConsole();*/
	
	/*WorkingGraph *g = new WorkingGraph(false);
	g->readGraphTxt("input_II_18.txt");
	g->printGraphConsole();

	if ( !g->isAcyclic() )
		cout << "Граф цикличный";
	else
		cout << "Граф ацикличный";*/
	/*
	WorkingGraph *g = new WorkingGraph(false);
	g->readGraphTxt("input_II_21.txt");
	g->printGraphConsole();

	int x = g->checkOnNewTree();
	switch( x )
	{
	case -1:
		{
			cout << "Дерево не получится"; 
			break;
		}
	case 0:
		{
			list <int> l = g->listOfLeaf();
			cout << "Граф уже дерево => можно удалить любой лист.\nСписок листов дерева: "; 
			for (list <int> :: iterator i = l.begin(); i != l.end(); i++)
			{
				cout << (*i) << " "; 
			}
			break;
		}
	default:
		{
			cout << "Дерево получится при удалении вершины " << x;
		}
	}*/
	
	cout << endl;
	system("pause");
	return 0;
}