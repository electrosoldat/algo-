// This program is for a string tokeniser function, which splits the string about the given character.

#include <iostream>
#include <cstring>

char* mystrtok(char str[],char delim)
{
    static char* input = NULL; // input points to the position from where to start reading the input string.


    if(str != NULL){     // New string has to be accessed for extracting the tokens
        input = str;
    } 

    if(input == NULL)
    {
        return NULL; // i.e. after returning all the words, the function will return null.
    }

    char* output = new char[strlen(input) + 1];
    // "+1" is to accomodate the "\0" or the null character at the end

    // we cannot return a static array from this function, beacuse it is destroyed after 
    // after the function is removed from the stack.
    // so we need to return the word as a dynamically allocated array from my function.
    // read the word from the input, and store it in output & just return the world till delim.

    int i;
    for(i=0;input[i]!='\0';i++)
    {
        if(input[i] != delim)
        {
            // Do some work - copy the char into the output array
            output[i] = input[i];
        }
        else
        {
            // You are now at the delim
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }
    }
    output[i] = '\0'; // return the last word, even if the delim isnt there.

    input = NULL;
    return output;

}

using namespace std;
int main() {
    
    char str[] = "Hi, I am teaching about strings, in C++.";

    char* ptr;
    ptr = mystrtok(str,'i');
    cout << ptr << endl;

    //ptr = mystrtok(str,' );
    //cout << ptr << endl;

    ptr = mystrtok(NULL,'i');
    cout << ptr << endl;

    while(ptr != NULL)
    {
        ptr = mystrtok(NULL,'i');
        cout << ptr << endl;
    }


    return 0;
}
