/*

STRINGS-MAX FREQUENCY CHARACTER
Take as input S, a string. Write a function that returns the character with maximum frequency. Print the value returned.

Input Format:
String

Constraints:
A string of length between 1 to 1000.

Output Format
Character

Sample Input
aaabacb
Sample Output
a

*/

#include<iostream>
using namespace std;

int main() {

    char str[1002];
    cin >> str;

    int i=0;
    int freq[26]={0};

    while(str[i] != '\0')
    {
        int inc = (str[i] - 'a');
        freq[inc] += 1;
        i++;
    }

    int maxf = -1;
    char maxfc; 
    for(int i=0;i<27;i++)
    {
        if(freq[i] > maxf)
        {
            maxf = freq[i];
            maxfc = char(i + 'a');
        }
    }

    cout << maxfc;

	return 0;
}
