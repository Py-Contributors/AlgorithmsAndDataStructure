#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Point {
public:
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

class QueueNode {
public:
    Point pt;
    int dist;
    QueueNode(Point _pt, int _dist) : pt(_pt), dist(_dist) {}
};

bool valid(int row, int col, int ROW, int COL) {
    return row >= 0 && row < ROW && col >= 0 && col < COL;
}

int BFS(vector<vector<int>>& matrix, Point source, Point destination) {
    int ROW = matrix.size();
    int COL = matrix[0].size();

    if (matrix[source.x][source.y] != 1 || matrix[destination.x][destination.y] != 1)
        return -1;

    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
    visited[source.x][source.y] = true;

    deque<QueueNode> q;
    QueueNode s(source, 0);
    q.push_back(s);

    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};

    while (!q.empty()) {
        QueueNode curr = q.front();
        Point pt = curr.pt;
        q.pop_front();

        if (pt.x == destination.x && pt.y == destination.y)
            return curr.dist;

        for (int i = 0; i < 4; i++) {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            if (valid(row, col, ROW, COL) && matrix[row][col] == 1 && !visited[row][col]) {
                visited[row][col] = true;
                QueueNode adj_cell(Point(row, col), curr.dist + 1);
                q.push_back(adj_cell);
            }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1}
    };

    Point source(0, 0);
    Point destination(5, 5);

    int distance = BFS(matrix, source, destination);

    if (distance == -1)
        cout << "Not possible" << endl;
    else
        cout << "Shortest distance: " << distance << endl;

    return 0;
}