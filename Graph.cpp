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
		//dFs.parent = "NIL";
		dFs.way_length = 0;
		dfs.insert (std::make_pair (X, dFs));
	}
}

void Graph::EddEdge (Vertex A, Vertex B, Weight x)
{
	My_graph::iterator fnd_1 = graph.find (A);
	My_graph::iterator fnd_2 = graph.find (B);
	if (fnd_1 == graph.end ())
	{
		Adjlist a;
		a.insert (std::make_pair (B, x));
		graph.insert (std::make_pair (A, a));
		bfs.insert (std::make_pair (A, 'w'));
			bfs.insert (std::make_pair (B, 'w'));
		DfS dFs;
		dFs.colour = 'w';
		//dFs.parent = "NIL";
		dFs.way_length = 0;
		dfs.insert (std::make_pair (A, dFs));
			dfs.insert (std::make_pair (B, dFs));
	} else 
	{
		(*fnd_1).second.insert (std::make_pair (B, x));
			bfs.insert (std::make_pair (B, 'w'));
			DfS dFs;
			dFs.colour = 'w';
			//dFs.parent = "NIL";
			dFs.way_length = 0;
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
		dFs.way_length = 0;
		dfs.insert (std::make_pair (B, dFs));
	} else
	{
		(*fnd_2).second.insert (std::make_pair (A, x));
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
/*std::vector <Graph>*/ void Graph::DFS (Cb &cb)
{
	std::vector <Graph> forest;
	Graph Tree;
	for (DColour::iterator it = dfs.begin (); it != dfs.end (); it++)
	{
		if ((*it).second.colour == 'w')
		{
			/*Tree = */DFSVisit ((*it).first, cb);
		} //else {
			std::cout << std::endl;
			//forest.push_back (Tree);
		//}
	}
	//std::cout << std::endl;
	//return forest;
}

template <typename Cb>
/*Graph*/ void Graph::DFSVisit (Vertex U, Cb &cb)
{
	//Graph Tree;
	DColour::iterator it = dfs.find (U);
	DColour::iterator t;
	My_graph::iterator fnd = graph.find (U);
	std::cout << (*it).first << "  ";
	/*if ((*it).second.parent == "NIL")
	{
		Tree.EddVertex ((*it).first);
	} else 
	{
		Tree.EddEdge ((*it).second.parent, (*it).first, 0);
	}*/
	if (fnd != graph.end ())
	{
		My_graph::iterator list = GetList ((*fnd).first);
		(*it).second.colour = 'g';
		(*it).second.way_length++;
		//std::cout << (*it).first << "  ";
		if (list != graph.end ())
		{
			for (Adjlist::iterator p = (*list).second.begin (); p != (*list).second.end (); p++)
			{
				Vertex T = (*p).first;
				t = dfs.find (T);
				if ((*t).second.colour == 'w')
				{
					//(*t).second.parent = (*it).first;
					DFSVisit ((*t).first, cb);
				}
			}
		}
	}
	(*it).second.colour = 'b';
	(*it).second.way_length++;
	cb.OnBlack ((*it).first);
	//return Tree;
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

/*std::vector <Graph>*/ void Graph::CCK ()
{
	//std::vector <Graph> forest;
	Graph::DfsCallback cb_g;
	DFS (cb_g);
	Graph tr = Transp ();
	Graph::DfsCallback cb_t;
	/*forest = */tr.DFS (cb_t);
	//return forest;
}