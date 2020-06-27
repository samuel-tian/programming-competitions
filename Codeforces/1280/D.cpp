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
#define smax(a, b) a < b ? a = b, 1 : 0
#define smin(a, b) a > b ? a = b, 1 : 0

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

const int N = 3005;

int n, m;
vi adj[N];
ll b[N], w[N];
pair<int, ll> dp[N][N];
int sz[N];

void reinit() {
    FOR (i, 0, n+5) {
        adj[i].clear();
        b[i] = w[i] = 0;
        FOR (j, 0, n+5) {
            dp[i][j] = mp(-INF, 0);
        }
    }
}

void dfs(int a, int p) {
    dp[a][0] = mp(0, w[a] - b[a]);
    sz[a] = 1;
    pair<int, ll> tmp[N];
    TRAV (b, adj[a]) {
        if (b == p) continue;
        dfs(b, a);
        FOR (i, 0, sz[a] + sz[b]) {
            tmp[i] = mp(-INF, 0);
        }
        FOR (i, 0, sz[a]) {
            FOR (j, 0, sz[b]) {
                // merge into the root of the subtree
                smax(tmp[i+j], mp(dp[a][i].f + dp[b][j].f, dp[a][i].s + dp[b][j].s));
                // don't merge
                smax(tmp[i+j+1], mp(dp[a][i].f + dp[b][j].f + (dp[b][j].s > 0), dp[a][i].s));
            }
        }
        FOR (i, 0, sz[a] + sz[b]) {
            dp[a][i] = tmp[i];
        }
        sz[a] += sz[b];
    }
}

void solve() {
    cin >> n >> m;
    reinit();
    FOR (i, 0, n)
        cin >> b[i];
    FOR (i, 0, n)
        cin >> w[i];
    FOR (i, 0, n-1) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(0, -1);
    int ans = dp[0][m-1].f + (dp[0][m-1].s > 0);
    cout << ans << endl;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

