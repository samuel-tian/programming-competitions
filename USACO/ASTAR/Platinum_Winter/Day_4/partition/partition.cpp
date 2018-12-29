#include <iostream>
#include <climits>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 15

int n, k;
int pastures[MAXN][MAXN];
int sum[MAXN + 1][MAXN + 1];
int dp[MAXN + 1][2*MAXN-2];
bool vfence[MAXN + 1];
int ans = INF;

int calc(int x1, int y1, int x2, int y2) {
	// (x2, y2) > (x1, y1)
	if (x1>=n || y1>=n || x2>=n || y2>=n) return -1;
	return sum[x2+1][y2+1] - sum[x1][y2+1] - sum[x2+1][y1] + sum[x1][y1];
}

int cost(int r1, int r2) {
	int ret = 0;
	int lastfence = 0;
	for (int i = 1; i <= n; ++i) {
		if (vfence[i]) {
			ret = max(ret, calc(r1, lastfence, r2-1, i-1));
			lastfence = i;
		}
	}
	return ret;
}

void recurse(int x, int fencesused) {
	if (x == n) {
		// cout << "FENCE: ";
		// for (int i = 0; i < n; ++i) {
		// 	cout << vfence[i] << " ";
		// }
		// cout << endl;
		// there is always going to be a fence at y=n
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= k - fencesused; ++j) {
				dp[i][j] = INF;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= k - fencesused; ++j) {
				if (dp[i][j] == INF) continue;
				if (j != k - fencesused) {
					for (int l = 1; i+l <= n; ++l) {
						dp[i+l][j+1] = min(dp[i+l][j+1], max(dp[i][j], cost(i, i+l)));
					}
				}
				dp[n][j] = min(dp[n][j], max(dp[i][j], cost(i, n)));
			}
		}
		// for (int i = 0; i <= n; ++i) {
		// 	for (int j = 0; j <= k-fencesused; ++j) {
		// 		printf("%-11d", dp[i][j]);
		// 	}
		// 	cout << endl;
		// }
		ans = min(ans, dp[n][k-fencesused]);
		return;
	}
	recurse(x+1, fencesused);
	if (fencesused+1 <= k) {
		vfence[x] = true;
		recurse(x+1, fencesused+1);
		vfence[x] = false;
	}
	return;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> pastures[i][j];
		}
	}
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			if (i * j == 0) sum[i][j] = 0;
			else sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + pastures[i-1][j-1];
		}
	}
	// for (int i = 0; i <= n; ++i) {
	// 	for (int j = 0; j <= n; ++j) {
	// 		cout << sum[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	vfence[n] = true;
	recurse(1, 0);
	cout << ans << endl;
}
