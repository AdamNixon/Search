#include<iostream>
#include<vector>
#include<list>
class Graph
{
	// vector of for each point (endPoint, cost)
	//std::vector<std::vector<int, double>> Edges;
	public:
		Graph();
		std::vector<std::vector<int>> Edges;
		void BFS(int start);
		void DFS(int start);

	//void Route(int start, int end);

	//void RouteCheap(int start, int end);

};

Graph::Graph()
{
	// For now we hard code a chosen graph	
	Edges={{1,3}, {0,2}, {1,3}, {0,2,4},{3}};

}

void Graph::BFS(int start)
{
	bool Visted[Edges.size()];
	for (int it=0; it<Edges.size(); it++)
		Visted[it]=false;

	std::list<int> Que;

	Que.push_back(start);

	while (!Que.empty())
	{
		int j=Que.front();
		Que.pop_front();
		if (!Visted[j])
		{
			Visted[j]=true;
			for (auto i = Edges[j].begin(); i != Edges[j].end(); ++i) 
				{
					Que.push_back(*i);
				}
			
			std::cout<< j << " ";
		}
	}
		std::cout<< "\n";
}

void Graph::DFS(int start)
{
	bool Visted[Edges.size()];
	for (int it=0; it<Edges.size(); it++)
		Visted[it]=false;

	std::list<int> Que;

	Que.push_back(start);

	while (!Que.empty())
	{
		int j=Que.front();
		Que.pop_front();
		if (!Visted[j])
		{
			Visted[j]=true;
			for (auto i = Edges[j].begin(); i != Edges[j].end(); ++i) 
				{
					Que.push_front(*i);
				}
			
			std::cout<< j << " ";
		}
	}
		std::cout<< "\n";
}

int main()
{
	Graph graph;
	graph.BFS(0);
	graph.DFS(0);

	return 0;
}

// Graph

// vector of pairs
// Edges are set of pairs (neighbour, cost)

// BFS
// DFS
// A* search

// search whole space
// search till x found