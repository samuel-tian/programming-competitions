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

const int N = 1005;

int n, k;
int inv[N];
vi sset[N];

int interact(int l, int r, int def = -2) {
    int ret;
    int sz = r-l+1;
    FOR (i, l, r+1) {
        if (inv[i] == def) sz--;
    }
    // if (sz == 0) cout << "zero: " << l << " " << r << " " << def << endl;
    assert(sz != 0);
    FOR (i, l, r+1) {
        if (i == l) cout << "? " << sz << " ";
        if (inv[i] != def) {
            cout << i << " ";
        }
        if (i == r) {
            cout << endl;
            cout.flush();
        }
    }
    cin >> ret;
    return ret;
}

void solve() {
    cin >> n >> k;
    fill(inv, inv + n + 1, -1);
    FOR (i, 0, k) {
        sset[i].clear();
        int x; cin >> x;
        FOR (j, 0, x) {
            int y; cin >> y;
            inv[y] = i;
            sset[i].pb(y);
        }
    }
    int max = interact(1, n);
    int lo = 1, hi = n;
    int cnt = 0;
    while (lo < hi) {
        assert(cnt < 12);
        int mid = (lo + hi) / 2;
        int mx = interact(lo, mid);
        if (mx == max) hi = mid;
        else lo = mid + 1;
        cnt++;
    }
    // lo contains index of maximum
    int max2 = interact(1, n, inv[lo]);
    FOR (i, 0, k) {
        if (i == 0) cout << "! ";
        if (i == inv[lo]) cout << max2 << " ";
        else cout << max << " ";
        if (i == k-1) {
            cout << endl;
            cout.flush();
        }
    }
    string success;
    cin >> success;
    assert(success == "Correct");
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

