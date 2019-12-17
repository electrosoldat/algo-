/*

CHEWBACCA AND NUMBER
Luke Skywalker gave Chewbacca an integer number x. Chewbacca isn't good at numbers but he loves inverting digits in them. Inverting digit t means replacing it with digit 9 - t.

Help Chewbacca to transform the initial number x to the minimum possible positive number by inverting some (possibly, zero) digits. The decimal representation of the final number shouldn't start with a zero.

Input Format:
The first line contains a single integer x (1 ≤ x ≤ 10^18) — the number that Luke Skywalker gave to Chewbacca.

Constraints:
x <= 100000000000000000

Output Format
Print the minimum possible positive number that Chewbacca can obtain after inverting some digits. The number shouldn't contain leading zeroes.

Sample Input
4545
Sample Output
4444

*/

#include<iostream>
using namespace std;

int main() 
{
	char str_in[19];
	cin >> str_in;

	int i=0;
	while(str_in[i]!='\0')
	{
		if(i==0 && str_in[i]=='9')
		{
			str_in[i] = '9';
		}
		else
		{
			int x = str_in[i] - '0';
			if(x>=5)
			{
				int y = 9-x;
				x = y;
			}
			char c = (char)x + '0';
			
			str_in[i] = c;
		}
		i++ ;
	}

	cout << str_in;
	return 0;
}
