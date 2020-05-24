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

const int N = 505;

int n, x;
int v[N];
vi adj[N];
int dp[N][2][N], aux[2][N], aux2[2][N];
bool vis[N], par[N];

void dfs(int a, int p) {
    vis[a] = true;
    dp[a][0][0] = 0;
    dp[a][1][0] = v[a];
    TRAV (b, adj[a]) {
        if (b == p) continue;
        dfs(b, a);
        FOR (i, 0, 2) {
            FOR (j, 0, n+1) {
                aux[i][j] = dp[a][i][j];
                aux2[i][j] = dp[a][i][j];
            }
        }
        FORd (i, n, 0) {
            FORd (j, n, 0) {
                if (i + j > n) continue;
                if (dp[b][0][j] != NINF) {
                    if (dp[a][0][i] != NINF) aux[0][i + j] = max(aux[0][i + j], aux[0][i] + dp[b][0][j]);
                    if (dp[a][1][i] != NINF) aux[1][i + j] = max(aux[1][i + j], aux[1][i] + dp[b][0][j]);
                }
                if (dp[b][1][j] != NINF) {
                    if (dp[a][0][i] != NINF) aux2[0][i + j] = max(aux2[0][i + j], aux2[0][i] + dp[b][1][j]);
                    if (dp[a][1][i] != NINF) aux2[1][i + j + 1] = max(aux2[1][i + j + 1], aux2[1][i] + dp[b][1][j]);
                }
            }
        }
        FOR (i, 0, 2) FOR (j, 0, n+1) dp[a][i][j] = max(aux[i][j], aux2[i][j]);
    }
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> x;
    FOR (i, 0, n) {
        int a, b;
        cin >> a >> b; b--;
        v[i] = a;
        if (b == -1) continue;
        adj[i].pb(b); adj[b].pb(i);
    }
    FOR (i, 0, n) {
        FOR (j, 0, 2) {
            FOR (k, 0, n+1) {
                dp[i][j][k] = NINF;
            }
        }
    }
    FOR (i, 0, n) {
        if (!vis[i]) {
            par[i] = true;
            dfs(i, -1);
        }
    }
    /*FOR (k, 0, 2) {
        cout << "k: " << k << endl;
        FOR (i, 0, n) {
            cout << i+1 << ": ";
            FOR (j, 0, n+1) {
                if (dp[i][k][j] == NINF) cout << "NINF ";
                else cout << dp[i][k][j] << " ";
            }
            cout << endl;
        }
    }*/
    int aux[N], aux2[N], ans[N];
    fill(ans, ans + N, NINF);
    ans[0] = 0;
    FOR (i, 0, n) {
        if (!par[i]) continue;
        FOR (k, 0, n+1) aux[k] = ans[k];
        FOR (k, 0, n+1) aux2[k] = ans[k];
        FORd (j, n, 0) {
            if (ans[j] == NINF) continue;
            FORd (k, n, 0) {
                if (j + k > n) continue;
                if (dp[i][0][k] != NINF) {
                    aux[j + k] = max(aux[j + k], aux[j] + dp[i][0][k]);
                }
                if (dp[i][1][k] != NINF) {
                    aux2[j + k] = max(aux2[j + k], aux2[j] + dp[i][1][k]);
                }
            }
        }
        FOR (k, 0, n+1) ans[k] = max(aux[k], aux2[k]);
    }
    // cout << "ans: "; PRSP(ans, n+1);
    int ret = -1;
    FOR (i, 0, n) {
        if (ans[i] >= x) {
            ret = max(ret, i);
        }
    }
    cout << ret << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

