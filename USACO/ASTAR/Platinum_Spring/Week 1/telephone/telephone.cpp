#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> pii;
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

int n, k;
vi adj[MAXN];
int par[MAXN];
int counter = 0;

int dfs(int node, int p) {
    par[node] = p;
    int c = adj[node].size() == 1;
    FOR (i, 0, adj[node].size()) {
        if (adj[node][i] == par[node]) continue;
        c += dfs(adj[node][i], node);
    }
    if (c % 2 == 0) {
        counter += min(k, c / 2);
        return 0;
    }
    else {
        if (c >= 2 * k) {
            counter += k;
            return 0;
        }
        else {
            counter += c / 2;
            return 1;
        }
    }
}

int main() {
    setIO("stdio");
    cin >> n >> k;
    int a, b;
    FOR (i, 0, n-1) {
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    fill(par, par + n, -1);
    dfs(0, 0);
    cout << counter << endl;
}