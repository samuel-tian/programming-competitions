#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define endl '\n'
#define MAXN 10000

int n;
vector<int> adj[MAXN];
int visited[MAXN];
int order[MAXN];
int counter = 1;

void toposort(int current) {
	if (visited[current] != 0) return;
	visited[current] = -1;
	for (int i = 0; i < adj[current].size(); ++i) {
		toposort(adj[current][i]);
	}
	visited[current] = counter;
	++counter;
}

int main() {
	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	toposort(0);
	for (int i = 0; i < n; ++i) {
		order[visited[i] - 1] = i;
	}
	fill(visited, visited)
	for (int i = 0; i < n; ++i) {
		cout << order[i] << " ";
	}
	cout << endl;
}
