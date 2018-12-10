#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

#define INF (int)((1LL<<31)-1)
#define endl '\n'
#define MAXN 100

int n, m;
int dist[MAXN];
int adjacent[MAXN][MAXN];
bool visited[MAXN];

int minField() {
	int ret = 0, minDist = INF;
	for (int i = 0; i < n; ++i) {
		if (!visited[i] && dist[i] < minDist) {
			minDist = dist[i];
			ret = i;
		}
	}
	return ret;
}

int prims(int start) {
	fill(dist, dist+n, INF);
	fill(visited, visited+n, false);
	dist[start] = 0;
	for (int times = 0; times < n-1; ++times) {
		int next;
		if (times == 0) next = start;
		else next = minField();
		visited[next] = true;
		for (int i = 0; i < n; ++i) {
			if (i == next || adjacent[next][i] == 0) continue;
			if (!visited[i] && adjacent[next][i] < dist[i]) {
				dist[i] = adjacent[next][i];
			}
		}
		for (int i = 0; i < n; ++i) {
			if (dist[i] == INF) cout << "inf" << " ";
			else cout << dist[i] << " ";
		}
		cout << endl;
	}

	long long ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += dist[i];
	}
	return ret;
}

int main() {
	cin >> n >> m;
	int from, to, length;
	for (int i = 0; i < m; ++i) {
		cin >> from >> to >> length;
		--from; --to;
		adjacent[from][to] = length;
		adjacent[to][from] = length;
	}

	int ans = 0;
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			adjacent[i][j] *= 2;
			adjacent[j][i] *= 2;
			int posAns = prims(0);
			cout << "ans: " << posAns << endl;
			if (posAns > ans) {
				ans = posAns;
			}
			adjacent[i][j] /= 2;
			adjacent[j][i] /= 2;
		}
	}*/

	cout << prims(0) << endl;
}
