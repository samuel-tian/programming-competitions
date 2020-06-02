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
vi adj[N];
pair<ll, pair<ll, ll> > w[N];
pair<ll, ll> cur[N], goal[N];
int todo[N];

void dfs(int a, int p) {
    if (w[a].s.f != w[a].s.s) {
        if (w[a].s.f == 0) {
            cur[a].f = 1;
            cur[a].s = 0;
        }
        else {
            cur[a].f = 0;
            cur[a].s = 1;
        }
    }
    TRAV (b, adj[a]) {
        if (b == p) continue;
        w[b].f = min(w[b].f, w[a].f);
        dfs(b, a);
        /*cur[a].f += cur[b].f;
        cur[a].s += cur[b].s;
        goal[a].f += goal[b].f;
        goal[a].s += goal[b].s;*/
    }
}

ll dfs2(int a, int p) {
    ll ret = 0;
    // cout << a << " " << p << endl;
    TRAV (b, adj[a]) {
        if (b == p) continue;
        ret += dfs2(b, a);
        cur[a].f += cur[b].f;
        cur[a].s += cur[b].s;
    }
    ll cnt = 0;
    // updates
    ll v = min(cur[a].f, cur[a].s);
    cnt += (ll) w[a].f * v * 2;
    cur[a].f -= v; cur[a].s -= v;

    return ret + cnt;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n;
    FOR (i, 0, n) {
        ll a, b, c;
        cin >> a >> b >> c;
        w[i] = make_pair(a, make_pair(b, c));
    }
    FOR (i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0, -1);
    ll x = dfs2(0, -1);
    FOR (i, 0, n) {
        // cout << cur[i].f << " " << cur[i].s << " " << goal[i].f << " " << goal[i].s << endl;
    }
    if (cur[0].f != 0 || cur[0].s != 0) cout << -1 << endl;
    else {

        cout << x << endl;
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

