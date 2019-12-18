// Check if the given array is a palindrome.

/*

IS PALINDROME?
Take as input N, a number. Take N more inputs and store that in an array. Write a recursive function which tests if the array is a palindrome and returns a Boolean value. Print the value returned.

Input Format:
Enter a number N , add N more numbers

Constraints:
None

Output Format
Display the Boolean result

Sample Input
4
1
2
2
1
Sample Output
true

*/

#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int *a = new int[n];

	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}

	bool flag = true;
	for(int i=0;i<n/2;i++)
	{
		int k = n - 1 - i;
		if(a[i]!=a[k])
		{
			flag = false;
			break;
		}
	}

	if(flag)
		cout << "true";
	else
		cout << "false";

	return 0;
}
