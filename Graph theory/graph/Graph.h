#pragma once

#include <set>
#include <list>
#include "Vertex.h"

using namespace std;

class Graph
{
protected:
	typedef list < Vertex* > *vs; // ������ ������� ������
	typedef pair < Vertex*, vs > pairs; // �������������� ����� �������
	set < pairs > vertices; // ��������� ������
	bool direct; // �����������������/���������������
	
public:
	Graph(void); // ������ ����
	Graph(bool d); // ������ ����/������

	void addVertex(int x); // �������� �������
	void addVertexToList(int u, int x); // �������� ������� � ������ ��������� ������� v

	Vertex* findVertex(int x); // ����� ������� �� ��������
	Vertex* findVertexInList(int u, int x); // ����� ������� �� ������ ���������� �� ��������

	void delVertex(int x);
	void delVertexFromList(int u, int x);

	void readGraphTxt(string file_name);
	void printGraphConsole();
	void printGraphTxt(string file_name);
};

