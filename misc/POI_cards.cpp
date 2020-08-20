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

struct node {
    bool uu, ud, du, dd;
    int lu, ld, ru, rd;
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
        if (l.lu == INF && r.lu == INF)
            return l;
        else if (l.lu == INF)
            return r;
        else if (r.lu == INF)
            return l;
        T ret = {};
        ret.lu = l.lu;
        ret.ld = l.ld;
        ret.ru = r.ru;
        ret.rd = r.rd;
        ret.uu = ((l.ru <= r.lu) ? (l.uu && r.uu) : 0) ||
            ((l.ru <= r.ld) ? (l.uu && r.du) : 0) ||
            ((l.rd <= r.lu) ? (l.ud && r.uu) : 0) ||
            ((l.rd <= r.ld) ? (l.ud && r.du) : 0);
        ret.ud = ((l.ru <= r.lu) ? (l.uu && r.ud) : 0) ||
            ((l.ru <= r.ld) ? (l.uu && r.dd) : 0) ||
            ((l.rd <= r.lu) ? (l.ud && r.ud) : 0) ||
            ((l.rd <= r.ld) ? (l.ud && r.dd) : 0);
        ret.du = ((l.ru <= r.lu) ? (l.du && r.uu) : 0) ||
            ((l.ru <= r.ld) ? (l.du && r.du) : 0) ||
            ((l.rd <= r.lu) ? (l.dd && r.uu) : 0) ||
            ((l.rd <= r.ld) ? (l.dd && r.du) : 0);
        ret.dd = ((l.ru <= r.lu) ? (l.du && r.ud) : 0) ||
            ((l.ru <= r.ld) ? (l.du && r.dd) : 0) ||
            ((l.rd <= r.lu) ? (l.dd && r.ud) : 0) ||
            ((l.rd <= r.ld) ? (l.dd && r.dd) : 0);
        return ret;
    }
    bool query(int i, int j) {
        T ret = queryUtil(0, 0, n-1, i, j);
        // cout << ret.uu << " " << ret.ud << " " << ret.du << " " << ret.dd << '\n';
        return ret.uu || ret.ud || ret.du || ret.dd;
    }
    T queryUtil(int node, int a, int b, int i, int j) {
        if (a >= i && b <= j)
            return seg[node];
        if (a > j || b < i)
            return {0, 0, 0, 0, INF, 0, 0, 0};
        int mid = (a + b) / 2;
        T l = queryUtil(2*node+1, a, mid, i, j);
        T r = queryUtil(2*node+2, mid+1, b, i, j);
        return combine(l, r);
    }
    void update(int i, int val1, int val2) {
        updateUtil(0, 0, n-1, i, val1, val2);
    }
    void updateUtil(int node, int a, int b, int i, int val1, int val2) {
        if (i < a || i > b)
            return;
        if (a == b)
            seg[node] = {1, 0, 0, 1, val1, val2, val1, val2};
        else {
            int mid = (a + b) / 2;
            updateUtil(2*node+1, a, mid, i, val1, val2);
            updateUtil(2*node+2, mid+1, b, i, val1, val2);
            seg[node] = combine(seg[2*node+1], seg[2*node+2]);
        }
    }
};

const int N = 200005;
const int M = 1000005;

int n, q;
pi cards[N];

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n;
    segtree<node> seg(n);
    FOR (i, 0, n) {
        int a, b;
        cin >> a >> b;
        cards[i] = mp(a, b);
        seg.update(i, a, b);
    }
    cin >> q;
    FOR (i, 0, q) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        pi tmp = cards[b];
        cards[b] = cards[a];
        cards[a] = tmp;
        seg.update(a, cards[a].f, cards[a].s);
        seg.update(b, cards[b].f, cards[b].s);
        cout << ((seg.query(0, n-1)) ? "TAK" : "NIE") << '\n';
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
