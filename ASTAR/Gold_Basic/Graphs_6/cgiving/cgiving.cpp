#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>

using namespace std;

#define endl '\n'
#define INF (int)((1LL<<31)-1)
#define MAXN 50000

int n, m, b;
int distFromBarn[MAXN];
bool visited[MAXN];
vector<pair<int, int> > adjacent[MAXN];
priority_queue<pair<int, int> > pq;

void dijkstra() {
	fill(distFromBarn, distFromBarn+n, INF);
	distFromBarn[0] = 0;
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		int cur = pq.top().second;
		pq.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		for (int i = 0; i < adjacent[cur].size(); ++i) {
			pair<int, int> next = adjacent[cur][i];
			if (distFromBarn[cur]+next.first < distFromBarn[next.second]) {
				distFromBarn[next.second] = distFromBarn[cur] + next.first;
				pq.push(make_pair(-distFromBarn[next.second], next.second));
			}
		}
	}
}

int main() {
	//freopen("cgiving_cases\\cgiving.2.in", "r", stdin);
	cin >> n >> m >> b;
	int one, two, weight;
	for (int i = 0; i < m; ++i) {
		cin >> one >> two >> weight;
		--one; --two;
		adjacent[one].push_back(make_pair(weight, two));
		adjacent[two].push_back(make_pair(weight, one));
	}

	dijkstra();
	for (int i = 0; i < b; ++i) {
		cin >> one >> two;
		cout << distFromBarn[--one]+distFromBarn[--two] << endl;
	}

	//fclose(stdin);
	return 0;
}
