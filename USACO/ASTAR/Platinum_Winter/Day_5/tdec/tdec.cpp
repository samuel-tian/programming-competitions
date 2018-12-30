#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 100000

long long n;
long long parent[MAXN];
vector<long long> children[MAXN];
long long ornaments[MAXN][2];
long long cost[MAXN];
long long ornamentsused[MAXN];

long long traversal[MAXN];
long long counter = 0;
void dfs(long long current) {
	for (long long i = 0; i < children[current].size(); ++i) {
		dfs(children[current][i]);
	}
	traversal[counter] = current;
	++counter;
}

int main() {
	cin >> n;
	for (long long i = 0; i < n; ++i) {
		cin >> parent[i];
		--parent[i];
		cin >> ornaments[i][0] >> ornaments[i][1];
		if (parent[i] == -2) continue;
		children[parent[i]].push_back(i);
	}
	dfs(0);
	// for (long long i = 0; i < n; ++i) {
	// 	cout << i << ": ";
	// 	for (long long j = 0; j < children[i].size(); ++j) {
	// 		cout << children[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// for (long long i = 0; i < n; ++i) {
	// 	cout << traversal[i] << " ";
	// }
	// cout << endl;
	for (long long k = 0; k < n; ++k) {
		long long i = traversal[k];
		long long ornamentsneeded = ornaments[i][0];
		long long mincost = ornaments[i][1];
		for (long long j = 0; j < children[i].size(); ++j) {
			long long child = children[i][j];
			ornamentsneeded -= ornamentsused[child];
			cost[i] += cost[child];
			mincost = min(mincost, ornaments[child][1]);
		}
		if (ornamentsneeded < 0) {
			ornaments[i][0] -= ornamentsneeded;
			ornaments[i][1] = mincost;
		}
		else {
			cost[i] += ornamentsneeded * mincost;
			ornaments[i][1] = mincost;
		}
		ornamentsused[i] = ornaments[i][0];
	}
	// for (long long i = 0; i < n; ++i) {
	// 	cout << cost[i] << " ";
	// }
	// cout << endl;
	cout << cost[0] << endl;
}
