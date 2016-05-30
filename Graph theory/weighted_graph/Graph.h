#pragma once

#include <set>
#include <list>
#include "Vertex.h"

using namespace std;

class Graph
{
protected:
	typedef pair < Vertex*, int > edges; // �������������� ������ �����
	typedef list < edges > *vs; // ������ ������� ������ 
	typedef pair < Vertex*, vs > pairs; // �������������� ����� �������
	set < pairs > vertices; // ��������� ������
	bool direct; // �����������������/���������������
	
public:
	Graph(void); // ������ ����
	Graph(bool d); // ������ ����/������

	void addVertex(int x); // �������� �������
	void addVertexToList(int u, int x, int e); // �������� ������� � ������ ��������� ������� v

	Vertex* findVertex(int x); // ����� ������� �� ��������

	void readGraphTxt(string file_name);
	void printGraphConsole();
	void printGraphTxt();
};

