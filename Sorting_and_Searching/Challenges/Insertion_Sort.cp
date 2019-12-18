/*

ARRAYS-INSERTION SORT
Take as input N, the size of array. Take N more inputs and store that in an array. Write a function that insertion sorts the array. Print the elements of sorted array.

Input Format:
Constraints:
Length of Array should be between 1 and 1000.

Output Format
Sample Input
4
3
4
2
1
Sample Output
1
2
3
4

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

    for(int i=1;i<n;i++)
    {
        int cur_no = a[i];
        int j;
        for(j=i-1;j>=0 && a[j] > cur_no; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = cur_no;
    }

    for(int i=0;i<n;i++)
    {
        cout << a[i] << "\n";
    }

    return 0;
}
