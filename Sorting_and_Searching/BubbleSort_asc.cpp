// this program includes code for Bubble Sort Algorithm

#include <iostream>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    int* arr = new int[n];
    
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int end=n;
    
    for(int i=0;i<n;i++)
    {
        cout <<  arr[i] << " ";
    }

    while(end>0)
    {
        for(int i=0;i<end-1;i++)
        {
            int i1 = i;
            int i2 = i+1;
            if(arr[i1]>arr[i2])
            {
                // swap the elements
                arr[i1] = arr[i1] + arr[i2];
                arr[i2] = arr[i1] - arr[i2];
                arr[i1] = arr[i1] - arr[i2];
            }
        }
        end-- ;
    }

    cout << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
