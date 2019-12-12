// This is a program to search a number in a sorted(both row-wise and column-wise) 2D array.
// The worst case time complexity of this algorithm is O(2N).

#include <iostream>
using namespace std;

void read_matrix(int arr[10][10], int nr, int nc)
{
    for(int i=0;i<nr;i++)
    {
        for(int j=0;j<nc;j++)
        {
            cin >> arr[i][j];
        }
    }
}

void print_matrix(int arr[10][10], int nr, int nc)
{
    for(int i=0;i<nr;i++)
    {
        for(int j=0;j<nc;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int arr[10][10];

    int nr,nc;
    cin >> nr >> nc;

    read_matrix(arr,nr,nc);
    print_matrix(arr,nr,nc);
    cout << "\n" ; 

    int N;
    cin >> N; // the element to be searched 

    int r = 0;
    int c = nc-1; // the values have been initialised such that the cur_val is set to the top-right corner of the matirix.
    
    // the algo is simple 
    // if the element to be searched is greater than the current value, then go down, else go left.

    while(arr[r][c] != N)
    {
        if(N > arr[r][c])
        {
            r += 1;
        }
        else{
            c -= 1;
        }
    }

    cout << r << " " << c;
    
    return 0;
}
