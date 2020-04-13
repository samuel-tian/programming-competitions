#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<21);
const int MUL = 1000001;
const int MOD = 1000000007;

const int MAXN = (int)1e6 + 5;

struct min_seg_tree {
	int n;
	int segTree[MAXSEG];
	min_seg_tree() {
		this->n = 0;
		fill(segTree, segTree + MAXSEG, 0);
	}
	min_seg_tree(int n) {
		this->n = n;
		fill(segTree, segTree + MAXSEG, 0);
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
			segTree[node] = val;
		}
		else if (a != b) {
			int mid = (a + b) / 2;
			updateUtil(2 * node + 1, a, mid, i, val);
			updateUtil(2 * node + 2, mid + 1, b, i, val);
			segTree[node] = min(segTree[2 * node + 1], segTree[2 * node + 2]);
		}
	}
};

int n;
vpi adj[MAXN];
bool s[MAXN];
int words_before[MAXN];
int dp[MAXN];
min_seg_tree segtree;
vi st;

int dfs(int a, int par) {
	segtree.update(st.size(), dp[a] - words_before[a]);
	st.pb(a);
	int tot = 0, sz = s[a];
	FOR (i, 0, adj[a].size()) {
		int b = adj[a][i].s;
		if (b == par) continue;
		words_before[b] = words_before[a] + sz;
		dp[b] = dp[a] + 1;
		if (s[b]) {
			dp[b] = min(dp[b], segtree.query(0, st.size()-1) + words_before[b] + 1);
		}
		int sub_sz = dfs(b, a);
		sz += sub_sz; tot += sub_sz;
	}
	st.pop_back();
	segtree.update(st.size(), 0);
	return sz;
}

int main() {
	setIO("stdio");
	cin >> n;
	segtree = min_seg_tree(n+1);
	FOR (i, 1, n+1) {
		int a; char c;
		cin >> a >> c;
		adj[a].pb(mp(c - 'a', i));
		adj[i].pb(mp(c - 'a', a));
	}
	FOR (i, 0, n+1) {
		sort(adj[i].begin(), adj[i].end());
	}
	int k;
	cin >> k;
	int g[k];
	FOR (i, 0, k) {
		cin >> g[i];
		s[g[i]] = true;
	}
	dp[0] = 0;
	words_before[0] = 0;
	dfs(0, -1);
//	PRSP(words_before, n+1);
//	PRSP(dp, n+1);
	FOR (i, 0, k) {
		cout << dp[g[i]] << " ";
	}
	cout << endl;
}
