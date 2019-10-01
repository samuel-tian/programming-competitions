//
// Created by Samuel on 9/30/2019.
//

/*
 * least common ancestor using sparse table
 * ----------------------------------------
 * 1) compute depth in a dfs
 * 2) compute sparse table
 * 		a) sparse table contains the 2^i-th ancestor of each node -> par[MAX][MAXLOG]
 * 		b) can be computed with the following recursive function
 * 			i) par[i][0] = parent of i (can be computed in the dfs)
 * 			ii) par[i][j] = j-1 parent of par[i][j-1]
 * 3) bring nodes A and B to the same depth
 * 		a) look at the difference in depths
 * 		b) propagate lower upwards in intervals of 2^i using the sparse table
 * 4) propagate A and B upwards while their 2^i-th parents are not equal
 * 		a) use sparse table, going from larger intervals to smaller ones
 * 		b) the following step depends on if nodes A and B are directly related (one is the descendant of another)
 * 			i) if not directly related, return parent of resulting node
 * 			ii) if directly related, return resulting node
 */

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 100000
#define MAXLOG 21

int n, m;
vector<int> adj[MAXN];
bool visited[MAXN];
int d[MAXN];
int par[MAXN][MAXLOG];

void calcDepth(int node, int depth) {
	for (int i = 0; i < adj[node].size(); ++i) {
		int next = adj[node][i];
		if (visited[next]) continue;
		d[next] = depth;
		par[next][0] = node;
		visited[next] = true;
		calcDepth(next, depth + 1);
	}
}

void calcST() {
	for (int j = 1; j < MAXLOG; ++j) {
		for (int i = 1; i < n; ++i) {
			par[i][j] = par[par[i][j-1]][j-1];
		}
	}
}

int lca(int n1, int n2) {
	// propagate to same depth
	int difference = d[n1] - d[n2];
	if (difference < 0) return lca(n2, n1); // n1 is lower
	for (int i = 0; i < MAXLOG; ++i) {
		if (difference & 1<<i) {
			n1 = par[n1][i];
		}
	}
	for (int i = MAXLOG - 1; i >= 0; --i) {
		if (par[n1][i] == par[n2][i]) continue;
		n1 = par[n1][i];
		n2 = par[n2][i];
	}
	if (n1 != n2) {
		return par[n1][0];
	}
	else { // n1 is a descendant of n2
		return n1;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	d[0] = 0;
	par[0][0] = 0;
	visited[0] = true;
	calcDepth(0, 1);
	calcST();
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < MAXLOG; ++j) {
//			cout << par[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << d[3] << " " << d[6] << endl;
}