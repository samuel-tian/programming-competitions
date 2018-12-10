/*input
5 2
4 1 2
1 3 1 3 4
6 2 2 5
5 2 2 5
2 2 3 4
*/

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 1000

int n;
long long e;
int quality[MAXN];
int dis[MAXN][MAXN];
long long dp[MAXN];
vector<int> adj[MAXN];

bool comparator(int a, int b) {
	return quality[a] < quality[b];
}

void bfs() {
	for (int start = 0; start < n; ++start) {
		fill(dis[start], dis[start] + n, INF);
		dis[start][start] = 0;
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < adj[cur].size(); ++i) {
				int next = adj[cur][i];
				if (dis[start][next] > dis[start][cur] + 1) {
					dis[start][next] = dis[start][cur] + 1;
					q.push(next);
				}
			}
		}
	}
}

void recurse() {
	for (int i = 0; i < n; ++i) {
		dp[i] = quality[i];
	}
	int torder[MAXN];
	for (int i = 0; i < n; ++i) {
		torder[i] = i;
	}
	sort(torder, torder + n, comparator);
	for (int cur = 0; cur < n; ++cur) {
		int i = torder[cur];
		for (int next = cur + 1; next < n; ++next) {
			int j = torder[next];
			if (dis[i][j] == INF || dis[i][j] == 0) continue;
			dp[j] = max(dp[j], dp[i] + quality[j] - e * dis[i][j]);
		}
	}
	/*for (int i = 0; i < n; ++i) {
		cout << dp[i] << " ";
	}
	cout << endl;*/
}

int main() {
	cin >> n >> e;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> quality[i] >> a;
		for (int j = 0; j < a; ++j) {
			int b;
			cin >> b;
			adj[i].push_back(b - 1);
		}
	}
	bfs();
	recurse();
	cout << *max_element(dp, dp + n) << endl;
}