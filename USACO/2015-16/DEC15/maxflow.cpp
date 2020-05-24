#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

const int N = 50005;
const int K = 100005;

struct DSU {
    vi par, r;
    DSU() = default;
    DSU(int n) {
        par.resize(n);
        r.resize(n);
        FOR (i, 0, n) { par[i] = i; r[i] = i; }
    }
    int find(int i) {
        if (par[i] != i) par[i] = find(par[i]);
        return par[i];
    }
    bool same_set(int i, int j) {
        return find(i) == find(j);
    }
    void join(int i, int j) {
        i = find(i), j = find(j);
        if (r[i] < r[j]) swap(i, j);
        par[j] = i;
        r[i] = max(r[i], r[j] + 1);
    }
} dsu;

int n, k;
vi adj[N];
pi q[K];
vpi queries[N];
int lca[K];
int anc[N], par[N];
bool vis[N];
int pre[N];

void dfs(int v, int p = -1) {
    vis[v] = true;
    anc[v] = v;
    par[v] = p;
    TRAV (u, adj[v]) {
        if (vis[u]) continue;
        dfs(u, v);
        dsu.join(v, u);
        anc[dsu.find(v)] = v;
    }
    TRAV (u, queries[v]) {
        if (vis[u.f]) {
            lca[u.s] = anc[dsu.find(u.f)];
        }
    }
}

void dfs2(int a, int p = -1) {
    TRAV (b, adj[a]) {
        if (b == p) continue;
        dfs2(b, a);
        pre[a] += pre[b];
    }
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("maxflow");
    cin >> n >> k;
    dsu = DSU(n);
    FOR (i, 0, n-1) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].pb(b); adj[b].pb(a);
    }
    FOR (i, 0, k) {
        cin >> q[i].f >> q[i].s;
        q[i].f--, q[i].s--;
        queries[q[i].f].pb(mp(q[i].s, i));
        queries[q[i].s].pb(mp(q[i].f, i));
    }
    dfs(0);
    FOR (i, 0, k) {
        pre[q[i].f]++, pre[q[i].s]++;
        pre[lca[i]]--;
        if (par[lca[i]] != -1) pre[par[lca[i]]]--;
    }
    dfs2(0);
    int ret = 0;
    FOR (i, 0, n) {
        ret = max(ret, pre[i]);
    }
    cout << ret << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

