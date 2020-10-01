// SudokuSolver
//Given a partially filled 9ï¿½9 2D array ï¿½grid[9][9]ï¿½, the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, and subgrid of size 3ï¿½3 contains exactly one instance of the digits from 1 to 9.
#include <bits/stdc++.h>
using namespace std;

bool isSafeToPut(int **mat, int i, int j, int n, int number)
{
    // Check the rows and cols
    for (int k = 0; k < n; k++)
    {
        if (mat[k][j] == number)
        {
            return false;
        }
    }

    for (int k = 0; k < n; k++)
    {
        if (mat[i][k] == number)
        {
            return false;
        }
    }

    n = sqrt(n);
    int starti = (i / n) * n;
    int startj = (j / n) * n;

    for (int k = starti; k < starti + n; k++)
    {
        for (int l = startj; l < startj + n; l++)
        {
            if (mat[k][l] == number)
            {
                return false;
            }
        }
    }
    return true;
}

bool SudokuSolver(int **mat, int i, int j, int n)
{
    if (i == n)
    {
        // Print the sudoku
        cout << endl;
        cout << "Solved Sudoku:" << endl;
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n; l++)
            {
                cout << mat[k][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    if (j == n)
    {
        return SudokuSolver(mat, i + 1, 0, n);
    }
    if (mat[i][j] != 0)
    {
        return SudokuSolver(mat, i, j + 1, n);
    }
    for (int number = 1; number <= n; number++)
    {
        if (isSafeToPut(mat, i, j, n, number))
        {
            mat[i][j] = number;
            bool t = SudokuSolver(mat, i, j + 1, n);
            if (t)
            {
                return true;
            }
            mat[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int **mat = new int *[n];

    //pointer initialization
    for (int i = 0; i < n; i++)
    {
        mat[i] = new int[n];
    }
    cout << "Enter elements and type 0 for empty cells: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    SudokuSolver(mat, 0, 0, n);

    return 0;
}

/*
Sample input/output:
Enter size of square matrix: 9
Enter elements and type 0 for empty cells:
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
Solved Sudoku:
3 1 6 5 7 8 4 9 2 
5 2 9 1 3 4 7 6 8 
4 8 7 6 2 9 5 3 1 
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9
Time complexity: O(9^(n*n))
Space Complexity: O(n*n)
*/
