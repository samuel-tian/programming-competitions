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

const int N = 40005;

struct segtree {
    int n;
    vector<ll> seg[4];
    segtree() = default;
    segtree(int n) {
        this->n = n;
        int sz = 4*n;
        FOR (i, 0, 4) seg[i].resize(sz);
        FOR (i, 0, 4) FOR (j, 0, sz) seg[i][j] = 0;
    }
    ll query() {
        ll ret = 0;
        FOR (i, 0, 4) {
            ret = max(ret, seg[i][0]);
            // cout << seg[i][0] << ", ";
        }
        // cout << endl;
        return ret;
    }
    void update(int i, ll v) { update_util(0, 0, n, i, v); }
    void update_util(int node, int a, int b, int i, ll v) {
        if (i > b || i < a) return;
        if (a == b) { seg[0][node] = v; }
        else {
            int mid = (a + b) / 2;
            int l = 2*node+1, r = 2*node+2;
            update_util(2*node+1, a, mid, i, v);
            update_util(2*node+2, mid+1, b, i, v);
            seg[0][node] = max3(seg[0][l] + seg[2][r], seg[1][l] + seg[0][r], seg[1][l] + seg[2][r]);
            seg[1][node] = max3(seg[0][l] + seg[3][r], seg[1][l] + seg[3][r], seg[1][l] + seg[1][r]);
            seg[2][node] = max3(seg[3][l] + seg[0][r], seg[3][l] + seg[2][r], seg[2][l] + seg[2][r]);
            seg[3][node] = max3(seg[3][l] + seg[3][r], seg[3][l] + seg[1][r], seg[2][l] + seg[3][r]);
        }
    }
};

int n, d;
segtree seg;

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> d;
    seg = segtree(n);
    FOR (i, 0, n) {
        int a; cin >> a;
        seg.update(i, a);
    }
    ll ret = 0;
    FOR (i, 0, d) {
        int a, b; cin >> a >> b;
        seg.update(--a, b);
        ll x = seg.query();
        ret += x;
    }
    cout << ret << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

