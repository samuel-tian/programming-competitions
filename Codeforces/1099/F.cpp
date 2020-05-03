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
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

struct sum_seg_tree {
	int n;
	vector<pair<int, ll> > segTree;
	sum_seg_tree() {
		this->n = 0;
		segTree.resize(1);
		fill(segTree.begin(), segTree.end(), mp(0, 0));
	}
	sum_seg_tree(int n) {
		this->n = n;
		int sz = (1<<(1+(int)ceil(log2(n))));
		segTree.resize(sz);
		fill(segTree.begin(), segTree.end(), mp(0, 0));
	}
	pair<int, ll> query(int i, int j) {
		return queryUtil(0, 0, n-1, i, j);
	}
	pair<int, ll> queryUtil(int node, int a, int b, int i, int j) {
		if (a >= i && b <= j) return segTree[node];
		if (a > j || b < i) return mp(0, 0);
		int mid = (a + b) / 2;
		pair<int, ll> l = queryUtil(2 * node + 1, a, mid, i, j);
		pair<int, ll> r = queryUtil(2 * node + 2, mid + 1, b, i, j);
		return mp(l.f+r.f, l.s+r.s);
	}
	void update(int i, int val) {
		updateUtil(0, 0, n-1, i, val);
	}
	void updateUtil(int node, int a, int b, int i, int val) {
		if (i < a || i > b) return;
		if (a == b) { segTree[node].f += val; segTree[node].s += (ll)val * i; }
		else if (a != b) {
			int mid = (a + b) / 2;
			updateUtil(2 * node + 1, a, mid, i, val);
			updateUtil(2 * node + 2, mid + 1, b, i, val);
			segTree[node].f = segTree[2 * node + 1].f + segTree[2 * node + 2].f;
			segTree[node].s = segTree[2 * node + 1].s + segTree[2 * node + 2].s;
		}
	}
	ll ans(ll t) {
		int lo = 0, hi = (int)1e6;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			pair<int, ll> q = query(0, mid);
			if (q.s >= t) hi = mid;
			else lo = mid + 1;
		}
		pair<int, ll> q = query(0, hi-1);
		ll ret = q.f + min((t - q.s) / hi, (ll)query(hi, hi).f);
		return ret;
	}
};

const int MAXN = (int)1e5 + 5;
const int MAX = (int)1e6 + 5;

ll N, T;
int x[MAXN];
int t[MAXN];
ll tpath[MAXN], f[MAXN];
vpi adj[MAXN];
sum_seg_tree segtree(MAX);
ll dp[MAXN];

void dfs(int a, int par) {
	segtree.update(t[a], x[a]);
	if (T - 2*tpath[a] <= 0) f[a] = 0;
	else f[a] = segtree.ans(T - 2*tpath[a]);
	TRAV (b, adj[a]) {
		if (b.f == par) continue;
		tpath[b.f] = tpath[a] + b.s;
		dfs(b.f, a);
	}
	segtree.update(t[a], -x[a]);
}

void dfs2(int a, int par) {
	dp[a] = f[a];
	vector<ll> m;
	TRAV (b, adj[a]) {
		if (b.f == par) continue;
		dfs2(b.f, a);
		m.pb(dp[b.f]);
	}
	sort(m.begin(), m.end(), greater<ll>());

	if (a == 0) {
		if (m.size() == 0) return;
		dp[a] = max(dp[a], m[0]);
	} else {
		if (m.size() <= 1) return;
		dp[a] = max(dp[a], m[1]);
	}
}

int main() {
	setIO();
	cin >> N >> T;
	FOR (i, 0, N) cin >> x[i];
	FOR (i, 0, N) cin >> t[i];
	FOR (i, 1, N) {
		int a, b;
		cin >> a >> b;
		adj[a-1].pb(mp(i, b));
		adj[i].pb(mp(a-1, b));
	}
	/*FOR (i, 0, N) {
		cout << i << ": ";
		TRAV (b, adj[i]) {
			cout << b.f << " ";
		}
		cout << endl;
	}*/
	dfs(0, -1);
//	PRSP(f, N);
	dfs2(0, -1);
//	PRSP(dp, N);
	cout << dp[0] << endl;
}
