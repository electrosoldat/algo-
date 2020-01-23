// Code Author : TAVISH CHADHA

#include <iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
	// This function tells whether we can place the queen at (i,j)th index or not.

	// check the column
	for(int row=0;row<i;row++)
	{
		if(board[row][j] == 1)
		{
			return false;
		}
	}

	// check the left diagonal
	int x = i;
	int y = j;
	while(x>=0 && y>=0)
	{
		if(board[x][y] == 1)
		{
			return false;
		}
		
		x-- ;
		y-- ;	
	}

	// check the right diagonal
	int x1 = i;
	int y1 = j;
	while(x1>=0 && y1<n)
	{
		if(board[x1][y1] == 1)
		{
			return false;
		}
		
		x1-- ;
		y1++ ;	
	}

	/// if the function reached this point , that means the position is correct.
	return true; 
}

bool solveNqueen(int board[][10],int i,int n)
{
	// Base case
	if(i == n)
	{
		// This means you have succesfully placed all the N queens in N rows

		// Print the board 
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j] == 1 )
				{
					cout << "Q " ;
				}
				else 
				{
					cout << "X ";
				}
			}
			cout << endl;
		}

		// to print only one of the possible positions
		//return true;

		// to print all of the possible board positions
		cout << endl;
		return false;
	}

	// Recursive case
		// Try to print in the current row and call the function again in the remaining part
	for(int j=0;j<n;j++)
	{
		// Now, I have to check whether (i,j)th position is safe or not.
		// To do this, I have to check the current column, the left diagonal and the right diagonal.
		// But, we only need to check for the previous rows 

		// To do this , we can use a helper function.
		if(isSafe(board,i,j,n))
		{
			// if the position is safe , then place the queen here.
			board[i][j] = 1;
			bool nextQueenRakhPaye = solveNqueen(board,i+1,n);
			if(nextQueenRakhPaye)
			{
				return true;
			}
			// if, you reach here that means next queen could not be placed.

			// Now, we have to reset the board to its previous postion, i.e. Backtracking
			board[i][j] = 0;
		}
	}
	// if you reached here, that means you could not place the queen anywhere in the current row.
	return false;
}

int main()
{
	// Type your code here.

	int n;
	cin >> n;

	int board[10][10] = {0};
	solveNqueen(board,0,n);

	return 0;
}
