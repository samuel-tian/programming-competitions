#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN 400
#define INF INT_MAX

int n, k;
int snakes[MAXN];
int psum[MAXN + 1];
int dp[MAXN + 1][MAXN + 1];

int main() {
//	freopen("input.txt", "r", stdin);
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	cin >> n >> k;
	psum[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> snakes[i];
		psum[i + 1] = psum[i] + snakes[i];
	}
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j <= k + 1; ++j) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (dp[i][j] == INF) continue;
			int maxSnake = -1;
			int snakeSum = 0;
			for (int l = 1; i + l <= n; ++l) {
				maxSnake = max(maxSnake, snakes[i + l - 1]);
				snakeSum += snakes[i + l - 1];
				dp[i + l][j + 1] = min(dp[i][j] + maxSnake * l - (snakeSum), dp[i + l][j + 1]);
			}
//			for (int i = 0; i <= n; ++i) {
//				for (int j = 0; j <= k + 1; ++j) {
//					printf("%-12d ", dp[i][j]);
//				}
//				cout << endl;
//			}
//			cout << endl;
		}
	}

	cout << dp[n][k + 1] << endl;
}
