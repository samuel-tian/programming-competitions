/*
 * Kruskal's minimum spanning tree algorithm
 * -----------------------------------------
 * 1) sort the edges in terms of ascending weight
 * 2) iterate through the edges, adding them to a disjoint set data structure if no cycle is created
 * 		a) disjoint set allows for O(log n) union and find operations
 * 		b) a cycle is created if the two endpoints of an edge are elements of the same subset
 * time complexity: O(E log E)
 */

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define MAXM 100000
#define INF INT_MAX
#define endl '\n'

int n, m;
//vector<pair<int, int> > adj[MAXN];
vector<pair<int, pair<int, int> > > edges;
int par[MAXN];
int r[MAXN];

int find(int i) {
	if (par[i] != i) {
		par[i] = find(par[i]);
	}
	return par[i];
}

void unionRank(int aa, int bb) { // append b to a
	int a = find(aa);
	int b = find(bb);
	if (r[b] > r[a]) {
		unionRank(bb, aa);
		return;
	}
	par[b] = a;
	r[a] = max(r[a], r[b] + 1);
}

int kruskal() {
    for (int i = 0; i < n; ++i) {
		par[i] = i;
	}
    sort(edges.begin(), edges.end());
	int ret = 0;
	for (int i = 0; i < edges.size(); ++i) {
		pair<int, int> e = edges[i].second;
		if (find(e.first) == find(e.second)) continue;
		unionRank(e.first, e.second);
		ret += edges[i].first;
	}
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		--a; --b;
//        adj[a].push_back(make_pair(c, b));
//        adj[b].push_back(make_pair(c, a));
		edges.push_back(make_pair(c, make_pair(a, b)));
	}
	cout << kruskal() << endl;
	return 0;
}