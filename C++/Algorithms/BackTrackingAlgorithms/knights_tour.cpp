/*
	Language - C++

	The Knights Tour Backtracking Problem

	Statement - The knight is placed on the first block 
	of an empty board and, moving according to the rules of chess, 
	must visit each square exactly once.

	Define the size of the chess board in the #define at line 17. 
*/

#include <iostream>
using namespace std;

// Define size of the board here 
#define n 8

// Two arrays that define the next move of the knight wrt. its current position
int iMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
int jMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 

// A function that tell if the cell we go on next is safe 
bool isSafe(int x, int y, int sol[n][n]) 
{ 
    if(x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1){
    	return true;
    } 
    return false;
} 

void printSolution(int sol[n][n]) 
{ 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < n; j++) 
            cout << sol[i][j] << " "; 
        cout << endl; 
    } 
}

int solveKTUtil(int x, int y, int movei, int sol[n][n]) 
{ 
    int k, next_x, next_y; 
    if (movei == n*n) 
        return 1; 
      
    /* Try all next moves from  
    the current coordinate x, y */
    for (k = 0; k < 8; k++) 
    { 
        next_x = x + iMove[k]; 
        next_y = y + jMove[k]; 
        if (isSafe(next_x, next_y, sol)) 
        { 
            sol[next_x][next_y] = movei; 
            if (solveKTUtil(next_x, next_y, movei + 1, sol) == 1) 
                return 1; 
            else
                // backtracking 
                sol[next_x][next_y] = -1; 
        } 
    } 
    return 0; 
} 

void solveKT(){
	// An array to represent the moves of the knight 
	int sol[n][n]; 

	// Initialising the board
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sol[i][j] = -1;
		}
	}

	// We start at 0, 0
	sol[0][0] = 0;

	if (solveKTUtil(0, 0, 1, sol) == 0) 
    { 
        cout << "Solution does not exist"; 
        return;
    } 

    printSolution(sol);
}

int main()
{
	/* code */
	solveKT();
	return 0;
}