/*input
5 8
1 2 3
5 3 5
5 1 7
1 3 1
5 2 9
5 4 4
4 3 6
2 3 4
*/
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

#define endl '\n'
#define INF LONG_LONG_MAX
#define MAXV 50000
#define ll long long

int v, e;
ll dis[MAXV];
bool vis[MAXV];
vector<pair<ll, int> > adj[MAXV];
priority_queue<pair<int, ll> > pq;

ll prims(int start) {
	fill(dis, dis+v, INF);
	dis[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cur = pq.top().second;
		pq.pop();
		if (vis[cur]) continue;
		//cout << "current:" << " " << cur << endl;
		vis[cur] = true;
		for (int i = 0; i < adj[cur].size(); ++i) {
			pair<ll, int> next = adj[cur][i];
			if (next.second < dis[next.first] && !vis[next.first]) {
				dis[next.first] = next.second;
				pq.push(make_pair(-dis[next.first], next.first));
			}
		}
		/*for (int i = 0; i < v; ++i) {
			cout << dis[i] << " ";
		}
		cout << endl;*/
	}
	ll ret = 0;
	for (int i = 0; i < v; ++i) {
		ret += dis[i];
		//cout << dis[i] << " ";
	}
	//cout << endl;
	return ret;
}

int main() {
	cin >> v >> e;
	int in1, in2, in3;
	for (int i = 0; i < e; ++i) {
		cin >> in1 >> in2 >> in3;
		--in1; --in2;
		adj[in1].push_back(make_pair(in2, in3));
		adj[in2].push_back(make_pair(in1, in3));
	}

	cout << prims(0) << endl;
}