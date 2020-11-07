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
#define eb emplace_back
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

const int N = 300005;

int n, x, y;
vi adj[N];
int par[N], par2[N];
vi cutoff;

void dfs(int a, int p) {
    par[a] = p;
    TRAV (b, adj[a]) {
        if (b == p)
            continue;
        dfs(b, a);
    }
}

int dfs2(int a, int p, int ind) {
    vi children;
    TRAV (b, adj[a]) {
        if (b == p)
            continue;
        if (b == cutoff[ind])
            continue;
        children.pb(dfs2(b, a, ind));
    }
    if (children.size()==0)
        return 0;
    sort(children.begin(), children.end(), greater<int>());
    FOR (i, 0, children.size()) {
        children[i] += (i+1);
    }
    int ret = -1;
    TRAV (i, children)
        ret = max(ret, i);
    return ret;
}

int solve(int ind) {
    int a = dfs2(x, x, ind);
    int b = dfs2(y, y, ind+1);
    return max(a, b);
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> x >> y;
    x--, y--;
    FOR (i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(x, x);
    int tmp = y;
    while (tmp != x) {
        cutoff.pb(tmp);
        tmp = par[tmp];
    }
    cutoff.pb(tmp);
    int ans;
    if (n <= 1000) {
        ans = INF;
        FOR (i, 0, cutoff.size()-1) {
            ans = min(ans, solve(i));
        }

    }
    else {
        ans = 0;
        int lo = 0, hi = cutoff.size()-2;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int l = (mid==0) ? INF : solve(mid-1);
            int r = (mid==cutoff.size()-2) ? INF : solve(mid+1);
            int m = solve(mid);
            // cout << l << " " << m << " " << r << '\n';
            if (l >= m && m <= r) {
                ans = m;
                break;
            }
            else if (l <= m && m <= r)
                hi = mid-1;
            else if (l >= m && m >= r)
                lo = mid+1;
        }
    }
    cout << ans << '\n';

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}


