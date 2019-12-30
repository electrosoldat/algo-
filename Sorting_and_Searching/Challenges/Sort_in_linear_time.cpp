/*

SORTING IN LINEAR TIME
You will be given an array containing only 0s, 1s and 2s. you have sort the array in linear time that is O(N) where N is the size of the array.

Input Format:
The first line contains N, which is the size of the array. The following N lines contain either 0, or 1, or 2.

Constraints:
Each input element x, such that x ∈ { 0, 1, 2 }.

Output Format
Output the sorted array with each element separated by a newline.

Sample Input
5
0
1
2
1
2
Sample Output
0
1
1
2
2

*/

#include<iostream>
using namespace std;

void myswap(int* a,int* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    return;
}

int main() {
    int n;
    cin >> n;

    int mid = 0;
    int low = 0;
    int high = n-1;

    int* arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    while(mid <= high)
    {
        //cout << "start : " << low << " " << mid << " " << high << endl;
        if(arr[mid]==1)
        {
            mid++ ;
        }
        else if(arr[mid]==2)
        {
            myswap(&arr[mid],&arr[high]);
            high-- ;
        }
        else if(arr[mid] == 0){
            myswap(&arr[mid],&arr[low]);
            low++ ;
            mid++ ;
        }
        //cout << "end : " << low << " " << mid << " " << high << endl;
    }

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << endl;
    }
	return 0;
}
