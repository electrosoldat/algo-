// This is a special kind of sorting algorithm
// asked in interview by tech giants.

// Wave Sort
// Arrange the elements in the array, such that the elements are alternatively big and small
// hence, creating a wave.

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int* a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    for(int i=0;i<n;i+=2)
    {
        if(i>0 && a[i]<a[i-1])
        {
            swap(a[i],a[i-1]);
        }
        if(i<n && a[i+1]>a[i])
        {
            swap(a[i],a[i+1]);
        }
    }

    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
