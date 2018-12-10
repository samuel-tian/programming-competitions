#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

#define endl "\n"
#define INF (int)((1LL<<31)-1)
#define MAXN 2000
typedef pair<int, int> Field;

int n, c;
int pipeCost[MAXN];
bool visited[MAXN];
Field fields[MAXN];

long long dist(Field a, Field b) {
	long long xDist = (a.first - b.first) * (a.first - b.first);
	long long yDist = (a.second - b.second) * (a.second - b.second);
	return xDist + yDist;
}

int minField() {
	int ret, minCost = INF;
	for (int i = 0; i < n; ++i) {
		if (!visited[i] && pipeCost[i] <= minCost && (pipeCost[i] == 0 || pipeCost[i] >= c)) {
			minCost = pipeCost[i];
			ret = i;
		}
	}
	return ret;
}

int mst(int start) {
	for (int i = 0; i < n; ++i) {
		pipeCost[i] = INF;
	}
	//visited[start] = true;
	pipeCost[start] = 0;

	for (int i = 0; i < n-1; ++i) {
		int next = minField();
		//cout << "next " << next << endl;
		visited[next] = true;
		for (int j = 0; j < n; ++j) {
			int distance = dist(fields[next], fields[j]);
			if (!visited[j] && distance < pipeCost[j] && distance >= c) {
				pipeCost[j] = distance;
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += pipeCost[i];
		//cout << pipeCost[i] << " ";
	}
	//cout << endl;
	return ret;
}

int main() {
	//freopen("irrigation_cases\\10.out", "r", stdin);
	cin >> n; cout << n << endl; fclose(stdin);
	//freopen("irrigation_cases\\10.in", "r", stdin);

	cin >> n >> c;
	for (int i = 0; i < n; ++i) {
		cin >> fields[i].first >> fields[i].second;
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << dist(fields[i], fields[j]) << " ";
		}
		cout << endl;
	}*/

	bool allVisited = true;
	int ret = mst(0);
	for (int i = 0; i < n; ++i) {
		if (pipeCost[i] == INF) {
			//cout << "INF" << " " << INF << " " << i;
			allVisited = false;
			break;
		}
	}
	if (allVisited) {
		cout << ret << endl;
	}
	else {
		cout << -1 << endl;
	}
	//fclose(stdin);
}
