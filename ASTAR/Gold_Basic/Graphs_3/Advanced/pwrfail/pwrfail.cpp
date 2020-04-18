#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

#define INF (int)((1LL<<31)-1)
#define endl '\n'
#define MAXN 1000

int n, w;
double m;
double wireCost[MAXN];
bool visited[MAXN], oneVisited[MAXN];
pair<int, int> poles[MAXN];
bool adjacent[MAXN][MAXN];

double euclidDist(pair<int, int> a, pair<int, int> b) {
	long long xDist = pow(a.first - b.first, 2);
	long long yDist = pow(a.second - b.second, 2);
	return sqrt(xDist + yDist);
}

int minWire() {
	int ret = 0;
	double minCost = (double)INF;
	for (int i = 0; i < n; ++i) {
		if (wireCost[i] < minCost && !visited[i]) {
			ret = i;
			minCost = wireCost[i];
		}
	}
	return ret;
}

void dijkstra() {
	fill(wireCost, wireCost + n, (double)INF);
	wireCost[n-1] = 0.0;
	for (int times = 0; times < n-1; ++times) {
		int next;
		if (times == 0) next = n-1;
		else next = minWire();
		//cout << "next: " << next << endl;
		visited[next] = true;
		for (int i = 0; i < n; ++i) {
			if (next == i) continue;
			double distance;
			if (adjacent[next][i]) distance = 0;
			else distance = euclidDist(poles[next], poles[i]);
			if (distance < m && !visited[i] && wireCost[next] + distance < wireCost[i]) {
				wireCost[i] = wireCost[next] + distance;
			}
		}
	}
	/*for (int i = 0; i < n; ++i) {
		if (wireCost[i] == INF) {
			cout << "inf" << " ";
		}
		else cout << wireCost[i] << " ";
	}
	cout << endl;*/
}

int main() {
	//freopen("pwrfail_cases\\pwrfail.20.out", "r", stdin);
	//cin >> n; cout << "ans: " << n << endl; fclose(stdin);
	freopen("pwrfail_cases\\pwrfail.4.in", "r", stdin);
	cin >> n >> w >> m;
	for (int i = 0; i < n; ++i) {
		cin >> poles[i].first >> poles[i].second;
	}
	for (int i = 0; i < w; ++i) {
		int first, second;
		cin >> first >> second;
		--first; --second;
		adjacent[first][second] = true;
		adjacent[second][first] = true;
	}
	dijkstra();
	if (wireCost[0] == (double)INF) cout << -1 << endl;
	else cout << (long long) (wireCost[0]*1000) << endl;
}
