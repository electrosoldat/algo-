// Code to print the spiral form of a given matrix

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

void spiral_print(int arr[10][10], int nr, int nc)
{
    int count = nr*nc;
    int start_row,start_col,end_row,end_col;
    start_row=0;
    start_col=0;
    end_row=nr-1;
    end_col=nc-1;

    while(start_col<=end_col && start_row<=end_row && count != 0)
    {
        // Print start_row from start_col to end_col and increment start_row by 1
        for(int j=start_col;j<=end_col;j++)
        {
            cout << arr[start_row][j] << " ";
        }
        start_row++ ;

        // Print end_col from start_row to end_row and decrement end_col by 1
        for(int i=start_row;i<=end_row;i++)
        {
            cout << arr[i][end_col] << " ";
        }
        end_col-- ;

        // Print end_row from end_col to start_col and decrement end_row by 1
        // Make sure it is print ed only if start_row < end_row. 
        // ## Similar conditions must be usd for all the 4 loops , in case of odd no. of columns or rows.
        for(int j=end_col;j>=start_col;j--)
        {
            cout << arr[end_row][j] << " ";
        }
        end_row-- ;

        // Print start_col from end_row to start_row and increment start_col by 1
        for(int i=end_row;i>=start_row;i--)
        {
            cout << arr[i][start_col] << " ";
        }
        start_col++ ;


        count-- ;

    }
}

int main() {
    int arr[10][10];

    int nr,nc;
    cin >> nr >> nc;

    read_matrix(arr,nr,nc);
    print_matrix(arr,nr,nc);
    cout << "\n" ; 
    spiral_print(arr,nr,nc);

    return 0;
}
