Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :
Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 50
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1

Solution:
#include <cstring>

bool is_cycle(char board[][MAXN], int si, int sj, int ei, int ej, int n, int m, bool **visited, char c, int len)
{
    if(len >= 4 && si == ei && sj == ej)
        return true;
    
    if(ei < 0 || ei >= n || ej < 0 || ej >= m || visited[ei][ej] == true || board[ei][ej] != c)
        return false;
    
    visited[ei][ej] = true;
    
    bool l = is_cycle(board, si, sj, ei, ej - 1, n, m, visited, c, len + 1);
    bool r = is_cycle(board, si, sj, ei, ej + 1, n, m, visited, c, len + 1);
    bool u = is_cycle(board, si, sj, ei - 1, ej, n, m, visited, c, len + 1);
    bool d = is_cycle(board, si, sj, ei + 1, ej, n, m, visited, c, len + 1);
    
    if(l || r || u || d)
        return true;
    
    visited[ei][ej] = false;
    
    return false;
}

int solve(char board[][MAXN],int n, int m)
{
    bool **visited = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for(int j = 0; j < m; j++)
            visited[i][j] = false;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            bool ans = is_cycle(board, i, j, i, j, n, m, visited, board[i][j], 0);
            if(ans == true)
                return 1;
        }
    }
    return 0;
}
