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
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

const int MAXN = 100005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<20);
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
	setIO("stdio");
	int n;
	cin >> n;
	int p[n], q[n], inv[n+1];
	FOR (i, 0, n) {
		cin >> p[i];
		inv[p[i]] = i;
	}
	FOR (i, 0, n) {
		cin >> q[i];
		q[i]--;
	}
	min_seg_lazy segtree(n);
	int k = n;
	FOR (i, 0, n) {
		if (i == 0) {
			segtree.update(0, inv[k], -1);
			cout << k;
		}
		else {
			segtree.update(0, q[i-1], 1);
			while (segtree.query(0, n-1) >= 0) {
				segtree.update(0, inv[--k], -1);
			}
			cout << " " << k;
		}

	}
	cout << endl;
}
