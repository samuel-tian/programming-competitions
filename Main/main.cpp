#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;
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
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	if (name == "")
        return;
    if (name == "input") {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
	else {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    ll operator()(ll x) const {
        return x ^ RANDOM;
    }
};

const int N = 200005;

int n;
vi adj[2*N];
int val[2*N];
int cnt = 0;

void update(vi& arr, int i, int v) {
    i++;
    while (i <= n) {
        arr[i] = arr[i] + v;
        i += i & (-i);
    }
}

int get(vi& arr, int i) {
    int ret = 0;
    i++;
    while (i > 0) {
        ret = ret + arr[i];
        i -= i & (-i);
    }
    return ret;
}

int query(vi& v, int i, int j) {
    return get(v, j) - get(v, i-1);
}

int read() {
    int a;
    cin >> a;
    if (a != 0) {
        val[cnt] = a;
        return cnt++;
    }
    else {
        int cur = cnt++;
        int l = read();
        int r = read();
        adj[cur].pb(l);
        adj[cur].pb(r);
        adj[l].pb(cur);
        adj[r].pb(cur);
        return cur;
    }
}

pair<vi, vi> dfs(int a, int p) {
    vi fenwick, vals;
    if (val[a] != 0) {
        fenwick = vi(N);
        vals = {val[a]};
        return mp(fenwick, vals);
    }
    pi p = {-1, -1};
    pair<vi, vi> fen_c;
    pair<vi, vi> val_c;
    TRAV (b, adj[a]) {
        if (b == p)
            continue;
        pair<vi, vi> tmp = dfs(b, a);
        if (p.f == -1) {
            p.f = b;
            fen_c.f = tmp.f;
            val_c.f = tmp.s;
        }
        else {
            p.s = b;
            fen_c.s = tmp.f;
            val_c.s = tmp.s;
        }
    }
    
    return mp(fenwick, vals);
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
