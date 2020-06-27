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

const int N = 1e5 + 100;

int n;
vi adj[N];
int enemy[N];
int in_cycle[N];
int vis[N];
bool vis2[N], is_root[N];
ll dp[N][2]; // with cur node, without cur node
int cnt = 1;

void dfs(int a) {
    vis[a] = cnt;
    TRAV (b, adj[a]) {
        if (vis[b]) continue;
        dfs(b);
    }
}

vi cycle;
bool in_stack[N];

int dfs2(int a, int p) {
    if (vis2[a]) return -1;
    if (in_stack[a]) return a;
    in_stack[a] = true;
    int ret = -1;
    int tmp = dfs2(enemy[a], a);
    if (tmp != -1) {
        cycle.pb(a);
        in_cycle[a] = true;
        ret = tmp;
    }
    in_stack[a] = false;
    vis2[a] = true;
    if (ret == a) return -1;
    return ret;
}

void dfs3(int a, int p) {
    dp[a][0] = 1, dp[a][1] = 1;
    TRAV (b, adj[a]) {
        if (b == p) continue;
        if (in_cycle[b]) continue;
        dfs3(b, a);
        dp[a][0] = (dp[a][0] * dp[b][1]) % MOD;
        dp[a][1] = (dp[a][1] * (dp[b][0] + dp[b][1])) % MOD;
    }
}

void reinit() {
    FOR (i, 0, N) {
        adj[i].clear();
        dp[i][0] = dp[i][1] = 0;
        in_cycle[i] = vis[i] = 0;
        vis2[i] = is_root[i] = false;
        in_stack[i] = false;
    }
}

void solve() {
    cin >> n;
    reinit();
    FOR (i, 0, n) {
        int a;
        cin >> a;
        --a;
        enemy[i] = a;
        adj[a].pb(i);
        adj[i].pb(a);
    }
    ll ret = 1;
    FOR (i, 0, n) {
        if (!vis[i]) {
            is_root[i] = true;
            dfs(i);
            cycle.clear();
            dfs2(i, -1);
            TRAV (x, cycle) {
                dfs3(x, -1);
            }
            ll tmp = 0;
            // choose first node in cycle
            pll ans = mp(dp[cycle[0]][0], 0);
            FOR (i, 1, cycle.size()) {
                int v = cycle[i];
                pll ans2;
                if (i == cycle.size()-1) {
                    ans2.f = 0;
                    ans2.s = (dp[v][1] * (ans.f + ans.s)) % MOD;
                }
                else {
                    ans2.f = (dp[v][0] * ans.s) % MOD;
                    ans2.s = (dp[v][1] * (ans.f + ans.s)) % MOD;
                }
                swap(ans, ans2);
            }
            tmp = (tmp + ans.f + ans.s) % MOD;
            // do not choose first node in cycle
            ans = mp(0, dp[cycle[0]][1]);
            FOR (i, 1, cycle.size()) {
                int v = cycle[i];
                pll ans2;
                ans2.f = (dp[v][0] * ans.s) % MOD;
                ans2.s = (dp[v][1] * (ans.f + ans.s)) % MOD;
                swap(ans2, ans);
            }
            tmp = (tmp + ans.f + ans.s) % MOD;
            ret = (ret * tmp) % MOD;
            cnt++;
        }
    }
    cout << ret << endl;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

