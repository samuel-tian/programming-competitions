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

const int N = 200005;

ll n, x;
ll d[2*N], e[2*N];
ll pre[2*N], pre2[2*N];

ll go(int i, int j) {
    return pre[j+1] - pre[i];
}

ll go2(int i, int j) {
    return pre2[j+1] - pre2[i];
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> x;
    FOR (i, 0, n) cin >> d[i];
    FOR (i, n, 2*n) d[i] = d[i - n];
    FOR (i, 0, 2*n) e[i] = (d[i] * (d[i] + 1)) / 2;
    FOR (i, 0, 2*n) pre[i+1] = pre[i] + d[i];
    FOR (i, 0, 2*n) pre2[i+1] = pre2[i] + e[i];
    int l = -1;
    ll ans = 0;
    FOR (i, n, 2*n) {
        while (l+1 <= i && go(l, i) > x) l++;
        ll tmp = go2(l, i);
        // cout << l << " " << i << endl;
        ll rem = x - go(l, i);
        if (l-1 >= 0) {
            assert(rem <= d[l-1]);
            tmp += rem * d[l-1] - (rem*(rem-1))/2;
        }
        ans = max(ans, tmp);
    }
    FOR (i, 0, n) {
        if (x <= d[i]) {
            ans = max(ans, x*d[i] - (x*(x-1))/2);
        }
    }
    cout << ans << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

