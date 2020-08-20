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
typedef pair<long long, long long> pll;
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

const int N = 1000005;
const int LOGN = 21;

ll n, k, m;
ll p[N];
int nex[LOGN][N];
int sz[N], vis[N];

int go(int a, int k) {
    FOR (i, 0, LOGN)
        if (k & (1<<i))
            a = nex[i][a];
    return a;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> k >> m;
    FOR (i, 0, n)
        cin >> p[i];
    pll rang = {0, k};
    FOR (i, 0, n) {
        while (rang.s+1<n && abs(p[i] - p[rang.s+1])<abs(p[i] - p[rang.f]))
            rang = {rang.f + 1, rang.s + 1};
        if (abs(p[i] - p[rang.f]) >= abs(p[i] - p[rang.s]))
            nex[0][i] = rang.f;
        else
            nex[0][i] = rang.s;
    }
    FOR (i, 1, LOGN)
        FOR (j, 0, n)
            nex[i][j] = nex[i-1][nex[i-1][j]];
    vi roots;
    FOR (i, 0, n) {
        if (vis[i])
            continue;
        int cur = i;
        while (!vis[cur]) {
            vis[cur] = i+1;
            cur = nex[0][cur];
        }
        if (vis[cur] != i+1)
            continue;
        while (roots.empty() || cur != roots[0]) {
            roots.pb(cur);
            cur = nex[0][cur];
        }
        FOR (i, 0, roots.size()) {
            sz[roots[i]] = roots.size();
        }
        roots.clear();
    }
    FOR (i, 0, n) {
        int ans = i;
        if (m <= n)
            ans = go(ans, m);
        else {
            ans = go(ans, n);
            ans = go(ans, (m - n) % sz[ans]);
        }
        cout << ans+1;
        if (i != n-1)
            cout << " ";
        else
            cout << '\n';
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
