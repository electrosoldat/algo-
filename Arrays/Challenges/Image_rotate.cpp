/*

ROTATE IMAGE (N X N ARRAY)
Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.

Input Format:
First line contains a single integer N. Next N lines contain N space separated integers.

Constraints:
N < 1000

Output Format
Print N lines with N space separated integers of the rotated array.

Sample Input
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Sample Output
4 8 12 16 
3 7 11 15 
2 6 10 14 
1 5 9 13 

*/

// Rotate array anti-clockwise

#include <iostream>
using namespace std;

void read_matrix(int arr[1000][1000],int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> arr[i][j];
        }
    }
}

void print_matrix(int arr[1000][1000],int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate_matrix(int arr[1000][1000], int N)
{
    // transpose the matrix
    int n=N;
    for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			arr[i][j] = arr[i][j] + arr[j][i];
			arr[j][i] = arr[i][j] - arr[j][i];
			arr[i][j] = arr[i][j] - arr[j][i];
		}
	}

    // Step - 2 : Reverse each col.
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n/2;i++)
        {
            int k = n - 1 - i;
        	arr[i][j] = arr[i][j] + arr[k][j];
        	arr[k][j] = arr[i][j] - arr[k][j];
        	arr[i][j] = arr[i][j] - arr[k][j];
        }
    }
}

int main()
{
    int N;
    cin >> N;

    int arr[1000][1000] = {0};

    read_matrix(arr,N);
    rotate_matrix(arr,N);
    print_matrix(arr,N);

    return 0;
}
