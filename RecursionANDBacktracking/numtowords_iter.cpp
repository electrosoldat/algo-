#include <iostream>
using namespace std;

void numtowords(int n)
{
    while(n!=0){
    int cur_dig = n%10;
    
    switch(cur_dig)
    {
        case 1:
            cout << "one ";
            break;
        case 2:
            cout << "two ";
            break;
        case 3:
            cout << "three ";
            break;
        case 4:
            cout << "four ";
            break;
        case 5:
            cout << "five ";
            break;
        case 6:
            cout << "six ";
            break;
        case 7:
            cout << "seven ";
            break;
        case 8:
            cout << "eight ";
            break;
        case 9:
            cout << "nine ";
            break;
        default:
            cout << "zero ";
            break;
    }
    n = n/10;
    }
}

int reversDigits(int num) 
{ 
    int rev_num = 0; 
    while(num > 0) 
    { 
        rev_num = rev_num*10 + num%10; 
        num = num/10; 
    } 
    return rev_num; 
}

int main() {
	// your code goes here
	int num;
	cin >> num;
	
	int revnum = reversDigits(num);
	
	numtowords(revnum);
	
	return 0;
}
