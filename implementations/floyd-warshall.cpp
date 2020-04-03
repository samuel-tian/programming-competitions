/*
 * Floyd-Warshall all-pairs shortest path algorithm
 * ------------------------------------------------
 * all-pairs shortest path that allows for negative edge weights
 * 1) initialize an adjacency matrix that stores the weights of the shortest paths
 * 2) calculate shortest paths
 *	  a) consider all nodes as intermediate nodes that lie on the shortest path connecting two other nodes
 *	  b) update the shortest path between the other nodes if the considering the intermediate decreases path length
 * time complexity: O(V^3)
 */

#include <bits/stdc++.h>

using namespace std;

#define MAXN 250
#define INF INT_MAX
#define endl '\n'

int n, m;
int dist[MAXN][MAXN];

void floydWarshall() {
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dist[i][k] == INF || dist[k][j] == INF) continue;
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
//	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dist[i][j] = i == j ? 0 : INF;
		}
	}
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a-1][b-1] = c;
		dist[b-1][a-1] = c;
	}
	floydWarshall();

}