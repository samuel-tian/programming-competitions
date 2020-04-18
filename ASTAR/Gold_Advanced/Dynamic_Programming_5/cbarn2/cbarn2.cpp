/*input
6 2
2
5
4
2
6
2
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 100
#define MAXK 7

int n, k;
int targetDistribution[MAXN];
long long dp[MAXN][MAXK + 1][MAXN + 1];

void rotateTarget() {
	int last = targetDistribution[n - 1];
	for (int i = n - 1; i >= 1; --i) 
		targetDistribution[i] = targetDistribution[i - 1];
	targetDistribution[0] = last;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &targetDistribution[i]);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			for (int l = 0; l <= n; ++l) {
				dp[i][j][l] = INF;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		dp[i][0][0] = 0;
		for (int j = 1; j <= k; ++j) { // NUMBER OF COWS LEFT
			for (int l = 0; l < n; ++l) { // PREVIOUS ROW
				if (dp[i][j - 1][l] == INF) continue;
				long long ret = 0;
				for (int m = l + 1; m <= n; ++m) { // CURRENT ROW
					// printf("ret: %d\n", ret);
					dp[i][j][m] = min(dp[i][j][m], ret + dp[i][j - 1][l]);
					if (m == n) continue;
					ret += targetDistribution[m] * (m - l);
				}
			}
		}
		/*
		for (int j = 0; j <= k; ++j) {
			for (int l = 0; l <= n; ++l) {
				printf("%-12d ", dp[i][j][l]);
			}
			printf("\n");
		}
		printf("\n");
		*/
		rotateTarget();
	}

	long long ret = INF;
	for (int i = 0; i < n; ++i)
		ret = min(ret, dp[i][k][n]);
	int ans = (int) ret;
	printf("%d\n", ans);

	return 0;
}