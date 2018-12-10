#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <utility>

using namespace std;

#define endl '\n'
#define INF (int)((1LL<<31)-1)
#define MAXV 2500
typedef pair<int, long long> Edge;

int v, e;
bool visited[MAXV];
vector<Edge> adjacent[MAXV];

long long minSpanningTree(int start) {
	priority_queue<Edge, vector<Edge>, greater<Edge> > q;
	long long ret = 0;
	q.push(make_pair(0, start));
	while (!q.empty()) {
		Edge current = q.top();
		q.pop();
		if (visited[current.second]) continue;
		visited[current.second] = true;
		//cout << current.second + 1 << " " << current.first << endl;
		ret += current.first;
		for (int i = 0; i < adjacent[current.second].size(); ++i) {
			//if (!visited[adjacent[current.first][i].first]) {
			//	visited[adjacent[current.first][i].first] = true;
				q.push(adjacent[current.second][i]);
			//}
		}
	}
	return ret;
}

int main() {
	int verticeFrom, verticeTo;
	long long weight;
	cin >> v >> e;
	for (int i = 0; i < e; ++i) {
		cin >> verticeFrom >> verticeTo >> weight;
		verticeFrom--; verticeTo--;
		adjacent[verticeFrom].push_back(make_pair(weight, verticeTo));
		adjacent[verticeTo].push_back(make_pair(weight, verticeFrom));
	}
	/*for (int i = 0; i < v; ++i) {
		cout << i << ":";
		for (int j = 0; j < adjacent[i].size(); ++j) {
			cout << " " << adjacent[i][j].second;
		}
		cout << endl;
	}*/
	long long minCost = minSpanningTree(3);
	cout << minCost << endl;
	return 0;
}
