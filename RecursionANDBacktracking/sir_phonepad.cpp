// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void phonepad(char* input, char* output, int i, int j)
{
	// Base case 
	if(input[i] == '\0')
	{
		output[j] = '\0';
		cout << output << endl;
		return;
	}

	// Recursive case 
	int curdig = input[i] - '0';

	if(curdig==0 || curdig==1)
	{
		phonepad(input,output,i+1,j);
	}
	else
	{
		for(int k=0;keypad[curdig][k] != '\0';k++)
		{
			output[j] = input[i];
			phonepad(input,output,i+1,j+1);
		}
	}

}

int main()
{
	// Type your code here.

	char input[21];
	cin >> input;
	cout << input << endl;

	char output[21];

	phonepad(input,output,0,0);

	return 0;
}
