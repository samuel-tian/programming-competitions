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
const int K = 52;

int n, q;
int a[N];
int cnt[K];
ll dp[K+10][N];
ll ans[K][K];
ll fact[N];

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) {
		ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d;
	}
	return x = 1, y = 0, a;
}

ll mod_inv(ll a, ll m) {
	ll x, y, g = euclid(a, m, x, y);
	assert(g == 1);
	return (x + m) % m;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    string s; cin >> s;
    n = s.size();
    FOR (i, 0, s.size()) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            a[i] = s[i] - 'a';
        }
        else {
            a[i] = s[i] - 'A' + 26;
        }
        cnt[a[i]]++;
    }
    FOR (i, 0, N) {
        if (i == 0) fact[i] = 1;
        else fact[i] = (fact[i-1] * i) % MOD;
    }
    ll mul = 1;
    mul = (mul * fact[n/2]) % MOD;
    mul = (mul * fact[n/2]) % MOD;
    FOR (i, 0, K) {
        mul = (mul * mod_inv(fact[cnt[i]], MOD)) % MOD;
    }
    dp[0][0] = 1;
    FOR (i, 1, K+1) {
        FOR (j, 0, n+1) {
            dp[i][j] = 0;
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (cnt[i-1] == 0 || j - cnt[i-1] < 0) continue;
            dp[i][j] = (dp[i][j] + dp[i-1][j-cnt[i-1]]) % MOD;
        }
    }
    int cpy[N];
    FOR (i, 0, n+1) {
        cpy[i] = dp[K][i];
    }
    FOR (i, 0, K) {
        if (cnt[i] == 0) continue;
        FOR (k, 0, n+1) {
            if (k - cnt[i] < 0) continue;
            cpy[k] = (cpy[k] - cpy[k-cnt[i]] + MOD) % MOD;
        }
        ans[i][i] = cpy[n/2];
        FOR (j, 0, K) {
            if (i == j || cnt[j] == 0) continue;
            FOR (k, 0, n+1) {
                if (k - cnt[j] < 0) continue;
                cpy[k] = (cpy[k] - cpy[k-cnt[j]] + MOD) % MOD;
            }
            ans[i][j] = cpy[n/2];
            FORd (k, n, 0) {
                if (k - cnt[j] < 0) break;
                cpy[k] = (cpy[k] + cpy[k-cnt[j]]) % MOD;
            }
        }
        FORd (k, n, 0) {
            if (k - cnt[i] < 0) break;
            cpy[k] = (cpy[k] + cpy[k-cnt[i]]) % MOD;
        }
    }
    cin >> q;
    FOR (i, 0, q) {
        int x, y;
        cin >> x >> y;
        x = a[x-1], y = a[y-1];
        cout << (ans[x][y] * mul * 2) % MOD << endl;
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

