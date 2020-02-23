/*
 * Topological Sort
 * ----------------
 * 1) dfs through the DAG
 * 2) push the node onto the sorted vector after all adjacent nodes have been traversed
 * 3) reverse the sorted vector to get the final topological sort
 *
 * time complexity: O(n)
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

const int MAXN = 100005;
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
vi adj[MAXN];
bool visited[MAXN];
vi tsorted;

void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = true;
    FOR (i, 0, adj[cur].size()) {
        dfs(adj[cur][i]);
    }
    tsorted.pb(cur);
}

void topologicalSort() {
    FOR (i, 0, n) {
        dfs(i);
    }
    reverse(tsorted.begin(), tsorted.end());
}

int main() {
    setIO("input");
    cin >> n >> m;
    int a, b;
    FOR (i, 0, m) {
        cin >> a >> b;
        adj[a].pb(b);
    }
    topologicalSort();
    PRSP(i, n, tsorted);
}