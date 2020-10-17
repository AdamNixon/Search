#include <iostream>
#include <list>

class Graph
{
public:
	Graph(int Nodes);
	
	int Nodes;
	std::list<int> *Edges;

	void AddEdge(int Node, int path);

	// print out all nodes found from start
	void BFS(int start);
};

Graph::Graph(int Nodes)
{
	this->Nodes=Nodes;
	Edges = new std::list<int>[Nodes]; 
}

void Graph::AddEdge(int Node, int path)
{
	Edges[Node].push_back(path);
}


void Graph::BFS(int start)
{
	bool Visted[Nodes];
	for (int it=0; it<Nodes; it++)
		Visted[it]=false;

	//Visted[start]=true;
	//std::cout<< start << " ";

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

int main()
{
	// 1-----2
	// |	 |
	// 0-----3-----4
	//
	Graph graph(5);

	graph.AddEdge(0, 1);
	graph.AddEdge(0, 3);
	graph.AddEdge(1, 0);
	graph.AddEdge(1, 2);
	graph.AddEdge(2, 1);
	graph.AddEdge(2, 3);
	graph.AddEdge(3, 0);
	graph.AddEdge(3, 2);
	graph.AddEdge(3, 4);
	graph.AddEdge(4, 3);

	graph.BFS(0);

	return 0;
}