/*
Title:Tiling Problem using Divide and Conquer algorithm.
Description: Given a n x n board where n is of form 2^k where k >= 1.The board has one missing cell (of size 1 x 1).
Expected Result: To fill the board using L shaped tiles of size(2x2) with one cell of size 1×1 missing.
*/

#include <bits/stdc++.h> 
using namespace std; 
int grid_size, b=0, a=0, cnt = 0; 
int arr[256][256]; 

// Placing tile at the specified position 
void place_tile(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
	cnt++; 
	arr[x1][y1] = cnt; 
	arr[x2][y2] = cnt; 
	arr[x3][y3] = cnt; 
} 

// Divide and Conquer Method
int tile(int n, int x, int y) 
{ 
int pos1,pos2; 
//if grid size =2x2, the grid can be filled with a single tile
if (n == 2) 
{ 
	cnt++; 
	for (int i = 0; i < n; i++)
	{ 
		for (int j = 0; j < n; j++) 
		{ 
			if (arr[x + i][y + j] == 0) 
			{ 
				arr[x + i][y + j] = cnt; 
			} 
		} 
	} 
		return 0; 
} 

/* Identifying the missing tile location*/
for (int i = x; i < n; i++)
{ 
	for (int j = y; j < n; j++) 
	{ 
		if (arr[i][j] != 0) 
			pos1 = i, pos2 = j; 
	} 
} 

/*A L shaped tile at the center such that it does not cover the n/2 * n/2 subsquare that has a missing square. Now all four subsquares of size n/2 x n/2 have a missing cell*/

	// If missing tile exists in first quadrant 
if (pos1 < x + n / 2 && pos2 < y + n / 2) 
	place_tile(x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2); 

	// If missing Tile exists in 2st quadrant 
if (pos1 >= x + n / 2 && pos2 < y + n / 2) 
	place_tile(x + n / 2, y + (n / 2) - 1, x + n / 2, y + n / 2, x + n / 2 - 1, y + n / 2 - 1); 

	// If missing Tile exists in 3st quadrant 
if (pos1 < x + n / 2 && pos2 >= y + n / 2) 
	place_tile(x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + n / 2, x + (n / 2) - 1, y + (n / 2) - 1); 

	// If missing Tile exists in 4st quadrant 
if (pos1 >= x + n / 2 && pos2 >= y + n / 2) 
	place_tile(x + (n / 2) - 1, y + (n / 2), x + (n / 2), y + (n / 2) - 1, x + (n / 2) - 1, y + (n / 2) - 1); 
	
/*recursively subdividing the problems into subquarters*/
tile(n / 2, x, y + n / 2); 
tile(n / 2, x, y); 
tile(n / 2, x + n / 2, y); 
tile(n / 2, x + n / 2, y + n / 2); 

	return 0; 
} 

void print_grid()
{
    for (int i = 0; i < grid_size; i++)
    { 
		for (int j = 0; j < grid_size; j++) 
			cout << arr[i][j] << " \t"; 
    	cout << "\n"; 
    }
}

int main() 
{ 
	cin>>grid_size;
	/*Block the tiles*/
	arr[a][b] = -1; 
	tile(grid_size, 0, 0); 
    print_grid();
} 

/* 
Recurrence relation for above recursive algorithm can be written as below. C is a constant.
T(n) = 4T(n/2) + C
Sample input: 2
Sample Output: -1 1
                1 1
                
Description: All the tiles having the same numbers help to identify a L-shaped tile.
             The missing tile spot is hence declared with reference as -1.
*/
