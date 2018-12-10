/*input
4 3
1 2 3
2 3 2
2 4 4
1 2
4 1
3 1
*/
#include <iostream>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>
#include <vector>

#define endl '\n'
#define INF INT_MAX
#define NINF INT_MIN
#define MAXN 100000
#define MAXQ 100000

using namespace std;

int n, q;
int dis[MAXN];
bool vis[MAXN];
vector<pair<int, int> > adj[MAXN];
int question[MAXQ][2];

void rel(int s) {
	fill(dis, dis+n, 0);
	fill(vis, vis+n, false);

	queue<int> q;
	q.push(s);
	dis[s] = INF;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		vis[cur] = true;
		for (int i = 0; i < adj[cur].size(); ++i) {
			pair<int, int> next = adj[cur][i];
			if (vis[next.second]) continue;
			dis[next.second] = min(next.first, dis[cur]);
			q.push(next.second);
		}
	}
}

int main() {
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	cin >> n >> q;
	int a, b, w;
	for (int i = 0; i < n-1; ++i) {
		cin >> a >> b >> w;
		--a; --b;
		adj[a].push_back(make_pair(w, b));
		adj[b].push_back(make_pair(w, a));
	}
	for (int i = 0; i < q; ++i) {
		cin >> question[i][0] >> question[i][1];
	}

	for (int i = 0; i < q; ++i) {
		int ret = 0;
		rel(question[i][1]-1);
		/*
		for (int j = 0; j < n; ++j) {
			cout << dis[j] << " ";
		}
		cout << endl;
		*/
		for (int j = 0; j < n; ++j) {
			if (question[i][1]-1 == j) continue;
			if (dis[j] >= question[i][0]) {
				++ret;
				//cout << j << " ";
			}
		}

		cout << ret << endl;
	}

	fclose(stdin);
	fclose(stdout);
}