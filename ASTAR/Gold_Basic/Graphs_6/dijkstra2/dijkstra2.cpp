/*input
6 5 1
3 4 5
5 6 4
1 2 6
3 2 3
3 1 2
*/
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <functional>

using namespace std;

#define endl '\n'
#define INF (1LL<<31)-1
#define MAXV 50000
#define ll long long

ll v, e, s;
ll dis[MAXV];
bool vis[MAXV];
vector<pair<ll, ll> > adj[MAXV];
priority_queue<pair<ll, ll> > pq;

void dijkstra(ll start) {
	fill(dis, dis+v, INF);
	dis[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		ll cur = pq.top().second;
		pq.pop();
		if (vis[cur]) continue;
		vis[cur] = true;
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
	cin >> v >> e >> s; --s;
	ll one, two, weight;
	for (ll i = 0; i < e; ++i) {
		cin >> one >> two >> weight;
		--one; --two;
		adj[one].push_back(make_pair(weight, two));
		adj[two].push_back(make_pair(weight, one));
	}

	dijkstra(s);
	for (ll i = 0; i < v; ++i) {
		if (dis[i] == INF) cout << -1 << endl;
		else cout << dis[i] << endl;
	}
	return 0;
}