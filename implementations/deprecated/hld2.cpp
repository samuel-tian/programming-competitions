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
typedef vector<long long> vll;
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
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

const int N = (int)1e5 + 5;

int n, m;
vi adj[N];

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

namespace hld {
	int par[N], d[N];
	int heavy[N], head[N], pos[N];
	int cur = 0;
	sum_seg_lazy segtree;
	int dfs(int a) {
		int ret = 1;
		int max_size = 0;
		TRAV (b, adj[a]) {
			if (b == par[a]) continue;
			par[b] = a;
			d[b] = d[a] + 1;
			int sz = dfs(b);
			ret += sz;
			if (sz > max_size) { max_size = sz; heavy[a] = b; }
		}
		return ret;
	}
	void decomp(int a, int h) {
		head[a] = h; pos[a] = cur++;
		if (heavy[a] != -1) decomp(heavy[a], h);
		TRAV (b, adj[a]) {
			if (b == par[a] || b == heavy[a]) continue;
			decomp(b, b);
		}
	}
	void init(int n) {
		segtree = sum_seg_lazy(n);
		fill(heavy, heavy + n, -1);
		cur = 0;
		dfs(0);
		decomp(0, 0);
	}
	void update(int a, int b, int val) {
		for (; head[a] != head[b]; b = par[head[b]]) {
			if (d[head[a]] > d[head[b]]) swap(a, b);
			segtree.update(pos[head[b]], pos[b], val);
		}
		if (d[a] > d[b]) swap(a, b);
		segtree.update(pos[a], pos[b], val);
	}
	int query(int a, int b) {
		int ret = 0;
		for (; head[a] != head[b]; b = par[head[b]]) {
			if (d[head[a]] > d[head[b]]) swap(a, b);
			ret += segtree.query(pos[head[b]], pos[b]);
		}
		if (d[a] > d[b]) swap(a, b);
		ret += segtree.query(pos[a], pos[b]);
		return ret;
	}
};

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("input");
	cin >> n >> m;
	int a, b; char c;
	FOR (i, 0, n-1) {
		cin >> a >> b; --a, --b;
		adj[a].pb(b); adj[b].pb(a);
	}
	hld::init(n);
	while (m--) {
		cin >> c >> a >> b; --a, --b;
		if (c == 'P') {
			hld::update(a, b, 1);
		}
		else {
			cout << hld::query(a, b) << endl;
		}
	}

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
