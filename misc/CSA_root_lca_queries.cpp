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

const int N = 100005;
const int Q = 100005;

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

struct Query {
    int a, b, c;
    int ind;
};

int n, q;
vi adj[N];
DSU dsu;
Query qry[N];
vector<Query> oth[N];
int vis[N], sz[N], anc[N], ans[Q];

void dfs(int a, int p) {
    vis[a] = 1;
    sz[a] = 1;
    anc[a] = a;
    unordered_set<int> children;
    TRAV (b, adj[a]) {
        if (vis[b])
            continue;
        dfs(b, a);
        sz[a] += sz[b];
        children.insert(b);
    }
    TRAV (q, oth[a]) {
        int pa = anc[dsu.find(q.a)];
        int pb = anc[dsu.find(q.b)];
        if (children.find(pa)==children.end())
            pa = -1;
        if (children.find(pb)==children.end())
            pb = -1;
        if (pa==-1 && pb==-1) { // C !> A, C !> B
            ans[q.ind] = 0;
            // cout << q.ind << " " << 1 << '\n';
        }
        else if (pa==pb) { // C > LCA(A, B)
            ans[q.ind] = 0;
            // cout << q.ind << " " << 2 << '\n';
        }
        else if (pa==-1 || pb==-1) { // C > A, C !> B
            if (pa==-1)
                swap(pa, pb);
            ans[q.ind] = sz[a] - sz[pa];
            // cout << q.ind << " " << 3 << '\n';
        }
        else { // C = LCA(A, B)
            ans[q.ind] = n - sz[pa] - sz[pb];
            // cout << q.ind << " " << 4 << '\n';
        }
    }
    TRAV (b, adj[a]) {
        if (b==p)
            continue;
        dsu.join(a, b);
    }
    anc[dsu.find(a)] = a;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> q;
    dsu = DSU(n);
    FOR (i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    FOR (i, 0, q) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        Query q = {a, b, c, i};
        qry[i] = q;
        oth[c].pb(q);
    }
    dfs(0, -1);
    FOR (i, 0, q)
        cout << ans[i] << '\n';

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}


