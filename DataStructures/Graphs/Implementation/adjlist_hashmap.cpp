// Code Author : TAVISH CHADHA

#include <iostream>
#include <map>
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
};

int main()
{
	// Type your code here.
	Graph<string> g1;
	g1.addEdge("Putin","Trump",false);
	g1.addEdge("Putin","Modi",false);
	g1.addEdge("Putin","Pope",false);
	g1.addEdge("Trump","Modi");
	g1.addEdge("Modi","Yogi");
	g1.addEdge("Yogi","Prabho",false);
	g1.addEdge("Prabho","Modi",false);

	g1.print_adjlist();

	Graph<int> g2;
	g2.addEdge(0,1);
	g2.addEdge(0,4);
	g2.addEdge(4,3);
	g2.addEdge(1,4);
	g2.addEdge(1,2);
	g2.addEdge(2,3);
	g2.addEdge(1,3);

	g2.print_adjlist();

	return 0;
}