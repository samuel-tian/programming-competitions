#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define endl "\n"
const int INF = (int) ((1LL<<31) - 1);

int n, m;
int path[10000];
int islandDist[100][100];
int pathDanger[100][100];
int minIslandDist[100];
queue<int> q;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> path[i];
		path[i]--;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			islandDist[i][j] = INF;
			cin >> pathDanger[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		q.push(i);
		islandDist[i][i] = 0;
		while (!q.empty()) {
			int current = q.front();
			q.pop();
			for (int j = 0; j < n; j++) {
				if (j == current) continue;
				if (islandDist[i][j] > islandDist[i][current] + pathDanger[current][j]) {
					islandDist[i][j] = islandDist[i][current] + pathDanger[current][j];
					q.push(j);
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << islandDist[i][j] << " ";
		}
		cout << endl;
	}

	int sum = 0;
	for (int i = 0; i < m-1; i++) {
		sum += islandDist[path[i]][path[i+1]];
	}
	cout << sum << endl;

}
