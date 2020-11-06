#include<iostream>
#include<queue>
/*
class Graph
{
public:
	Graph();
	~Graph();

	void Draw();
	
};*/


void AddAdj(std::queue<std::pair<int,int>>& Que, std::pair<int,int> currentPoint, const int N )
{
	int i{currentPoint.first};
	int j{currentPoint.second};
	// up
	if (i>0)
		Que.push(std::make_pair (i-1,j));
	// down
	if (i<N)
		Que.push(std::make_pair (i+1,j));
	// up
	if (j>0)
		Que.push(std::make_pair (j,j-1));
	// down
	if (j<N)
		Que.push(std::make_pair (i,j+1));
}


void BFS(std::pair<int,int> Start, std::pair<int,int> End)
{
	int N{5};
	std::queue<std::pair<int,int>> Que;
	int graph[N][N]{0};
	bool visited[N][N]{false};
	bool bFound{false};
	std::pair<int,int> currentPoint;
	currentPoint = Start;

	Que.push(Start);

	while(Que.size() !=0 && !bFound)
	{
		currentPoint = Que.front();
		if (visited[currentPoint.first][currentPoint.second]==false  )
		{
			if (currentPoint== End)
				bFound=true;
			visited[currentPoint.first][currentPoint.second]==true;
			AddAdj( Que, currentPoint, N);
		}
		else
		{
			Que.pop();
		}
	}

	if (!bFound)
		std::cout<<"not found\n";
	else
	{
		for(int i; i<N; i++)
		{
			for (int j = 0; j < N; ++j)
			{
				if (visited[i][j])
					std::cout<<"V";
				else
					std::cout<<"O";
			}
			std::cout<<"\n";
		}
	}

}

int main()
{
	// create a 20x20 grid which can search from a start to find end point.


	std::pair<int,int> Start;
	std::pair<int,int> End;

	Start = std::make_pair (0,0);
  	End = std::make_pair (4,4);

	BFS(Start, End);

	// DFS

	return 0.;
}