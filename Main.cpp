#include "Graph.h"

int main ()
{
	std::string root, name_1, name_2, name_find, name_del, name_del_1, name_del_2, name_sort;
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
			//std::vector <Graph> Forest;
			/*Forest = */New.CCK ();
			/*for (std::vector <Graph>::iterator it = Forest.begin (); it != Forest.end (); it++)
			{
				(*it).Print_Graph ();
			}*/
		}
		if (Command == "exit")
		{
			N = 100;
		}
	}

	return 0;
}