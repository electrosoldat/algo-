// Code Author : TAVISH CHADHA

#include <iostream>
#include <map>
#include <queue>
#include <list>
#include <cstring>
using namespace std;

template <typename T> 
class Graph
{
	map< T , list <T> > adj_list;
public:
	void addEdge(T u, T v, bool bidir=true)
	{
		adj_list[u].push_back(v);
		if(bidir)
			adj_list[v].push_back(u);
	}

	void print_adjlist()
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

	void bfs(T src)
	{
		queue <T> q;
		map<T,bool> visited;

		q.push(src);
		visited[src] = true;

		while(!q.empty())
		{
			T node = q.front();
			cout << node << " ";
			q.pop();

			//for the neighbours of curnode, find out the nodes which are not visited.
			for(int neighbour : adj_list[node])
			{
				if(!visited[neighbour])
				{
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}
};

int main()
{
	Graph<int> g2;
	g2.addEdge(0,1);
	g2.addEdge(0,4);
	g2.addEdge(4,3);
	g2.addEdge(1,4);
	g2.addEdge(1,2);
	g2.addEdge(2,3);
	g2.addEdge(1,3);

	g2.print_adjlist();

	g2.bfs(0);

	return 0;
}