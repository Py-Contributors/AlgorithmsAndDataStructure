"""
Tic Tac Toe Player
"""

import math
import copy
X = "X"
O = "O"
EMPTY = None

# class IllegalMove(Exception):
#     print("Not a legal move")
#     pass

def initial_state():
    """
    Returns starting state of the board.
    """
    return [[EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY],
            [EMPTY, EMPTY, EMPTY]]


def player(board):
    """
    Returns player who has the next turn on a board.
    """    
    moves_x = board[0].count(X)+board[1].count(X)+board[2].count(X)    
    moves_y = board[0].count(O)+board[1].count(O)+board[2].count(O)    
    if moves_x > moves_y:
        return O
    else:
        return X

def actions(board):
    """
    Returns set of all possible actions (i, j) available on the board.
    """
    possibleMoves = set()
    for i in range(3):
        for j in range(3):
            if board[i][j] == EMPTY:
                possibleMoves.add((i,j))
    return possibleMoves


def result(board, action):
    """
    Returns the board that results from making move (i, j) on the board.
    """
    if action not in actions(board):
        raise IndexError
    tempBoard = copy.deepcopy(board)
    tempBoard[action[0]][action[1]] = player(board)
    return tempBoard


def winner(board):
    """
    Returns the winner of the game, if there is one.
    """
    for rows in board:
        xRow = rows.count(X)
        oRow = rows.count(O)
        if xRow == 3:
            return X
        if oRow == 3:
            return O
    # transpose
    cols = []
    for x in range(3):
        col = []
        for row in board:
            col.append(row[x])
        cols.append(col)

    for col in cols:
        xCol = col.count(X)
        oCol = col.count(O)
        if xCol == 3:
            return X
        if oCol == 3:
            return O

    if board[0][0]==X and board[1][1]==X and board[2][2]==X:
        return X
    if board[0][0]==O and board[1][1]==O and board[2][2]==O:
        return O
    if board[0][2] == X and board[1][1] == X and board[2][0] == X:
        return X
    if board[0][2] == O and board[1][1] == O and board[2][0] == O:
        return O
    return None


def terminal(board):
    """
    Returns True if game is over, False otherwise.
    """
    if winner(board)!=None:
        return True
    if board[0].count(EMPTY)==board[1].count(EMPTY)==board[2].count(EMPTY)==0:
        return True
    return False


def utility(board):
    """
    Returns 1 if X has won the game, -1 if O has won, 0 otherwise.
    """
    konJeeta = winner(board)
    if konJeeta == X:
        return 1
    elif konJeeta == O:
        return -1
    else:
        return 0

def max_value(board):
    if terminal(board) == True:
        return utility(board)
    v = -math.inf
    for action in actions(board):
        v = max(v,min_value(result(board,action)))
    return v

def min_value(board):
    if terminal(board) == True:
        return utility(board)
    v = math.inf
    for action in actions(board):
        v = min(v,max_value(result(board,action)))
    return v

def minimax(board):
    """
    Returns the optimal action for the current player on the board.
    """
    currentPlayer = player(board)
    if terminal(board) == True:
        return None
    if currentPlayer == X:
        v = -math.inf
        for action in actions(board):
            outcome = min_value(result(board,action))
            if outcome > v:
                v = outcome
                bestMove = action                
    else:
        v = math.inf
        for action in actions(board):
            outcome = max_value(result(board,action))
            if outcome < v:
                v = outcome
                bestMove = action                
    return bestMove