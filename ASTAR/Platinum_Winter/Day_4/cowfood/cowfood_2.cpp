#include <iostream>
#include <climits>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 12
#define MOD 100000000

int n, m;
int grid[MAXN+1][MAXN+1];
int dp[MAXN+1][MAXN+1][1<<MAXN];

int recurse(int r, int c) {
	// cout << r << " " << c << endl;
	if (r == n + 1) return 1;
	int nr = r, nc = c + 1;
	if (nc > m) {
		++nr;
		nc = 1;
	}
	int mask = 0;
	for (int i = 1; i <= m; ++i) {
		if (i < c) {
			mask |= grid[r][i]<<(i-1);
		}
		else {
			mask |= grid[r-1][i]<<(i-1);
		}
	}
	if (dp[r][c][mask] != -1) return dp[r][c][mask];
	if (grid[r][c] == 0) {
		dp[r][c][mask] = recurse(nr, nc);
		return dp[r][c][mask];
	}
	grid[r][c] = 0;
	int ret = recurse(nr, nc);
	grid[r][c] = 1;
	if (grid[r-1][c] + grid[r][c-1] == 0)
		ret += recurse(nr, nc);
	dp[r][c][mask] = ret;
	return dp[r][c][mask];
}

int main() {
	cin >> n >> m;
	// one indexed grid
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i*j == 0) grid[i][j] = 0;
			else cin >> grid[i][j];
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k < 1<<m; ++k) {
				if (i*j == 0) dp[i][j][k] = 0;
				else dp[i][j][k] = -1;
			}
		}
	}
	recurse(1, 1);
	// for (int k = 0; k < 1<<m; ++k) {
	// 	for (int i = 0; i <= n; ++i) {
	// 		for (int j = 0; j <= m; ++j) {
	// 			printf("%2d ", dp[i][j][k]);
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }
	cout << dp[1][1][0] % MOD << endl;
}
