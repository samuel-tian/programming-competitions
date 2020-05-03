#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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

struct segtree {
    int n;
    vpi tree;
    segtree() {
        this->n = 1; int sz = this->n * 4;
        tree.resize(sz);
        fill(tree.begin(), tree.end(), mp(INF, -1));
    }
    segtree(int n) {
        this->n = n; int sz = 4 * this->n;
        tree.resize(sz);
        fill(tree.begin(), tree.end(), mp(INF, -1));
    }
    pi merge(pi l, pi r) {
        int x = 0, y = 0;
        pi ret = mp(0, 0);
        FOR (t, 0, 2) {
            int lv = (x == 0) ? l.f : l.s;
            int rv = (y == 0) ? r.f : r.s;
            if (lv < rv) {
                if (t == 0) ret.f = lv;
                else ret.s = lv;
                x++;
            }
            else {
                if (t==0) ret.f = rv;
                else ret.s = rv;
                y++;
            }
        }
        return ret;
    }
    pi query(int i, int j) { return queryUtil(0, 0, n-1, i, j); }
    pi queryUtil(int node, int a, int b, int i, int j) {
        if (a >= i && b <= j) return tree[node];
        if (a > j || b < i) return mp(INF, INF);
        int mid = (a + b) / 2;
        pi l = queryUtil(2*node+1, a, mid, i, j);
        pi r = queryUtil(2*node+2, mid+1, b, i, j);
        return merge(l, r);
    }
    void update(int i, int v) { updateUtil(0, 0, n-1, i, v); }
    void updateUtil(int node, int a, int b, int i, int v) {
        if (i < a || i > b) return;
        if (a == b) tree[node] = mp(v, INF);
        else {
            int mid = (a + b) / 2;
            updateUtil(2*node+1, a, mid, i, v);
            updateUtil(2*node+2, mid+1, b, i, v);
            tree[node] = merge(tree[2*node+1], tree[2*node+2]);
        }
    }
};

int n, m;
vector<segtree> seg;

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

    setIO();
    cin >> n >> m;
    vi a(n);
    seg.resize(10);
    FOR (i, 0, 10) {
        seg[i] = segtree(n);
    }
    FOR (i, 0, n) cin >> a[i];
    FOR (i, 0, n) {
        int ac = a[i];
        FOR (j, 0, 10) {
            int v = ac % 10;
            ac /= 10;
            if (v == 0) continue;
            seg[j].update(i, a[i]);
        }
    }
    int q, l, r;
    FOR (i, 0, m) {
        cin >> q >> l >> r;
        if (q == 1) {
            --l;
            int x = r;
            FOR (j, 0, 10) {
                int v = x % 10;
                x /= 10;
                if (v == 0) seg[j].update(l, INF);
                else seg[j].update(l, r);
            }
        }
        else {
            --l, --r;
            int ans = INF;
            FOR (j, 0, 10) {
                pi f = seg[j].query(l, r);
                if (f.f == INF || f.s == INF) continue;
                ans = min(ans, f.f + f.s);
            }
            cout << ((ans==INF) ? -1 : ans) << endl;
        }
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
