// This is the c++ code for selection sort

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int* arr = new int[n];

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    for(int i=0;i<n-1;i++)
    {
        int min_pos = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min_pos]>arr[j])
            {
                min_pos = j;
            }
        }
        // swap the cur_val, with the current min.
        int temp = arr[i];
        arr[i] = arr[min_pos];
        arr[min_pos] = temp;

    }

    cout << endl;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << "\n";
    }


    return 0;
}
