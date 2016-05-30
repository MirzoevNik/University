#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>

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
		list < Vertex* > *l_vs = new list < Vertex* >;

		pairs p;
		p.first = v;
		p.second = l_vs;

		vertices.insert(p);
	}
}

void Graph::addVertexToList(int u, int x)
{
	addVertex(u);
	addVertex(x);
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		if ( (*i).first->getValue() == u )
		{
			bool find = false;
			for ( list <Vertex* > :: iterator j = (*i).second->begin(); j != (*i).second->end(); j++ )
			{
				if ( (*j)->getValue() == x )
					find = true;
			}
			if ( !find )
				(*i).second->push_back( findVertex(x) );
		}
		else if ( !direct && (*i).first->getValue() == x )
		{
			bool find = false;
			for ( list <Vertex* > :: iterator j = (*i).second->begin(); j != (*i).second->end(); j++ )
			{
				if ( (*j)->getValue() == u )
					find = true;
			}
			if ( !find )
				(*i).second->push_back( findVertex(u) );
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

Vertex* Graph::findVertexInList(int u, int x)
{
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		if ( (*i).first->getValue() == u)
		{
			for (list < Vertex* > :: iterator j = ((*i).second)->begin(); j != ((*i).second)->end(); j++)
			{
				if ( (*j)->getValue() == x )
					return (*j);
			}
		}
	}
	return NULL;
}

void Graph::delVertex(int x)
{
	set < pairs > :: iterator it = vertices.begin();
	while ( it != vertices.end() )
	{
		if ( (*it).first->getValue() != x )
		{
			delVertexFromList( (*it).first->getValue(), x );
		}
		it++;
	}

	it = vertices.begin();
	while ( it != vertices.end() )
	{
		if ( (*it).first->getValue() == x )
		{
			it = vertices.erase(it);
		}	
		it++;
	}
}

void Graph::delVertexFromList(int u, int x)
{
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		if ( (*i).first->getValue() == u)	
		{
			list < Vertex* > :: iterator j = ((*i).second)->begin();
			while ( j != ((*i).second)->end() )
			{
				if ( (*j)->getValue() == x )
				{
					j = ((*i).second)->erase(j);
					if (j == ((*i).second)->end())
						return;
				}
				j++;
			}
		}
	}
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
			std::size_t p = s.find(" ", x);
			if (p != string::npos)
			{
				s1 = s.substr(x, p - x);
				int u = atoi( s1.c_str() );
				addVertexToList(v, u);
				x = p + 1;
			}
			else
			{
				s1 = s.substr(x, s.length() - x);
				int u = atoi( s1.c_str() );
				addVertexToList(v, u);
				break;
			}
		}
	}
	in.close();
}

void Graph::printGraphConsole()
{
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		cout << (*i).first->getValue() << ": "; 
		for (list < Vertex* > :: iterator j = ((*i).second)->begin(); j != ((*i).second)->end(); j++)
			cout << (*j)->getValue() << " "; 
		cout << endl;
	}
	cout << endl;
}

void Graph::printGraphTxt(string file_name)
{
	ofstream out(file_name);
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		out << (*i).first->getValue() << ": "; 
		for (list < Vertex* > :: iterator j = ((*i).second)->begin(); j != ((*i).second)->end(); j++)
			out << (*j)->getValue() << " "; 
		out << endl;
	}
	out << endl;
	out.close();
}