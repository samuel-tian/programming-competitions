#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

#define endl '\n'
#define MAXN 100000
#define INF INT_MAX

int n, m;
int tree[2*MAXN-1];
int lazy[2*MAXN-1];

void update(int index, int intStart, int intEnd, int a, int b) {
    if (intStart > intEnd || intStart > b || intEnd < b) return;
    if (lazy[index] != 0) {
        if (lazy[index] % 2 == 1) {
            tree[index] = intEnd - intStart + 1 - tree[index];
            // propagate to children
            if (intStart != intEnd) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
        }
        lazy[index] = 0;
    }
    if (intStart >= a && intEnd <= b) {
        tree[index] = intEnd - intStart + 1- tree[index];
        if (intStart != intEnd) {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
    }
    else {
        int mid = (intStart + intEnd) / 2;
        update(2 * index + 1, intStart, mid, a, b);
        update(2 * index + 2, mid + 1, intEnd, a, b);
        tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
    }
}

int query(int index, int intStart, int intEnd, int a, int b) {
    if (lazy[index] != 0) {
        if (lazy[index] % 2 == 1) {
            tree[index] = intEnd - intStart + 1 - tree[index];
            // propagate to children
            if (intStart != intEnd) {
                lazy[2 * index + 1] += lazy[index];
                lazy[2 * index + 2] += lazy[index];
            }
        }
        lazy[index] = 0;
    }
    if (intStart > intEnd || intStart > b || intEnd < a) return 0;
    if (intStart >= a && intEnd <= b) {
        return tree[index];
    }
    int mid = (intStart + intEnd) / 2;
    int l = query(2 * index + 1, intStart, mid, a, b);
    int r = query(2 * index + 2, mid + 1, intEnd, a, b);
    return l + r;
}

int main() {
//    ifstream ifs ("input.txt", ios::in);
//    ofstream ofs ("input.txt", ios::out);
//    ofs << "lmao" << endl;
//    return 0;
    cin >> n >> m;
    cout << n << " " << m << endl;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            update(0, 0, n - 1, b, c);
        }
        else {
            cout << query(0, 0, n - 1, b, c) << endl;
        }
    }
}
