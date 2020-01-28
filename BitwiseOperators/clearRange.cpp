// Code Author : TAVISH CHADHA

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	// Type your code here.

	int n;
	int i;
	int j; // j > i
	// clear the bits lying between i and j positions.

	scanf("%d %d %d", &n,&i,&j);

	int mask1 = (-1 << i);
	int mask2 = (-1 << (j+1));
	mask1 = ~mask1;

	mask2 = mask1 | mask2;

	n = n & mask2;
	printf("%d\n", n);

	return 0;
}
