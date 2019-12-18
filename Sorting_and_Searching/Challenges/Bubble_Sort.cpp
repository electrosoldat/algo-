/*

ARRAYS-BUBBLE SORT
Take as input N, the size of array. Take N more inputs and store that in an array. Write a function that bubble sorts the array. Print the elements of sorted array.

1.It reads a number N.
2.Take Another N numbers as input and store them in an Array.
3.Bubble sort the array and print the Array.

Input Format:
Constraints:
N cannot be Negative. Range of Numbers can be between -1000000000 to 100000000.

Output Format
Sample Input
4
2
-18
45
30
Sample Output
-18
2
30
45

*/

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int* arr = new int[n];
    
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int end=n;
    
    for(int i=0;i<n;i++)
    {
        cout <<  arr[i] << " ";
    }

    while(end>0)
    {
        for(int i=0;i<end-1;i++)
        {
            int i1 = i;
            int i2 = i+1;
            if(arr[i1]>arr[i2])
            {
                // swap the elements
                arr[i1] = arr[i1] + arr[i2];
                arr[i2] = arr[i1] - arr[i2];
                arr[i1] = arr[i1] - arr[i2];
            }
        }
        end-- ;
    }

    cout << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
© 2019 GitHub, Inc.
