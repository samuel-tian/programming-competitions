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

const int N = 1e5 + 100;

template <class T>
struct BIT {
	int n;
	vector<T> arr;
	BIT() {
		n = 0; arr = {};
	}
	BIT(int n) {
		this->n = n; arr.resize(n + 1);
	}
	void clear() { arr.clear(); }
	void update(int i, T v) {
		++i;
		while (i <= n) {
			arr[i] = (arr[i] + v);
			i += i & (-i);
		}
	}
	T get(int i) {
		T ret = 0; ++i;
		while (i > 0) {
			ret = (ret + arr[i]);
			i -= i & (-i);
		}
		return ret;
	}
	T query(int i, int j) { return (get(j) - get(i-1)); }
};

int n, q;
vi adj[N];
int ord[N], st[N], en[N];
ll sz[N];
int t = 0;
BIT<ll> abv(N), bel(N);
ordered_set<pi> colors[N];

void dfs(int a, int p) {
    ord[t] = a;
    st[a] = t++;
    sz[a] = 1;
    TRAV (b, adj[a]) {
        if (b != p) {
            dfs(b, a);
            sz[a] += sz[b];
        }
    }
    en[a] = t-1;
}

void update(int node, int v) {
    abv.update(st[node], v); abv.update(en[node]+1, -v);
    bel.update(st[node], v * sz[node]);
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("snowcow");
    cin >> n >> q;
    FOR (i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(0, -1);
    // PRSP(ord, n); PRSP(st, n); PRSP(en, n);
    FOR (i, 0, q) {
        int x; cin >> x;
        if (x == 1) {
            int a, b; cin >> a >> b;
            a--;
            int y = colors[b].order_of_key(mp(st[a], INF));
            if (y > 0 && en[colors[b].find_by_order(y-1)->s] >= en[a]) { // one of its ancestors is already colored
                continue;
            }
            while (y != colors[b].size()) {
                auto z = colors[b].find_by_order(y);
                if (en[z->s] > en[a]) break;
                update(z->s, -1);
                colors[b].erase(z);
            }
            colors[b].insert(mp(st[a], a));
            update(a, 1);
        }
        else {
            int a; cin >> a;
            a--;
            ll ans = sz[a] * abv.query(0, st[a]) + bel.query(st[a]+1, en[a]);
            cout << ans << endl;
        }
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

