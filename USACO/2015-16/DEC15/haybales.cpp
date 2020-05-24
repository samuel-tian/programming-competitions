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
const int Q = 100005;

struct segtree {
    int n;
    vll sum_seg, min_seg;
    vll lazy;
    segtree() = default;
    segtree(int n) {
        int sz = 4 * n;
        this->n = n;
        sum_seg.resize(sz); min_seg.resize(sz); lazy.resize(sz);
    }
    void prop(int node, int a, int b) {
        if (lazy[node] != 0) {
            sum_seg[node] += lazy[node] * (b - a + 1);
            min_seg[node] += lazy[node];
            if (a != b) {
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    pair<ll, ll> query(int i, int j) { return query_util(0, 0, n-1, i, j); }
    pair<ll, ll> query_util(int node, int a, int b, int i, int j) {
        prop(node, a, b);
        if (a > b || a > j || b < i) return mp(0, LLONG_MAX);
        if (a >= i && b <= j) return mp(sum_seg[node], min_seg[node]);
        int mid = (a + b) / 2;
        pair<ll, ll> l = query_util(2*node+1, a, mid, i, j);
        pair<ll, ll> r = query_util(2*node+2, mid+1, b, i, j);
        return mp(l.f + r.f, min(l.s, r.s));
    }
    void update(int i, int j, ll v) { return update_util(0, 0, n-1, i, j, v); }
    void update_util(int node, int a, int b, int i, int j, ll v) {
        prop(node, a, b);
        if (a > b || a > j || b < i) return;
        if (a >= i && b <= j) {
            sum_seg[node] += v * (b - a + 1);
            min_seg[node] += v;
            if (a != b) {
                lazy[2*node+1] += v;
                lazy[2*node+2] += v;
            }
            return;
        }
        int mid = (a + b) / 2;
        update_util(2*node+1, a, mid, i, j, v);
        update_util(2*node+2, mid+1, b, i, j, v);
        sum_seg[node] = sum_seg[2*node+1] + sum_seg[2*node+2];
        min_seg[node] = min(min_seg[2*node+1], min_seg[2*node+2]);
    }
};

int n, q;
segtree seg;

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("haybales");
    int n, m;
    cin >> n >> m;
    seg = segtree(n);
    FOR (i, 0, n) {
        int a; cin >> a;
        seg.update(i, i, a);
    }
    FOR (i, 0, m) {
        char c;
        int a, b, v;
        cin >> c;
        if (c == 'M' || c == 'S') {
            cin >> a >> b;
            pair<ll, ll> q = seg.query(--a, --b);
            cout << ((c == 'M') ? q.s : q.f) << endl;
        }
        else if (c == 'P') {
            cin >> a >> b >> v;
            seg.update(--a, --b, v);
        }
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
