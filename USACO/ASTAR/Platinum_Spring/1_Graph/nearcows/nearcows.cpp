#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
int cows[MAXN];
int par[MAXN];
int dp[MAXN][25];
int dpf[MAXN][25];

void dfs(int c, int p) {
    par[c] = p;
    FOR (i, 0, adj[c].size()) {
        if (adj[c][i] == par[c]) continue;
        dfs(adj[c][i], c);
    }
}

void dfs2(int c, int v) {
    if (v == 0) {
        FOR (i, 0, n) {
            dpf[i][v] = cows[i];
        }
        return;
    }
    if (c == 0) dpf[0][v] = dp[0][v];
    else {
        if (v < 2) dpf[c][v] = dp[c][v] + dpf[par[c]][v-1];
        else dpf[c][v] = dp[c][v] + dpf[par[c]][v-1] - dp[c][v-2];
    }
    FOR (i, 0, adj[c].size()) {
        if (adj[c][i] == par[c]) continue;
        dfs2(adj[c][i], v);
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
    FOR (i, 0, n) {
        cin >> cows[i];
    }
    dfs(0, 0);
    FOR (i, 0, n) {
        dp[i][0] = cows[i];
    }
    FOR (j, 1, k + 1) {
        FOR (i, 0, n) {
            dp[i][j] = cows[i];
            FOR (l, 0, adj[i].size()) {
                if (adj[i][l] == par[i]) continue;
                dp[i][j] += dp[adj[i][l]][j-1];
            }
        }
        /*FOR (i, 0, n) {
            cout << dp[i][j] << " ";
        } cout << endl;*/
    }
    FOR (j, 0, k + 1) {
        dfs2(0, j);
//        cout << "v=" << j << ": ";
        /*FOR (i, 0, n) {
            cout << dpf[i][j] << " ";
        } cout << endl;*/
    }
    FOR (i, 0, n) {
        cout << dpf[i][k] << endl;
    }
}