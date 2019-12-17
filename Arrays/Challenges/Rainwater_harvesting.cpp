/*

RAIN WATER HARVESTING
Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

Explanation for the Sample input Testcase:
So the total units of water she can save is 5 units

Input Format:
First line contains an integer n. Second line contains n space separated integers representing the elevation map.

Constraints:
Output Format
Print a single integer containing the maximum unit of waters she can save.

Sample Input
10
0 2 1 3 0 1 2 1 2 1
Sample Output
5

*/

#include<iostream>
#include <cmath>
using namespace std;

int main() {

    int n;
    cin >> n;

    int* arr = new int[n];
    int* left_max = new int[n];
    int* right_max = new int[n];

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    left_max[0] = arr[0];
    right_max[n-1] = arr[n-1];

    for(int i=1;i<n;i++)
    {
        left_max[i] = max(left_max[i-1],arr[i]);
    }

    for(int i=n-2;i>=0;i--)
    {
        right_max[i] = max(right_max[i+1],arr[i]);
    }

    int * water = new int[n];
    int ans =0;
    for(int i=0;i<n;i++)
    {
        water[i] = min(right_max[i],left_max[i]) - arr[i];
        ans += water[i];
    }

    cout << ans;

	return 0;
}
