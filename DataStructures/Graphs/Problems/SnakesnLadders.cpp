// Code Author : TAVISH CHADHA

#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <limits.h>
using namespace std;

template <typename T>

class Graph
{
	map <T, list<T> > adj_list;
public:
	void addEdge(T u, T v)
	{
		adj_list[u].push_back(v);
	}

	void printAdjList()
	{
		for(auto obj:adj_list)
		{
			cout << obj.first << "->";
			for(auto entry:obj.second)
			{
				cout << entry << ",";
			}
			cout << endl;
		}
	}


	int bfs(T src, T dest)
	{
		map<T, int> dist;
		queue<T> q;
		map<T,T> parent;

		for(auto node_pair : adj_list)
		{
			T node = node_pair.first;
			dist[node] = INT_MAX;
		} 

		q.push(src);
		dist[src] = 0;
		parent[src] = src;

		while(!q.empty())
		{
			T node = q.front();
			q.pop();

			for(int nbr: adj_list[node])
			{
				if(dist[nbr] == INT_MAX)
				{
					q.push(nbr);
					dist[nbr] = dist[node] + 1;
					parent[nbr] = node;
				}
			}
		}

 		cout << endl;

 		// to print the path
 		T temp = dest;
 		while(temp != src)
 		{
 			cout << temp << "<--" ;
 			temp = parent[temp];
 		}
 		cout << src << endl;
 		return dist[dest];

	}
};

int main()
{
	// Type your code here.
	int board[50] = {0}; //board[j] = +ve -> ladder | board[j] = -ve -> snake
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;

	Graph<int> g;

	for(int i=0;i<=36;i++)
	{
		for(int dice=1;dice<=6;dice++)
		{
			int j = i + dice;
			j += board[j];
			if(j <= 36)
			{
				g.addEdge(i,j);
			}
		}
	}

	g.addEdge(36,36);

	cout << g.bfs(0,36) << endl; // bfs(src,dest) returns the shortest path from the source to the destination.

	return 0;
}