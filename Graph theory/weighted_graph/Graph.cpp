#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>

typedef pair < int, pair < int, list <int> > > leader;
typedef pair < int, pair < int, int > > save_edge;

Graph::Graph(void)
{
	direct = false;
}

Graph::Graph(bool d)
{
	direct = d;
}

void Graph::addVertex(int x)
{
	if (findVertex(x) == NULL)
	{
		Vertex *v = new Vertex(x);
		list < edges > *l_vs = new list < edges >;

		pairs p;
		p.first = v;
		p.second = l_vs;

		vertices.insert(p);
	}
}

void Graph::addVertexToList(int u, int x, int e)
{
	addVertex(u);
	addVertex(x);
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		if ( (*i).first->getValue() == u )
		{
			bool find = false;
			for ( list < edges > :: iterator j = (*i).second->begin(); j != (*i).second->end(); j++ )
			{
				if ( (*j).first->getValue() == x )
					find = true;
			}
			if ( !find )
			{
				edges ed;
				ed.first = findVertex(x);
				ed.second = e;
				(*i).second->push_back( ed );
			}
		}
		else if ( !direct && (*i).first->getValue() == x )
		{
			bool find = false;
			for ( list < edges > :: iterator j = (*i).second->begin(); j != (*i).second->end(); j++ )
			{
				if ( (*j).first->getValue() == u )
					find = true;
			}
			if ( !find )
			{
				edges ed;
				ed.first = findVertex(u);
				ed.second = e;
				(*i).second->push_back( ed );
			}
		}
	}
}

Vertex* Graph::findVertex(int x)
{
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		if ( (*i).first->getValue() == x)
			return (*i).first;
	}
	return NULL;
}

void Graph::readGraphTxt(string file_name)
{
	ifstream in(file_name);
	while (in.peek() != EOF)
	{
		string s;
		getline(in, s);
		int x = s.find(':');
		string s1 = s.substr(0, x);
		int v = atoi( s1.c_str() );
		addVertex(v);
		x += 2;
		while (x < s.length())
		{
			std::size_t p = s.find("(", x);
			s1 = s.substr(x, p - x);
			int u = atoi( s1.c_str() );

			x = p + 1;
			p = s.find(")", x);
			s1 = s.substr(x, p - x);
			int e = atoi( s1.c_str() );

			addVertexToList(v, u, e);

			x = p + 2;
		}
	}
	in.close();
}

void Graph::printGraphConsole()
{
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		cout << (*i).first->getValue() << ": "; 
		for (list < edges > :: iterator j = (*i).second->begin(); j != (*i).second->end(); j++)
			cout << (*j).first->getValue() << "(" << (*j).second << ")" << " "; 
		cout << endl;
	}
	cout << endl;
}

void Graph::printGraphTxt()
{
	ofstream out("output.txt");
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		out << (*i).first->getValue() << ": "; 
		for (list < edges > :: iterator j = (*i).second->begin(); j != (*i).second->end(); j++)
			out << (*j).first->getValue() << "(" << (*j).second << ")" << " "; 
		out << endl;
	}
	out << endl;
	out.close();
}