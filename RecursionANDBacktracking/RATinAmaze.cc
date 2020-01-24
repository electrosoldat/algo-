// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

int count = 0;

bool findpath(char** maze_map,int soln[10][10],int nr,int nc,int srci, int srcj)
{
	// Base case 
	if(srci == nr-1 && srcj == nc-1)
	{
		// If the rat has reached this cell , it means it can get out of the maze 

		// print the path
		soln[srci][srcj] = 1;
		count++ ;
		for(int a=0;a<nr;a++)
		{
			for(int b=0;b<nc;b++)
			{
				cout << soln[a][b] << " ";
			}
			cout << endl;
		}
		cout << endl;

		return true;
	}

	// The rat should remain inside the grid
	if(srci>=nr || srcj>=nc)
	{
		return false;
	}

	// If the current cell is blocked
	if(maze_map[srci][srcj] == 'X')
	{
		return false;
	}

	// Recursive case
		// Here, I have to assume that after the current cell, RECURSION will find the path.
	soln[srci][srcj] = 1;

	bool rightSuccess = findpath(maze_map,soln,nr,nc,srci,srcj+1);
	bool downSuccess = findpath(maze_map,soln,nr,nc,srci+1,srcj);

	// Backtracking
	soln[srci][srcj] = 0;

	if(rightSuccess || downSuccess)
	{
		return true;
	}
	return false;

}

int main()
{
	// Type your code here.

	int nr,nc;
	cin >> nr >> nc;

	char** maze_map = new char*[nr];
	for(int i=0;i<nr;i++)
	{
		maze_map[i] = new char[nc];
	}

	for(int i=0;i<nr;i++)
	{
		for(int j=0;j<nc;j++)
		{
			cin >> maze_map[i][j];
		}
	}

	int soln[10][10] = {0};

	bool ans = findpath(maze_map,soln,nr,nc,0,0);
	
	cout << count << endl;

	if(!ans)
	{
		cout << "Sorry no path exists !!" << endl;
	}

	return 0;
}
