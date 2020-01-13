//
// Created by samue on 10/11/2019.
//

/*
 * Segment Tree (without lazy propagation, range sum queries)
 * ----------------------------------------------------------
 * A segment tree allows for O(log n) update and range query operations.
 * - each node in the segment tree represents a segment of the desired data
 *      - 2*n+1 and 2*n+2 are the two children of node n
 *      - each parent node is twice the size of both children
 * // update() //
 * 1) recurse through all segments in the tree
 *      a) if segment is completely contained in the update range, add the update value to the segment
 *      b) otherwise, return
 * // query() //
 * 2) recurse through all segments in the tree
 *      a) if segment is completely contained in the query range, return the value of the segment
 *      b) if segment is partially contained in the query range, recurse to its children
 *      c) otherwise, return 0
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INT INT_MAX
#define MAXN 100000

int n;
int segTree[2*MAXN + 1];

/*
 * node is the current node
 * a, b are the starting and ending iterators
 * i, j are the query range
 * iterators and nodes are inclusive
 */
int query(int node, int a, int b, int i, int j) {
    if (a >= i && b <= j) {
        return segTree[node];
    }
    if (a > j || b < i) {
        return 0;
    }
    if (a != b) {
        int mid = (a + b) / 2;
        return query(2 * node + 1, a, mid, i, j) + query(2 * node + 2, mid + 1, b, i, j);
    }
}

/*
 * node is the current node
 * a, b are the starting and ending iterators
 * i is the updated index
 * value is the updated value
 * iterators and nodes are inclusive
 */
void update(int node, int a, int b, int i, int value) {
    if (i < a || i > b) {
        return;
    }
    segTree[node] += value;
    if (a != b) {
        int mid = (a + b) / 2;
        update(2 * node + 1, a, mid, i, value);
        update(2 * node + 2, mid + 1, b, i, value);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        update(0, 0, n-1, i, a);
    }
    for (int i = 0; i < 2 * n + 1; ++i) {
        cout << segTree[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            cout << query(0, 0, n-1, i, j) << " ";
        }
        cout << endl;
    }
}