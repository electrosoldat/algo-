#include <iostream>
using namespace std;

void allsubstrings(char* input, char* output, int i, int j)
{
    // Base Case 
    if(input[i] == '\0')
    {
        output[j] = '\0';
        cout << "{" << output << "}";
        cout << " , ";

        return; 
    }

    // Recursive Case 
    /// 1. include 
    output[j] = input[i] ;
    allsubstrings(input,output,i+1,j+1);

    /// 2. don't include
    allsubstrings(input,output,i+1,j);
}

int main() 
{   
    char input[100];
    char output[100];

    cin >> input;

    allsubstrings(input,output,0,0);

    return 0;
}
