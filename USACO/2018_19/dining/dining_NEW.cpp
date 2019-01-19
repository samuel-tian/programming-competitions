#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

#define endl '\n'
#define MAXN 50000
#define INF INT_MAX

int n, m, k;
vector<pair<int, int> > adj[MAXN];
int dist[2][MAXN];
bool visited[MAXN];
// [0] is the distance from node 0, [1] is the distance from node n-1

void dijkstra(int start, int time) {
	priority_queue<pair<int, int> > pq;
	fill(dist[time], dist[time] + n, INF);
	fill(visited, visited + n, false);
	dist[time][start] = 0;
	pq.push_back(make_pair(0, start));
	while (!pq.empty()) {
		int cur = pq.top().second;
		pq.pop();
		if (visited[cur]) continue;
		for (int i = 0; i < adj[cur].size(); ++i) {
			pair<int, int> next = adj[cur][i];
			if (dist[cur] + next.first < dist[next.second]) {
				dist[next.second] = dist[cur] + next.first;
				pq.push(make_pair(-dist[next.second], next.second));
			}
		}
		visited[cur] = true;
	}
}

int main() {
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int a, b, t;
		cin >> a >> b >> t;
		adj[a - 1].push_back(make_pair(t, b - 1));
		adj[b - 1].push_back(make_pair(t, a - 1));
	}
	dijkstra()
}
