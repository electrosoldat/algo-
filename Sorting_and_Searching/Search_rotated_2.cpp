// In this approach, there is no nee to rotate the array.

#include <iostream>
using namespace std;

int binarySearch(int a[],int s,int e,int key)
{
    int m;
    int ans = -1;
    while(s<= e)
    {
        m = (s+e)/2;
        if(a[m]==key)
        {
            ans = m;
            break;
        }
        else if(a[m]>key)
        {
            e = m-1;
        }
        else
        {
            s = m+1;
        }
    }
    return ans;

}
int main() {
    
    int a[] = {4,5,6,1,2,3};
    int n = sizeof(a)/sizeof(int);

    int k; // k is the index where the last element is the 1st sorted array is placed.
    for(k=0;k<n;k++)
    {
        if(a[k+1]<a[k])
            break;
    }

    // now, I have 2 separate sorted arrays , and I can find the required element by separately appliying binary
    // search to one of them.

    int key;
    cin >> key; // key is the element to be found

    int pos,s,e;
    if(key>a[0])
    {
        s = 0;
        e = k;
        pos = binarySearch(a,s,e,key);
    }
    else
    {
        s = k+1;
        e = n-1;
        pos = binarySearch(a,s,e,key);
    }

    cout << pos;



    
    return 0;
}
