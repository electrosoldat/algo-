// How to allocate memory dynamically for a 2D array.
#include <iostream>
using namespace std;
int main() {
    
    int nr,nc;
    cin >> nr >> nc;

    int **arr = new int*[nr]; // 'arr' is a pointer to an array of pointers, and the sixe of that array is "nr"
    // nr = the no. of rows
    // this array of pointers is the primary array in the structure of a 2D array in memory.

    for(int i=0;i<nr;i++) // this loop is to allocate memory to each pointer(in the primary array of pointers)
    {
        arr[i] = new int[nc]; 
        // nc = the no. of columns
        // each array here allocated, is secondary array to which the pointers stored in the primary 
        // array point to.
    }

    int value = 1;
    for(int i=0;i<nr;i++)
    {
        for(int j=0;j<nc;j++)
        {
            arr[i][j] = value++;
        }
    }

    for(int i=0;i<nr;i++)
    {
        for(int j=0;j<nc;j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    // De-allocation of 2D array in C++
    for(int i=0;i<nr;i++)
    {
        delete []arr[i]; // firs, we delete all the secondary arrays
    }

    // next, we delete the primary array.
    delete []arr;

    cout << " HELLO " << endl;
    return 0;
}
