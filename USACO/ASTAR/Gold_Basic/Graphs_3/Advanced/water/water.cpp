#include <iostream>

using namespace std;

#define INF (int)((1LL<<31)-1)
#define endl '\n'
#define MAXN 300

int n;
int pipeCost[MAXN][MAXN];
int wellCost[MAXN], cost[MAXN];
bool visited[MAXN];

int minPasture() {
	int ret, minCost = INF;
	for (int i = 0; i < n; ++i) {
		if (minCost > cost[i] && !visited[i]) {
			minCost = cost[i];
			ret = i;
		}
	}
	return ret;
}

int mst() {
	for (int i = 0; i < n; ++i) {
		cost[i] = wellCost[i];
	}
	// int start = minPasture();
	// visited[start] = true;
	for (int times = 0; times < n-1; ++times) {
		int next = minPasture();
		//cout << "next: " << next << endl;
		visited[next] = true;
		for (int i = 0; i < n; ++i) {
			if (i == next) continue;
			int costOfPipe = pipeCost[next][i];
			if (!visited[i] && costOfPipe < cost[i]) {
				cost[i] = costOfPipe;
			}
		}
	}

	int ret = 0;
	for (int i : cost) {
		ret += i;
	}
	return ret;
}

int main() {
	//freopen("water_cases\\water.10.out", "r", stdin);
	//cin >> n; cout << n << endl; fclose(stdin);
	//freopen("water_cases\\water.10.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> wellCost[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> pipeCost[i][j];
		}
	}
	cout << mst() << endl;
}
