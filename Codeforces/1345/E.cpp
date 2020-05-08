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

const int N = 200005;

int n, m;
vector<vi> adj, radj;

vector<bool> vis;
vector<bool> temp;
vi topo, rtopo;
bool cyclic = false;
vi dp, dpr;

void dfs(int cur, vi& topo) {
    if (vis[cur]) return;
    if (temp[cur]) { cyclic = true; return; }
    temp[cur] = true;
    TRAV (b, adj[cur]) {
        dfs(b, topo);
    }
    temp[cur] = false;
    vis[cur] = true;
    topo.pb(cur);
}

void topo_sort() {
    vis.resize(n); temp.resize(n);
    FOR (i, 0, n) {
        dfs(i, topo);
    }
    rtopo = topo;
    reverse(topo.begin(), topo.end());
}

void go(vi& dp, vi& topo, vector<vi> adj) {
    TRAV (x, topo) {
        dp[x] = x;
        TRAV (b, adj[x]) {
            dp[x] = min(dp[x], dp[b]);
        }
    }
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> m;
    adj.resize(n); radj.resize(n);
    FOR (i, 0, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].pb(b);
        radj[b].pb(a);
    }
    topo_sort();
    if (cyclic) {
        cout << -1 << endl;
    }
    else {
        dp.resize(n); dpr.resize(n);
        go(dp, topo, radj);
        go(dpr, rtopo, adj);
        string ret = "";
        int cnt = 0;
        FOR (i, 0, n) {
            if (dp[i] >= i && dpr[i] >= i) {
                ret += "A";
                cnt++;
            }
            else {
                ret += "E";
            }
        }
        cout << cnt << endl;
        cout << ret << endl;
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}


