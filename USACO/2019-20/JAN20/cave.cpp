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

struct DSU {
	vi par;
	vi r;
	DSU(int n) {
		par.resize(n);
		r.resize(n);
		FOR (i, 0, n) { par[i] = i; r[i] = 0; }
	}
	int find(int i) {
		if (par[i] != i) par[i] = find(par[i]);
		return par[i];
	}
	bool same_set(int a, int b) {
		return find(a) == find(b);
	}
	void join(int a, int b) {
		a = find(a), b = find(b);
        if (a > b) swap(a, b);
		par[b] = a;
		r[a] = max(r[a], r[b] + 1);
	}
};

const int N = 1005;

int n, m;
char grid[N][N];
int id[N][N];
unordered_map<int, ll> dp;
unordered_map<int, bool> used;

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("cave");
    cin >> n >> m;
    FOR (i, 0, n) {
        string s; cin >> s;
        FOR (j, 0, m) {
            grid[i][j] = s[j];
        }
    }
    DSU dsu = DSU(n*m);
    FORd (i, n-2, 1) {
        FOR (j, 1, m-1) {
            if (grid[i][j] == '.') {
                if (grid[i+1][j] == '.') {
                    dsu.join(i*m+j, (i+1)*m+j);
                }
                if (grid[i][j+1] == '.') {
                    dsu.join(i*m+j, i*m+j+1);
                }
            }
        }
        FOR (j, 1, m-1) {
            if (grid[i][j] == '.') {
                id[i][j] = dsu.find(i*m+j);
            }
        }
        FOR (j, 1, m-1) {
            if (grid[i][j] == '.') {
                if (dp[id[i][j]] == 0) dp[id[i][j]] = 1;
                if (grid[i+1][j] == '.' && !used[id[i+1][j]]) {
                    used[id[i+1][j]] = true;
                    dp[id[i][j]] = dp[id[i][j]] * (dp[id[i+1][j]] + 1) % MOD;
                }
            }
        }
    }
    ll ans = 1;
    FOR (i, 0, n) {
        FOR (j, 0, m) {
            if (grid[i][j] == '.') {
                if (dsu.find(i*m+j) == i*m+j) {
                    // cout << i << " " << j << " " << i*m+j << endl;
                    ans = (ans * (dp[i*m+j] + 1)) % MOD;
                }
            }
        }
    }
    /*cout << "ID" << endl;
    FOR (i, 0, n) {
        FOR (j, 0, m) {
            cout << id[i][j] << " ";
        }
        cout << endl;
    }
    cout << "DP" << endl;
    FOR (i, 0, n) {
        FOR (j, 0, m) {
            cout << dp[i*m+j] << " ";
        }
        cout << endl;
    }*/
    cout << ans << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

