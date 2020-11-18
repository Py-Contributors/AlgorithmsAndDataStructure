// https://ide.codingblocks.com/s/4400
#include <iostream>
#include<climits>
using namespace std;

#define inf 1000000000

int lazy[100000]  = {0};

int query(int *tree, int ss, int se, int qs, int qe, int index) {
    ///Complete Overlap
    if (ss >= qs && se <= qe) {
        return tree[index];
    }

    //No Overlap
    if (qe < ss || qs > se) {
        return INT_MAX;
    }

    //Partial Overlap - Call both sides and update the current ans
    int mid = (ss + se) / 2;
    int leftAns = query(tree, ss, mid, qs, qe, 2 * index);
    int rightAns  = query(tree, mid + 1, se, qs, qe, 2 * index + 1);
    return min(leftAns, rightAns);

}


void buildTree(int *a, int s, int e, int *tree, int index) {

    if (s == e) {
        tree[index] = a[s];
        return ;
    }

    //Rec case
    int mid = (s + e) / 2;
    buildTree(a, s, mid, tree, 2 * index);
    buildTree(a, mid + 1, e, tree, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);

    return;
}

void updateNode(int *tree, int ss, int se, int i, int increment, int index) {
    //Leaf updateNode
    //Out of bounds - No Overlap
    if (i > se || i < ss) {
        return;
    }

    //Leaf Node
    if (ss == se) {
        tree[index] += increment;
        return;
    }

    //Left and Right - Call
    int mid = (ss + se) / 2;
    updateNode(tree, ss, mid, i, increment, 2 * index);
    updateNode(tree, mid + 1, se, i, increment, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

void updateRangeLazy(int *tree, int ss, int se, int l, int r, int inc, int index) {
    //First Step - Never we go down if you have lazy value at node, first resolve it

    if (lazy[index] != 0) {

        tree[index] += lazy[index];

        //if not a leaf node
        if (ss != se) {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    // Out of Bounds
    if (ss > r || l > se) {
        return;
    }
    // Complete Overlap- Beeche Raste Mei
    if (ss >= l && se <= r) {
        tree[index] += inc;

        // Pass the lazy value to children if they are not leaf
        if (ss != se) {
            lazy[2 * index] +=  inc;
            lazy[2 * index + 1] += inc;
        }
        return ;
    }

    int mid = (ss + se) / 2;
    updateRangeLazy(tree, ss, mid, l, r, inc, 2 * index);
    updateRangeLazy(tree, mid + 1, se, l, r, inc, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;
}

int queryLazy(int *tree, int ss, int se, int qs, int qe, int index)
{
    //Never go downn if we have lazy value at node, first resolve it
    if (lazy[index] != 0)
    {
        tree[index] += lazy[index];

        // if not a leaf node
        if (ss != se)
        {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    // No overlap
    if (ss > qe || se < qs)
    {
        return inf;
    }
    // Complete overlap
    if (ss >= qs && se <= qe)
    {
        return tree[index];
    }

    // Partial
    int mid = (ss + se) / 2;
    int left = queryLazy(tree, ss, mid, qs, qe, 2 * index);
    int right = queryLazy(tree, mid + 1, se, qs, qe, 2 * index + 1);

    return min(left, right);

}



void updateRange(int *tree, int ss, int se, int l, int r, int inc, int index) {
    //Out of bounds
    if (l > se || r < ss) {
        return;
    }

    // Leaf Node
    if (ss == se) {
        tree[index] += inc;
        return;
    }

    // Left and Right  Call Otherwise
    int mid = (ss + se) / 2;

    updateRange(tree, ss, mid, l, r, inc, 2 * index);
    updateRange(tree, mid + 1, se, l, r, inc, 2 * index + 1);

    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    return;

}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a[] = {1, 3, 2, -5, 6, 4};
    int n = sizeof(a) / sizeof(int);

    int *tree = new int[4 * n + 1];

    buildTree(a, 0, n - 1, tree, 1);

    //Let print the tree
    // for(int i=1;i<=13;i++){
    // cout<<tree[i]<<" ";
    // }



    //updateNode(tree,0,n-1,2,10,1);
    //updateNode(tree,0,n-1,3,15,1);
    updateRangeLazy(tree, 0, n - 1, 2, 3, 10, 1); //here we are using 1 based indexing

    int no_of_q = 6;

    while (no_of_q--) {
        int l, r;
        cin >> l >> r;
        cout << queryLazy(tree, 0, n - 1, l, r, 1) << "\n";
    }


    return 0;
}
/*input:
0 0
1 1
2 2
3 3
4 4
4 5
output:
1
3
12
5
6
4
 */