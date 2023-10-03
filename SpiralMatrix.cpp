#include <iostream>
#include <vector>

using namespace std;

void spiral_matrix() {
    int i = 0;  // starting row index
    int j = 0;  // starting column index
    int c = 0;
    int no;

    cout << "Please enter number of rows of the spiral matrix: ";
    cin >> no;

    int high = no * no;
    int val = 1;

    vector<vector<int>> a(no, vector<int>(no, 0));

    while (val <= high) {
        while (j < no - 1) {  // for first row
            a[i][j] = val;
            val++;
            j++;
        }
        while (i < no - 1) {  // for last column
            a[i][j] = val;
            val++;
            i++;
        }
        while (j > c) {  // for last row
            a[i][j] = val;
            val++;
            j--;
        }
        while (i > c) {  // for first column
            a[i][j] = val;
            val++;
            i--;
        }
        no--;
        i++;
        j++;
        c++;
        if (val == high) {  // for odd matrix size
            a[i][j] = val;
            break;
        }
    }

    cout << "Spiral matrix is:" << endl;
    for (const auto& row : a) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    spiral_matrix();
    return 0;
}