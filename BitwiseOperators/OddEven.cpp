// Check whether a number is odd/even by using bitwise operators

#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	if(N&1)
		cout << "ODD";
	else
		cout << "EVEN";
		
	
	return 0;
}
