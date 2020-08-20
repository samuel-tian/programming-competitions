#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <utility>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;

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
const int LOGN = 19;
const int Q = 200005;

int n, q;
vi adj[N];
int dep[N];
int par[LOGN][N];

void dfs(int a, int p) {
    if (a == 0)
        dep[a] = 0;
    TRAV (b, adj[a]) {
        if (b == p)
            continue;
        dep[b] = dep[a] + 1;
        dfs(b, a);
    }
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> q;
    FOR (i, 1, n) {
        int a;
        cin >> a;
        a--;
        adj[a].pb(i);
        adj[i].pb(a);
        par[0][i] = a;
    }
    par[0][0] = 0;
    FOR (i, 1, LOGN) {
        FOR (j, 0, n) {
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }
    dfs(0, -1);
    FOR (i, 0, q) {
        int x, k;
        cin >> x >> k;
        x--;
        if (k > dep[x]) {
            cout << -1 << '\n';
            continue;
        }
        int ret = x;
        FORd (j, LOGN-1, 0) {
            if (k & (1<<j))
                ret = par[j][ret];
        }
        cout << ret+1 << '\n';
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

