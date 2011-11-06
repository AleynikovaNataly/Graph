#include "Graph.h"

Graph::Graph () {}

void Graph::EddVertex (Vertex X)
{
    My_graph::iterator fnd = graph.find (X);
	if (fnd == graph.end ())
	{
        Adjlist x;
		graph.insert (std::make_pair (X, x));
		bfs.insert (std::make_pair (X, 'w'));
		DfS dFs;
		dFs.colour = 'w';
		dFs.f = 0;
		dfs.insert (std::make_pair (X, dFs));
	}
}

void Graph::EddEdge (Vertex A, Vertex B, Weight x)
{
	My_graph::iterator fnd_1 = graph.find (A);
	My_graph::iterator fnd_2 = graph.find (B);
	Edge edge; //по хорошему надо сделать так, чтобы одинаковые ребра не добавлялись несколько раз, но это можно реализовать легко при необходимости
	edge.Begin = A;
	edge.End = B;
	edges.insert (std::make_pair (x, edge));
	if (fnd_1 == graph.end ())
	{
		Adjlist a;
		a.insert (std::make_pair (B, x));
		graph.insert (std::make_pair (A, a));
		bfs.insert (std::make_pair (A, 'w'));
		bfs.insert (std::make_pair (B, 'w'));
		DfS dFs;
		dFs.colour = 'w';
		dFs.f = 0;
		dfs.insert (std::make_pair (A, dFs));
		dfs.insert (std::make_pair (B, dFs));
	} else 
	{
		(*fnd_1).second.insert (std::make_pair (B, x));
		bfs.insert (std::make_pair (B, 'w'));
		DfS dFs;
		dFs.colour = 'w';
		dFs.f = 0;
		dfs.insert (std::make_pair (B, dFs));
	}
	/*if (fnd_2 == graph.end ())
	{
		Adjlist b;
		b.insert (std::make_pair (A, x));
		graph.insert (std::make_pair (B, b));
		bfs.insert (std::make_pair (B, 'w'));
		DfS dFs;
		dFs.colour = 'w';
		dFs.f = 0;
		dfs.insert (std::make_pair (B, dFs));
	} else
	{
		(*fnd_2).second.insert (std::make_pair (A, x));
		bfs.insert (std::make_pair (A, 'w'));
		DfS dFs;
		dFs.colour = 'w';
		dFs.f = 0;
		dfs.insert (std::make_pair (A, dFs));
	}*/
}

My_graph::iterator Graph::GetList (Vertex X)
{
	My_graph::iterator fnd = graph.find (X);
		return fnd;
}

void Graph::Delete_Ver (Vertex X)
{
    /*My_graph::iterator fnd = GetList (X);
    My_graph::iterator it;
    Adjlist::iterator del;
	BColour::iterator del_b = bfs.find (X);
	DColour::iterator del_d = dfs.find (X);
    if (fnd != graph.end ())
    {
		for (Adjlist::iterator p = (*fnd).second.begin (); p != (*fnd).second.end (); p++)
		{
            Vertex Fnd_list = (*p).first;
            it = graph.find (Fnd_list);
            del = (*it).second.find (X);
			(*it).second.erase (del);
        }
		graph.erase (fnd);
		bfs.erase (del_b);
		dfs.erase (del_d);
    }*/
	My_graph::iterator fnd = graph.find (X);
	if (fnd != graph.end ())
	{
		graph.erase (fnd);
	}
	for (My_graph::iterator it = graph.begin (); it != graph.end (); it++)
	{
		for (Adjlist::iterator p = (*it).second.begin (); p != (*it).second.end (); p++)
		{
			if ((*p).first == X)
			{
				(*it).second.erase (p);
			}
		}
	}
}

void Graph::Delete_Edge (Vertex X, Vertex Y)
{
	/*My_graph::iterator fnd_x = GetList (X);
	Adjlist::iterator del_x;
	My_graph::iterator fnd_y = GetList (Y);
	Adjlist::iterator del_y;
	if (fnd_x != graph.end ())
	{
		del_x = (*fnd_x).second.find (Y);
		(*fnd_x).second.erase (del_x);
	}
	if (fnd_y != graph.end ())
	{
		del_y = (*fnd_y).second.find (X);
		(*fnd_y).second.erase (del_y);
	}*/
	My_graph::iterator fnd_x = GetList (X);
	Adjlist::iterator del_x;
	if (fnd_x != graph.end ())
	{
		del_x = (*fnd_x).second.find (Y);
		(*fnd_x).second.erase (del_x);
	}
}

