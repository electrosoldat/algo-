// This is the code to search for the pivot element in a rotated-sorted array.

#include <iostream>
using namespace std;

int main() {
    
    int a[] = {4,5,6,7,9,1,2,3};
    int n = sizeof(a)/sizeof(int);

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

