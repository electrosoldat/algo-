/*

MAXIMUM SUBARRAY SUM
You are given a one dimensional array that may contain both positive and negative integers, find the sum of contiguous subarray of numbers which has the largest sum. For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.

Input Format:
The first line consists of number of test cases T. Each test case consists of N followed by N integers.

Constraints:
1 <= N <= 100000

1 <= t <= 20

 -100000000 <= A[i] <= 100000000

Output Format
The maximum subarray sum

Sample Input
2
4
1 2 3 4
3
-10 5 10

*/

#include <iostream>
#include <limits.h>
using namespace std;
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

        int local_max = 0;
        int global_max = INT_MIN;

        for(int i=0;i<N;i++)
        {
            local_max = max(local_max+arr[i],arr[i]);
            if(local_max > global_max)
            {
                global_max = local_max;
            }
        }

        cout << global_max << endl;

    
    }
    return 0;
}
