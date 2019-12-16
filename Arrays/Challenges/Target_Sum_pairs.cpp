/*
ARRAYS-TARGET SUM PAIRS
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.

Input Format:
The first line contains input N. Next N lines contains the elements of array and (N+1)th line contains target number.

Constraints:
Length of the arrays should be between 1 and 1000.

Output Format
Print all the pairs of numbers which sum to target. Print each pair in increasing order.

Sample Input
5
1
3
4
2
5
5
Sample Output
1 and 4
2 and 3

*/

#include<iostream>
#include <algorithm>
using namespace std;

int main() {

	int N;
	cin >> N;

	int* arr = new int[N];

	for(int i=0;i<N;i++)
	{
		cin >> arr[i];
	}

	int T;
	cin >> T;

	sort(arr,arr+N);

	for(int i=0;i<N-1;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(arr[i]+arr[j] == T)
			{
				cout << arr[i] << " and " << arr[j] << "\n";
			}
		}
	}

	return 0;
}
