#include <iostream>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 100000
#define MOD 1000000007L

int n, m;
bool visited[MAXN];
bool currentVisited[MAXN];
vector<int> adj[MAXN];

pair<int, int> dfs(int start) {
    // first: nodes; second: edges
    if (visited[start]) return make_pair(0, 0);
    visited[start] = true;
    pair<int, int> ret = make_pair(1, adj[start].size());
    for (int i = 0; i < adj[start].size(); ++i) {
        pair<int, int> next = dfs(adj[start][i]);
        ret.first += next.first;
        ret.second += next.second;
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    long long ans = 1;
    for (int i = 0; i < n; ++i) {
        if (visited[i] || adj[i].size() == 0) continue;
        pair<int, int> inc = dfs(i);
        inc.second /= 2;
        if (inc.first > inc.second) {
            ans = (ans * (long long) inc.first) % MOD;
        }
        else {
            ans = (2LL * ans) % MOD;
        }
        // cout << ans << endl;
    }
    cout << ans << endl;
}
