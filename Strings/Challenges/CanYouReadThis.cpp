/*

One of the important aspect of object oriented programming is readability of the code. To enhance the readability of code, developers write function and variable names in Camel Case. You are given a string, S, written in Camel Case. FindAllTheWordsContainedInIt.

Input Format
A single line contains the string.

Constraints
|S|<=1000

Output Format
Print words present in the string, in the order in which it appears in the string.

Sample Input
IAmACompetitiveProgrammer
Sample Output
I
Am
A
Competitive
Programmer
Explanation
There are 5 words in the string.

*/

// in this question, just count the number of capital letters encountered.

#include<iostream>
using namespace std;

bool isCapital(char a)
{
	if((int)a <= 'Z' && (int)a >= 'A')
		return true;
	else
		return false;
}

int main() {
	char camel[1003];
	cin >> camel;

	int i = 0;
	while(camel[i] != '\0')
	{
		cout << camel[i];
		if(isCapital(camel[i+1]))
		{
			cout << endl; 
		}
		i++ ;
	}

	return 0;
}
