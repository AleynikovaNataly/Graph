#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <vector>
#include <set>

struct DfS
{
	char colour;
	int f;
};

typedef std::string Vertex;
typedef int Weight;

struct P_R
{
	Vertex Parent;
	int Rank;
};

typedef std::map <Vertex, Weight> Adjlist;
typedef std::map <Vertex, DfS> DColour;
typedef std::map <Vertex, char> BColour;
typedef std::map <Vertex, Adjlist> My_graph;
typedef std::map <Vertex, P_R> Host_Kruskal;
typedef std::vector <Host_Kruskal> Forest_Kruskal;

struct Edge
{
	Vertex Begin;
	Vertex End;
};

class Graph
{
private:
    My_graph graph;
	BColour bfs;
	DColour dfs;
	std::map <int, Vertex> final;
	std::multimap <Weight, Edge> edges;

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
	std::vector <std::vector <Vertex> > DFS (Cb &cb);
    template <typename Cb>
	void DFSVisit (Vertex U, Cb &cb, std::vector <Vertex> &Tree, std::vector <std::vector <Vertex> > &Forest);
    void Top_sort (Vertex X);
	Graph Transp ();
	std::vector <std::vector <Vertex> > CCK ();
	Host_Kruskal Make_Set (Vertex V);
	Vertex Find_Set (Vertex X, Forest_Kruskal &New_Forest_Kruskal);
	void Link (Vertex U, Vertex V, Forest_Kruskal &New_Forest_Kruskal);
	void Union (Vertex U, Vertex V, Forest_Kruskal &New_Forest_Kruskal);
	std::vector <Edge> MST_Kruskal ();
	std::map <std::string, std::string> Dejkstra (Vertex V);
};