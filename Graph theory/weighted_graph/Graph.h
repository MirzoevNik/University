#pragma once

#include <set>
#include <list>
#include "Vertex.h"

using namespace std;

class Graph
{
protected:
	typedef pair < Vertex*, int > edges; // характеристики одного ребра
	typedef list < edges > *vs; // список смежных вершин 
	typedef pair < Vertex*, vs > pairs; // характеристики одной вершины
	set < pairs > vertices; // множество вершин
	bool direct; // неориентированный/ориентированный
	
public:
	Graph(void); // пустой граф
	Graph(bool d); // пустой граф/орграф

	void addVertex(int x); // добавить вершину
	void addVertexToList(int u, int x, int e); // добавить вершину в список смежности вершины v

	Vertex* findVertex(int x); // найти вершину по значению

	void readGraphTxt(string file_name);
	void printGraphConsole();
	void printGraphTxt();
};

