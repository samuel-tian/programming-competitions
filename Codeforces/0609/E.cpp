#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define f first
#define s second
#define pb push_back
#define eb emplace_back
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
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	if (name == "")
        return;
    if (name == "input") {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
	else {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    ll operator()(ll x) const {
        return x ^ RANDOM;
    }
};

const int N = 200005;
const int LOGN = 19;
const int M = 200005;

struct DSU {
    vector<int> par, r;
    DSU() = default;
	DSU(int n) {
		par.resize(n);
		r.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            r[i] = 0;
        }
	}
	int find(int i) {
		if (par[i] != i)
            par[i] = find(par[i]);
		return par[i];
	}
	bool same_set(int a, int b) {
		return find(a) == find(b);
	}
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (r[a] < r[b])
            swap(a, b);
		par[b] = a;
		r[a] = max(r[a], r[b] + 1);
	}
};

int n, m;
pair<long long, pair<int, int> > edg[M], edg2[M];
vector<pair<int, int> > adj[N];
int dep[N];
pair<int, ll> par[LOGN][N];

long long kruskal() {
    DSU dsu(n);
    sort(edg, edg + m);
    long long ret = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        pair<int, int> e = edg[i].second;
        if (dsu.same_set(e.first, e.second))
            continue;
        cnt++;
        dsu.join(e.first, e.second);
        ret += edg[i].first;
        adj[e.first].emplace_back(e.second, edg[i].first);
        adj[e.second].emplace_back(e.first, edg[i].first);
    }
    if (cnt != n-1)
        return -1;
    else
        return ret;
}

void dfs(int a, int p) {
    if (p==-1) {
        dep[a] = 0;
        par[0][a] = {a, 0};
    }
    for (auto b : adj[a]) {
        if (b.f == p)
            continue;
        par[0][b.f] = {a, b.s};
        dep[b.f] = dep[a] + 1;
        dfs(b.f, a);
    }
}

pair<int, ll> lca(int a, int b) {
    ll ans = 0;
    if (dep[a] < dep[b])
        swap(a, b);
    int dif = dep[a] - dep[b];
    for (int i = 0; i < LOGN; i++) {
        if (dif & (1<<i)) {
            ans = max(ans, par[i][a].s);
            a = par[i][a].f;
        }
    }
    for (int i = LOGN-1; i >= 0; i--) {
        if (par[i][a].f == par[i][b].f)
            continue;
        ans = max(ans, par[i][a].s);
        ans = max(ans, par[i][b].s);
        a = par[i][a].f;
        b = par[i][b].f;
    }
    if (a != b)
        return {par[0][a].f, max(ans, max(par[0][a].s, par[0][b].s))};
    else
        return {a, ans};
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--, v--;
        edg[i] = make_pair(w, make_pair(u, v));
        edg2[i] = edg[i];
    }
    long long ans = kruskal();
    dfs(0, -1);
    for (int i = 1; i < LOGN; i++) {
        for (int j = 0; j < n; j++) {
            par[i][j].f = par[i-1][par[i-1][j].f].f;
            par[i][j].s = max(par[i-1][j].s, par[i-1][par[i-1][j].f].s);
        }
    }
    /*FOR (i, 0, n) {
        FOR (j, 0, LOGN) {
            cout << par[j][i].s << " ";
        }
        cout << '\n';
    }*/
    // cout << "mst: " << ans << '\n';
    FOR (i, 0, m) {
        pair<int, ll> tmp = lca(edg2[i].s.f, edg2[i].s.s);
        // cout << i << ": " << tmp.f << " " << tmp.s << " ";
        cout << ans + edg2[i].f - tmp.s << '\n';
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

