// First is my code
// Second is Prateek sir's code.

// Bianry Search Algorithm
#include <iostream>
using namespace std;
int main() {
    
    int arr[] = {1,2,3,4,6,8,19,54,90,456};
    int n = 10;

    int num = 256;

    int s = 0;
    int e = n-1;
    bool flag = false;
    int pos = -1;
    while(s<=e)
    {
        int m = (s+e)/2;
        if(arr[m] == num)
        {
            flag = true;
            pos = m;
            break;
        }
        else if(num < arr[m])
        {
            e = m-1;
        }
        else
        {
            s = m + 1;
        }
    }

    if(flag)
        cout << "Found " << num << " at " << pos << "th index" << endl;
    else
    {
        cout << "Not Found";
    }
    return 0;
}

// Second, is Prateek Sir's Code.

int BinarySearch(int a[],int n,int key)
{
  int start=0;end=n-1;
  int mid;
  
  while(start<=end)
  {
    mid = (start+end)/2;
    
    if(a[mid]==key)
    {
      /// Element found
      return mid;
    }
    else if
    {
      // Key might be present in the left half.
      end = mid-1;
    }
    else
    {
    // Key might be present in the right half.
    start = mid +1;
    }
  }
  return -1; // This means that the element was not found.
}
