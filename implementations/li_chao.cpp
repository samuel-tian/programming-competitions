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
struct li_chao {
    struct L {
        T m, b;
        L() = default;
        L(T m, T b) { this->m = m, this->b = b; }
        T dot(L other) { return m * other.m + b * other.b; }
    };
    vector<L> tree;
    int n;
    li_chao() = default;
    li_chao(int n) {
        this->n = n;
        int sz = 4*n;
        tree.resize(sz);
        FOR (i, 0, sz) {
            tree[i] = L(0, INF);
        }
    }
    T f(L l, int x) { return l.dot(L(x, 1)); } // change f() for if you want a non-linear function
    T min(T a, T b) { return (a < b) ? a : b; }
    void add(int m, int x) { add_util(0, 0, n, L(m, x)); }
    void add_util(int node, int l, int r, L line) {
        int mid = (l + r) / 2;
        bool on_left = (f(line, l) < f(tree[node], l));
        bool on_right = (f(line, mid) < f(tree[node], mid));
        if (on_right) swap(tree[node], line);
        if (r - l <= 1) return;
        else if (on_left ^ on_right) add_util(2*node+1, l, mid, line);
        else add_util(2*node+2, mid, r, line);
    }
    T query(int x) { return query_util(0, 0, n-1, x); }
    T query_util(int node, int l, int r, int x) {
        int mid = (l + r) / 2;
        T ret = f(tree[node], x);
        if (r - l <= 1) ret = ret;
        else if (x < mid) ret = min(ret, query_util(2*node+1, l, mid, x));
        else ret = min(ret, query_util(2*node+2, mid, r, x));
        return ret;
    }
};

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    li_chao<int> tree(100);
    tree.add(-2, 1);
    tree.add(-1, 3);
    tree.add(0, 2);
    tree.add(1, 2);
    cout << tree.query(-3) << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
