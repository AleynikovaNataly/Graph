#include "Graph.h"

int main ()
{
	std::string root, name_1, name_2, name_find, name_del, name_del_1, name_del_2, name_sort, name_kruskal, name_dejkstra;
	int weight;
	std::string Command;
	int N = 0;
	Graph New/*, New_Transp*/;
    Graph::DfsCallback CB;
	for (int N = 0; N < 100; N++) 
	{
		std::cin >> Command;
		if (Command == "vertex")
		{
			std::cin >> name_1;
			New.EddVertex (name_1);
		}
		if (Command == "edge")
		{
			std::cin >> name_1 >> name_2 >> weight;
			Vertex A (name_1);
			Vertex B (name_2);
			New.EddEdge (A, B, weight);
		}
		if (Command == "list")
		{
			std::cin >> name_find;
			Vertex Find (name_find);
			New.Print_Sm (Find);
		}
		if (Command == "graph")
		{
			New.Print_Graph ();
		}
		if (Command == "del_v")
		{
			std::cin >> name_del;
			Vertex Del (name_del);
			New.Delete_Ver (Del);
		}
		if (Command == "del_e")
		{
			std::cin >> name_del_1 >> name_del_2;
			Vertex Del_1 (name_del_1);
			Vertex Del_2 (name_del_2);
			New.Delete_Edge (Del_1, Del_2);
		}
		if (Command == "bfs")
		{
			std::cin >> root;
			New.BFS (root);
		}
		if (Command == "dfs")
		{
			New.DFS (CB);
		}
        if (Command == "sort")
        {
            std::cin >> name_sort;
            New.Top_sort (name_sort);
        }
		/*if (Command == "transp")
		{
			New_Transp = New.Transp ();
			New_Transp.Print_Graph ();
		}*/
		if (Command == "cck")
		{
			std::vector <std::vector <Vertex> > Forest;
			Forest = New.CCK ();
			for (std::vector <std::vector <Vertex> >::iterator it = Forest.begin (); it != Forest.end (); it++)
			{
				for (std::vector <Vertex>::iterator p = (*it).begin (); p != (*it).end (); p++)
				{
					std::cout << (*p) << "  ";
				}
				std::cout << std::endl;
			}
		}
		if (Command == "Kruskal")
		{
			std::vector <Edge> rez;
			rez = New.MST_Kruskal ();
			for (std::vector <Edge>::iterator it = rez.begin (); it != rez.end (); it++)
			{
				std::cout << (*it).Begin << (*it).End << "  ";
			}
			std::cout << std::endl;
			for (std::vector <Edge>::iterator it = rez.begin (); it != rez.end (); it++)
			{
				std::cout << (*it).Begin << (*it).End << "  " << std::endl;
			}
			std::cout << std::endl;
		}
		if (Command == "Dejkstra")
		{
			std::map <std::string, std::string> dejkstr;
			std::cin >> name_dejkstra;
			dejkstr = New.Dejkstra (name_dejkstra);
			for (std::map <std::string, std::string>::iterator it = dejkstr.begin (); it != dejkstr.end (); it++)
			{
				std::cout << (*it).first << " " << (*it).second << std::endl;
			}
		}
		if(Command == "exit")
		{
			N = 100;
		}
	}

	return 0;
}