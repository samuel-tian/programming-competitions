#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (int (i) = (a); i < (b); ++i)
#define FORd(i, a, b) for (int (i) = (a); i >= (b); --i)
#define TRAV(i, x) for (int (i) : (x))
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

const int MAXN = (int) 1e5 + 5;

int n;
vi adj[MAXN];
ll v[MAXN];
ll s[MAXN];

void dfs(int a, int par, ll sum) {
    if (s[a] == -1) {
        ll min_val = INF;
        TRAV (b, adj[a]) {
            if (b == par) continue;
            min_val = min(min_val, s[b]);
        }
        if (min_val == INF) min_val = sum;
        v[a] = min_val - sum;
        sum += v[a];
    }
    else {
        v[a] = s[a] - sum;
        sum += v[a];
    }
    TRAV (b, adj[a]) {
        if (b == par) continue;
        dfs(b, a, sum);
    }
}

int main() {
    setIO();
    cin >> n;
    FOR (i, 1, n) {
        int a;
        cin >> a;
        adj[i].pb(a-1);
        adj[a-1].pb(i);
    }
    FOR (i, 0, n) cin >> s[i];
    dfs(0, -1, 0);
    ll ret = 0;
    bool is_good = true;
    FOR (i, 0, n) { ret += v[i]; is_good = is_good && (v[i]>=0); }
    cout << ((is_good) ? ret : -1) << endl;
//    PRSP(v, n);
}