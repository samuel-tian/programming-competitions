#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <climits>
#include <math.h>
#include <random>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
 
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
 
struct node {
    ll maxs, pre, suf;
    ll sum;
    friend ostream& operator << (ostream& os, node n) {
        os << n.maxs << " " << n.pre << " " << n.suf << " " << n.sum;
        return os;
    }
};
 
template<typename T>
struct segtree {
    int n;
    vector<T> seg;
    segtree() = default;
    segtree(int n) {
        this->n = n;
        int sz = 4 * n;
        seg.resize(sz);
        FOR (i, 0, sz)
            seg[i] = {};
    }
    T combine(T l, T r) {
        T ret = {};
        ret.pre = max(l.pre, l.sum + r.pre);
        ret.suf = max(r.suf, l.suf + r.sum);
        ret.maxs = max3(l.maxs, r.maxs, l.suf + r.pre);
        ret.sum = l.sum + r.sum;
        return ret;
    }
    void update(int i, ll v) {
        updateUtil(0, 0, n-1, i, v);
    }
    void updateUtil(int node, int a, int b, int i, ll v) {
        if (i < a || i > b)
            return;
        if (a == b) {
            ll v2 = max(v, 0LL);
            seg[node] = {v2, v2, v2, v};
        }
        else {
            int mid = (a + b) / 2;
            updateUtil(2*node+1, a, mid, i, v);
            updateUtil(2*node+2, mid+1, b, i, v);
            seg[node] = combine(seg[2*node+1], seg[2*node+2]);
        }
    }
    T query(int i, int j) {
        return queryUtil(0, 0, n-1, i, j);
    }
    T queryUtil(int node, int a, int b, int i, int j) {
        if (a >= i && b <= j)
            return seg[node];
        if (a > j || b < i)
            return {};
        int mid = (a + b) / 2;
        T l = queryUtil(2*node+1, a, mid, i, j);
        T r = queryUtil(2*node+2, mid+1, b, i, j);
        return combine(l, r);
    }
};
 
const int N = 200005;
const int M = 200005;
 
int n, m;
 
int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();
 
	setIO();
    cin >> n >> m;
    segtree<node> seg(n);
    FOR (i, 0, n) {
        ll x;
        cin >> x;
        seg.update(i, x);
    }
    FOR (i, 0, m) {
        ll j, v;
        cin >> j >> v;
        j--;
        seg.update(j, v);
        cout << (seg.query(0, n-1)).maxs << '\n';
        // cout << seg.query(0, n-1) << '\n';
    }
 
	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
