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
const int LOGN = 20;
const int Q = 200005;

int q, n = 1;
vi adj[N];
int p[LOGN][N], dep[N];
pi diam = {0, 0};

int lca(int a, int b) {
    if (dep[a] > dep[b])
        swap(a, b);
    int dif = dep[b] - dep[a];
    FOR (i, 0, LOGN)
        if (dif & (1<<i))
            b = p[i][b];
    FORd (i, LOGN-1, 0) {
        if (p[i][a] == p[i][b])
            continue;
        a = p[i][a];
        b = p[i][b];
    }
    if (a != b)
        return p[0][a];
    else
        return a;
}

int dis(int a, int b) {
    int l = lca(a, b);
    return dep[a] + dep[b] - 2*dep[l];
}

void update(int i) {
    n++;
    if (i != -1) {
        i--;
        adj[i].pb(n-1);
        adj[n-1].pb(i);
        p[0][n-1] = i;
        dep[n-1] = dep[i] + 1;
    }
    FOR (i, 1, LOGN)
        p[i][n-1] = p[i-1][p[i-1][n-1]];
    int lat = dis(diam.f, diam.s);
    if (dis(diam.f, n-1) > lat)
        diam.s = n-1;
    else if (dis(diam.s, n-1) > lat)
        diam.f = n-1;
    cout << dis(diam.f, diam.s) << " ";
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> q;
    FOR (i, 0, q-1) {
        int a;
        cin >> a;
        update(a);
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}


