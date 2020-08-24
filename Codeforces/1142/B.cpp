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
const int M = 200005;
const int Q = 200005;
const int LOGN = 20;

int n, m, q;
int p[N], a[M];
vi loc[N];
int pre[LOGN][M], inv[N], ans[M];

int get(vi& vec, int v) {
    int lo = 0, hi = vec.size()-1;
    if (vec.empty() || vec[0] > v)
        return -1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (vec[mid] >= v)
            hi = mid - 1;
        else
            lo = mid;
    }
    return vec[lo];
}

int go(int a, int k) {
    FOR (i, 0, LOGN) {
        if (a == -1)
            break;
        if (k & (1<<i))
            a = pre[i][a];
    }
    return a;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> m >> q;
    FOR (i, 0, n) {
        cin >> p[i];
        p[i]--;
        inv[p[i]] = i;
    }
    FOR (i, 0, m) {
        cin >> a[i];
        a[i]--;
        loc[a[i]].pb(i);
    }
    FOR (i, 0, m) {
        int v = p[(inv[a[i]]-1+n) % n];
        pre[0][i] = get(loc[v], i);
    }
    FOR (i, 1, LOGN) {
        FOR (j, 0, m) {
            if (pre[i-1][j] == -1)
                pre[i][j] = -1;
            else
                pre[i][j] = pre[i-1][pre[i-1][j]];
        }
    }
    FOR (i, 0, m) {
        if (i == 0)
            ans[i] = go(i, n-1);
        else
            ans[i] = max(ans[i-1], go(i, n-1));
    }
    FOR (i, 0, q) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (ans[b] < a)
            cout << 0;
        else
            cout << 1;
        if (i == q-1)
            cout << '\n';
    }
    
    return 0;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

