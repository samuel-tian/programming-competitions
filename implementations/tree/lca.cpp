#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int LOGN = 19;
const int Q = 200005;

int n, q;
vector<int> adj[N];
int dep[N], par[LOGN][N];

void dfs(int a, int p) {
    if (p==-1) {
        dep[a] = 0;
        par[0][a] = a;
    }
    for (int b : adj[a]) {
        if (b == p)
            continue;
        par[0][b] = a;
        dep[b] = dep[a] + 1;
        dfs(b, a);
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b])
        swap(a, b);
    int dif = dep[a] - dep[b];
    for (int i = 0; i < LOGN; i++)
        if (dif & (1<<i))
            a = par[i][a];
    for (int i = LOGN; i >= 0; i--) {
        if (par[i][a] == par[i][b])
            continue;
        a = par[i][a];
        b = par[i][b];
    }
    if (a != b)
        return par[0][a];
    else
        return a;
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    for (int i = 1; i < LOGN; i++)
        for (int j = 0; j < n; j++)
            par[i][j] = par[i-1][par[i-1][j]];
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int l = lca(a, b);
        cout << l+1 << '\n';
    }
}

