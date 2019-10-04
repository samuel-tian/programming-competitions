//
// Created by samue on 10/3/2019.
//

/*
 * Binary Indexed Tree (Fenwick Tree)
 * ----------------------------------
 * allows for O(log n) update and range sum queries
 * time complexity: O(n log n) for n updates and queries
 */

#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define MAXN 100000
#define endl '\n'

int n;
int fenwick[MAXN+1];

void insert(int index, int val) {
    ++index;
    while (index <= n) {
        fenwick[index] += val;
        index += index & (-index);
    }
}

int get(int index) {
    int ret = 0;
    ++index;
    while (index > 0) {
        ret += fenwick[index];
        index -= index & (-index);
    }
    return ret;
}

int psum(int l, int r) { // exclusive
    return get(r) - get(l - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        insert(i, a);
    }
    for (int i = 0; i < n; ++i) {
        cout << psum(i, i + 1) << endl;
    }
}