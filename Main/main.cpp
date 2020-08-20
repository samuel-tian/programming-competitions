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
const int Q = 200005;
const int LOGN = 20;

int n, q;
int nex[N], tnex[LOGN][N]; // successor, successor in tree
vi adj[N];
int suc[LOGN][N];
int comp[N], tr[N], dep[N], rn[N], cycsz[N]; // component label, tree label, depth in tree, root number, cycle size
bool rt[N], vis[N]; // is root, visited

void dfs(int a, int p, int c, int t) {
    if (rt[a])
        dep[a] = 0;
    vis[a] = true;
    comp[a] = c;
    tr[a] = t;
    TRAV (b, adj[a]) {
        if (b == p || rt[b])
            continue;
        dep[b] = dep[a] + 1;
        dfs(b, a, c, t);
    }
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> q;
    FOR (i, 0, n) {
        cin >> nex[i];
        nex[i]--;
        tnex[0][i] = nex[i];
        adj[nex[i]].pb(i);
    }
    int c = 0;
    FOR (i, 0, n) {
        if (vis[i])
            continue;
        int cur = i;
        while (!vis[cur]) {
            vis[cur] = true;
            cur = nex[cur];
        }
        vi roots;
        while (roots.empty() || cur != roots[0]) {
            rt[cur] = true;
            rn[cur] = roots.size();
            tnex[0][cur] = cur;
            roots.pb(cur);
            cur = nex[cur];
        }
        FOR (i, 0, roots.size()) {
            cycsz[roots[i]] = roots.size();
            dfs(roots[i], -1, c, roots[i]);
        }
        c++;
    }
    FOR (i, 1, LOGN) {
        FOR (j, 0, n) {
            tnex[i][j] = tnex[i-1][tnex[i-1][j]];
        }
    }
    FOR (i, 0, q) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int ans = 0;
        if (comp[a] != comp[b])
            ans = -1;
        else {
            if (tr[a] == tr[b]) { // same tree
                if (dep[a] < dep[b])
                    ans = - 1;
                else {
                    int dif = dep[a] - dep[b];
                    FOR (j, 0, LOGN) {
                        if (dif & (1<<j)) {
                            a = tnex[j][a];
                        }
                    }
                    if (a == b)
                        ans = dif;
                    else
                        ans = -1;
                }
            }
            else {
                if (!rt[b])
                    ans = -1;
                else {
                    int art = tr[a];
                    ans = dep[a] + (rn[b] - rn[art] + cycsz[art]) % cycsz[art];
                }
            }
        }
        cout << ans << '\n';
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
