#include <iostream>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
using namespace std;

/*
This is the basic code required to generate a random number

	srand(time(NULL));

	cout << rand() % num << endl;
*/

void randomShuffle(int* arr, int start, int end)
{
	srand(time(NULL));
	
	for(int i=end;i>0;i--)
	{
		int j = rand() % (i+1);
		swap(arr[i],arr[j]);
	}

	return;
}

int partition(int* arr, int start, int end)
{
	int pivot = arr[end]; // This our pivot element
	int i=start-1; // This represents the index of the element, begore the pivot element
	for(int j=start;j<end;j++)
	{
		if(arr[j] <= pivot)
		{
			i++ ;
			swap(arr[j],arr[end-1]);
		}
	}

	swap(arr[i+1],arr[end]);

	return i+1;
}

void optimisedQuickSort(int* arr, int start, int end)
{
	if(start >= end)
	{
		return;
	}

	int p = partition(arr,start,end);

	optimisedQuickSort(arr,start,p-1);
	optimisedQuickSort(arr,p+1,end);

}

int main()
{
	int n;
	cin >> n;

	int* arr = new int[n];

	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}

	randomShuffle(arr,0,n-1);

	optimisedQuickSort(arr,0,n-1);

	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}
