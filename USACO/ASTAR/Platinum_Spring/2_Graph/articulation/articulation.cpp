#include <bits/stdc++.h>

using namespace std;

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

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))

const int MAXN = 100005;
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

int n, m;
vi adj[MAXN];
bool visited[MAXN];
int in[MAXN];
int low[MAXN];
int t = 0;
set<int> articulation;

int dfs(int v, int p = -1) {
    visited[v] = true;
    in[v] = low[v] = t++;
    int children = 0;
    FOR (i, 0, adj[v].size()) {
        int to = adj[v][i];
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], in[to]);
        }
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (p != -1 && low[to] >= in[v]) {
                articulation.insert(v);
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        articulation.insert(v);
    }
}

void tarjans() {
    fill(in, in + n, -1);
    fill(low, low + n, -1);
    FOR (i, 0, n) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    setIO("stdio");
    cin >> n >> m;
    int a, b;
    FOR (i, 0, m) {
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    tarjans();
    cout << articulation.size() << endl;
}