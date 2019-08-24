#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN 100000
#define INF INT_MAX
#define NINF INT_MIN

/*
maintain two segment segmentSums
one to store the cummulative sum on the interval

*/
int segmentSum[2 * MAXN + 1];
int prefixSum[2 * MAXN + 1];
int lazy[2* MAXN + 1];

/*
node is the current node of the recursion
(a, b) is the current range of the recursion
(i, j) is the bound of the recursion
value is the increment that we are applying to the range
*/
void update(int node, int a, int b, int i, int j, int value) {
    if (lazy[node] != 0) {
        segmentSum[node] += (b - a + 1) * lazy[node];
        if (a != b) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (a > b || a > j || b < i) return;
    if (a >= i && b <= j) {
        segmentSum[node] += (b - a + 1) * value;
        if (a != b) {
            lazy[node * 2 + 1] += value;
            lazy[node * 2 + 2] += value;
        }
        return;
    }
    update(node * 2, a, (a + b) / 2, i, j, value);
    update(node * 2 + 1, 1 + (a + b) / 2, b, i, j, value);
    segmentSum[node] = max(segmentSum[node * 2], segmentSum[node * 2 + 1]);
    // prefixSum[node] = max(prefixSum[node * 2], segmentSum[node * 2 + 1] + prefixSum[node * 2 + 1]);
    return;
}

int query(int node, int a, int b, int i, int j) {
    if (a > b || a > j || b < i) return NINF;
    if (lazy[node] != 0) {
        segmentSum[node] += lazy[node];
        // prefixSum[node] += lazy[node];
        if (a != b) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (a >= i && b <= j) {
        return segmentSum[node];
    }
    int leftSegment = query(2 * node, a, (a + b) / 2, i, j);
    int rightSegment = query(2 * node + 1, 1 + (a + b) / 2, b, i, j);
    return max(leftSegment, rightSegment);
}

int main() {
    int n = 10;
    for (int i = 0; i < n; ++i) {
        update(0, 0, n - 1, i, i, i + 1);
    }
    for (int i = 0; i < 10; ++i) {
        cout << query(0, 0, n - 1, i, i) << " ";
    }
    cout << endl;
}
