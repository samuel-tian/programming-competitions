/*
 * Bellman Ford Algorithm
 * ----------------------
 * 1) for n-1 times, perform relaxations on all the edges
 *      a) a relaxation for edge u-v is dist[v] = min(dist[v], dist[u] + weight)
 * 2) on the nth iteration, if edges are still being relaxed, then a negative cycle exists
 *
 * time complexity: O(E*V)
 */
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

int n, m;
vector<ppi> edges;
int d[N];

bool bellman_ford(int s = 0) {
    fill(d, d + n, INF);
    d[s] = 0;
    bool bad = false;
    FOR (j, 0, n) {
        TRAV (x, edges) {
            int u = x.f.f, v = x.f.s, w = x.s;
            if (d[u] != INF && d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (j == n-1) bad = true;
            }
        }
    }
    return bad;
}

int main() {
    setIO("input");
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        edges.pb(mp(mp(a-1, b-1), c));
    }
    bellman_ford();
}