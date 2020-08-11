#include <iostream>
#include <fstream>
#include <climits>
#include <algorithm>
#include <vector>
#include <utility>
#include <chrono>
#include <random>

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
	int pre, suf, unf;
	int len;
    friend ostream& operator << (ostream& os, node n) {
        os << n.pre << " " << n.suf << " " << n.unf;
        return os;
    }
};

template<typename T>
struct seg {
	int n;
	vector<T> segtree;
	vector<int> lazy;
    seg() = default;
    seg(int n) {
        this->n = n;
        int sz = 4 * n;
        segtree.resize(sz);
        lazy.resize(sz);
        FOR (i, 0, sz)
            segtree[i] = {};
        FOR (i, 0, sz)
            lazy[i] = -1;
    }
    void propagate(int node, int a, int b) {
        if (lazy[node] != -1) {
            int l = b - a + 1;
            int v = lazy[node];
            segtree[node] = {l*v, l*v, l*v, l};
            if (a != b) {
                lazy[2*node+1] = lazy[node];
                lazy[2*node+2] = lazy[node];
            }
            lazy[node] = -1;
        }
    }
    T combine(T l, T r) {
        T ret = {};
        // set prefix
        if (l.pre == l.len)
            ret.pre = l.pre + r.pre;
        else
            ret.pre = l.pre;
        // set suffix
        if (r.suf == r.len)
            ret.suf = l.suf + r.suf;
        else
            ret.suf = r.suf;
        // set unfilled
        ret.unf = max3(l.unf, r.unf, l.suf + r.pre);

        ret.len = l.len + r.len;
        return ret;
    }
    void init(int node, int a, int b) {
        int mid = (a + b) / 2;
        if (a != b) {
            init(2*node+1, a, mid);
            init(2*node+2, mid+1, b);
            segtree[node] = combine(segtree[2*node+1], segtree[2*node+2]);
        }
        else {
            segtree[node] = {1, 1, 1, 1};
        }
    }
    T query(int i, int j) {
        return queryUtil(0, 0, n-1, i, j);
    }
    T queryUtil(int node, int a, int b, int i, int j) {
        propagate(node, a, b);
        if (a > b || a > j || b < i)
            return {};
        if (a >= i && b <= j)
            return segtree[node];
        int mid = (a + b) / 2;
        T l = queryUtil(2*node+1, a, mid, i, j);
        T r = queryUtil(2*node+2, mid+1, b, i, j);
        return combine(l, r);
    }
    void update(int i, int j, int val) {
        updateUtil(0, 0, n-1, i, j, val);
    }
    void updateUtil(int node, int a, int b, int i, int j, int val) {
        propagate(node, a, b);
        if (a > b || a > j || b < i)
            return;
        if (a >= i && b <= j) {
            lazy[node] = val;
            propagate(node, a, b);
            return;
        }
        int mid = (a + b) / 2;
        updateUtil(2*node+1, a, mid, i, j, val);
        updateUtil(2*node+2, mid+1, b, i, j, val);
        segtree[node] = combine(segtree[2*node+1], segtree[2*node+2]);
    }
    int walk(int node, int a, int b, int len) {
        int l = 2*node+1, r = 2*node+2;
        propagate(node, a, b);
        propagate(l, a, (a+b)/2);
        propagate(r, (a+b)/2+1, b);
        if (segtree[node].unf < len)
            return -1;
        else {
            int mid = (a + b) / 2;
            // completely contained within left segment
            if (segtree[l].unf >= len)
                return walk(l, a, mid, len);
            // crosses the boundary
            else if (segtree[l].suf + segtree[r].pre >= len)
                return a + segtree[l].len - segtree[l].suf;
            // completely contained within right segment
            else
                return walk(r, mid+1, b, len);
        }
    }
    void print() {
        FOR (i, 0, n) {
            cout << i << " " << this->query(i, i) << '\n';
            if (i == n-1)
                cout << '\n';
        }
    }
};

const int N = 500005;
const int M = 300005;

int n, m;

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("seating");
    cin >> n >> m;
    seg<node> segtree(n);
    segtree.update(0, n-1, 1);
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        char c;
        cin >> c;
        if (c == 'A') {
            int a;
            cin >> a;
            int pos = segtree.walk(0, 0, n-1, a);
            if (pos == -1) {
                cnt++;
                // cout << "bad" << '\n';
            }
            else {
                segtree.update(pos, pos + a - 1, 0);
                // cout << "good" << '\n';
            }
        }
        else {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            segtree.update(a, b, 1);
        }
    }
    cout << cnt << '\n';

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

