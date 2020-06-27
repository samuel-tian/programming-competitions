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

const int N = (int)1e6 + 100;

int n;
int a[N];
ll cl[N], cr[N];
pi st[N];

ll solve() {
    fill(cl, cl + n, 0); fill(cr, cr + n, 0);
    int sz = 0;
    FOR (i, 0, n) {
        while (sz > 0 && a[i] >= st[sz-1].f) {
            cl[i] += cl[st[sz-1].s] + 1;
            sz--;
        }
        st[sz++] = mp(a[i], i);
    }
    sz = 0;
    FORd (i, n-1, 0) {
        while (sz > 0 && a[i] > st[sz-1].f) {
            cr[i] += cr[st[sz-1].s] + 1;
            sz--;
        }
        st[sz++] = mp(a[i], i);
    }
    ll ret = 0;
    FOR (i, 0, n) {
        ret += a[i] * (cl[i] + 1) * (cr[i] + 1);
    }
    return ret;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n;
    FOR (i, 0, n) cin >> a[i];
    ll maxi = solve();
    FOR (i, 0, n) a[i] = -a[i];
    ll mini = solve();
    // cout << maxi << " " << mini << endl;
    cout << maxi + mini << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
