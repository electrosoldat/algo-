// This is the code to find the submatrix from a 2D-matrix, which is row and column wise sorted.
// the submstrix should have the maximum sum of all the possible submatrices.
#include <iostream>
#include <limits.h>
using namespace std;

void inputmatrix(int** a,int nr, int nc)
{
    for(int i=0;i<nr;i++)
    {
        for(int j=0;j<nc;j++)
        {
            cin >> a[i][j];
        }
    }
}

void outputmatrix(int** a,int nr, int nc)
{
    for(int i=0;i<nr;i++)
    {
        for(int j=0;j<nc;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int nr;
    int nc;
    cin >> nr >> nc;

    int** a = new int*[nr];
    for(int i=0;i<nr;i++)
    {
        a[i] = new int[nc];
    }

    inputmatrix(a,nr,nc);

    outputmatrix(a,nr,nc);

    // Now, I have to make the suffix sum matrix
    for(int i=nr-1;i>=0;i--)
    {
        for(int j=nc-1;j>=0;j--)
        {
            if(j!=nc-1)
            {
                a[i][j] = a[i][j] + a[i][j+1];
            }
        }
    }

    for(int j=nc-1;j>=0;j--)
    {
        for(int i=nr-1;i>=0;i--)
        {
            if(i!=nr-1)
            {
                a[i][j] = a[i][j] + a[i+1][j];
            }
        }
    }

    outputmatrix(a,nr,nc);

    int max=INT_MIN;
    int ans_i,ans_j,i,j;
    for(i=nr-1;i>=0;i--)
    {
        for(j=nc-1;j>=0;j--)
        {
            if(a[i][j] > max)
            {
                max = a[i][j];
                ans_i = i;
                ans_j = j;
            }
        }
    }

    cout << ans_i << " " << ans_j << " " << max;

    return 0;
}
