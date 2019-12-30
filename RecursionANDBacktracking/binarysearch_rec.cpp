#include <iostream>
using namespace std;

int binarysearch(int*a, int start, int end, int key)
{
    int mid = (start + end) / 2;
    if(start > end)
        return -1;
        
    if(a[mid] == key)
        return mid;
        
    else if(key < a[mid])
        return binarysearch(a,start,mid - 1,key);
    else 
        return binarysearch(a,mid + 1,end,key);
}

int main()
{
    int n;
    cin >> n;
    
    int *a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    
    int key;
    cin >> key;
    
    int start = 0;
    int end = n - 1;
    
    int ans = binarysearch(a,start,end,key);
    cout << ans;
    
    return 0;
}
