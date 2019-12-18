// insertion sort algorithm

#include <iostream>
using namespace std;
int main() {
    
    int n;
    cin >> n;

    int* a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    for(int i=1;i<n;i++)
    {
        int cur_no = a[i];
        int j;
        for(j=i-1;j>=0 && a[j] > cur_no; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = cur_no;
    }

    for(int i=0;i<n;i++)
    {
        cout << a[i] << "\n";
    }

    return 0;
}
