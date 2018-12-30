#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 50000

int n, k;
vector<int> adj[MAXN];
vector<int> children[MAXN];
int visited[MAXN];
int depth[MAXN];
int traversal[MAXN];
int counter = 0;
int inc[MAXN];
int ans[MAXN];
int par[MAXN][17]; // 16 is roughly log_2(MAXN)

void dfs(int current, int d) {
	depth[current] = d;
	visited[current] = true;
	for (int i = 0; i < adj[current].size(); ++i) {
		int next = adj[current][i];
		if (visited[next]) continue;
		children[current].push_back(next);
		par[next][0] = current;
		dfs(next, d+1);
	}
	traversal[counter] = current;
	++counter;
}

int lca(int node1, int node2) {
	// bring both nodes to the same depth
	if (depth[node1] > depth[node2]) {
		int difference = depth[node1] - depth[node2];
		for (int i = 0; i < 17; ++i) {
			if (difference & (1<<i)) {
				node1 = par[node1][i];
			}
		}
	}
	else if (depth[node1] < depth[node2]){
		int difference = depth[node2] - depth[node1];
		for (int i = 0; i < 17; ++i) {
			if (difference & (1<<i)) {
				node2 = par[node2][i];
			}
		}
	}
	if (node1 == node2) return node1;
	for (int i = 16; i >= 0; --i) {
		if (par[node1][i] == par[node2][i]) continue;
		node1 = par[node1][i];
		node2 = par[node2][i];
	}
	return par[node1][0];
}

int main() {
	cin >> n >> k;
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	// root at node 0
	par[0][0] = 0;
	dfs(0, 0);
	for (int j = 1; j < 17; ++j) {
		for (int i = 0; i < n; ++i) {
			par[i][j] = par[par[i][j-1]][j-1];
		}
	}
	for (int i = 0; i < k; ++i) {
		cin >> a >> b;
		--a; --b;
		int ancestor = lca(a, b);
		inc[a] += 1;
		inc[b] += 1;
		inc[ancestor] -= 1;
		if (ancestor != 0) inc[par[ancestor][0]] -= 1;
	}
	for (int i = 0; i < n; ++i) {
		int current = traversal[i];
		if (children[current].size() == 0) {
			ans[current] = inc[current];
		}
		else {
			for (int j = 0; j < children[current].size(); ++j) {
				ans[current] += ans[children[current][j]];
			}
			ans[current] += inc[current];
		}
	}
	// cout << "INC: ";
	// for (int i = 0; i < n; ++i) {
	// 	cout << inc[i] << " ";
	// }
	// cout << endl;
	int maxmilk = 0;
	for (int i = 0; i < n; ++i) {
		maxmilk = max(maxmilk, ans[i]);
		// cout << ans[i] << " ";
	}
	cout << endl;
	cout << maxmilk << endl;
}
