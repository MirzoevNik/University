#include "WorkingGraph.h"
#include <stack>
#include <iostream>
using namespace std;

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
		for (list < Vertex* > :: iterator j = ((*i).second)->begin(); j != ((*i).second)->end(); j++)
		{
			addVertexToList( (*i).first->getValue(), (*j)->getValue() );
		}
	}
	
	return this;
}

void WorkingGraph::printLoops()
{
	bool flag = false;
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		for (list < Vertex* > :: iterator j = ((*i).second)->begin(); j != ((*i).second)->end(); j++)
		{
			if ( (*j)->getValue() == (*i).first->getValue() )
			{
				if (!flag)
					cout << "¬ершины орграфа, у которых есть петли: " << endl;
				cout << (*j)->getValue() << " ";
				flag = true;
				break;
			}
		}
	}
	cout << endl;
}

int WorkingGraph::isWay(int u, int v)
{
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		if ( (*i).first->getValue() == u)
		{
			for (list < Vertex* > :: iterator j = ((*i).second)->begin(); j != ((*i).second)->end(); j++)
			{
				if ( findVertexInList( (*j)->getValue(), v ) != NULL )
					return (*j)->getValue();
			}
		}
	}
	return -1;
}

void WorkingGraph::setOfDegs(set< pair< int, bool > > &d)
{
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		pair<int, bool> p;
		p.first = (*i).first->getValue();
		if ( (*i).second->size() % 2 == 0)
			p.second = false;
		else
			p.second = true;

		for (set < pairs > :: iterator j = vertices.begin(); j != vertices.end(); j++)
		{
			for (list < Vertex* > :: iterator k = ((*j).second)->begin(); k != ((*j).second)->end(); k++)
			{
				if ( (*k)->getValue() == p.first )
				{
					if ( p.second )
						p.second = false;
					else
						p.second = true;
				}
			}
		}
		d.insert(p);
	}
}

void WorkingGraph::delArcs()
{
	set< pair< int, bool > > degs;
	setOfDegs(degs);

	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		bool first_deg;
		for (set< pair< int, bool > > :: iterator j = degs.begin(); j != degs.end(); j++)
		{
			if ( (*j).first == (*i).first->getValue() )
			{
				first_deg = (*j).second;
				break;
			}
		}

		list < Vertex* > :: iterator it = (*i).second->begin();
		while ( it != (*i).second->end() )
		{
			bool second_deg;
			for (set< pair< int, bool > > :: iterator j = degs.begin(); j != degs.end(); j++)
			{
				if ( (*j).first == (*it)->getValue() )
				{
					second_deg = (*j).second;
					break;
				}
			}
			
			if ( first_deg != second_deg )
			{
				it++;
				if ( it == (*i).second->end() )
				{
					it--;
					(*i).second->erase(it);
					break;
				}
				it--;
				it = (*i).second->erase(it);
				it--;
			}
			it++;
		}
	}
}

void WorkingGraph::dfs()
{
	cout << endl;
	stack < pairs > st;
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		if ( (*i).first->getColor() == 0 )
		{
			(*i).first->setColor(1);
			cout << (*i).first->getValue() << " ";
			st.push( *i );

			while ( !st.empty() )
			{
				pairs u = st.top();
				u.first->setColor(1);
				bool flag = false;
				for (list < Vertex* > :: iterator j = u.second->begin(); j != u.second->end(); j++)
				{
					if ( (*j)->getColor() == 0 )
					{
						flag = true;
						Vertex *w = (*j);
						w->setColor(2);
						cout << w->getValue() << " ";

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
		}
	}

	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		(*i).first->setColor(0);
	}

	cout << endl;
}

bool WorkingGraph::isAcyclic()
{
	stack < pairs > st;
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		if ( (*i).first->getColor() == 0 )
		{
			(*i).first->setColor(1);
			st.push( *i );

			while ( !st.empty() )
			{
				pairs u = st.top();
				u.first->setColor(1);
				bool flag = false;
				for (list < Vertex* > :: iterator j = u.second->begin(); j != u.second->end(); j++)
				{
					if ( (*j)->getColor() == 0 )
					{
						flag = true;
						Vertex *w = (*j);
						w->setColor(2);

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
					for (list < Vertex* > :: iterator j = u.second->begin(); j != u.second->end(); j++)
					{
						pairs t = st.top();
						st.pop();
						if ( ( !st.empty() ) && ( (*j)->getColor() == 1 ) && ( st.top().first->getValue() != (*j)->getValue() ) )
						{
							while( !st.empty() )
								st.pop();
							return false;
						}
						st.push(t);
					}

					u.first->setColor(2);
					st.pop();
				}
			}
		}
	}

	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		(*i).first->setColor(0);
	}

	return true;
}

int WorkingGraph::allCycles( list < list <int> > &cs )
{
	list < list <int> > cycles;
	stack < pairs > st;
	int count = 0; // дл€ подсчЄта компонент св€зности графа
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		if ( (*i).first->getColor() == 0 )
		{
			count++;
			(*i).first->setColor(1);
			st.push( *i );

			while ( !st.empty() )
			{
				pairs u = st.top();
				u.first->setColor(1);
				bool flag = false;
				for (list < Vertex* > :: iterator j = u.second->begin(); j != u.second->end(); j++)
				{
					if ( (*j)->getColor() == 0 )
					{
						flag = true;
						Vertex *w = (*j);
						w->setColor(2);

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
					bool flag2 = false;
					for (list < Vertex* > :: iterator j = u.second->begin(); j != u.second->end(); j++)
					{
						pairs t = st.top();
						st.pop();
						stack < pairs > st2;
						st2 = st;
						if ( ( !st2.empty() ) && ( (*j)->getColor() == 1 ) && ( st2.top().first->getValue() != (*j)->getValue() ) )
						{
							list <int> l;
							l.push_back( t.first->getValue() );
							while( ( !st2.empty() ) && ( st2.top().first->getValue() != (*j)->getValue() ) )
							{
								t = st2.top();
								l.push_back( t.first->getValue());
								st2.pop();
							}
							l.push_back( st2.top().first->getValue() );

							flag2 = true;
							cycles.push_back( l );
							if (st2.empty())
								st = st2;
							break;
						}
						if (st2.empty())
							st = st2;
						st.push(t);
					}

					u.first->setColor(2);
					if ( !flag2 )
						st.pop();
				}
			}
		}
	}

	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		(*i).first->setColor(0);
	}

	cs = cycles;
	return count;
}

