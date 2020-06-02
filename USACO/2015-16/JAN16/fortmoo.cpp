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

const int N = 205;

int n, m;
char grid[N][N];
int pre[N][N];
int last[N][N];

bool good(int x1, int y1, int x2, int y2) {
    int tot = pre[x2+1][y2+1] - pre[x2+1][y1] - pre[x1][y2+1] + pre[x1][y1];
    return tot == 0;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("fortmoo");
    cin >> n >> m;
    FOR (i, 0, n) {
        string s; cin >> s;
        FOR (j, 0, m) {
            grid[i][j] = s[j];
        }
    }
    FOR (i, 0, n) {
        FOR (j, 0, m) {
            if (grid[i][j] == 'X') pre[i+1][j+1]++;
            pre[i+1][j+1] += pre[i][j+1] + pre[i+1][j] - pre[i][j];
        }
    }
    int ans = 0;
    FOR (i, 0, n) {
        FOR (l, 0, n) {
            if (i + l >= n) continue;
            int prev = 0;
            bool upd = false;
            FOR (j, 0, m) {
                bool g = good(i, j, i+l, j);
                if (grid[i][j] == 'X' || grid[i+l][j] == 'X') {
                    upd = true;
                }
                if (j == 0 && !g) {
                    upd = true;
                }
                if (g && upd) {
                    prev = j;
                    upd = false;
                }
                if (g) {
                    if ((j - prev + 1) * (l + 1) > ans) {
                        // cout << i << " " << j << " " << l << " " << (j - prev + 1) * (l + 1) << endl;
                        ans = (j - prev + 1) * (l + 1);
                    }
                }
            }
        }
    }
    cout << ans << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

