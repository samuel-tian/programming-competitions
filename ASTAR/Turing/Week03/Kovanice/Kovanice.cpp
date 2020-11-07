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

const int N = 300005;
const int M = 300005;
const int V = 300005;

int n, m, v;
vi adj[M], radj[M];
ppi weigh[V];
int in[M], dis[M];

vi tsorted;
bool cyclic = false;
bool temp[M], visited[M];
int ans[M];

void dfs(int cur) {
    if (visited[cur]) return;
    if (temp[cur]) {
        cyclic = true;
        return;
    }
    temp[cur] = true;
    FOR (i, 0, adj[cur].size()) {
        dfs(adj[cur][i]);
    }
    temp[cur] = false;
    visited[cur] = true;
    tsorted.pb(cur);
}

void topologicalSort() {
    FOR (i, 0, m) {
        dfs(i);
    }
    reverse(tsorted.begin(), tsorted.end());
}

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
} dsu;

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> m >> v;
    dsu = DSU(M);
    FOR (i, 0, v) {
        string s;
        cin >> s;
        int ind = -1;
        FOR (j, 0, s.size()) {
            if (s[j] == '<' || s[j] == '=') {
                ind = j;
                break;
            }
        }
        int a = stoi(s.substr(0, ind));
        int b = stoi(s.substr(ind+1));
        a--, b--;
        int c = (s[ind]=='<');
        weigh[i] = mppi(a, b, c);
        // cout << a << " " << b << " " << c << '\n';
        if (c == 0)
            dsu.join(a, b);
    }
    FOR (i, 0, v) {
        if (weigh[i].s==0)
            continue;
        int a = dsu.find(weigh[i].f.f);
        int b = dsu.find(weigh[i].f.s);
        adj[a].pb(b);
        radj[b].pb(a);
        in[b]++;
    }
    // PRSP(in, m);
    fill(dis, dis + M, -1);
    topologicalSort();
    FOR (ii, 0, m) {
        int i = dsu.find(ii);
        if (in[i] == 0) {
            dis[i] = 0;
        }
    }
    TRAV (ii, tsorted) {
        int i = dsu.find(ii);
        TRAV (bb, adj[i]) {
            int b = dsu.find(bb);
            dis[b] = max(dis[b], dis[i] + 1);
        }
    }
    // PRSP(dis, m);
    fill(ans, ans + m, -1);
    FORd (ii, m-1, 0) {
        int i = dsu.find(tsorted[ii]);
        if (dis[i] == n-1) {
            ans[i] = n-1;
        }
        if (ans[i]==-1)
            continue;
        TRAV (bb, radj[i]) {
            int b = dsu.find(bb);
            if (dis[b] == dis[i]-1)
                ans[b] = ans[i]-1;
        }
    }
    FOR (i, 0, m) {
        int x = ans[dsu.find(i)];
        if (x==-1)
            cout << "?" << '\n';
        else
            cout << "K" << x+1 << '\n';
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

