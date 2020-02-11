/*

Take as input N, the size of an integer array. Take one more input, which is a list of N integers separated by a space, and store that in an array. Write a recursive function which prints true if the array is sorted, and false otherwise.

Input Format
N x y z

Constraints
1 < N < 1000
-10^9 < i < 10^9, where i is an element of the array

Output Format
true OR false

Sample Input
5
1 2 3 4 5
Sample Output
true


*/

#include<iostream>
using namespace std;

int main() {
	bool flag = true;
	int n;
	cin >> n;
	long long int* a = new long long int[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}

	int i=1;
	while(i<n)
	{
		if(a[i] < a[i-1])
		{
			flag = false;
			break;
		}
		i++ ;
	}

	if(flag)
		cout << "true";
	else
		cout << "false";


	return 0;
}
