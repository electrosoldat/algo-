#include <iostream>
using namespace std;

void merge(int* a,int s, int e)
{
    int mid = (s+e)/2;
    int temp[100] = {0};
    
    // we will merge the two sorted arrays using the 3 pointer method
    int i = s;
    int j = mid + 1;
    int k = s;
    
    while(i<=mid && j <= e)
    {
        if(a[i]<a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    
    while(j<=e)
    {
        temp[k++] = a[j++];
    }
    
    while(i<=mid)
    {
        temp[k++] = a[i++];
    }
    
    
    for(int h=s;h<=e;h++)
    {
        a[h]=temp[h];
    }
    
    return;
}

void mergesort(int a[],int s, int e)
{
    // we have to solve this problem recursively
    
    // Base case
    if(s>=e)
    {
        return ;
    }
    
    // now, the recursive case 
    // it has 3 steps
    
    // 1. divide the array into 2 parts
    int mid = (s+e)/2;
    
    // 2. sort the two parts 
    mergesort(a,s,mid);
    mergesort(a,mid + 1,e);
    
    // 3. merge the two sorted parts
    merge(a,s,e);
}

int main() {
	
	int n;
	cin >> n;
	
	int* a = new int[n];
	for(int i=0;i<n;i++)
	{
	    cin >> a[i];
	}
	
	mergesort(a,0,n - 1);
	
	for(int i=0;i<n;i++)
	{
	    cout << a[i] << " ";
	}
	
	
	return 0;
}
