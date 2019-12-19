/*

PIVOT OF SORTED AND ROTATED ARRAY
You are given a sorted but rotated array. You need to fine the index of the pivot element of the array where pivot is that element in the array which is greater than its next element and divides the array into two monotonically increasing halves.

Input Format:
The first line denotes N - the size of the array. The following N lines each denote the numbers in the array.

Constraints:
Output Format
Output the index of the pivot of the array.

Sample Input
5
4
5
1
2
3
Sample Output
1

*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    // We will find the pivot element 
    // using the binary seacrh algo and not the linear search algo
    int pivot;
    int s=0;
    int e=n-1;
    int m;
    while(s<=e)
    {
        m = (s+e)/2;

        if(a[m]>a[m+1] && m<e)
        {
            pivot = m;
            break;
        }
        else if(a[m]<a[m-1] && m>s)
        {
            pivot = m-1;
            break;
        }
        else
        {
            // that means, pivot has not bean found yet
            // and, it can be present in either left or right portion of the element.
            // but, out of the 2 portions one is properly sorted and other is not sorted.
            
            ///$$ And, it is for sure that the pivot will be in the unsorted portion.
            if(a[s]>=a[m]) 
            {
                //i.e. left portion of the array is unsorted
                e = m-1;
            }
            else if(a[e]<=a[m])
            {
                //i.e. right portion of the array is unsorted
                s = m+1;
            }

        }
    }

    cout << pivot;

    
    return 0;
}
