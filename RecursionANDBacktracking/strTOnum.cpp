// Given a strig , convert into its number form.

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int strtonum(char str[])
{
    int ans=0;
    if(strlen(str)==1)
    {
        return (str[0]-'0');
    }
    
    int x = (str[0]-'0') * pow(10,(strlen(str) - 1));
    ans = x + strtonum(str+1);
    
    return ans;
}

int main()
{
    char str[] = "123567";
    int ans = strtonum(str);
    cout << ans;
    
    return 0;
}
