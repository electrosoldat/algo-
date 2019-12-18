/*

LOWER UPPER
Print "lowercase" if user enters a character between 'a-z' , Print "UPPERCASE" is character lies between 'A-Z' and print "Invalid" for all other characters like $,.^# etc.

Input Format:
Single Character .

Constraints:
-

Output Format
lowercase UPPERCASE Invalid

Sample Input
$
Sample Output
Invalid

*/

#include<iostream>
using namespace std;

int main() {
	char ch;
	cin >> ch;

	if((int)ch >= (int)'a' && (int)ch <= (int)'z')
	{
		cout << "lowercase";
	}

	else if((int)ch >= (int)'A' && (int)ch <= (int)'Z')
	{
		cout << "UPPERCASE";
	}

	else
	{
		cout << "Invalid";
	}

	return 0;
}
