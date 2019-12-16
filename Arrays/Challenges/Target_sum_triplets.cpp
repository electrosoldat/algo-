/* 

ARRAYS-TARGET SUM TRIPLETS
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all triplets of numbers which sum to target.

Input Format:
First line contains input N. Next N lines contains the elements of array and N+1 line contains target number.

Constraints:
Length of Array should be between 1 and 1000.

Output Format
Print all the triplet present in the array.

Sample Input
9
5
7
9
1
2
4
6
8
3
10
Sample Output
1, 2 and 7
1, 3 and 6
1, 4 and 5
2, 3 and 5

*/

#include<iostream>
using namespace std;
#include <algorithm>

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

    for(int i=0;i<N-2;i++)
    {
    	int left = i+1;
    	int right = N-1;
    	while(left<right)
    	{
	    	if(arr[left]+arr[right]+arr[i] == T)
	    	{
	    		cout << arr[i] << ", " << arr[left] << " and " << arr[right] << endl;
	    		left++ ;
	    	}
	    	else
	    	{
	    		right-- ;
	    	}
    	}
    }

	return 0;
}
