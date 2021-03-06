// This code returns the value of the last occurence of an element in an array.
// upper bound = last occurence

#include <iostream>
using namespace std;

int lastOccurence(int arr[],int n,int key)
{
    // Binary Search algorithm
    // Modified to find the first occurence, aka lower bound

    int start = 0;
    int end = n-1;
    int mid;
    int ans = -1;

    while(start<=end)
    {
        mid = (start+end)/2;
        if(arr[mid]==key)
        {
            // first, I need to update the value of ans
            // next, I nee to disccard the portion to the right of mid.
            ans = mid;
            start = mid + 1;
        }
        else if(key < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {

    int arr[] = {1,2,2,2,2,3,4,4,4};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin >> key;

    int pos = lastOccurence(arr,n,key);
    cout << pos;
    
    return 0;
}
