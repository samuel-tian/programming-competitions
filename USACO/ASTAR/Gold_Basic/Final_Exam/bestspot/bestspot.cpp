/*input

*/
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

#define MAXP 500
#define INF (int)((1LL<<31)-1)
#define endl '\n'

int p, f, c;
int dis[MAXP], minDis[MAXP];
vector<pair<int, int> > adj[MAXP];
bool vis[MAXP], fav[MAXP];
priority_queue<pair<int, int> > pq;

void dijkstra(int start) {
	fill(dis, dis+p, INF);
	fill(vis, vis+p, false);
	dis[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int cur = pq.top().second;
		pq.pop();
		if (vis[cur]) continue;
		vis[cur] = true;
		for (int i = 0; i < adj[cur].size(); ++i) {
			pair<int, int> next = adj[cur][i];
			if (dis[cur] + next.first < dis[next.second]) {
				dis[next.second] = dis[cur]+next.first;
				pq.push(make_pair(-dis[next.second], next.second));
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < p; ++i) {
		if (fav[i]) {
			ret += dis[i];
		}
	}
	minDis[start] = ret;
}

int main() {
	cin >> p >> f >> c;
	int one, two, weight;
	for (int i = 0; i < f; ++i) {
		cin >> one;
		fav[--one] = true;
	}
	for (int i = 0; i < c; ++i) {
		cin >> one >> two >> weight;
		--one; --two;
		adj[one].push_back(make_pair(weight, two));
		adj[two].push_back(make_pair(weight, one));
	}

	int mini = INF, pr;
	for (int i = 0; i < p; ++i) {
		dijkstra(i);
		if (minDis[i] < mini) {
			mini = minDis[i];
			pr = i;
		}
	}

	cout << ++pr << endl;
}