//
// Created by Samuel on 11/29/2019.
//

/*
 * Lazy Propagation in Segment Trees (range sum queries)
 * -----------------------------------------------------
 * postpone updates to child nodes using a lazy array
 * // update() //
 * 1) recurse through all segments in the tree
 * 		a) if the interval is completely contained in the update range, update the current node and postpone children updates
 * 		b) if the interval partially overlaps with the update range, recurse to chlid nodes and update after
 * 		c) otherwise, return
 * // query() //
 * 2) recurse through all segments in the tree
 * 		a) if the segment is completely contained in the query range, return the value of the segment
 * 		b) if the segment is partially contained in the query range, recurse to the children
 * 		c) otherwise, return 0
 * 3) if the current segment has a lazy update, update the value of the segment before calling the query
 */

#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define MAXN 100000
#define MAXLOG 262144
#define endl '\n'

int n, q;
int segTree[MAXLOG];
int lazy[MAXLOG];

/*
 * node is the current node
 * a, b are the starting and ending iterators
 * i, j is the update range
 * value is the updated value
 * iterators and nodes are inclusive
 */
void update(int node, int a, int b, int i, int j, int value) {
	if (lazy[node] != 0) {
		segTree[node] += lazy[node] * (b - a + 1);
		if (a != b) {
			lazy[2 * node + 1] += lazy[node];
			lazy[2 * node + 2] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (a > b || a > j || b < i) return;
	if (a >= i && b <= j) {
		segTree[node] += value * (b - a + 1);
		if (a != b) {
			lazy[2 * node + 1] += value;
			lazy[2 * node + 2] += value;
		}
		return;
	}
	int mid = (a + b) / 2;
	update(node * 2 + 1, a, mid, i, j, value);
	update(node * 2 + 2, mid + 1, b, i, j, value);
	segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
}

/*
 * node is the current node
 * a, b are the starting and ending iterators
 * i, j is the query range
 * iterators and nodes are inclusive
 */
int query(int node, int a, int b, int i, int j) {
	if (lazy[node] != 0) {
		segTree[node] += lazy[node] * (b - a + 1);
		if (a != b) {
			lazy[2 * node + 1] += lazy[node];
			lazy[2 * node + 2] += lazy[node];
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
	freopen("input.txt", "r", stdin);
	cin >> n >> q;
	for (int i = 0; i < q; ++i) {
		char c;
		cin >> c;
		if (c == 'U') {
			int u, v, w;
			cin >> u >> v >> w;
			--u; --v;
			update(0, 0, n-1, u, v, w);
		}
		else if (c == 'Q') {
			int u, v;
			cin >> u >> v;
			--u; --v;
			cout << query(0, 0, n-1, u, v) << endl;
		}
	}
}