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

const int N = 1000005;

int n, m;
string s;
int dp[40][N];
unordered_map<ppi, int> comp;

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> m;
    cin >> s;
    int cnt = 0;
    FOR (i, 0, 5) {
        FOR (j, 0, 5) {
            if (i > j)
                continue;
            FOR (k, 0, 5) {
                if (k >= i && k <= j) {
                    comp[mppi(i, j, k)] = cnt++;
                }
            }
        }
    }
    FORd (l, n, 0) {
        FOR (i, 0, 5) {
            FOR (j, 0, 5) {
                if (j < i)
                    continue;
                FOR (k, 0, 5) {
                    if (k > j || k < i) {
                        continue;
                    }
                    int ind = comp[mppi(i, j, k)];
                    if (l == n) {
                        dp[ind][l] = 1;
                    }
                    else {
                        if (k+1 <= j)
                            dp[ind][l] = (dp[ind][l] + dp[comp[mppi(i, j, k+1)]][l+1]) % m;
                        if (k-1 >= i)
                            dp[ind][l] = (dp[ind][l] + dp[comp[mppi(i, j, k-1)]][l+1]) % m;
                    }
                }
            }
        }
    }
    int ans = 1;
    int mi = 2, ma = 2, cur = 2;
    FOR (i, 0, s.size()) {
        if (s[i] == 'P') {
            if (ma - mi == 2)
                ans += dp[mi][ma][cur+1][i+1];
            else if (ma - mi == 1) {
                ans += dp[mi-1][ma][cur+1][i+1] + dp[mi][ma+1][cur+1][i+1];
                ans -= dp[mi][ma][cur+1][i+1];
            }
            else if (ma - mi == 0) {
                ans += dp[mi-2][ma][cur+1][i+1] + dp[mi-1][ma+1][cur+1][i+1] + dp[mi][ma+2][cur+1][i+1];
                ans -= dp[mi-1][ma][cur+1][i+1] + dp[mi][ma+1][cur+1][i+1];
                ans += dp[mi][ma][cur+1][i+1];
            }
            ans = ans % m;
        }
        cur += (s[i] == 'L') ? 1 : -1;
        mi = min(mi, cur);
        ma = max(ma, cur);
    }
    cout << ans % m << '\n';

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

