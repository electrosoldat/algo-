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

	void dfs_helper(T src, map<T,bool>&visited)
	{
		//recursive function that will traverse the graph.
		visited[src] = true;
		cout << src << " ";
		// go to all neighbours of src, which are not visited earlier.
		for(T nbr:adj_list[src])
		{
			if(!visited[nbr])
				dfs_helper(nbr,visited);
		}

		return;
	}

	void dfs(T src)
	{
		map<T,bool> visited;
		// mark all the nodes as not visited in the beginning.
		for(auto p:adj_list)
		{
			T node = p.first;
			visited[node] = false;
		}

		int cnt = 0;
		for(auto p:adj_list)
		{
			T node = p.first;
			if(!visited[node])
			{
				cout << "component " << cnt << "-->";
				dfs_helper(node,visited);
				cnt++;
                cout << endl;
			}
		}

	}
};

int main()
{
	Graph<int> g2;

	g2.addEdge(0,1);
	g2.addEdge(0,3);
	g2.addEdge(0,4);
	g2.addEdge(2,1);
	g2.addEdge(3,2);
	g2.addEdge(5,6);
	g2.addEdge(7,6);
	g2.addEdge(8,8);

	g2.dfs(0);

	return 0;
}