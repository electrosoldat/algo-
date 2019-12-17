/*

ARRAYS-SPIRAL PRINT ANTICLOCKWISE
Take as input a 2-d array. Print the 2-D array in spiral form anti-clockwise.

Input Format:
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints:
Both M and N are between 1 to 10.

Output Format
All M * N integers separated by commas with 'END' written in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output
11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END

*/

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
        // Print start_col from end_row to start_row and increment start_col by 1
        for(int i=start_row;i<=end_row;i++)
        {
            cout << arr[i][start_col] << ", ";
        }
        start_col++ ;

         // Print end_row from end_col to start_col and decrement end_row by 1
        // Make sure it is print ed only if start_row < end_row. 
        // ## Similar conditions must be usd for all the 4 loops , in case of odd no. of columns or rows.
        for(int j=start_col;j<=end_col;j++)
        {
            cout << arr[end_row][j] << ", ";
        }
        end_row-- ;

         // Print end_col from start_row to end_row and decrement end_col by 1
        for(int i=end_row;i>=start_row;i--)
        {
            cout << arr[i][end_col] << ", ";
        }
        end_col-- ;

        // Print start_row from start_col to end_col and increment start_row by 1
        for(int j=end_col;j>=start_col;j--)
        {
            cout << arr[start_row][j] << ", ";
        }
        start_row++ ;

        count-- ;

    }
}

int main() {
    int arr[10][10];

    int nr,nc;
    cin >> nr >> nc;

    read_matrix(arr,nr,nc);
    spiral_print(arr,nr,nc);

    cout << "END";

    return 0;
}
