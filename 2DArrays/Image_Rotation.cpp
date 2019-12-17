// Image rotation problem
// Basically, to rotate a 2D array by 90 deg. clockise

#include <iostream>
using namespace std;

void gen_matrix(int arr[10][10], int n)
{
    int value=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            arr[i][j] = value++ ;
        }
    }
}

void print_matrix(int arr[10][10], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void rotate_matrix(int arr[10][10], int n)
{
    // Step - 1 : Transpose the matrix
    for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			arr[i][j] = arr[i][j] + arr[j][i];
			arr[j][i] = arr[i][j] - arr[j][i];
			arr[i][j] = arr[i][j] - arr[j][i];
		}
	}

    // Step - 2 : Reverse each row.
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n/2;j++)
        {
            int k = n - 1 - j;
            arr[i][j] = arr[i][j] + arr[i][k];
			arr[i][k] = arr[i][j] - arr[i][k];
			arr[i][j] = arr[i][j] - arr[i][k];
        }
    }
}

int main() {
    
    int arr[10][10]={0};
    // a square matrix, of max sixe 10

    int n;
    cin >> n; // input the no. of rows and columns

    gen_matrix(arr,n);

    print_matrix(arr,n);

    cout << "\n";

    rotate_matrix(arr,n);

    print_matrix(arr,n);

    cout << endl;

    rotate_matrix(arr,n);

    print_matrix(arr,n);

    cout << endl;

    rotate_matrix(arr,n);

    print_matrix(arr,n);

    cout << endl;

    rotate_matrix(arr,n);

    print_matrix(arr,n);

    cout << endl;

    return 0;
}
