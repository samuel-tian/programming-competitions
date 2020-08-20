#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <utility>
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

const int N = 100005;

int n, q;
pi check[N];

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
            seg[i] = 0;
    }
    T combine(T l, T r) {
        return l + r;
    }
    T query(int i, int j) {
        return queryUtil(0, 0, n-1, i, j);
    }
    T queryUtil(int node, int a, int b, int i, int j) {
        if (a >= i && b <= j)
            return seg[node];
        if (a > j || b < i)
            return 0;
        int mid = (a + b) / 2;
        T l = queryUtil(2*node+1, a, mid, i, j);
        T r = queryUtil(2*node+2, mid+1, b, i, j);
        return combine(l, r);
    }
    void update(int i, int val) {
        updateUtil(0, 0, n-1, i, val);
    }
    void updateUtil(int node, int a, int b, int i, int val) {
        if (i < a || i > b)
            return;
        if (a == b)
            seg[node] = val;
        else {
            int mid = (a + b) / 2;
            updateUtil(2*node+1, a, mid, i, val);
            updateUtil(2*node+2, mid+1, b, i, val);
            seg[node] = combine(seg[2*node+1], seg[2*node+2]);
        }
    }
};

template<typename T>
struct segtree2 {
    int n;
    vector<T> seg;
    segtree2() = default;
    segtree2(int n) {
        this->n = n;
        int sz = 4 * n;
        seg.resize(sz);
        FOR (i, 0, sz)
            seg[i] = 0;
    }
    T combine(T l, T r) {
        return min(l, r);
    }
    T query(int i, int j) {
        return queryUtil(0, 0, n-1, i, j);
    }
    T queryUtil(int node, int a, int b, int i, int j) {
        if (a >= i && b <= j)
            return seg[node];
        if (a > j || b < i)
            return 0;
        int mid = (a + b) / 2;
        T l = queryUtil(2*node+1, a, mid, i, j);
        T r = queryUtil(2*node+2, mid+1, b, i, j);
        return combine(l, r);
    }
    void update(int i, int val) {
        updateUtil(0, 0, n-1, i, val);
    }
    void updateUtil(int node, int a, int b, int i, int val) {
        if (i < a || i > b)
            return;
        if (a == b)
            seg[node] = val;
        else {
            int mid = (a + b) / 2;
            updateUtil(2*node+1, a, mid, i, val);
            updateUtil(2*node+2, mid+1, b, i, val);
            seg[node] = combine(seg[2*node+1], seg[2*node+2]);
        }
    }
};

int dist(pi a, pi b) {
    return abs(a.f-b.f) + abs(a.s-b.s);
}

int shortcut(pi a, pi b, pi c) {
    return dist(a, c) - (dist(a, b) + dist(b, c));
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("marathon");
    cin >> n >> q;
    FOR (i, 0, n) {
        int a, b;
        cin >> a >> b;
        check[i] = mp(a, b);
    }
    segtree<int> sumseg(n);
    segtree2<int> minseg(n);
    FOR (i, 0, n-1) {
        int d = dist(check[i], check[i+1]);
        sumseg.update(i, d);
    }
    FOR (i, 1, n-1) {
        int d = shortcut(check[i-1], check[i], check[i+1]);
        minseg.update(i, d);
    }
    FOR (i, 0, q) {
        char c;
        cin >> c;
        if (c == 'Q') {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            int s = (b-1 < a) ? 0 : sumseg.query(a, b-1);
            int m = (b-1 < a+1) ? 0 : minseg.query(a+1, b-1);
            cout << s + m << '\n';
        }
        else {
            int a, x, y;
            cin >> a >> x >> y;
            a--;
            check[a] = mp(x, y);
            if (a-1 >= 0)
                sumseg.update(a-1, dist(check[a-1], check[a]));
            if (a+1 < n)
                sumseg.update(a, dist(check[a], check[a+1]));
            if (a-2 >= 0)
                minseg.update(a-1, shortcut(check[a-2], check[a-1], check[a]));
            if (a-1 >= 0 && a+1 < n)
                minseg.update(a, shortcut(check[a-1], check[a], check[a+1]));
            if (a+2 < n)
                minseg.update(a+1, shortcut(check[a], check[a+1], check[a+2]));
        }
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

