// code to check if two strings are permutations of each other, i.e are they anagrams
#include <iostream>
using namespace std;

int strlen(char* str)
{
    int i=0;
    while(str[i] != '\0')
    {
        i++ ;
    }
    return i;
}

bool isAnagram(char* A, char* B)
{
    int lenA = strlen(A);
    int lenB = strlen(B);

    if(lenA != lenB)
    {
        return false;
    }
    else
    {
        int freq[26] = {0};

        for(int i=0;i<lenA;i++)
        {
            freq[A[i]-'a']++;
        }

         for(int i=0;i<lenB;i++)
        {
            freq[B[i]-'a']--;
        }

        for(int i=0;i<26;i++)
        {
            if(freq[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
}

int main() {
    int T;   // T is the no. of testcases
    cin >> T;

    for(int i=0;i<T;i++)
    {
        char str1[20];
        char str2[20];

        cin >> str1;
        cin >> str2;

        bool ans = isAnagram(str1,str2);

        if(ans)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
