#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int Q = 200005;

struct DSU {
    vector<int> par, r;
    DSU() = default;
	DSU(int n) {
		par.resize(n);
		r.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            r[i] = 0;
        }
	}
	int find(int i) {
		if (par[i] != i)
            par[i] = find(par[i]);
		return par[i];
	}
	bool same_set(int a, int b) {
		return find(a) == find(b);
	}
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (r[a] < r[b])
            swap(a, b);
		par[b] = a;
		r[a] = max(r[a], r[b] + 1);
	}
};

int n, q;
vector<int> adj[N];
pair<int, int> qry[Q];
vector<pair<int, int> > oth[N];
int anc[N], vis[N], ans[Q];
DSU dsu;

void dfs(int v) {
    vis[v] = 1;
    anc[v] = v;
    for (int u : adj[v]) {
        if (vis[u])
            continue;
        dfs(u);
        dsu.join(u, v);
        anc[dsu.find(v)] = v;
    }
    for (pair<int, int> other : oth[v]) {
        if (vis[other.first])
            ans[other.second] = anc[dsu.find(other.first)];
    }
}

int main() {
    cin >> n >> q;
    dsu = DSU(n);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        a--;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        qry[i] = {a, b};
        oth[a].emplace_back(b, i);
        oth[b].emplace_back(a, i);
    }
    dfs(0);
    for (int i = 0; i < q; i++)
        cout << ans[i]+1 << '\n';
}

