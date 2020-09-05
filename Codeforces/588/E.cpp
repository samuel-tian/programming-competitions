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

const int N = 1e5 + 5;
const int LOGN = 17;
const int M = 1e5 + 5;
const int Q = 1e5 + 5;
const int A = 11;

int n, m, q;
vi adj[N], cit[N], mins[LOGN][N];
int dep[N];
int par[LOGN][N];

void merge(vi& l, vi r) {
    vi tmp;
    int lpt = 0, rpt = 0;
    FOR (i, 0, A) {
        if (lpt==l.size() || rpt==r.size()) {
            if (lpt == l.size() && rpt == r.size())
                break;
            if (lpt == l.size()) {
                swap(lpt, rpt);
                swap(l, r);
            }
            tmp.pb(l[lpt++]);
            continue;
        }
        if (l[lpt] < r[rpt])
            tmp.pb(l[lpt++]);
        else
            tmp.pb(r[rpt++]);
    }
    swap(tmp, l);
}

void dfs(int a, int p=-1) {
    if (p == -1) {
        dep[a] = 0;
        par[0][a] = a;
        mins[0][a] = {};
    }
    TRAV (b, adj[a]) {
        if (b == p)
            continue;
        dep[b] = dep[a] + 1;
        par[0][b] = a;
        TRAV (c, cit[a])
            mins[0][b].pb(c);
        dfs(b, a);
    }
}

pair<int, vi> lca(int a, int b) {
    if (dep[a] < dep[b])
        swap(a, b);
    int acpy = a, bcpy = b;
    int dif = dep[a] - dep[b];
    vi amin = {}, bmin = {};
    FOR (i, 0, LOGN) {
        if (dif & (1<<i)) {
            merge(amin, mins[i][a]);
            a = par[i][a];
        }
    }
    FORd (i, LOGN-1, 0) {
        if (par[i][a] == par[i][b])
            continue;
        merge(amin, mins[i][a]);
        merge(bmin, mins[i][b]);
        a = par[i][a];
        b = par[i][b];
    }
    if (a == b) {
        merge(amin, cit[acpy]);
        return mp(a, amin);
    }
    else {
        merge(amin, mins[0][a]);
        merge(amin, cit[acpy]);
        merge(bmin, cit[bcpy]);
        merge(amin, bmin);
        return mp(par[0][a], amin);
    }
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> m >> q;
    FOR (i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    FOR (i, 0, m) {
        int a;
        cin >> a;
        a--;
        cit[a].pb(i+1);
    }
    FOR (i, 0, n)
        sort(cit[i].begin(), cit[i].end());
    dfs(0);
    FOR (i, 1, LOGN) {
        FOR (j, 0, n) {
            par[i][j] = par[i-1][par[i-1][j]];
            mins[i][j] = {};
            merge(mins[i][j], mins[i-1][j]);
            merge(mins[i][j], mins[i-1][par[i-1][j]]);
        }
    }
    FOR (i, 0, q) {
        int v, u, a;
        cin >> v >> u >> a;
        v--, u--;
        pair<int, vi> ret = lca(v, u);
        int k = min(a, (int)((ret.s).size()));
        cout << k;
        FOR (i, 0, k) {
            cout << " " << ret.s[i];
        }
        cout << '\n';
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}


