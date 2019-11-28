//
// Created by Samuel on 11/27/2019.
//

/*
 * heavy-light decomposition (range max tree queries)
 * --------------------------------------------------
 * - a heavy edge from node A to node B means that the size of the subtree of B is greater than all of its siblings
 * - a heavy path from node A consists of heavy paths and a single light path going up to the root
 * - tree is decomposed into a series of segment trees
 * 		- each segment tree will keep track of the maximum for each heavy path
 * 		- the segment trees can be condensed into one big segment tree
 *
 * 1) construct the heavy edges via a dfs through the tree
 * 2) decompose the tree
 * 		a) create a head array that stores the head of the heavy path containing the node
 * 		b) create a pos array that stores the position of the node in the segment tree
 * 3) to update
 * 		a) update the segment tree for the heavy path containing the node
 * 4) to query
 * 		a) propagate the nodes upwards to the root of the heavy path, keeping track of the maximum for each heavy path
 * 		b) once they are the in the same heavy path, compute the maximum on that interval
 * 		c) this is equivalent to finding the lca
 */

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000
#define MAXPOW 262144
#define endl '\n'

int n, q;
vector<int> adj[MAXN];
int heavy[MAXN]; // heavy[a]=b means that a-b is a heavy edge
int parent[MAXN];
int depth[MAXN];
int head[MAXN]; // head[a]=b means that b is the head of the heavy path containing a
int pos[MAXN]; // pos[a]=b means that b is the position of a in the segment tree
int cur = 0;

int segTree[MAXPOW];

int querySeg(int node, int a, int b, int i, int j) {
	if (a >= i && b <= j) {
		return segTree[node];
	}
	if (a > j || b < i) {
		return 0;
	}
	if (a != b) {
		int mid = (a + b) / 2;
		return (querySeg(2 * node + 1, a, mid, i, j) ^ querySeg(2 * node + 2, mid + 1, b, i, j));
	}
}

void updateSeg(int node, int a, int b, int i, int value) {
	if (i < a || i > b) {
		return;
	}
	if (a == b) {
		segTree[node] = value;
	}
	else {
		int mid = (a + b) / 2;
		if (i >= a && i <= mid) {
			updateSeg(2 * node + 1, a, mid, i, value);
		}
		else {
			updateSeg(2 * node + 2, mid + 1, b, i, value);
		}
		segTree[node] = segTree[2 * node + 1] ^ segTree[2 * node + 2];
	}
}

int dfs(int v) {
	int ret = 1;
	int maxSubsize = 0;
	for (int c : adj[v]) {
		if (c != parent[v]) {
			parent[c] = v;
			depth[c] = depth[v] + 1;
			int subsize = dfs(c);
			ret += subsize;
			if (subsize > maxSubsize) {
				maxSubsize = subsize;
				heavy[v] = c;
			}
		}
	}
	return ret;
}

void decompose(int v, int h) {
	head[v] = h;
	pos[v] = cur++;
	if (heavy[v] != -1) {
		decompose(heavy[v], h);
	}
	for (int c : adj[v]) {
		if (c != parent[v] && c != heavy[v]) {
			decompose(c, c);
		}
	}
}

void construct() {
	fill(heavy, heavy + n, -1);
	cur = 0;
	dfs(0);
	decompose(0, 0);
}

void update(int a, int value) {
	updateSeg(0, 0, n-1, pos[a], value);
}

int query(int a, int b) {
	int ret = 0;
	for (; head[a] != head[b]; b = parent[head[b]]) {
		if (depth[head[a]] > depth[head[b]]) {
			int temp = a;
			a = b;
			b = temp;
		}
		ret = (ret ^ querySeg(0, 0, n-1, pos[head[b]], pos[b]));
	}
	if (depth[a] > depth[b]) {
		int temp = a;
		a = b;
		b = temp;
	}
	ret = (ret ^ querySeg(0, 0, n-1, pos[a], pos[b]));
	return ret;
}

int temp[MAXN];

int main() {
	freopen("cowland.in", "r", stdin);
	freopen("cowland.out", "w", stdout);
	std::ios::sync_with_stdio(false);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> temp[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	construct();
	for (int i = 0; i < n; ++i) {
		update(i, temp[i]);
	}
	for (int i = 0; i < q; ++i) {
		char c;
		int u, v;
		cin >> c >> u >> v;
		if (c == '1') {
			update(u - 1, v);
		}
		else if (c == '2') {
			cout << query(u - 1, v - 1) << endl;
		}
	}
}