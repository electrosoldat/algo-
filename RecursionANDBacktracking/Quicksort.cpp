// implementation of the quicksort algorithm
#include <iostream>
using namespace std;

void myswap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    
    return;
}

int partition(int *arr, int start, int end)
{
    int i = start-1;
    int pivot = arr[end];
    
    for(int j=start;j<end;j++)
    {
        if(arr[j] <= pivot)
        {
            i+=1 ;
            myswap(&arr[i],&arr[j]);
        }
    }
    
    myswap(&arr[i+1],&arr[end]);
    
    return i+1;
}

void quicksort(int* arr, int start, int end)
{
    // Base case 
    if(start>=end)
    {
        return ;
    }
    
    // Recursive case
    
    // the partition function returns the index of the 
    // pivot element in the sorted array.
    int p = partition(arr,start,end);
    
    // Now we will separately sort the 2 parts of the array .
    quicksort(arr,start,p-1);
    quicksort(arr,p+1,end);
}

int main()
{
    int n;
    cin >> n;
    
    int* arr = new int[n];
    
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    
    quicksort(arr, 0, n-1);
    
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
