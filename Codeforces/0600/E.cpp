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

const int N = 100005;

int n;
ll color[N];
vi adj[N];
unordered_map<ll, int> col_freq[N];
unordered_map<int, ll> col_sum[N];
int max_freq[N];
ll ans[N];

void dfs(int a, int p) {
    col_freq[a][color[a]]++;
    col_sum[a][1] += color[a];
    max_freq[a] = 1;
    TRAV (b, adj[a]) {
        if (b == p)
            continue;
        dfs(b, a);
        if (col_freq[a].size() < col_freq[b].size()) {
            swap(col_freq[a], col_freq[b]);
            swap(col_sum[a], col_sum[b]);
            swap(max_freq[a], max_freq[b]);
        }
        TRAV (v, col_freq[b]) {
            col_sum[a][col_freq[a][v.f]] -= v.f;
            col_sum[a][col_freq[a][v.f]+v.s] += v.f;
            col_freq[a][v.f] += v.s;
            max_freq[a] = max(max_freq[a], col_freq[a][v.f]);
        }
        col_freq[b].clear();
        col_sum[b].clear();
    }
    ans[a] = col_sum[a][max_freq[a]];
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n;
    FOR (i, 0, n)
        cin >> color[i];
    FOR (i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0, -1);
    FOR (i, 0, n)
        cout << ans[i] << " ";

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
