#include <iostream>
using namespace std;

/*
char spellings[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
*/

void numtowords(int n) // recursive function
{
    if(n==0)
    {
        return;
    }
    int cur_dig = n%10;
    numtowords(n/10);
    
    //instead of the switch case statement, we can also use a 2D character array.
    // cout << spellings[cur_dig] << " ";
    
    switch(cur_dig)
    {
        case 1:
            cout<< "one ";
            break;
        case 2:
            cout<< "two ";
            break;
        case 3:
            cout<< "three ";
            break;
        case 4:
            cout<< "four ";
            break;
        case 5:
            cout<< "five ";
            break;
        case 6:
            cout<< "six ";
            break;
        case 7:
            cout<< "seven ";
            break;
        case 8:
            cout<< "eight ";
            break;
        case 9:
            cout<< "nine ";
            break;
        default:
            cout << "zero ";
            break;
    }
}

int main() {
	// your code goes here
	int num;
	cin >> num;
	
	numtowords(num);
	
	return 0;
}
