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

const int N = 105;
const int K = 55;

int n, k;
vpi adj[N];
int w[N];
int sz[N], dep[N];
int pre[N][N];

void dfs2(int a, int p) {
    sz[a] = 1;
    TRAV (b, adj[a]) {
        if (b.f == p) continue;
        dep[b.f] = dep[a] + 1;
        dfs2(b.f, a);
        sz[a] += sz[b.f];
    }
}

void trav(int a, int p, int r, int v) {
    pre[a][dep[a] - dep[r]] = v;
    TRAV (b, adj[a]) {
        if (b.f == p) continue;
        trav(b.f, a, r, v + b.s);
    }
}

void init(int a, int p) {
    trav(a, p, a, 0);
    TRAV (b, adj[a]) {
        if (b.f == p) continue;
        init(b.f, a);
    }
}

int dp[N][K][N];
int aux[N][K][N]; // without mill at u; current subtree, number of mills, distance to next mill
int aux2[N][K]; // with mill at u; current subtree, number of mills

void dfs(int u, int p) {
    int cnt = 0;
    TRAV (x, adj[u]) {
        if (x.f == p) continue;
        dfs(x.f, u);
    }
    FOR (i, 0, K) {
        if (i == 0) {
            FOR (j, 0, N) {
                aux[0][i][j] = 0;
            }
            aux2[0][i] = 0;
        }
        else {
            FOR (j, 0, N) {
                aux[0][i][j] = INF;
            }
            aux2[0][i] = INF;
        }
    }
    TRAV (x, adj[u]) {
        int v = x.f;
        if (v == p) continue;
        cnt++;
        FOR (i, 0, K) {
            FOR (j, 0, N) {
                aux[cnt][i][j] = INF;
            }
            aux2[cnt][i] = INF;
        }
        FOR (i, 0, K) {
            if (i > sz[u]) break;
            FOR (l, 0, N) {
                if (l > dep[u]) continue;
                FOR (j, 0, K) {
                    if (i - j < 0) break;
                    if (aux[cnt-1][i-j][l] != INF) {
                        if (dp[v][j][l+1] != INF) {
                            aux[cnt][i][l] = min(aux[cnt][i][l], aux[cnt-1][i-j][l] + dp[v][j][l+1]);
                        }
                    }
                }
            }
            FOR (j, 0, K) {
                if (i - j < 0) break;
                if (aux2[cnt-1][i-j] != INF) {
                    if (dp[v][j][1] != INF) {
                        aux2[cnt][i] = min(aux2[cnt][i], aux2[cnt-1][i-j] + dp[v][j][1]);
                    }
                }
            }
        }
    }
    FOR (i, 0, K) {
        FOR (j, 0, N) {
            if (j > dep[u]) {
                dp[u][i][j] = INF;
            }
            else {
                int v = aux2[cnt][i-1];
                if (i == 0) {
                    v = INF;
                }
                if (aux[cnt][i][j] != INF && j != 0) {
                    dp[u][i][j] = min(v, aux[cnt][i][j] + pre[u][j] * w[u]);
                }
                else {
                    dp[u][i][j] = v;
                }
            }
        }
    }
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("");
    cin >> n >> k;
    n++;
    FOR (i, 1, n) {
        int a, b, c;
        cin >> a >> b >> c;
        w[i] = a;
        adj[i].emplace_back(b, c); adj[b].emplace_back(i, c);
    }
    dep[0] = 0;
    dfs2(0, -1);
    init(0, -1);
    /*cout << "depth: ";PRSP(dep, n);
    cout << "subtree size: ";PRSP(sz, n);
    cout << "weight: ";PRSP(w, n);
    FOR (i, 0, n) {
        FOR (j, 0, n) {
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }*/
    dfs(0, -1);
    /*FOR (i, 0, n) {
        cout << "village " << i << endl;
        FOR (l, 0, k+2) {
            FOR (m, 0, n) {
                if (dp[i][l][m] == INF) cout << "INF ";
                else cout << dp[i][l][m] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }*/
    int ans = dp[0][k+1][0];
    cout << ans << endl;

    int ret = 0;
    FOR (i, 0, n) {
        if (i == 0 || i == 1 || i == 4) continue;
        ret += w[i] * pre[i][dep[i]];
    }
    // cout << ret << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

