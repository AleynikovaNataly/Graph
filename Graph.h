#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <vector>

struct DfS
{
	char colour;
	std::string parent;
	int way_length;
};

typedef std::string Vertex;
typedef int Weight;
typedef std::map <Vertex, Weight> Adjlist;
typedef std::map <Vertex, DfS> DColour;
typedef std::map <Vertex, char> BColour;
typedef std::map <Vertex, Adjlist> My_graph;

class Graph
{
private:
    My_graph graph;
	BColour bfs;
	DColour dfs;

public:
    struct DfsCallback
    {
        std::vector <Vertex> stack;
        void OnBlack (Vertex X);
        void print ();
    };
	Graph ();
    void EddVertex (Vertex X);
	void EddEdge (Vertex A, Vertex B, Weight x);
	My_graph::iterator GetList (Vertex X);
	void Delete_Ver (Vertex X);
	void Delete_Edge (Vertex X, Vertex Y);
    void Print_Sm (Vertex X);
	void Print_Graph ();
	void BFS (Vertex Root);
	template <typename Cb>
	/*std::vector <Graph>*/ void DFS (Cb &cb);
    template <typename Cb>
	/*Graph*/ void DFSVisit (Vertex U, Cb &cb);
    void Top_sort (Vertex X);
	Graph Transp ();
	/*std::vector <Graph>*/ void CCK ();
};