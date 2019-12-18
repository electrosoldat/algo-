// Counting sort algorithm
#include<iostream>
#include <limits.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int* a = new int[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

	int max=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max = a[i];
		}
	}

	int* freq = new int[max+1];

	for(int i=0;i<n;i++)
	{
		freq[a[i]]++;
	}
	

	int* output = new int[max+1];

	int j=0;
	for(int i=0;i<max+1;i++)
	{
		if(freq[i] != 0)
		{
			while(freq[i]>0)
			{
				output[j] = i;
				freq[i]--;
				j++;
			}
		}
	}

	for(int i=0;i<n;i++)
    {
        cout << output[i] << " ";
    }
    
	return 0;
}
