/*

Given a brick wall of dimension 4xN.
We have tiles of dimension 4x1.

Now, we need to calculate the no. of ways to arrange the tiles

*/
#include <iostream>
using namespace std;

int tiling(int n)
{
    // f(n) = f(n-1) + f(n-4);
    if(n<4 && n>0)
        return 1;
    if(n==4)
        return 2;
        
    int ans=0;
    ans = tiling(n - 1) + tiling(n - 4);
    return ans;
     
}

int main()
{
    int n; // this gives the length of the wall
    cin >> n; // 4*n is the dimension of the wall (4 = height)
    
    // we have 4*1 tiles and we need to find total no. of ways to arrange  
    // these tiles on the wall.
    
    int no_of_ways = tiling(n);
    cout << no_of_ways;
    return 0;
}
