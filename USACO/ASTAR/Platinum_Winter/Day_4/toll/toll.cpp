#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 250

int n, m, q;
int nodeweight[MAXN];
int traversal[MAXN];
int dist[MAXN][MAXN];
int ans[MAXN][MAXN];
// adj.first is the edge weight, adj.second is the next node

bool comp(int a, int b) {
	if (nodeweight[a] == nodeweight[b]) {
		return a < b;
	}
	return nodeweight[a] < nodeweight[b];
}

int main() {
	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i) {
		cin >> nodeweight[i];
		traversal[i] = i;
	}
	sort(traversal, traversal + n, comp);
	// 0 1 2 3 4
	// 2 5 3 3 4
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dist[i][j] = INF;
			ans[i][j] = INF;
		}
		ans[i][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a-1][b-1] = min(dist[a-1][b-1], c);
		dist[b-1][a-1] = min(dist[a-1][b-1], c);
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int l = traversal[k];
				if (dist[i][l] == INF || dist[l][j] == INF) continue;
				int d = dist[i][l] + dist[l][j];
				if (d < dist[i][j]) {
					dist[i][j] = d;
					dist[j][i] = d;
				}
				int a = dist[i][j] + max(nodeweight[i], max(nodeweight[j], nodeweight[l]));
				if (a < ans[i][j]) {
					ans[i][j] = a;
					ans[j][i] = a;
				}
			}
		}
	}
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		cout << dist[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		cout << ans[a-1][b-1] << endl;
	}
}
