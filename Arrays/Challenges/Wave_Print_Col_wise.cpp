/*

ARRAYS-WAVE PRINT COLUMN WISE
Take as input a two-d array. Wave print it column-wise.

Input Format:
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints:
Both M and N are between 1 to 10.

Output Format
All M * N integers seperated by commas with 'END' wriiten in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output
11, 21, 31, 41, 42, 32, 22, 12, 13, 23, 33, 43, 44, 34, 24, 14, END

*/

#include<iostream>
using namespace std;

void input_matrix(int arr[10][10], int nr, int nc)
{
	for(int i=0;i<nr;i++)
	{
		for(int j=0;j<nc;j++)
		{
			cin >> arr[i][j];
		}
	}
}

void wave_print(int arr[10][10], int nr, int nc)
{
	for(int j=0;j<nc;j++)
	{
		if(j%2==0)
		{
			for(int i=0;i<nr;i++)
			{
				cout << arr[i][j] << ", ";
			}
		}
		else
		{
			for(int i=nr-1;i>=0;i--)
			{
				cout << arr[i][j] << ", ";
			}
		}
	}
}
int main() {

	int arr[10][10];

	int nr,nc;
	cin >> nr >> nc;

	input_matrix(arr,nr,nc);

	wave_print(arr,nr,nc);

	cout << "END";

	return 0;
}
