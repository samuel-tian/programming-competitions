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

const int N = 200005;

int n;
ll k;
vector<pair<int, ll> > adj[N];
bool del[N];
int sz[N];

void dfs(int a, int p) {
    sz[a] = 1;
    TRAV (b, adj[a]) {
        int to = b.f;
        if (to == p || del[to]) continue;
        dfs(to, a);
        sz[a] += sz[to];
    }
}

int dfs2(int a) {
    dfs(a, -1);
    int hi = sz[a] / 2;
    int p = -1;
    while (true) {
        bool found = false;
        TRAV (b, adj[a]) {
            int to = b.f;
            if (del[to] || to == p || sz[to] <= hi) continue;
            found = true;
            p = a; a = to; break;
        }
        if (!found) return a;
    }
}

void go(int a, int p, ll v, int d, multiset<pair<ll, int> >& s) {
    TRAV (b, adj[a]) {
        if (b.f == p || del[b.f]) continue;
        go(b.f, a, v + b.s, d + 1, s);
    }
    s.insert(mp(v, d));
}

multiset<pair<ll, int> > tot, child;
int ans = INF;

void decomp(int a) {
    int c = dfs2(a);
    // cerr << "centroid: " << c << endl;
    tot.clear();
    go(c, -1, 0, 0, tot);
    del[c] = true;
    /*cerr << "tot: "; TRAV (x, tot) {
        cerr << x.f << " ";
    } cerr << endl;*/
    TRAV (b, adj[c]) {
        int to = b.f;
        if (del[to]) continue;
        child.clear();
        go(to, a, b.s, 1, child);
        TRAV (x, child) {
            auto iter = tot.find(x);
            // cerr << (*iter).f << " " << (*iter).s << endl;
            assert(iter != tot.end());
            tot.erase(iter);
        }
        TRAV (x, child) {
            auto iter = tot.upper_bound(mp(k - x.f, -1));
            if (iter == tot.end() || (*iter).f != k - x.f) continue;
            ans = min(ans, x.s + (*iter).s);
        }
        TRAV (x, child) {
            tot.insert(x);
        }
    }
    TRAV (b, adj[c]) {
        int to = b.f;
        if (del[to]) continue;
        decomp(to);
    }
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("input");
    cin >> n >> k;
    FOR (i, 0, n-1) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    decomp(0);
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}


