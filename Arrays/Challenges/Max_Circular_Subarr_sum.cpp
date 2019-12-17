/*

MAXIMUM CIRCULAR SUM
You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum sum of consecutive number.

Input Format:
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the size of numbers and next line contains n space separated integers.

Constraints:
1<=t<=100 1<=n<=1000

Output Format
Print the maximum sum.

Sample Input
1
7
8 -8 9 -9 10 -11 12
Sample Output
22

*/

#include<iostream>
#include <limits.h>
#include <cmath>
using namespace std;

int kadane(int* arr,int N)
{
    int local_max = 0;
    int global_max = INT_MIN;
    for(int k=0;k<N;k++)
    {
        local_max = max(arr[k],local_max+arr[k]);
        global_max = max(global_max,local_max);
    }

    return global_max;
}

int max_circular(int* arr, int N)
{
    int max_kadane = kadane(arr,N);

    // now, we will find max_wrap
    // i.e. the max sum with the corner elements

    int max_wrap = 0;
    int i;
    for(i=0; i<N;i++)
    {
        max_wrap = max_wrap + arr[i];
        arr[i] = -arr[i];
    }

    max_wrap = max_wrap + kadane(arr,N);

    int return_val = max(max_wrap,max_kadane);

    return return_val;
}

int main() {

    int t;
    cin >> t;

    while(t--)
    {
        int N;
        cin >> N;
        
        int* arr = new int[N];

        for(int i=0;i<N;i++)
        {
            cin >> arr[i];
        }

        int ans = max_circular(arr,N);

        cout << ans << endl;
    }

	return 0;
}
