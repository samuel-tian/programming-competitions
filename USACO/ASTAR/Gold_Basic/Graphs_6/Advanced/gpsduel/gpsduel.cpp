/*

*/
#include <iostream>
#include <climits>
#include <queue>
#include <utility>

using namespace std;

#define INF INTEGER_MAX
#define endl '\n'
#define MAXN 10000
#define MAXM 50000

int n, m;
int dis[MAXN], pDis[MAXN], qDis[MAXN];
int in[MAXM][4];
bool vis[MAXN];
vector<pair<int, int> > adj[MAXN];
priority_queue<pair<int, int> > pq;

void dij(int start) {

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> in[i][j];
		}
	}

	return 0;
}