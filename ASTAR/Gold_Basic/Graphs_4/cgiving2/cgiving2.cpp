#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define INF (int)((1LL<<31)-1)
#define MAXN 2500
#define endl '\n'
typedef pair<int, int> Pasture;

int n, m, b;
int distFromBarn[MAXN];
vector<Pasture> adjacent[MAXN];
//bool visited[MAXN];

void dijkstra() {
	fill(distFromBarn, distFromBarn + n, INF);
	distFromBarn[0] = 0;
	//visited[0] = true;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		//if (visited[current] && current != 0) continue;
		cout << "current" << " " << current << endl;
		for (int i = 0; i < adjacent[current].size(); ++i) {
			Pasture next = adjacent[current][i];
			if (distFromBarn[next.first] < distFromBarn[current] + next.second) {
				continue;
			}
			distFromBarn[next.first] = distFromBarn[current] + next.second;
			q.push(next.first);
		}
		//visited[current] = true;
		for (int i = 0; i < n; ++i) {
			cout << distFromBarn[i] << " ";
		}
		cout << endl;
	}
	return;
}

int main() {
	freopen("cgiving2_cases\\cgiving.10.in", "r", stdin);
	cin >> n >> m >> b;
	int one, two, weight;
	for (int i = 0; i < m; ++i) {
		cin >> one >> two >> weight;
		--one; --two;
		adjacent[one].push_back(make_pair(two, weight));
		adjacent[two].push_back(make_pair(one, weight));
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << i+1 << ": ";
		for (int j = 0; j < adjacent[i].size(); ++j) {
			cout << adjacent[i][j].first << " ";
		}
		cout << endl;
	}
	cout << endl;
	dijkstra();
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << i+1 << ": " << distFromBarn[i] << endl;
	}
	cout << endl;

	for (int i = 0; i < b; ++i) {
		cin >> one >> two;
		--one; --two;
		cout << distFromBarn[one] + distFromBarn[two] << endl;
	}
	return 0;
}
