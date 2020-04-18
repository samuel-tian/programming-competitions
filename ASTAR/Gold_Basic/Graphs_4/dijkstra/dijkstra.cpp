#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define INF (int)((1LL<<31)-1)
#define MAXV 2500
#define endl '\n'
typedef pair<int, int> Vertice;

int v, e, s;
int dist[MAXV];
vector<Vertice> adjacent[MAXV];
bool visited[MAXV];

void dijkstra(int start) {
	fill(dist, dist + v, INF);
	dist[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < adjacent[current].size(); ++i) {
			Vertice next = adjacent[current][i];
			if (visited[next.first] || dist[current] + next.second > dist[next.first]) {
				continue;
			}
			dist[next.first] = dist[current] + next.second;
			q.push(next.first);
		}
	}
	return;
}

int main() {
	cin >> v >> e >> s;
	s--;
	int one, two, weight;
	for (int i = 0; i < e; ++i) {
		cin >> one >> two >> weight;
		--one; --two;
		adjacent[one].push_back(make_pair(two, weight));
		adjacent[two].push_back(make_pair(one, weight));
	}

	dijkstra(s);
	for (int i = 0; i < v; ++i) {
		if (dist[i] == INF) {
			cout << -1 << endl;
		}
		else {
			cout << dist[i] << endl;
		}
	}
	return 0;
}
