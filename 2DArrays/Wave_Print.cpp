// This program reads the given 2D matiix of numbers in a wave form.
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

void wave_print(int arr[10][10],int nr,int nc)
{
    for(int i=0;i<nc;i++)
    {
        if(i%2 == 0)
        {
            for(int j=0;j<nr;j++)
            {
                cout << arr[j][i] << " ";
            }
        }
        else
        {
            for(int j=nr-1;j>=0;j--)
            {
                cout << arr[j][i] << " ";
            }
        }
    }
}

int main() {
    int arr[10][10];

    int nr,nc; //nr=no.of rows, nc = no. of columns
    cin >> nr >> nc;

    read_matrix(arr,nr,nc);
    print_matrix(arr,nr,nc);
    cout << "\n" << "$$$$$$$$$$$$$" << "\n";
    wave_print(arr,nr,nc);
}
