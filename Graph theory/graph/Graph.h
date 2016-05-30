#pragma once

#include <set>
#include <list>
#include "Vertex.h"

using namespace std;

class Graph
{
protected:
	typedef list < Vertex* > *vs; // список смежных вершин
	typedef pair < Vertex*, vs > pairs; // характеристики одной вершины
	set < pairs > vertices; // множество вершин
	bool direct; // неориентированный/ориентированный
	
public:
	Graph(void); // пустой граф
	Graph(bool d); // пустой граф/орграф

	void addVertex(int x); // добавить вершину
	void addVertexToList(int u, int x); // добавить вершину в список смежности вершины v

	Vertex* findVertex(int x); // найти вершину по значению
	Vertex* findVertexInList(int u, int x); // найти вершину из списка смежностей по значений

	void delVertex(int x);
	void delVertexFromList(int u, int x);

	void readGraphTxt(string file_name);
	void printGraphConsole();
	void printGraphTxt(string file_name);
};

