// Code Author : TAVISH CHADHA

#include <iostream>
#include <queue>
using namespace std;

int JoinwithMinCost(int* ropes, int n)
{
	priority_queue <int, vector<int>, greater<int> > pq(ropes,ropes+n);

	int cost = 0;
	while(pq.size() > 1)
	{
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();

		cost += first + second;
		pq.push(first+second);
	}

	return cost;
}

int main()
{
	// Type your code here.
	int n;
	cin >> n;

	int* ropes = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> ropes[i];
	}

	int min_cost = JoinwithMinCost(ropes,n);
	cout << min_cost;

	return 0;
}