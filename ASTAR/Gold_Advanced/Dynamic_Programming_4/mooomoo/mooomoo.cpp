/*input
5 2
5
7
0
17
16
20
19
*/
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 100
#define MAXB 20
#define MAXV 100000

int n, b;
int v[MAXN];
int breedVolume[MAXB];
int dp[MAXV+1];

int knapsack(int volume) {
	if (dp[volume] != INF)
		return dp[volume];
	if (volume == 0) {
		dp[volume] = 0;
		return dp[volume];
	}

	int ret = INF;
	for (int i = 0; i < b; ++i) {
		if (volume - breedVolume[i] < 0) continue; 
		int ks = knapsack(volume-breedVolume[i]);
		if (ks == INF) continue;
		ret = min(ret, ks+1);
	}
	dp[volume] = ret;
	return dp[volume];

}

int main() {
	cin >> n >> b;
	for (int i = 0; i < b; ++i) 
		cin >> breedVolume[i];
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	for (int i = n-1; i > 0; --i)
		if (v[i-1] != 0)
			v[i] -= v[i-1]-1;

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		fill(dp, dp+v[i]+1, INF);
		int ks = knapsack(v[i]);
		if (ks == INF) {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		ret += ks;
	}

	/*
	for (int i = 0; i < n; ++i)
		printf("%d ", v[i]);
	printf("\n");
	for (int i = 0; i < n; ++i)
		printf("%d ", dp[i][v[i]]);
	printf("\n");
	*/

	cout << ret << endl;
	return 0;
}