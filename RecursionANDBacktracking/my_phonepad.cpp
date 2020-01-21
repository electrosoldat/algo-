// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

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

	switch(curdig)
	{
		case 2:
			output[j] = 'A';
			phonepad(input,output,i+1,j+1);
			output[j] = 'B';
			phonepad(input,output,i+1,j+1);
			output[j] = 'C';
			phonepad(input,output,i+1,j+1);
			break;
		case 3:
			output[j] = 'D';
			phonepad(input,output,i+1,j+1);
			output[j] = 'E';
			phonepad(input,output,i+1,j+1);
			output[j] = 'F';
			phonepad(input,output,i+1,j+1);
			break;
		case 4:
			output[j] = 'G';
			phonepad(input,output,i+1,j+1);
			output[j] = 'H';
			phonepad(input,output,i+1,j+1);
			output[j] = 'I';
			phonepad(input,output,i+1,j+1);
			break;
		case 5:
			output[j] = 'J';
			phonepad(input,output,i+1,j+1);
			output[j] = 'K';
			phonepad(input,output,i+1,j+1);
			output[j] = 'L';
			phonepad(input,output,i+1,j+1);
			break;
		case 6:
			output[j] = 'M';
			phonepad(input,output,i+1,j+1);
			output[j] = 'N';
			phonepad(input,output,i+1,j+1);
			output[j] = 'O';
			phonepad(input,output,i+1,j+1);
			break;
		case 7:
			output[j] = 'P';
			phonepad(input,output,i+1,j+1);
			output[j] = 'Q';
			phonepad(input,output,i+1,j+1);
			output[j] = 'R';
			phonepad(input,output,i+1,j+1);
			output[j] = 'S';
			phonepad(input,output,i+1,j+1);
			break;
		case 8:
			output[j] = 'T';
			phonepad(input,output,i+1,j+1);
			output[j] = 'U';
			phonepad(input,output,i+1,j+1);
			output[j] = 'V';
			phonepad(input,output,i+1,j+1);
			break;
		case 9:
			output[j] = 'W';
			phonepad(input,output,i+1,j+1);
			output[j] = 'X';
			phonepad(input,output,i+1,j+1);
			output[j] = 'Y';
			phonepad(input,output,i+1,j+1);
			output[j] = 'Z';
			phonepad(input,output,i+1,j+1);
			break;
		default:
			phonepad(input,output,i+1,j);
			break;
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
