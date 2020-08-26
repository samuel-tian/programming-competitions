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
 *      c) otherwise, return DEFAULT
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)
#define PRSP(x, a) for (int rv = 0; rv < a; ++rv) {cout << ((rv==0 ? "" : " ")) << x[rv];} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

const int MAXN = 100005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (name == "input") {
		freopen("input.txt","r",stdin);
	}
	else if (name == "stdio") {

	}
	else {
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
}

struct sum_seg_tree {
	int n;
	vi segTree;
	sum_seg_tree() {
		this->n = 0;
		segTree.resize(1);
		fill(segTree.begin(), segTree.end(), 0);
	}
	sum_seg_tree(int n) {
		this->n = n;
		int sz = (1<<(1+(int)ceil(log2(n))));
		segTree.resize(sz);
		fill(segTree.begin(), segTree.end(), 0);
	}
	int query(int i, int j) {
		return queryUtil(0, 0, n-1, i, j);
	}
	int queryUtil(int node, int a, int b, int i, int j) {
		if (a >= i && b <= j) {
			return segTree[node];
		}
		if (a > j || b < i) {
			return 0;
		}
		int mid = (a + b) / 2;
		int l = queryUtil(2 * node + 1, a, mid, i, j);
		int r = queryUtil(2 * node + 2, mid + 1, b, i, j);
		return l + r;
	}
	void update(int i, int val) {
		updateUtil(0, 0, n-1, i, val);
	}
	void updateUtil(int node, int a, int b, int i, int val) {
		if (i < a || i > b) {
			return;
		}
		if (a == b) {
			segTree[node] += val;
		}
		else if (a != b) {
			int mid = (a + b) / 2;
			updateUtil(2 * node + 1, a, mid, i, val);
			updateUtil(2 * node + 2, mid + 1, b, i, val);
			segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
		}
	}
};

struct max_seg_tree {
	int n;
	vi segTree;
	max_seg_tree() {
		this->n = 0;
		segTree.resize(1);
		fill(segTree.begin(), segTree.end(), 0);
	}
	max_seg_tree(int n) {
		this->n = n;
		int sz = (1<<(1+(int)ceil(log2(n))));
		segTree.resize(sz);
		fill(segTree.begin(), segTree.end(), 0);
	}
	int query(int i, int j) {
		return queryUtil(0, 0, n-1, i, j);
	}
	int queryUtil(int node, int a, int b, int i, int j) {
		if (a >= i && b <= j) {
			return segTree[node];
		}
		if (a > j || b < i) {
			return 0;
		}
		int mid = (a + b) / 2;
		int l = queryUtil(2 * node + 1, a, mid, i, j);
		int r = queryUtil(2 * node + 2, mid + 1, b, i, j);
		return max(l, r);
	}
	void update(int i, int val) {
		updateUtil(0, 0, n-1, i, val);
	}
	void updateUtil(int node, int a, int b, int i, int val) {
		if (i < a || i > b) {
			return;
		}
		if (a == b) {
			segTree[node] += val;
		}
		else if (a != b) {
			int mid = (a + b) / 2;
			updateUtil(2 * node + 1, a, mid, i, val);
			updateUtil(2 * node + 2, mid + 1, b, i, val);
			segTree[node] = max(segTree[2 * node + 1], segTree[2 * node + 2]);
		}
	}
};

struct min_seg_tree {
	int n;
	vi segTree;
	min_seg_tree() {
		this->n = 0;
		segTree.resize(1);
		fill(segTree.begin(), segTree.end(), 0);
	}
	min_seg_tree(int n) {
		this->n = n;
		int sz = (1<<(1+(int)ceil(log2(n))));
		segTree.resize(sz);
		fill(segTree.begin(), segTree.end(), 0);
	}
	int query(int i, int j) {
		return queryUtil(0, 0, n-1, i, j);
	}
	int queryUtil(int node, int a, int b, int i, int j) {
		if (a >= i && b <= j) {
			return segTree[node];
		}
		if (a > j || b < i) {
			return INF;
		}
		int mid = (a + b) / 2;
		int l = queryUtil(2 * node + 1, a, mid, i, j);
		int r = queryUtil(2 * node + 2, mid + 1, b, i, j);
		return min(l, r);
	}
	void update(int i, int val) {
		updateUtil(0, 0, n-1, i, val);
	}
	void updateUtil(int node, int a, int b, int i, int val) {
		if (i < a || i > b) {
			return;
		}
		if (a == b) {
			segTree[node] += val;
		}
		else if (a != b) {
			int mid = (a + b) / 2;
			updateUtil(2 * node + 1, a, mid, i, val);
			updateUtil(2 * node + 2, mid + 1, b, i, val);
			segTree[node] = min(segTree[2 * node + 1], segTree[2 * node + 2]);
		}
	}
};

int main() {
	setIO("input");
	int n;
	cin >> n;
	int a[n];
	FOR (i, 0, n) {
		cin >> a[i];
	}
	sum_seg_tree sumSeg(n);
	FOR (i, 0, n) {
		sumSeg.update(i, a[i]);
	}
	cout << sumSeg.query(0, n-1) << endl;
}