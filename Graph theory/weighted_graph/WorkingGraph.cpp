#include "WorkingGraph.h"
#include <stack>
#include <iostream>

WorkingGraph::WorkingGraph(void) : Graph()
{
}

WorkingGraph::WorkingGraph(bool d) : Graph(d)
{
}

WorkingGraph::~WorkingGraph(void)
{
}

WorkingGraph* WorkingGraph::operator = (WorkingGraph *g)
{
	for (set < pairs > :: iterator i = g->vertices.begin(); i != g->vertices.end(); i++)
	{
		addVertex( (*i).first->getValue() );
	}
	
	return this;
}

typedef pair < int, pair < int, list <int> > > leader;
typedef pair < int, pair < int, int > > save_edge;

void WorkingGraph::mstBoruvki(WorkingGraph *g)
{
	*this = g;

	int count_components = vertices.size(); // кол-во компонент связности
	list < leader > leaders; // список лидеров

	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		leader p;
		p.first = (*i).first->getValue(); // вершина-лидер
		p.second.push_back( (*i).first->getValue() ); // список вершин из одной комп.связн. с лидером
		leaders.push_back(p);
	}

	while (count_components > 1)
	{
		list < save_edge > save = findSaveEdges(g, leaders);
		for ( list < save_edge > :: iterator se = save.begin(); se != save.end(); se++ )
			addVertexToList( (*se).first, (*se).second.second, (*se).second.first );
		leaders.clear();
		count_components = dfs(leaders);
	}
}

int WorkingGraph::dfs(list < leader > &leaders)
{
	stack < pairs > st;
	int count = 0;
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		if ( (*i).first->getColor() == 0 )
		{
			count++;

			leader lead;
			lead.first = (*i).first->getValue(); // добавляем вершину к списку лидеров
			lead.second.push_back( (*i).first->getValue() );

			(*i).first->setColor(1);
			st.push( *i );

			while ( !st.empty() )
			{
				pairs u = st.top();
				u.first->setColor(1);
				bool flag = false;
				for (list < edges > :: iterator j = u.second->begin(); j != u.second->end(); j++)
				{
					if ( (*j).first->getColor() == 0 )
					{
						flag = true;
						Vertex *w = (*j).first;
						w->setColor(2);

						lead.second.push_back( w->getValue() );

						pairs p;
						for (set < pairs > :: iterator k = vertices.begin(); k != vertices.end(); k++)
						{
							if ( (*k).first->getValue() == w->getValue() )
							{
								p = (*k);
								break;
							}
						}
						st.push(p);
						break;
					}			
				}
				if (flag == false)
				{
					u.first->setColor(2);
					st.pop();
				}
			}

			leaders.push_back(lead);
		}
	}

	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		(*i).first->setColor(0);
	}

	return count;
}

list < save_edge > WorkingGraph::findSaveEdges(WorkingGraph *g, list < leader > leaders)
{
	list < save_edge > save;

	for ( list <leader> :: iterator i = leaders.begin(); i != leaders.end(); i++ )
	{
		save_edge se;
		se.first = (*i).first;
		se.second.first = 100000;
		se.second.second = -1;
		save.push_back(se);
	}

	for ( set < pairs > :: iterator i = g->vertices.begin(); i != g->vertices.end(); i++ )
	{
		for (list < edges > :: iterator j = (*i).second->begin(); j != (*i).second->end(); j++)
		{
			int v, u;
			short c = 0;
			for ( list < leader > :: iterator leads = leaders.begin(); leads != leaders.end(); leads++)
			{
				for ( list <int> :: iterator k = (*leads).second.begin(); k != (*leads).second.end(); k++ )
				{
					if ( *k == (*i).first->getValue() )
					{
						v = (*leads).first;
						c++;
					}
					if ( *k == (*j).first->getValue() )
					{
						u = (*leads).first;
						c++;
					}
					if (c == 2)
						break;
				}
				if (c == 2)
					break;
			}

			if (v != u)
			{
				for ( list < save_edge > :: iterator se = save.begin(); se != save.end(); se++ )
				{
					if ( (*se).first == v && (*j).second < (*se).second.first )
					{
						(*se).first = (*i).first->getValue();
						(*se).second.first = (*j).second;
						(*se).second.second = (*j).first->getValue();
						for ( list < leader > :: iterator leads = leaders.begin(); leads != leaders.end(); leads++)
						{
							if ( leads->first == v)
							{
								leads->first = (*i).first->getValue();
							}
						}
					}
					if ( (*se).first == u && (*j).second < (*se).second.first )
					{
						(*se).first = (*j).first->getValue();
						(*se).second.first = (*j).second;
						(*se).second.second = (*i).first->getValue();
						for ( list < leader > :: iterator leads = leaders.begin(); leads != leaders.end(); leads++)
						{
							if ( leads->first == u)
							{
								leads->first = (*j).first->getValue();
							}
						}
					}
				}
			}
		}
	}

	return save;
}

vector < pair < int, int > > WorkingGraph::fordBellman(int v)
{
	pair < int, int > p;
	p.first = INT_MAX;
	p.second = -1;
	vector < pair < int, int > > d( vertices.size() + 1, p );
	d[v].first = 0;
	bool any = true;
	while (any)
	{
		any = false;
		for ( set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++ )
		{
			for (list < edges > :: iterator j = (*i).second->begin(); j != (*i).second->end(); j++)
			{
				if ( d[ (*i).first->getValue() ].first < INT_MAX)
				{
					if ( d[ (*j).first->getValue() ].first > d[ (*i).first->getValue() ].first + (*j).second )
					{
						d[ (*j).first->getValue() ].first = d[ (*i).first->getValue() ].first + (*j).second;
						d[ (*j).first->getValue() ].second = (*i).first->getValue();
						any = true;
					}
				}
			}
		}
	}
	return d;
}

list <int> WorkingGraph::shortWay( int v, vector < pair < int, int > > d )
{
	list <int> way;
	if (d[v].first == INT_MAX)
		return way;
	else
	{
		int i = v;
		while ( d[i].first != 0 )
		{
			way.push_back( i );
			i = d[i].second;
		}
		way.push_back( i );
	}
	way.reverse();
	return way;
}