bool WorkingGraph::checkOnTree()
{
	stack < pairs > st;
	int count = 0; // дл€ подсчЄта компонент св€зности графа
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		if ( (*i).first->getColor() == 0 )
		{
			count++;
			(*i).first->setColor(1);
			st.push( *i );

			while ( !st.empty() )
			{
				pairs u = st.top();
				u.first->setColor(1);
				bool flag = false;
				for (list < Vertex* > :: iterator j = u.second->begin(); j != u.second->end(); j++)
				{
					if ( (*j)->getColor() == 0 )
					{
						flag = true;
						Vertex *w = (*j);
						w->setColor(2);

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
					for (list < Vertex* > :: iterator j = u.second->begin(); j != u.second->end(); j++)
					{
						pairs t = st.top();
						st.pop();
						if ( ( !st.empty() ) && ( (*j)->getColor() == 1 ) && ( st.top().first->getValue() != (*j)->getValue() ) )
						{
							while( !st.empty() )
								st.pop();
							for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
								(*i).first->setColor(0);
							return false;
						}
						st.push(t);
					}

					u.first->setColor(2);
					st.pop();
				}
			}
		}
	}

	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		(*i).first->setColor(0);
	}

	if ( count == 1 )
		return true;
	else
		return false;
}

int WorkingGraph::checkOnNewTree()
{
	list < list <int> > cycles;

	int connectedComponents = allCycles(cycles);

	if ( connectedComponents > 2) 
	{
		return -1;
	}
	else
	{
		if ( connectedComponents == 2 )
		{
			/*ѕрохожу по всем вершинам графа, если у какой-то вершины все смежные вершины - эта же вершина или список смежности пуст, то ћќ∆Ќќ удалить эту вершину, иначе Ќ≈Ћ№«я.*/
			for ( set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++  )
			{
				if ( (*i).second->empty() )
					return (*i).first->getValue();
				for ( list < Vertex* > :: iterator j = (*i).second->begin(); j != (*i).second->end(); j++ )
				{
					if ( (*i).first->getValue() != (*j)->getValue() )
						break;
					else
					{
						j++;
						if ( j == (*i).second->end() )
						{
							return (*i).first->getValue();
						}
						j--;
					}
				}
				return -1;
			}
		}
		else
		{
			if ( cycles.empty() )
			{
				return 0; // уже дерево
			}
			else
			{
				//создаю список всех вершин, которые вход€т во все циклы. ≈сли список пуст, то Ќ≈Ћ№«я
				set <int> vs; // вершины, которые вход€т во все циклы

				list < list <int> > :: iterator it = cycles.begin(); 

				for ( list <int> :: iterator i = (*it).begin(); i != (*it).end(); i++ )
				{
					int x = *i; // элемент из первого цикла

					list < list <int> > :: iterator j = cycles.begin();
					j++; // провер€ем все оставшиес€ циклы на наличие элемента x

					if ( j == cycles.end() )
					{
						vs.insert(x); // добавл€ем вершину в список вершин, вход€щих во все циклы
					}

					while ( j != cycles.end() )
					{
						bool find = false;
						for ( list <int> :: iterator k = (*j).begin(); k != (*j).end(); k++ )
						{
							if ( *k == x )
							{
								find = true;
								break;
							}
						}
						if ( !find )
							break;
						else
						{
							j++;
							if ( j == cycles.end() )
							{
								vs.insert(x); // добавл€ем вершину в список вершин, вход€щих во все циклы
							}
							j--;
						}
						j++;
					}
				}

				if ( vs.empty() )
				{
					return -1;
				}
				else
				{
					/*»ду по списку потенциальных вершин дл€ удалени€ и создаю подграф данного графа, в котором удал€ю вершину из списка.*/
					for ( set <int> :: iterator i = vs.begin(); i != vs.end(); i++ )
					{
						WorkingGraph *g2 = new WorkingGraph( direct );
						*g2 = this;

						g2->delVertex( *i );

						bool isTree = g2->checkOnTree();
						if ( isTree )
						{
							return (*i);
						}
						else
						{
							i++;
							if ( i == vs.end() )
								return -1;
							i--;
						}
					}
				}
			}
		}
	}
	return -1;
}

list < int > WorkingGraph::listOfLeaf()
{
	list <int> l;
	for (set < pairs > :: iterator i = vertices.begin(); i != vertices.end(); i++)
	{
		if ( (*i).second->size() == 0 )
		{
			l.push_back( (*i).first->getValue() );
			continue;
		}
		int other = 0;
		for ( list < Vertex* > :: iterator j = (*i).second->begin(); j != (*i).second->end(); j++ )
		{
			if ( (*i).first->getValue() != (*j)->getValue() )
			{
				other++;
			}
		}
		if ( other == 1 )
			l.push_back( (*i).first->getValue() );
	}
	return l;
}