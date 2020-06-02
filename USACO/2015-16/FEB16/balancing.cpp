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

const int N = 1<<17;

template<class T>
struct segtree {
    int n;
    vector<T> t;
    segtree() {
        this->n = N;
        t.resize(2*N);
    }
    T comb(T l, T r) {
        return l + r;
    }
    void set(int i, T v) {
        t[i + n] += v;
    }
    void build() {
        FORd (i, n-1, 1) {
            t[i] = comb(t[i<<1], t[i<<1|1]);
        }
    }
    void update(int i, T v) {
        i += n;
        t[i] += v;
        while (i != 1) {
            i >>= 1;
            t[i] = comb(t[i<<1], t[i<<1|1]);
        }
    }
    T query(int l, int r) {
        T resl = 0, resr = 0;
        l += n, r += n+1;
        while (l < r) {
            if (l & 1) resl = comb(resl, t[l++]);
            if (r & 1) resr = comb(t[--r], resr);
            l >>= 1, r >>= 1;
        }
        return comb(resl, resr);
    }
};

int n;
pi coor[N];
vi x[N];

segtree<int> left_seg, right_seg;

int solve(int node, int q1, int q2, int q3, int q4) {
    /*
     * q2 | q1
     * -------
     * q3 | q4
     */
    vector<int> &t1 = left_seg.t, &t2 = right_seg.t;
    if (node > N) {
        // cout << q1 << " " << q2 << " " << q3 << " " << q4 << endl;
        int tmp = max(max(q1 + t2[node], q2 + t1[node]), max(q3, q4));
        int tmp2 = max(max(q1, q2), max(q3 + t1[node], q4 + t2[node]));
        return min(tmp, tmp2);
    }

    int l = 2*node, r = 2*node+1;
    // cout << "comp: " << max(q3 + t1[l], q4 + t2[l]) << " " << max(q1 + t2[r], q2 + t1[r]) << endl;
    if (max(q3 + t1[l], q4 + t2[l]) < max(q1 + t2[r], q2 + t1[r])) {
        // moving the line up gets a smaller max than moving the line down
        return solve(r, q1, q2, q3 + t1[l], q4 + t2[l]);
    }
    else {
        return solve(l, q1 + t2[r], q2 + t1[r], q3, q4);
    }
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("balancing");
    cin >> n;
    FOR (i, 0, n) cin >> coor[i].f >> coor[i].s;
    ordered_set<int> comp;
    FOR (i, 0, n) comp.insert(coor[i].s);
    FOR (i, 0, n) coor[i].s = comp.order_of_key(coor[i].s);
    comp.clear();
    FOR (i, 0, n) comp.insert(coor[i].f);
    FOR (i, 0, n) coor[i].f = comp.order_of_key(coor[i].f);
    FOR (i, 0, n) {
        x[coor[i].f].pb(coor[i].s);
        right_seg.update(coor[i].s, 1);
        // cout << "(" << coor[i].f << ", " << coor[i].s << ")" << endl;
    }
    int ans = INF;
    FOR (i, 0, comp.size()+1) {
        // cout << i << ": ";
        ans = min(ans, solve(1, 0, 0, 0, 0));
        /*cout << "left: ";
        TRAV (x, left_seg.t) cout << x << " "; cout << endl;
        cout << "right: ";
        TRAV (x, right_seg.t) cout << x << " "; cout << endl;*/
        if (i != comp.size()) {
            TRAV (j, x[i]) {
                // cout << "switch: (" << i << ", " << j << ")" << endl;
                right_seg.update(j, -1);
                left_seg.update(j, 1);
            }
        }
    }
    cout << ans << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

