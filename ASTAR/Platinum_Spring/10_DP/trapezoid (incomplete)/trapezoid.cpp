#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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

#define FOR(i, a, b) for (int (i) = (a); i < (b); ++i)
#define FORd(i, a, b) for (int (i) = (a); i >= (b); --i)
#define TRAV(i, x) for (auto& (i) : (x))
#define PRSP(x, a) for (int rv = 0; rv < a; ++rv) {cout << ((rv==0 ? "" : " ")) << x[rv];} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c))
#define min3(a, b, c) min(min((a), (b)), (c))

void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (name == "") return;
	if (name == "input") {freopen("input.txt","r",stdin);}
	else {freopen((name+".in").c_str(),"r",stdin); freopen((name+".out").c_str(),"w",stdout);}
}

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<19);
const int MUL = 1000001;
const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

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

const int MAXN = 1e5 + 5;

struct trapezoid {
	int a, b, c, d;
	bool operator < (trapezoid& other) {
		return this->a < other.a;
	}
};

int n;
trapezoid t[MAXN];
int dp[MAXN];
int sum[MAXN];
max_seg_tree segtree1;

int main() {
	setIO();
	cin >> n;
	FOR (i, 0, n) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		t[i] = {a, b, c, d};
	}
	sort(t, t + n);
	vi comp(2*n);
	FOR (i, 0, n) {
		comp[2*i] = t[i].c;
		comp[2*i+1] = t[i].d;
	}
	sort(comp.begin(), comp.end());
	unordered_map<int, int> inv;
	FOR (i, 0, 2*n) {
		inv[comp[i]] = i;
	}
	FOR (i, 0, n) {
		t[i].c = inv[t[i].c];
		t[i].d = inv[t[i].d];
	}
	/*FOR (i, 0, n) {
		cout << i + 1 << " " << t[i].c << " " << t[i].d << endl;
	}*/
	vector<pair<pair<int, bool>, int> > v(2*n);
	FOR (i, 0, n) {
		v[2*i] = mp(mp(t[i].a, true), i);
		v[2*i+1] = mp(mp(t[i].b, false), i);
	}
	sort(v.begin(), v.end());
	segtree1 = max_seg_tree(2*n);
	dp[0] = 0;
	FOR (i, 0, 2*n) {
		int j = v[i].s;
		if (v[i].f.s) {
			dp[j + 1] = max(dp[j + 1], segtree1.query(0, t[j].c) + 1);
		}
		else {
			segtree1.update(t[j].d, dp[j + 1]);
		}
	}
//	PRSP(dp, n+1);
	vi count(n+1);
	count[0] = 1;
	FOR (i, 1, n+1) {
		count[dp[i]] += count[dp[i]-1];
	}
	int ret = 0;
	FOR (i, 0, n+1) {
		ret = max(ret, dp[i]);
	}
	cout << ret << " " << count[ret] << endl;
}
