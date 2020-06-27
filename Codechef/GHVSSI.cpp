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
const int MOD = 998244353;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

const int N = 306;

int n;
ll a[N];
int dp[N][N][N][4];

void preprocess() {
    FOR (i, 0, N)
        FOR (j, 0, N)
            FOR (k, 0, N)
                FOR (x, 0, 4)
                    dp[i][j][k][x] = INF;
    FOR (i, 0, 4) {
        if (i == 2)
            dp[0][0][0][i] = 1;
        else
            dp[0][0][0][i] = 0;
    }
    FOR (i, 0, N) {
        FOR (j, 0, N-i) {
            FOR (k, 0, N-i-j) {
                FOR (x, 0, 4) {
                    if (dp[i][j][k][x] == -1) continue;
                    if (x == 2)
                        dp[i][j][k][x] = 1;
                    else {
                        int mini = INF;
                        if (i)
                            smin(mini, dp[i-1][j][k][(x+3)%4]);
                        if (j)
                            smin(mini, dp[i][j-1][k][(x+2)%4]);
                        if (k)
                            smin(mini, dp[i][j][k-1][(x+1)%4]);
                        if (mini == INF) continue;
                        dp[i][j][k][x] = 1 - mini;
                    }
                }
            }
        }
    }
}

void solve() {
    cin >> n;
    int cnt[4];
    memset(cnt, 0, sizeof(cnt));
    FOR (i, 0, n) {
        cin >> a[i];
        a[i] %= 4;
        cnt[a[i]]++;
    }
    // cout << dp[cnt[1]][cnt[2]][cnt[3]][0] << endl;
    if (cnt[0] & 1) {
        cout << (dp[cnt[1]][cnt[2]][cnt[3]][0] ? "Siroj" : "Ghayeeth") << endl;
    }
    else {
        cout << (dp[cnt[1]][cnt[2]][cnt[3]][0] ? "Ghayeeth" : "Siroj") << endl;
    }
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    int T;
    cin >> T;
    preprocess();
    while (T--) {
        solve();
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

