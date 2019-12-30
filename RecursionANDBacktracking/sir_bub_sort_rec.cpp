#include <iostream>
using namespace std;

void myswap(int* a , int* b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    return;
}

void bubblesort(int* a,int n, int j)
{
    // Base cases
    if(n==1)
    {
        return;
    }
    if(j==n - 1)
    {
        // this condition checks if the inner loop has reached the 
        // end of the array.
        // then, we will reduce the size of the loop by n-1
        // also, we will reset the value of j to 0
        
        bubblesort(a,n - 1,0); // recursive call 1
        
    }
    
    if(a[j] > a[j + 1])
    {
        myswap(&a[j],&a[j + 1]);
    }
    bubblesort(a,n,j + 1); // recursive call 2
    
    return;
    // now, we will sort one element and call the function again for th remaining 
    // n-1 elements
    /* 
    for(int i=0;i<n - 1;i++)
    {
        if(a[i] > a[i+1])
        {
            myswap(&a[i],&a[i + 1]);
        }
    } */
    
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
    
    bubblesort(a,n,0);
    
    for(int i=0;i<n;i++)
    {
        cout << a[i] << " ";
    }
    
    return 0;
}
