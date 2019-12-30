// this is the implementation of bubble sort using recursion for the outer loop a
// while, using for loop for the inner loop

#include <iostream>
using namespace std;

void myswap(int* a , int* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    return;
}

void bubblesort(int* a,int n)
{
    // Base case
    if(n==1)
    {
        return;
    }
    
    // now, we will sort one element and call the function again for th remaining 
    // n-1 elements
    for(int i=0;i<n - 1;i++)
    {
        if(a[i] > a[i+1])
        {
            myswap(&a[i],&a[i + 1]);
        }
    }
    
    bubblesort(a,n - 1);
}

int main()
{
    int n;
    cin >> n;
    
    int* a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    
    bubblesort(a,n);
    
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    
    return 0;
}
