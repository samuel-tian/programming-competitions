#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;

const int MAXN = 505;
const int INF = INT_MAX;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name == "input") {
        freopen("input.txt","r",stdin);
    }
    else if (name == "stdio") {

    }
    else {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

int f;
int n, m, w;
vector<ppi> edges;
int d[MAXN];

int main() {
    setIO("stdio");
    cin >> f;
    FOR (i, 0, f) {
        cin >> n >> m >> w;
        while (!edges.empty()) edges.pop_back();
        int a, b, c;
        FOR (j, 0, m) {
            cin >> a >> b >> c;
            edges.pb(mp(mp(a-1, b-1), c));
            edges.pb(mp(mp(b-1, a-1), c));
        }
        FOR (j, 0, w) {
            cin >> a >> b >> c;
            edges.pb(mp(mp(a-1, b-1), -1 * c));
        }
        FOR (j, 0, n) {
            d[j] = INF;
        }
        d[0] = 0;
        bool negativeCycle = false;
        FOR (k, 0, n) {
            FOR (j, 0, edges.size()) {
                int u = edges[j].f.f; int v = edges[j].f.s;
                int w = edges[j].s;
                if (d[u] != INF && d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    if (k == n-1) {
                        negativeCycle = true;
                    }
                }
            }
        }
//        PRSP(j, n, d);
        cout << (negativeCycle ? "YES" : "NO") << endl;
    }
}