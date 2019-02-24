#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define endl '\n'
#define MAXN 50000
#define INF INT_MAX

int n, m, k;
vector<pair<int, int> > adj[MAXN];
int dist[MAXN];
int masterdist[MAXN];
int possible[MAXN];

void bfs(int start) {
	fill(dist, dist + n, INF);
	dist[start] = 0;
	// bfs from ending node, store results from node start in dist[start][...]
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); ++i) {
			pair<int, int> next = adj[cur][i];
			if (dist[next.first] <= dist[cur] + next.second) continue;
			dist[next.first] = dist[cur] + next.second;
			q.push(next.first);
		}
	}
	return;
}

void masterbfs(int start) {
	// masterdist is to store results from bfs starting at n-1
	fill(masterdist, masterdist + n, INF);
	masterdist[start] = 0;
	// bfs from ending node, store results from node start in dist[start][...]
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); ++i) {
			pair<int, int> next = adj[cur][i];
			if (masterdist[next.first] <= masterdist[cur] + next.second) continue;
			masterdist[next.first] = masterdist[cur] + next.second;
			q.push(next.first);
		}
	}
	return;
}

int main() {
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int a, b, t;
		cin >> a >> b >> t;
		adj[a - 1].push_back(make_pair(b - 1, t));
		adj[b - 1].push_back(make_pair(a - 1, t));
	}
	masterbfs(n - 1);
	/*for (int i = 0; i < n; ++i) {
		cout << masterdist[i] << " ";
	}
	cout << endl;*/
	/*cout << "PRE" << endl;
	for (int i = 0; i < n - 1; ++i) {
		cout << possible[i] << endl;
	}*/
	for (int i = 0; i < k; ++i) {
		int index, yummy;
		cin >> index >> yummy;
		--index;
		bfs(index);
		/*for (int i = 0; i < n; ++i) {
			cout << dist[i] << " ";
		}
		cout << endl;*/
		for (int j = 0; j < n - 1; ++j) {
			if (possible[j] == 1) continue;
			if (dist[j] + dist[n - 1] - masterdist[j] <= yummy) {
				// cout << j << ": " << dist[j] + dist[n] - masterdist[j] << "<" << yummy << endl;
				possible[j] = 1;
			}
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		cout << possible[i] << endl;
	}
}