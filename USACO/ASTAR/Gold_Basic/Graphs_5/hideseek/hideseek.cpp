#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define INF (int)((1LL<<31)-1)
#define MAXN 20000

int n, m;
int dist[MAXN];
vector<int> adjacent[MAXN];

int fillDist(int start) {
	fill(dist, dist + n, INF);
	dist[start] = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < adjacent[current].size(); ++i) {
			int next = adjacent[current][i];
			if (dist[next] > dist[current] + 1) {
				dist[next] = dist[current] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	//int i1, i2, i3;
	//freopen("hideseek_cases\\hideseek.10.out", "r", stdin);
	//cin >> i1 >> i2 >> i3; cout << i1 << " " << i2 << " " << i3 << endl; fclose(stdin);
	//freopen("hideseek_cases\\hideseek.10.in", "r", stdin);
	cin >> n >> m;
	int first, second;
	for (int i = 0; i < m; ++i) {
		cin >> first >> second;
		first = first - 1, second = second - 1;
		adjacent[first].push_back(second);
		adjacent[second].push_back(first);
	}

	fillDist(0);

	int barn = INF, path = 0, num = 0;
	for (int i = 1; i < n; ++i) {
		if (dist[i] == path) ++num;
		else if (dist[i] > path) { barn = i; num = 1; path = dist[i]; }
	}
	cout << barn+1 << " " << path << " " << num << endl;
}
