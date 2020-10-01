"""
-SUDOKU SOLVER ALGORITHM
-It will solve a sudoku board passed in as input
-Backtracking has been used to solve the problem

A sudoku solution must satisfy all of the following rules:

  1. Each of the digits 1-9 must occur exactly once in each row.
  2. Each of the digits 1-9 must occur exactly once in each column.
  3. Each of the the digits 1-9 must occur exactly once in each of
     the 9 3x3 sub-boxes of the grid.

"""

from collections import defaultdict


class Solve:
    def __init__(self):
        self.solved = []

    def solveSudoku(self, board) -> None:
        # keep track of the digits already present in each of the 9 sub-boxes
        h = defaultdict(set)
        # keep track of the digits already present in each row and column
        rows, cols = defaultdict(set), defaultdict(set)
        for i in range(9):
            for j in range(9):
                if board[i][j] != ".":
                    h[3 * (i // 3) + j // 3].add(int(board[i][j]))
                    rows[i].add(int(board[i][j]))
                    cols[j].add(int(board[i][j]))

        # helper function that makes use of backtracking
        def helper(row, col):
            # board has been solved, since we have exhausted all the rows (rows
            # start from 0)
            if row == 9:
                for i in range(9):
                    self.solved.append(board[i][:])
                return
            if board[row][col] == ".":  # i.e. we need to fill up that position
                for num in range(1, 10):
                    # check that the chosen digit does not violate rules
                    if (
                        num not in h[(row // 3) * 3 + col // 3]
                        and num not in rows[row]
                        and num not in cols[col]
                    ):
                        board[row][col] = str(num)
                        h[(row // 3) * 3 + col // 3].add(num)
                        rows[row].add(num)
                        cols[col].add(num)
                        if col == 8:  # move to the next row
                            helper(row + 1, 0)
                        else:
                            helper(row, col + 1)
                        h[(row // 3) * 3 + col // 3].remove(num)
                        rows[row].remove(num)
                        cols[col].remove(num)
                        board[row][col] = "."
            else:
                if col == 8:
                    helper(row + 1, 0)
                else:
                    helper(row, col + 1)

        helper(0, 0)
        # overwrite values
        for i in range(9):
            for j in range(9):
                board[i][j] = self.solved[i][j]


sol = Solve()
board = [
    ["5", "3", ".", ".", "7", ".", ".", ".", "."],
    ["6", ".", ".", "1", "9", "5", ".", ".", "."],
    [".", "9", "8", ".", ".", ".", ".", "6", "."],
    ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
    ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
    ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
    [".", "6", ".", ".", ".", ".", "2", "8", "."],
    [".", ".", ".", "4", "1", "9", ".", ".", "5"],
    [".", ".", ".", ".", "8", ".", ".", "7", "9"],
]
"""
This is what the board looks like initially:
    [["5","3",".",".","7",".",".",".","."]
     ["6",".",".","1","9","5",".",".","."]
     [".","9","8",".",".",".",".","6","."]
     ["8",".",".",".","6",".",".",".","3"]
     ["4",".",".","8",".","3",".",".","1"]
     ["7",".",".",".","2",".",".",".","6"]
     [".","6",".",".",".",".","2","8","."]
     [".",".",".","4","1","9",".",".","5"]
     [".",".",".",".","8",".",".","7","9"]]

"""
sol.solveSudoku(board)
print(board)
"""
This is the final board:
    [["5","3","4","6","7","8","9","1","2"]
     ["6","7","2","1","9","5","3","4","8"]
     ["1","9","8","3","4","2","5","6","7"]
     ["8","5","9","7","6","1","4","2","3"]
     ["4","2","6","8","5","3","7","9","1"]
     ["7","1","3","9","2","4","8","5","6"]
     ["9","6","1","5","3","7","2","8","4"]
     ["2","8","7","4","1","9","6","3","5"]
     ["3","4","5","2","8","6","1","7","9"]]

"""
