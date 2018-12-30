#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXV 50000
#define ll long long

ll v, e, s;
ll dis[MAXV];
bool vis[MAXV];
vector<pair<ll, ll> > adj[MAXV];

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
	cin >> v >> e >> s;
	ll one, two, weight;
	for (ll i = 0; i < e; ++i) {
		cin >> one >> two >> weight;
		adj[one-1].push_back(make_pair(weight, two-1));
		adj[two-1].push_back(make_pair(weight, one-1));
	}

	dijkstra(s-1);
	for (ll i = 0; i < v; ++i) {
		if (dis[i] == INF) cout << -1 << endl;
		else cout << dis[i] << endl;
	}
	return 0;
}
