#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int M = 200005;

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

int n, m;
pair<long long, pair<int, int> > edg[M];
vector<pair<int, int> > adj[N];

long long  kruskal() {
    DSU dsu(n);
    sort(edg, edg + m);
    long long ret = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        pair<int, int> e = edg[i].second;
        if (dsu.same_set(e.first, e.second))
            continue;
        cnt++;
        dsu.join(e.first, e.second);
        ret += edg[i].first;
        adj[e.first].emplace_back(e.second, edg[i].first);
        adj[e.second].emplace_back(e.first, edg[i].first);
    }
    if (cnt != n-1)
        return -1;
    else
        return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--, v--;
        edg[i] = make_pair(w, make_pair(u, v));
    }
    long long ans = kruskal();
    if (ans == -1)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << ans << '\n';
}

