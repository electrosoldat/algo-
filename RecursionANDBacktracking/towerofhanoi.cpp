#include <iostream>
using namespace std;

void towerofhanoi(int n,char src,char helper,char dest)
{
    // base case 
    if(n==0)
        return;
    
    // recuesive case
    
    // step 1 => move n-1 disks from src to helper
    towerofhanoi(n - 1,src,dest,helper);
    
    // step 2 => move nth disk from src to dest
    cout << "Move " << n << " from " << src << " to " << dest << endl;
    
    // step 3 => move n-1 disks from helper to dest
    towerofhanoi(n - 1,helper,src,dest);
    
}

int main()
{
    int n;
    cin >> n;
    
    towerofhanoi(n,'A','B','C');
    
    return 0;
}
