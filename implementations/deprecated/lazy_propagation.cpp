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

/*
 * node is the current node
 * a, b are the starting and ending iterators
 * i, j is the update range
 * value is the updated value
 * iterators and nodes are inclusive
 */

struct sum_seg_lazy {
	int n;
	vi segTree, lazy;
	sum_seg_lazy() {
		this->n = 0;
		segTree.resize(1); lazy.resize(1);
		fill(segTree.begin(), segTree.end(), 0);
		fill(lazy.begin(), lazy.end(), 0);
	}
	sum_seg_lazy(int n) {
		this->n = n; int sz = 4*n;
		segTree.resize(sz); lazy.resize(sz);
		fill(segTree.begin(), segTree.end(), 0);
		fill(lazy.begin(), lazy.end(), 0);
	}
	void propagate(int node, int a, int b) {
		if (lazy[node] != 0) {
			segTree[node] = lazy[node] * (b - a + 1);
			if (a != b) {
				lazy[2*node+1] = lazy[node];
				lazy[2*node+2] = lazy[node];
			}
			lazy[node] = 0;
		}
	}
	int query(int i, int j) { return queryUtil(0, 0, n-1, i, j); }
	int queryUtil(int node, int a, int b, int i, int j) {
		propagate(node, a, b);
		if (a > b || a > j || b < i) return 0;
		if (a >= i && b <= j) return segTree[node];
		int mid = (a + b) / 2;
		int left = queryUtil(2 * node + 1, a, mid, i, j);
		int right = queryUtil(2 * node + 2, mid + 1, b, i, j);
		return left + right;
	}
	void update(int i, int j, int val) { updateUtil(0, 0, n-1, i, j, val); }
	void updateUtil(int node, int a, int b, int i, int j, int val) {
		propagate(node, a, b);
		if (a > b || a > j || b < i) return;
		if (a >= i && b <= j) {
			segTree[node] = val * (b - a + 1);
			if (a != b) {
				lazy[2 * node + 1] += val;
				lazy[2 * node + 2] += val;
			}
			return;
		}
		int mid = (a + b) / 2;
		updateUtil(node * 2 + 1, a, mid, i, j, val);
		updateUtil(node * 2 + 2, mid + 1, b, i, j, val);
		segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
	}
};

struct max_seg_lazy {
	int n;
	int segTree[MAXSEG];
	int lazy[MAXSEG];
	max_seg_lazy() {
		this->n = 0;
		fill(lazy, lazy + MAXSEG, 0);
		fill(segTree, segTree + MAXSEG, 0);
	}
	max_seg_lazy(int n) {
		this->n = n;
		fill(lazy, lazy + MAXSEG, 0);
		fill(segTree, segTree + MAXSEG, 0);
	}
	int query(int i, int j) {
		return queryUtil(0, 0, n-1, i, j);
	}
	int queryUtil(int node, int a, int b, int i, int j) {
		if (lazy[node] != 0) {
			segTree[node] += lazy[node];
			if (a != b) {
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (a > b || a > j || b < i) return NINF;
		if (a >= i && b <= j) return segTree[node];
		int mid = (a + b) / 2;
		int left = queryUtil(2 * node + 1, a, mid, i, j);
		int right = queryUtil(2 * node + 2, mid + 1, b, i, j);
		return max(left, right);
	}
	void update(int i, int j, int val) {
		updateUtil(0, 0, n-1, i, j, val);
	}
	void updateUtil(int node, int a, int b, int i, int j, int val) {
		if (lazy[node] != 0) {
			segTree[node] += lazy[node];
			if (a != b) {
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (a > b || a > j || b < i) return;
		if (a >= i && b <= j) {
			segTree[node] += val;
			if (a != b) {
				lazy[2 * node + 1] += val;
				lazy[2 * node + 2] += val;
			}
			return;
		}
		int mid = (a + b) / 2;
		updateUtil(node * 2 + 1, a, mid, i, j, val);
		updateUtil(node * 2 + 2, mid + 1, b, i, j, val);
		segTree[node] = max(segTree[2 * node + 1], segTree[2 * node + 2]);
	}
};

struct min_seg_lazy {
	int n;
	int segTree[MAXSEG];
	int lazy[MAXSEG];
	min_seg_lazy() {
		this->n = 0;
		fill(lazy, lazy + MAXSEG, 0);
		fill(segTree, segTree + MAXSEG, 0);
	}
	min_seg_lazy(int n) {
		this->n = n;
		fill(lazy, lazy + MAXSEG, 0);
		fill(segTree, segTree + MAXSEG, 0);
	}
	int query(int i, int j) {
		return queryUtil(0, 0, n-1, i, j);
	}
	int queryUtil(int node, int a, int b, int i, int j) {
		if (lazy[node] != 0) {
			segTree[node] += lazy[node];
			if (a != b) {
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (a > b || a > j || b < i) return INF;
		if (a >= i && b <= j) return segTree[node];
		int mid = (a + b) / 2;
		int left = queryUtil(2 * node + 1, a, mid, i, j);
		int right = queryUtil(2 * node + 2, mid + 1, b, i, j);
		return min(left, right);
	}
	void update(int i, int j, int val) {
		updateUtil(0, 0, n-1, i, j, val);
	}
	void updateUtil(int node, int a, int b, int i, int j, int val) {
		if (lazy[node] != 0) {
			segTree[node] += lazy[node];
			if (a != b) {
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (a > b || a > j || b < i) return;
		if (a >= i && b <= j) {
			segTree[node] += val;
			if (a != b) {
				lazy[2 * node + 1] += val;
				lazy[2 * node + 2] += val;
			}
			return;
		}
		int mid = (a + b) / 2;
		updateUtil(node * 2 + 1, a, mid, i, j, val);
		updateUtil(node * 2 + 2, mid + 1, b, i, j, val);
		segTree[node] = min(segTree[2 * node + 1], segTree[2 * node + 2]);
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	min_seg_lazy segtree(10);
}