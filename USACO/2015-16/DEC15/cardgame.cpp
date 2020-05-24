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

template<class T>
struct segtree {
    int n;
    vector<T> t;
    segtree() = default;
    segtree(int n) {
        this->n = n;
        int sz = 2*n;
        t.resize(sz);
    }
    T comb(T l, T r) { // covers, coverables, points
        int ad = min(l.f.s, r.f.f);
        int covers = l.f.f + r.f.f - ad;
        int coverables = l.f.s + r.f.s - ad;
        int points = l.s + r.s + ad;
        return mppi(covers, coverables, points);
    }
    void set(int i, T v) {
        t[i + n] = v;
    }
    void build() {
        FORd (i, n-1, 1) {
            t[i] = comb(t[i<<1], t[i<<1|1]);
        }
    }
    void update(int p, T v) {
        p += n;
        t[p] = v;
        while (p != 1) {
            p >>= 1;
            t[p] = comb(t[p<<1], t[p<<1|1]);
        }
    }
    T query(int l, int r) {
        T resl = mppi(0, 0, 0), resr = mppi(0, 0, 0);
        l += n, r += n+1;
        while (l < r) {
            if (l & 1) resl = comb(resl, t[l++]);
            if (r & 1) resr = comb(t[--r], resr);
            l >>= 1, r >>= 1;
        }
        return comb(resl, resr);
    }
    void clear() {
        fill(t.begin(), t.end(), mppi(0, 0, 0));
    }
};

const int N = 50005;

int n;
vi bessie, elsie;
bool used[2*N];
int pre[N+1], suf[N+1];

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n;
    elsie.resize(n);
    FOR (i, 0, n) {
        cin >> elsie[i];
        elsie[i]--;
        used[elsie[i]] = true;
    }
    FORd (i, 2*n-1, 0) {
        if (!used[i]) {
            bessie.pb(i);
        }
    }
    segtree<ppi> seg = segtree<ppi>(2*n);
    FOR (i, 0, n) {
        seg.update(bessie[i], mppi(1, 0, 0));
        seg.update(elsie[i], mppi(0, 1, 0));
        pre[i+1] = seg.query(0, 2*n-1).s;
    }
    seg.clear();
    FORd(i, n-1, 0) {
        seg.update(bessie[i], mppi(0, 1, 0));
        seg.update(elsie[i], mppi(1, 0, 0));
        suf[i] = seg.query(0, 2*n-1).s;
    }
    int ret = 0;
    FOR (i, 0, n+1) {
        ret = max(ret, pre[i] + suf[i]);
    }
    cout << ret << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
