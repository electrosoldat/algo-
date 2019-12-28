// This code provides the best possible way to find the sum of all possible subarrays in a given matrix.
// O(N^2) is the time complexity of this solution.
// O(1) is the space complexity of this solution.

#include <iostream>
using namespace std;

int main()
{
    int a[2][2] = {{1,1},{1,1}};
    int nr=2,nc=2;
    int ans = 0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            // Now. we want to find the contributio of the (i,j)th element 
            ans += a[i][j] * ((i+1)*(j+1) * (nr-i)*(nc-j));
            //1- a[i][j] is the current element
            //2- (i+1)(j+1) is the no. of total possible TL-corner positions
            //3- (nr-i)(nc-j) is the no. of total possble BR-corner positions
            // the product of last two(2*3) is the total no. of submatrices in which that element appears. 
            // the product of the above three(1*2*3) is the total contribution made by that element
        }
    }

    cout << ans;

    return 0;
}
