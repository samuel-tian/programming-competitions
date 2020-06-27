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

const int N = 305;
const int M = (N*(N+1))/2;

int n, m;
pair<ll, pi> cows[M];
ll dp[N][N];
ll mx[N][N][N];

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("pieaters");
    cin >> n >> m;
    FOR (i, 0, m) {
        ll w, l, r;
        cin >> w >> l >> r;
        --l, --r;
        cows[i] = mp(w, mp(l, r));
        FOR (j, l, r+1) {
            mx[l][r][j] = max(mx[l][r][j], w);
        }
    }
    /*FOR (i, 2, n) {
        FOR (j, 0, n) {
            int k = j + i - 1;
            if (k >= n) continue;
            FOR (l, j, k) {
                mx[j][k][l] = max(mx[j][k][l], mx[j][k-1][l]);
            }
            FOR (l, j+1, k+1) {
                mx[j][k][l] = max(mx[j][k][l], mx[j+1][k][l]);
            }
        }
    }*/
    FOR (i, 0, n) {
        FORd (j, i, 0) {
            FOR (k, i, n) {
                if (j != 0) mx[j-1][k][i] = max(mx[j-1][k][i], mx[j][k][i]);
                if (k != n-1) mx[j][k+1][i] = max(mx[j][k+1][i], mx[j][k][i]);
            }
        }
    }
    FOR (i, 1, n+1) {
        FOR (j, 0, n) {
            int k = j + i - 1;
            if (k >= n) continue;
            FOR (l, j, k+1) {
                int left_itv = (l-1 < j) ? 0 : dp[j][l-1];
                int right_itv = (l+1 > k) ? 0 : dp[l+1][k];
                dp[j][k] = max(dp[j][k], left_itv + right_itv + mx[j][k][l]);
            }
            FOR (l, j, k) {
                dp[j][k] = max(dp[j][k], dp[j][l] + dp[l+1][k]);
            }
        }
    }
    /*FOR (i, 0, n) {
        FOR (j, i, n) {
            cout << i << " " << j << ": ";
            FOR (l, i, j+1) {
                cout << mx[i][j][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }*/
    cout << dp[0][n-1] << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

