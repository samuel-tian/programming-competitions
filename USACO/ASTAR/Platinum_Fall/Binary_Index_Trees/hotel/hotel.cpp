#include <bits/stdc++.h>

using namespace std;

#define MAXN 50000

int n;
int segTree[2 * MAXN + 1];
/*
 * flag of 0 means that all of the rooms in the interval are empty
 * flag of 1 means that all of the rooms in the interval are filled
 * flag of 2 means a combination of the first two cases
 */
int lazy[2 * MAXN + 1];

void update(int index, int intStart, int intEnd, int a, int b, int val) {
    if (intStart > intEnd) return;
    if (lazy[index] != -1) {
        segTree[index] = lazy[index];
        if (intStart != intEnd) {
            lazy[2 * index + 1] = lazy[index];
            lazy[2 * index + 2] = lazy[index];
        }
        lazy[index] = -1;
    }
    if (intStart >= a && intEnd <= b) {
        segTree[index] = val;
        if (intStart != intEnd) {
            lazy[2 * index + 1] = val;
            lazy[2 * index + 2] = val;
        }
    }
    else {
        segTree[index] = 2;
        int mid = (intStart + intEnd) / 2;
        update(2 * index + 1, intStart, mid, a, b, val);
        update(2 * index + 2, mid + 1, intEnd, a, b, val);
    }
}

int main() {
    int m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a;
        cin >> a == 1 ? b : b >> c;

    }
    return 0;
}
