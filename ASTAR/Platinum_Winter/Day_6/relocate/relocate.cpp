#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 10000

int n, m, k;
int markets[5];
bool ismarket[MAXN];
vector<pair<int, int> > adj[MAXN];
int dist[5][MAXN];
int traversal[5];

int fact(int i) {
	int ans = 1;
	for (; i>=1; --i) {
		ans *= i;
	}
	return ans;
}

void dijkstra(int index) {
	int start = markets[index];
	fill(dist[index], dist[index]+n, INF);
	dist[index][start] = 0;
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		int current = q.top().second;
		q.pop();
		for (int i = 0; i < adj[current].size(); ++i) {
			pair<int, int> next = adj[current][i];
			if (dist[index][current] + next.first < dist[index][next.second]) {
				dist[index][next.second] = dist[index][current] + next.first;
				q.push(make_pair(-dist[index][next.second], next.second));
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		cin >> markets[i];
		--markets[i];
		ismarket[markets[i]] = true;
	}
	int a, b, d;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> d;
		adj[a-1].push_back(make_pair(d, b-1));
		adj[b-1].push_back(make_pair(d, a-1));
	}
	for (int i = 0; i < k; ++i) {
		dijkstra(i);
		// for (int j = 0; j < n; ++j) {
		// 	cout << dist[i][j] << " ";
		// }
		// cout << endl;
	}
	for (int i = 0; i < k; ++i) {
		traversal[i] = i;
	}
	int mind = INF;
	for (int i = 0; i < fact(k); ++i) {
		int d = 0;
		for (int j = 1; j < k; ++j) {
			d += dist[traversal[j]][markets[traversal[j-1]]];
		}
		for (int i = 0; i < n; ++i) {
			if (ismarket[i]) continue;
			mind = min(mind, d + dist[traversal[0]][i] + dist[traversal[k-1]][i]);
		}
		next_permutation(traversal, traversal+k);
	}
	cout << mind << endl;
}
