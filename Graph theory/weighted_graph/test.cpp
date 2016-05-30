#include <set>
#include <iostream>
#include <list>
#include "WorkingGraph.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	/*WorkingGraph *g = new WorkingGraph(false);
	g->readGraphTxt("input_III.txt");
	g->printGraphConsole();

	WorkingGraph *g2 = new WorkingGraph(false);
	g2->mstBoruvki(g);
	g2->printGraphConsole();*/

	WorkingGraph *g = new WorkingGraph(true);
	g->readGraphTxt("input_IV.txt");
	g->printGraphConsole();

	int u, v1, v2; 
	cout << endl << "������� ����� ������� u: ";
	cin >> u;
	cout << endl << "������� ����� ������� v1: ";
	cin >> v1;
	cout << endl << "������� ����� ������� v2: ";
	cin >> v2;
	cout << endl;

	vector < pair < int, int > > d = g->fordBellman(u);
	list <int> way = g->shortWay( v1, d );
	if ( way.empty() )
	{
		cout << "������� " << v1 << " ����������� �� ������� " << u << endl << endl;
	}
	else
	{
		cout << "���������� ���� �� ������� " << u << " � ������� " << v1 << ":" << endl; 
		for ( list <int> :: iterator i = way.begin(); i != way.end(); i++ )
			cout << *i << " ";
		cout << endl << "����� ��� ����: " << d[v1].first << endl << endl;
	}

	way = g->shortWay( v2, d );
	if ( way.empty() )
	{
		cout << "������� " << v2 << " ����������� �� ������� " << u << endl << endl;
	}
	else
	{
		cout << "���������� ���� �� ������� " << u << " � ������� " << v2 << ":" << endl; 
		for ( list <int> :: iterator i = way.begin(); i != way.end(); i++ )
			cout << *i << " ";
		cout << endl << "����� ��� ����: " << d[v2].first << endl << endl;
	}
	
	cout << endl;
	system("pause");
	return 0;
}