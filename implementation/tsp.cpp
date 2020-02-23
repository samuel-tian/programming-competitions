/*
 * Traveling Salesman Problem
 * --------------------------
 * 1) dp[bitmask][i] represents the minimum distance traversing all the nodes in bitmask, ending at node i
 * 2) dp[bitmask][i] can be computed by iterating all neighboring points and taking the minimum of the previous dp state and the edge weight
 *      a) dp[bitmask][i] = min{all dp[bitmask ^ i][k] + dist(i, k)}
 *
 * time complexity: O(2^n * n^2)
 */
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

const int MAXN = 19;
const int INF = INT_MAX;
const int NINF = INT_MIN;
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
vpi adj[MAXN];
int dist[MAXN][MAXN];
//unordered_map<int, int[MAXN]> dp;
int dp[1<<MAXN][MAXN];

int main() {
    setIO("stdio");
    cin >> n >> m;
    int a, b, c;
    FOR (i, 0, m) {
        cin >> a >> b >> c;
        adj[a-1].pb(mp(b-1, c));
        adj[b-1].pb(mp(a-1, c));
        dist[a-1][b-1] = c;
        dist[b-1][a-1] = c;
    }
    FOR (i, 0, 1<<n) {
        FOR (j, 0, n) {
            dp[i][j] = INF;
        }
    }
    FOR (i, 0, n) {
        dp[1<<i][i] = 0;
    }
    FOR (i, 0, 1<<n) {
        FOR (j, 0, n) {
            if (i & (1<<j) == 0) continue;
            FOR (k, 0, n) {
                if (i & (1<<k) == 0) continue;
                if (dist[j][k] == 0) continue;
                if (dp[i^(1<<j)][k] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i^(1<<j)][k] + dist[j][k]);
            }
        }
    }
    int ret = INF;
    FOR (i, 0, n) {
        ret = min(ret, dp[(1<<n) - 1][i]);
    }
    /*FOR (i, 1, 1<<n) {
        FOR (j, 0, n) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << ret << endl;
}