void Graph::Print_Sm (Vertex X)
{
    My_graph::iterator it = GetList (X);
	if (it != graph.end ())
	{
		for (Adjlist::iterator p = (*it).second.begin(); p != (*it).second.end (); p++)
		{
				std::cout << (*p).first << "  ";
		}
		std::cout << std::endl;
	} else 
	{
		std::cout << "There isn't this vertex" << std::endl;
	}
}

void Graph::Print_Graph ()
{
    for (My_graph::iterator it = graph.begin (); it != graph.end (); it++)
	{
		std::cout << (*it).first << "   ";
        for (Adjlist::iterator p = (*it).second.begin (); p != (*it).second.end (); p++)
		{
			std::cout << (*it).first << (*p).first << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::BFS (Vertex Root)
{
	BColour::iterator it = bfs.find (Root);
	(*it).second = 'g';
	std::deque <Vertex> Deque;
	Deque.push_back (Root);
	do 
	{
		Vertex Gray = Deque.front ();
		std::cout << Gray << "  ";
		My_graph::iterator list = GetList (Gray);
		if (list != graph.end ())
		{
			for (Adjlist::iterator p = (*list).second.begin (); p != (*list).second.end (); p++)
			{
				BColour::iterator k = bfs.find ((*p).first);

				if ((*k).second == 'w')
				{
					Deque.push_back ((*p).first);
					BColour::iterator fnd = bfs.find ((*p).first);
					(*fnd).second = 'g';
				}
			(*p).second = 'b';
			}
		}
		Deque.pop_front ();
	}
	while (Deque.size () != 0);
	std::cout << std::endl;
}

void Graph::DfsCallback::OnBlack (Vertex X)
{
    stack.push_back (X);
}

void Graph::DfsCallback::print ()
{
    while (!stack.empty ())
    {
        std::cout << stack.back () << " ";
        stack.pop_back ();
    }
   std::cout << std::endl;
}

template <typename Cb>
std::vector <std::vector <Vertex> > Graph::DFS (Cb &cb)
{
	std::vector <std::vector <Vertex> > forest;
	std::vector <Vertex> tree;
	if (final.size () == 0)
	{
		for (DColour::iterator it = dfs.begin (); it != dfs.end (); it++)
		{
			if ((*it).second.colour == 'w')
			{
				DFSVisit ((*it).first, cb, tree, forest);
			} else {
				if ((*it).second.colour == 'b') 
				{
					if (tree.size () != 0)
					{
						forest.push_back (tree);
						tree.clear ();
					}
				}
			}
		}
	} else 
	{
		for (std::map <int, Vertex>::iterator it = final.begin (); it != final.end (); it++)
		{
			DColour::iterator fnd = dfs.find ((*it).second);
			if ((*fnd).second.colour == 'w')
			{
				DFSVisit ((*fnd).first, cb, tree, forest);
			} else {
				if ((*fnd).second.colour == 'b') 
				{
					if (tree.size () != 0)
					{
						forest.push_back (tree);
						tree.clear ();
					}
				}
			}
		}
	}
	return forest;
}

template <typename Cb>
void Graph::DFSVisit (Vertex U, Cb &cb, std::vector <Vertex> &Tree, std::vector <std::vector <Vertex> > &Forest)
{
	int flag = 0;
	DColour::iterator it = dfs.find (U);
	DColour::iterator t;
	My_graph::iterator fnd = graph.find (U);
	Tree.push_back ((*it).first);
	if (fnd != graph.end ())
	{
		My_graph::iterator list = GetList ((*fnd).first);
		(*it).second.colour = 'g';
		if (list != graph.end ())
		{
			for (Adjlist::iterator p = (*list).second.begin (); p != (*list).second.end (); p++)
			{
				Vertex T = (*p).first;
				t = dfs.find (T);
				if ((*t).second.colour == 'w')
				{
					DFSVisit ((*t).first, cb, Tree, Forest);
				} else {
					/*My_graph::iterator bl = graph.find ((*p).first);
					if (bl == graph.end ())
					{
						if (Tree.size () != 0)
						{
							Forest.push_back (Tree);
							Tree.clear ();
						}
					}
					for (Adjlist::iterator yes = (*bl).second.begin (); yes != (*bl).second.end (); yes++)
					{
						Vertex Y = (*yes).first;
						DColour::iterator du = dfs.find (Y);
						if ((*du).second.colour == 'w')
						{
							flag = 1;
						}
					}
					if (flag == 0)
					{*/
						if (Tree.size () != 0)
						{
							Forest.push_back (Tree);
							Tree.clear ();
						}
					/*} else {
						flag = 0;
					}*/
				}
			}
		} else {
			if (Tree.size () != 0)
			{
				Forest.push_back (Tree);
				Tree.clear ();
			}
		}
	}
	(*it).second.colour = 'b';
	if (final.size () != 0)
	{
		std::map <int, Vertex>::reverse_iterator rev = final.rbegin ();
		int fin = (*rev).first;
		fin++;
		(*it).second.f = fin;
	} else {
		(*it).second.f = 1;
	}
	final.insert (std::make_pair ((*it).second.f, (*it).first));
	cb.OnBlack ((*it).first);
}

void Graph::Top_sort (Vertex X)
{
    DfsCallback cb;
    DFS (cb);
    cb.print ();
}

Graph Graph::Transp ()
{
	Graph Transp;
	My_graph::iterator fnd;
	for (My_graph::iterator it = graph.begin (); it != graph.end (); it++)
	{
		for (Adjlist::iterator p = (*it).second.begin (); p != (*it).second.end (); p++)
		{
			Transp.EddEdge ((*p).first, (*it).first, (*p).second);
		}
	}
	return Transp;
}

std::vector <std::vector <Vertex> > Graph::CCK ()
{
	std::vector <std::vector <Vertex> > forest;
	Graph::DfsCallback cb_g;
	DFS (cb_g);
	Graph tr = Transp ();
	Graph::DfsCallback cb_t;
	forest = tr.DFS (cb_t);
	return forest;
}

Host_Kruskal Graph::Make_Set (Vertex V)
{
	Host_Kruskal new_host;
	P_R p_r;
	p_r.Parent = V;
	p_r.Rank = 0;
	new_host.insert (std::make_pair (V, p_r));
	return new_host;
}

Vertex Graph::Find_Set (Vertex X, Forest_Kruskal &New_Forest_Kruskal)
{
	Host_Kruskal::iterator fnd;
	Host_Kruskal::iterator mur;
	for (Forest_Kruskal::iterator it = New_Forest_Kruskal.begin (); it != New_Forest_Kruskal.end (); it++)
	{
		fnd = (*it).find (X);
		if (fnd != (*it).end ())
		{
			mur = fnd;
		}
	}
	if ((*mur).first != (*mur).second.Parent)
	{					
		Find_Set ((*mur).second.Parent, New_Forest_Kruskal);
	} else {
		return ((*mur).second.Parent);
	}
}
void Graph::Link (Vertex U, Vertex V, Forest_Kruskal &New_Forest_Kruskal)
{
	Host_Kruskal::iterator t_u, t_v, p_u, p_v;
	int rank_u, rank_v;
	Vertex parent_u, parent_v;
	for (Forest_Kruskal::iterator it = New_Forest_Kruskal.begin (); it != New_Forest_Kruskal.end (); it++)
	{
		t_u = (*it).find (U);
		if (t_u != (*it).end ())
		{
			p_u = t_u;
			rank_u = (*t_u).second.Rank;
		}
	}
	for (Forest_Kruskal::iterator it = New_Forest_Kruskal.begin (); it != New_Forest_Kruskal.end (); it++)
	{
		t_v = (*it).find (V);
		if (t_v != (*it).end ())
		{
			p_v = t_v;
			rank_v = (*t_v).second.Rank;
		}
	}
	if (rank_u > rank_v)
	{
		(*p_v).second.Parent = U;
	} else {
		(*p_u).second.Parent = V; //!!! iterator defer
		if (rank_u == rank_v)	
		{
			(*p_v).second.Rank++;
		}
	}
}

void Graph::Union (Vertex U, Vertex V, Forest_Kruskal &New_Forest_Kruskal)
{
	Link (Find_Set (U, New_Forest_Kruskal), Find_Set (V, New_Forest_Kruskal), New_Forest_Kruskal);
}

std::vector <Edge> Graph::MST_Kruskal ()
{
	std::vector <Edge> Rez;
	Forest_Kruskal new_forest_kruskal;
	for (BColour::iterator iter = bfs.begin (); iter != bfs.end (); iter++)
	{
		Host_Kruskal new_host_kruskal = Make_Set ((*iter).first);
		new_forest_kruskal.push_back (new_host_kruskal);
	}
	for (std::multimap <Weight, Edge>::iterator p = edges.begin (); p != edges.end (); p++)
	{
		Vertex One = Find_Set ((*p).second.Begin, new_forest_kruskal);
		Vertex Two = Find_Set ((*p).second.End, new_forest_kruskal);
		if (One != Two)
		{
			Edge edge;
			edge.Begin = (*p).second.Begin;
			edge.End = (*p).second.End;
			Rez.push_back (edge);
			Union ((*p).second.Begin, (*p).second.End, new_forest_kruskal);
		}
	}
	return Rez;
}

std::map <std::string, std::string> Graph::Dejkstra (Vertex W)
{
	std::multimap <int, std::string> distance;
	std::map <std::string, int> tdistance;
	std::map <std::string, std::string> parent;
	My_graph::iterator it;
	std::map <std::string, int>::iterator f, t;
	std::multimap <int, std::string>::iterator iter;
	std::map <std::string, std::string>::iterator q;
	Vertex U, V;
	int Dv, Du;
	distance.insert (std::make_pair (0, W));
	tdistance.insert (std::make_pair (W, 0));
	parent.insert (std::make_pair (W, "NIL"));
	while (distance.empty () == false)
	{
		iter = distance.begin ();
		U = (*iter).second;
		Du = (*iter).first;
		distance.erase (iter);
		it = graph.find (U);
		if (it != graph.end ())
		{
			for (Adjlist::iterator p = (*it).second.begin (); p != (*it).second.end (); p++)
			{
				V = (*p).first;
				t = tdistance.find (V);
				if (t != tdistance.end ())
				{
					Dv = (*t).second;
				} else {
					Dv = 1000000;
				}
				if (Dv > Du + (*p).second)
				{
					distance.insert (std::make_pair ((Du + (*p).second), V));
					f = tdistance.find (V);
					if (f != tdistance.end ())
					{
						tdistance.erase (f);
					}
					tdistance.insert (std::make_pair (V, (Du + (*p).second)));
					q = parent.find (V);
					if (q != parent.end ())
					{
						parent.erase (q);
					}
					parent.insert (std::make_pair (V, U));
				}
			}
		}
	}
	return parent;
}

/*{
	std::set <std::string> used;
	std::map <std::string, std::string> parent;

	distance[v0] = 0;
	while (true)
	{
		std::string vm = "";
		int dmin = -1;
		for (TDistance::iterator it = distance.begin (); it != distance.end (); it++)
		{
			if (! used.count((*it).first) < dmin)
			{
				if (dmin == -1 || (*it).second < dmin)
				{
					dmin = (*it).second;
					vm = (*it).first;
				}
			}
		}
		if (vm == "")
		{
			break;
		}
		My_graph::iterator fnd = graph.find (vm);
		Adjlist neighbors = (*fnd).second;
		for (Adjlist::iterator it = neighbors.begin (); it != neighbors.end (); it++)
		{
			std::map <std::string, int>::iterator jt = distance.find ((*it).first);
			if (jt == distance.end () || (*jt).second > dmin + (*it).second)
			{
				distance[(*it).first] = dmin + (*it).second;
				parent[(*it).first] = vm;
			}
		}
		used.insert (vm);
	}

	return used;
}*/