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

void dijkstra(ll start) {
	priority_queue<pair<ll, ll> > pq;
	fill(dis, dis+v, INF);
	dis[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		ll cur = pq.top().second;
		pq.pop();
		for (ll i = 0; i < adj[cur].size(); ++i) {
			pair<ll, ll> next = adj[cur][i];
			if (dis[cur]+next.first < dis[next.second]) {
				dis[next.second] = dis[cur]+next.first;
				pq.push(make_pair(-dis[next.second], next.second));
			}
		}
	}
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
