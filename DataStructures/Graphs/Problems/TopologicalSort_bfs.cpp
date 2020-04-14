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
	void addEdge(T u, T v)
	{
		adj_list[u].push_back(v);
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

	void dfs_helper(T src, map<T,bool>&visited,list<T>&ordering)
	{
		//recursive function that will traverse the graph.
		visited[src] = true;
		// go to all neighbours of src, which are not visited earlier.
		for(T nbr:adj_list[src])
		{
			if(!visited[nbr])
				dfs_helper(nbr,visited,ordering);
		}

		ordering.push_front(src);

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
		dfs_helper(src,visited);
	}

	void bfsTopologicalSort()
	{
		queue <T> q;
		map <T,bool> visited;
		map <T,int> indegree;

		for(auto i:adj_list)
		{
			// i is a pair of node & its list
			T node = i.first;
			visited[node] = false;
			indegree[node] = 0;
		}

		//initialise the indegree's of all nodes.
		for(auto i: adj_list)
		{
			T u = i.first;
			for(T v : adj_list[u])
			{
				indegree[v]++ ;
			}
		}

		//find out all nodes with 0 indegree.
		for(auto i:adj_list)
		{
			T node = i.first;
			if(indegree[node]==0)
			{
				q.push(node);
			}
		}

		//start with the algo 
		while(!q.empty())
		{
			T node = q.front();
			q.pop();
			cout << node << "-->";

			for(T neighbour : adj_list[node])
			{
				indegree[neighbour]--;
				if(indegree[neighbour] == 0)
				{
					q.push(neighbour);
				}
			}
		}
	}
};

int main()
{
	Graph<string> g;
	g.addEdge("English","Programming Logic");
	g.addEdge("English","HTML");
	g.addEdge("Maths","Programming Logic");
	g.addEdge("Programming Logic"," HTML");
	g.addEdge("Programming Logic","Python");
	g.addEdge("Programming Logic","JS");
	g.addEdge("Programming Logic","Java");
	g.addEdge("Python","Web Development");
	g.addEdge("HTML","CSS");
	g.addEdge("CSS","JS");
	g.addEdge("JS","Web Development");
	g.addEdge("Java","Web Development");

	g.bfsTopologicalSort();

	return 0;
}
