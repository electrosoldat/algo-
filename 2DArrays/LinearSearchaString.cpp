// This program linearly searches for a string in an entire array of stings
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

void read_str_list(char str_list[10][100],int N)
{
    for(int i=0;i<N;i++)
    {
        cin.getline(str_list[i],100);
    }
}

void print_str_list(char str_list[10][100],int N)
{
    for(int i=0;i<N;i++)
    {
        cout << str_list[i] << endl;
    }
}

int main() {
    char str_list[10][100];

    int N;
    cin >> N; // The no. of strings the user wants to enter
    cin.ignore();

    read_str_list(str_list,N);
    print_str_list(str_list,N);

    // To linear search a given string in the array of strings.
    char key[100];
    cout << "Enter string to search : ";
    cin.getline(key,100);

    int i;
    for(i=0;i<N;i++)
    {
        if(strcmp(key,str_list[i])==0)
        {
            cout << "Found at index :" << i << endl;
            break;
        }
    }
    if(i == N)
    {
        cout << "Not Found" ;
    }
}
