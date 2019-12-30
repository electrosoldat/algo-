// recursive algorithm to linear search an element in an array.

#include <iostream>
using namespace std;

int linearsearch(int* a,int i,int key,int n) // i is the index of current element
{
    if(i==n)
    {
        return -1;
    }
    if(a[i] == key)
        return i;
    
    int ans = linearsearch(a,i+1,key,n);
    return ans;
}

int main()
{
    int a[] = {4,2,0,9,-5,6,7};
    int n = sizeof(a) / sizeof(int);
    int key;
    cin >> key;
    int ans = linearsearch(a,0,key,n);
    cout << ans ;
    
    return 0;
}
