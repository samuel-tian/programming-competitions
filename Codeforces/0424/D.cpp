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

const int N = 300;

int n, m, t;
int tp, tu, td;
int grid[N][N];
int up[N][N], down[N][N], lef[N][N], rig[N][N];

int eval(int u, int d, int l, int r) {
    int ans = 0;
    ans += (rig[u][r] - rig[u][l]); // top border
    ans += (lef[d][l] - lef[d][r]); // bottom border
    ans += (down[d][r] - down[u][r]); // right border
    ans += (up[u][l] - up[d][l]); // left border
    return ans;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> m >> t;
    cin >> tp >> tu >> td;
    FOR (i, 0, n) {
        FOR (j, 0, m) {
            cin >> grid[i][j];
        }
    }
    FOR (j, 0, m) {
        down[0][j] = 0;
        FOR (i, 1, n) {
            int upd;
            if (grid[i-1][j] < grid[i][j]) // ascent
                upd = tu;
            else if (grid[i-1][j] > grid[i][j]) // descent
                upd = td;
            else // flat ground
                upd = tp;
            down[i][j] = down[i-1][j] + upd;
        }
        up[n-1][j] = 0;
        FORd (i, n-2, 0) {
            int upd;
            if (grid[i+1][j] < grid[i][j])
                upd = tu;
            else if (grid[i+1][j] > grid[i][j])
                upd = td;
            else
                upd = tp;
            up[i][j] = up[i+1][j] + upd;
        }
    }
    FOR (i, 0, n) {
        rig[i][0] = 0;
        FOR (j, 1, m) {
            int upd;
            if (grid[i][j-1] < grid[i][j])
                upd = tu;
            else if (grid[i][j-1] > grid[i][j])
                upd = td;
            else
                upd = tp;
            rig[i][j] = rig[i][j-1] + upd;
        }
        lef[i][m-1] = 0;
        FORd (j, m-2, 0) {
            int upd;
            if (grid[i][j+1] < grid[i][j])
                upd = tu;
            else if (grid[i][j+1] > grid[i][j])
                upd = td;
            else
                upd = tp;
            lef[i][j] = lef[i][j+1] + upd;
        }
    }
    int ans = INF;
    pair<pi, pi> ret = {};
    FOR (i, 0, n) { // top boundary
        FOR (j, i+2, n) { // bottom boundary
            set<pi> s;
            FORd (k, m-3, 0) {
                s.insert(mp(rig[i][k+2] + down[j][k+2]-down[i][k+2] + lef[j][0]-lef[j][k+2], k+2));
                int v = t - (up[i][k]-up[j][k] - rig[i][k] - (lef[j][0]-lef[j][k]));
                // cout << i << " " << j << " " << k << " " << v << endl;
                auto it = s.lower_bound(mp(v, -1));
                if (it != s.end()) {
                    if (smin(ans, abs(v - it->f))) {
                        ret = mp(mp(i, k), mp(j, it->s));
                    }
                }
                if (it != s.begin()) {
                    it--;
                    if (smin(ans, abs(v - it->f))) {
                        ret = mp(mp(i, k), mp(j, it->s));
                    }
                }
            }
        }
    }
    // cout << ans << endl;
    cout << ret.f.f+1 << " " << ret.f.s+1 << " " << ret.s.f+1 << " " << ret.s.s+1 << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

