// Code Author : TAVISH CHADHA

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool canPlace(int sudoku_puzzle[][9], int i, int j, int n, int number)
{
	// Rules for solving Sudoku
		// 1. a number should appear only once in a row.
		// 2. a number should appear only once in a column.
		// 3. a number should appear only once in a subgrid of size sqrt(n)Xsqrt(n).


		// Check the row and the column.
		for(int x=0;x<n;x++)
		{
			if(sudoku_puzzle[i][x] == number || sudoku_puzzle[x][j] == number)
			{
				return false;
			}
		}

		// Check the subgrid.
			// For this, we must know in which subgrid our cell lies.
			// let the coordinates of the current cell be (i,j).
			// now, to find in which subgroup the cell lies, we need the starting coordinates of the cell.
			// These coordinates can be calculated using the formula ...
			// SX = (i / sqrt(n)) * sqrt(n) , SY = (j / sqrt(n)) * sqrt(n) 

			// we can visualise the grid as a grid of subgrids.
			// [(i/sqrt(n)),(j/sqrt(n))] are the coordinates of the subgrid.
			// when we multiply them by sqrt(n), we get the starting positions of that grid.

		int rn = sqrt(n);
		int sx = (i/rn)*rn; 
		int sy = (j/rn)*rn; 
		for(int x=sx;x<sx+rn;x++)		  
		{							 
			for(int y=sy;y<sy+rn;y++)
			{
				if(sudoku_puzzle[x][y] == number)
				{
					return false;
				}
			}	
		}

		// If you reach this point 
		return true;

}

bool sudokuSolve(int sudoku_puzzle[][9], int i, int j, int n)
{
	// Base case
	if(i == n)
	{
		// Print the solved sudoku puzzle
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout << sudoku_puzzle[i][j] << " " ;
			}
			cout << endl;
		}

		return true;
	}

	// If we have reached the end of the row.
	if(j == n)
	{
		return sudokuSolve(sudoku_puzzle,i+1,0,n);
	}

	// If we have encountered a cell which is already filled.
	if(sudoku_puzzle[i][j] != 0)
	{
		return sudokuSolve(sudoku_puzzle,i,j+1,n);
	}

	// Recursive case
		// Fill the current cell with a number and check whether rest of the puzzle can be solved or not.
		// if it is not the correct answer, then check the next possible number.

	for(int number=1;number<=n;number++)
	{
		if(canPlace(sudoku_puzzle,i,j,n,number))
		{
			// Assuming that the number placed here is correct.
			sudoku_puzzle[i][j] = number;
			// After placing the number, I will let recursion solve for the remaining portion
			// of the sudoku.
			bool couldweSolve = sudokuSolve(sudoku_puzzle,i,j+1,n);
			if(couldweSolve == true)
			{
				return true;
			}
		}
	}
	// If we reach here, that means we have tried placing all possible numbers at this position
	// but , none of them is correct.
	// So, we will return False to the previous position so that, it can change whatever no. it had 
	// placed.

	// Before returning, we will have to backtrack.
	sudoku_puzzle[i][j] = 0;
	return false;

}

int main()
{
	// Type your code here.

	// sudoku is a nXn grid and n is a perfect square.
	int sudoku_puzzle[9][9] = 
	{
		{0,8,0,7,0,1,0,3,0},
		{4,0,9,0,0,0,0,0,0},
		{0,5,0,0,6,0,4,1,8},
		{7,0,0,0,0,9,0,0,0},
		{8,0,0,6,1,0,5,0,0},
		{0,3,5,0,0,0,0,2,9},
		{0,6,0,4,0,7,0,9,0},
		{1,0,0,0,0,8,0,0,4},
		{0,2,0,0,5,0,0,7,0}
	};

	sudokuSolve(sudoku_puzzle,0,0,9);

	return 0;
}
