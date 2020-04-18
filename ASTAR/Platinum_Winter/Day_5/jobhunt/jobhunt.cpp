#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 220

int d, p, n, f, s;
vector<pair<int, int> > adj[MAXN];
int dist[MAXN];
// first is the weight, second is the next node

int main() {
	cin >> d >> p >> n >> f >> s;
	--s;
	for (int i = 0; i < p; ++i) {
		int a, b;
		cin >> a >> b;
		adj[a-1].push_back(make_pair(-d, b-1));
	}
	for (int i = 0; i < f; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a-1].push_back(make_pair(c-d, b-1));
	}
	// for (int i = 0; i < n; ++i) {
	// 	cout << i << ": ";
	// 	for (int j = 0; j < adj[i].size(); ++j) {
	// 		cout << adj[i][j].second << "-" << adj[i][j].first << " ";
	// 	}
	// 	cout << endl;
	// }
	for (int i = 0; i < n; ++i) {
		dist[i] = INF;
	}
	dist[s] = -d;
	for (int iter = 0; iter < n; ++iter) {
		// for (int i = 0; i < n; ++i) {
		// 	cout << dist[i] << " ";
		// }
		// cout << endl;
		for (int i = 0; i < n; ++i) {
			if (dist[i] == INF) continue;
			for (int j = 0; j < adj[i].size(); ++j) {
				pair<int, int> edge = adj[i][j];
				int d = edge.first + dist[i];
				if (d < dist[edge.second]) {
					if (iter == n - 1) {
						// cout << "NEGATIVE CYCLE" << endl;
						cout << -1 << endl;
						return 0;
					}
					dist[edge.second] = d;
				}
			}
		}
	}
	int ans = -INF;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, -1*dist[i]);
		// cout << dist[i] << " ";
	}
	// cout << endl;
	cout << ans << endl;
}
