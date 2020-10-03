/* 
 * The Fenwick Tree, also known as a Binary Indexed Tree is a very useful data
 * structure that can be used for answering range type queries and single
 * point updates. There are multiple adaptations of it and it can be made to
 * support more complex operations, however this is the simplest one.
 *
 *
 * Time Complexity:
 *   - O(log n) for every operation
 *
 * Space Complexity:
 *   - O(n)
 *
 * */


#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct FenwickTree {
    int size;
    vector<int> tree;

    FenwickTree(int n) {
        size = n + 1;
        tree.assign(size + 1, 0);
    }

    // Calculates the sum in range [0, right]
    int query(int right) {
        int sum = 0;
        for (; right > 0; right -= right & -right)
            sum += tree[right];
        return sum;
    }

    // Calculates the sum in range [left, right]
    int query(int left, int right) {
        return query(right) - query(left - 1);
    }

    // Adds a certain amount to given index
    void update(int idx, int amount) {
        for (; idx <= size; idx += idx & -idx)
            tree[idx] += amount;
    }
} FenwickTree;


int main() {
    int n = 10;
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    FenwickTree fw = FenwickTree(n);

    for (int i = 1; i <= n; i++)
        fw.update(i, a[i]);

    printf("sum of first 10 elements is % d\n", fw.query(10));
    printf("sum of all elements in range[2, 7] is % d\n", fw.query(2, 7));

    return 0;
}
