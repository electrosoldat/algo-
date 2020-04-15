// Code Author : TAVISH CHADHA


#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <cstring>
#include <list>
#include <limits.h>
#include <queue>

using namespace std;

template <typename T>
class Graph
{
	unordered_map < T, list < pair < T, int > > > m;
public:
	void addEdge(T u, T v, int dist, bool bidir = true)
	{
		m[u].push_back(make_pair(v,dist));
		if(bidir)
		{
			m[v].push_back(make_pair(u,dist));
		}
	}

	void printAdjList()
	{
		for(auto j:m)
		{
			cout << j.first << "-->";
			for(auto l : j.second)
			{
				cout << "(" << l.first << "," << l.second << ")";
			}
			cout << endl;
		}
	}

	void dijsktraSSSP(T src)
	{
		unordered_map<T,int> dist;

		// set all dist to inf.
		for(auto j:m)
		{
			dist[j.first] = INT_MAX;
		}

		// make a set to find out a node with the min. distance
		set < pair <int, T> > s;
		dist[src] = 0;
		s.insert(make_pair(0,src));

		while(!s.empty())
		{
			//find the pair at the front.
			auto p = *(s.begin());
			T node = p.second;

			int nodeDist = p.first;
			s.erase(s.begin());

			//iterate over the neighbours of the cur node.
			for(auto childPair : m[node])
			{
				// check if the curnode covers the current child in a better way
				if(nodeDist + childPair.second < dist[childPair.first])
				{
					// in the set, updation is not possible 
					// so, we have to remove the old & insert the new 
					T dest = childPair.first;
					auto f = s.find(make_pair(dist[dest],dest));
					if(f!=s.end())
					{
						s.erase(f);
					}

					// now, insert the new pair.
					dist[dest] = nodeDist + childPair.second;
					s.insert(make_pair(dist[dest],dest));
				}
			}
		}

		for(auto d : dist)
		{
			cout << d.first << " is located at a distance of " << d.second << endl;
		}
	}
};

int main()
{
	// Type your code here.
	Graph<int> g;
	g.addEdge(1,2,1);
	g.addEdge(1,3,4);
	g.addEdge(1,4,7);
	g.addEdge(3,2,1);
	g.addEdge(4,3,2);

	g.dijsktraSSSP(1);
    cout << endl << "----------------------------------------------------" << endl;
    Graph<string> india;
    india.addEdge("amritsar","jaipur",4);
    india.addEdge("amritsar","delhi",1);
    india.addEdge("jaipur","delhi",2);
    india.addEdge("jaipur","mumbai",8);
    india.addEdge("delhi","agra",1);
    india.addEdge("bhopal","mumbai",3);
    india.addEdge("bhopal","agra",2);
    india.dijsktraSSSP("amritsar");

	return 0;
}