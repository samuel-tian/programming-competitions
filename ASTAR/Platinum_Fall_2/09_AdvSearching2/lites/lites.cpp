//
// Created by Samuel on 11/29/2019.
//

/*
 * Lazy Propagation in Segment Trees (range sum queries)
 * -----------------------------------------------------
 * 1)
 */

#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define MAXN 100000
#define MAXLOG 400000
#define endl '\n'

int n, q;
int segTree[MAXLOG];
int lazy[MAXLOG];

/*
 * node is the current node
 * a, b are the starting and ending iterators
 * i, j is the update range
 * iterators and nodes are inclusive
 */
void update(int node, int a, int b, int i, int j) {
	if (lazy[node] != 0) {
		if (lazy[node] % 2 == 1) {
			segTree[node] = (b - a + 1) - segTree[node];
			if (a < b) {
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
		}
		lazy[node] = 0;
	}
	if (a > b || a > j || b < i) return;
	if (a >= i && b <= j) {
		segTree[node] = (b - a + 1) - segTree[node];
		if (a < b) {
			lazy[2 * node + 1] += 1;
			lazy[2 * node + 2] += 1;
		}
	}
	else {
		int mid = (a + b) / 2;
		update(2 * node + 1, a, mid, i, j);
		update(2 * node + 2, mid + 1, b, i, j);
		segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
	}
}

/*
 * node is the current node
 * a, b are the starting and ending iterators
 * i, j is the query range
 * iterators and nodes are inclusive
 */
int query(int node, int a, int b, int i, int j) {
	if (lazy[node] != 0) {
		if (lazy[node] % 2 == 1) {
			segTree[node] = (b - a + 1) - segTree[node];
			if (a < b) {
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
		}
		lazy[node] = 0;
	}
	if (a > b || a > j || b < i) return 0;
	if (a >= i && b <= j) return segTree[node];
	int mid = (a + b) / 2;
	int left = query(2 * node + 1, a, mid, i, j);
	int right = query(2 * node + 2, mid + 1, b, i, j);
	return left + right;
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> n >> q;
	for (int i = 0; i < q; ++i) {
		int c;
		int a, b;
		cin >> c >> a >> b;
		--a; --b;
		if (c == 0) { // update
			update(0, 0, n-1, a, b);
		}
		else if (c == 1) { // query
			cout << query(0, 0, n-1, a, b) << endl;
		}
	}
}