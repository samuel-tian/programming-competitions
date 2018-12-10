#include <iostream>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

#define INF (int)((1LL<<31)-1)
#define endl '\n'
#define MAXN 100

int n, m;
int dist[MAXN], parent[MAXN];
int adjacent[MAXN][MAXN];
pair<int, int> paths[MAXN];
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

int dijkstra(int start) {
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
			if (!visited[i] && adjacent[next][i] + dist[next] < dist[i]) {
				dist[i] = adjacent[next][i] + dist[next];
			}
		}
		/*for (int i = 0; i < n; ++i) {
			if (dist[i] == INF) cout << "inf" << " ";
			else cout << dist[i] << " ";
		}
		cout << endl;*/
	}

	return dist[n-1];
}

int dijkstraNext(int start) {
	fill(dist, dist+n, INF);
	fill(visited, visited+n, false);
	dist[start] = 0;
	parent[start] = -1;
	for (int times = 0; times < n-1; ++times) {
		int next;
		if (times == 0) next = start;
		else next = minField();
		//cout << "next: " << next << endl;
		visited[next] = true;
		for (int i = 0; i < n; ++i) {
			if (i == next || adjacent[next][i] == 0) continue;
			if (!visited[i] && adjacent[next][i] + dist[next] < dist[i]) {
				dist[i] = adjacent[next][i] + dist[next];
				parent[i] = next;
			}
		}
		/*for (int i = 0; i < n; ++i) {
			if (dist[i] == INF) cout << "inf" << " ";
			else cout << dist[i] << " ";
		}
		cout << endl;*/
	}

	return dist[n-1];
}

int main() {
	//freopen("rblock_cases\\10.out", "r", stdin);
	//cin >> n; cout << n << endl; fclose(stdin);
	//freopen("rblock_cases\\10.in", "r", stdin);
	//freopen("rblock.in", "r", stdin);
	//freopen("rblock.out", "w", stdout);
	cin >> n >> m;
	int from, to, length;
	for (int i = 0; i < m; ++i) {
		cin >> from >> to >> length;
		--from; --to;
		adjacent[from][to] = length;
		adjacent[to][from] = length;
	}

	int normalAns = dijkstraNext(0);
	int ans = 0;
	/*for (int i = 0; i < n; ++i) {
		cout << parent[i] << " ";
	}
	cout << endl;*/
	for (int i = 0; i < n; ++i) {
		if (parent[i] == -1) continue;
		adjacent[i][parent[i]] *= 2;
		adjacent[parent[i]][i] *= 2;
		int posAns = dijkstra(0);
		//cout << "ans: " << posAns << endl;
		if (posAns > ans) {
			ans = posAns;
		}
		adjacent[i][parent[i]] /= 2;
		adjacent[parent[i]][i] /= 2;
	}
	cout << ans - normalAns << endl;

	//fclose(stdin);
	//fclose(stdout);
}
