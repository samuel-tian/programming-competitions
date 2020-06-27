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

const int N = 1e5 + 100;
const int LOG = 21;
const int Q = 1e5 + 100;
const int M = 305;

int n, q;
vi adj[N];
int dep[N];
int par[N][LOG];
int st[N], en[N];
int t = 0;
ll dp[N][M];
bool in[N];

template <class T>
struct BIT {
	int n;
	vector<T> arr;
	BIT() {
		n = 0; arr = {};
	}
	BIT(int n) {
		this->n = n; arr.resize(n + 1);
	}
	void clear() { arr.clear(); }
	void update(int i, T v) {
		++i;
		while (i <= n) {
			arr[i] = (arr[i] + v);
			i += i & (-i);
		}
	}
	T get(int i) {
		T ret = 0; ++i;
		while (i > 0) {
			ret = (ret + arr[i]);
			i -= i & (-i);
		}
		return ret;
	}
	T query(int i, int j) { return (get(j) - get(i-1)); }
};
BIT<int> bit;

void dfs(int a, int p) {
    st[a] = t++;
    TRAV (b, adj[a]) {
        if (b == p) continue;
        dfs(b, a);
    }
    en[a] = t-1;
}

void calc_depth(int a, int p) {
    TRAV (b, adj[a]) {
        if (b == p) continue;
        dep[b] = dep[a] + 1;
        par[b][0] = a;
        calc_depth(b, a);
    }
}

void calc_st() {
    dep[0] = 0;
    par[0][0] = 0;
    calc_depth(0, -1);
    FOR (j, 1, LOG) {
        FOR (i, 0, n) {
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
}

int lca(int n1, int n2) {
    int dif = dep[n1] - dep[n2];
    if (dif < 0) {
        swap(n1, n2);
        dif = -dif;
    }
    FOR (i, 0, LOG) {
        if (dif & (1<<i)) {
            n1 = par[n1][i];
        }
    }
    FORd (i, LOG-1, 0) {
        if (par[n1][i] == par[n2][i]) continue;
        n1 = par[n1][i];
        n2 = par[n2][i];
    }
    if (n1 != n2)
        return par[n1][0];
    else
        return n1;
}

int r;

int f(int a, int b) {
    int l = lca(a, b);
    int aq = bit.query(0, st[a]);
    int bq = bit.query(0, st[b]);
    int lq = bit.query(0, st[l]);
    return aq + bq - 2 * lq + in[l];
}

bool comp(int a, int b) {
    return f(a, r) < f(b, r);
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> q;
    FOR (i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bit = BIT<int>(n+5);
    dfs(0, -1);
    calc_st();
    FOR (x, 0, q) {
        int k, m;
        cin >> k >> m >> r;
        r--;
        int a[k];
        FOR (j, 0, k) {
            cin >> a[j];
            a[j]--;
            in[a[j]] = true;
            bit.update(st[a[j]], 1);
            bit.update(en[a[j]]+1, -1);
        }
        sort(a, a + k, comp);
        // PRSP(a, k);
        FOR (i, 0, k+1) {
            FOR (j, 0, m+1) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        FOR (i, 1, k+1) {
            ll anc = f(r, a[i-1]) - 1;
            // cout << a[i-1] << " " << anc << endl;
            FOR (j, 1, m+1) {
                ll a = dp[i-1][j-1];
                ll b = dp[i-1][j];
                dp[i][j] = (a + (b * (j - anc)) % MOD) % MOD;
            }
        }
        /*FOR (i, 0, k+1) {
            FOR (j, 0, m+1) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        ll ans = 0;
        FOR (i, 1, m+1) {
            ans = (ans + dp[k][i]) % MOD;
        }
        cout << ans << endl;
        FOR (j, 0, k) {
            in[a[j]] = false;
            bit.update(st[a[j]], -1);
            bit.update(en[a[j]]+1, 1);
        }
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

