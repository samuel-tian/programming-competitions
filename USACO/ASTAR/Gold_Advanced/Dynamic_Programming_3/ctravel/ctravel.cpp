/*input
4 5 6
...*.
...*.
.....
.....
1 3 1 5
*/
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 100
#define MAXM 100
#define MAXT 15

int n, m, t;
int r1, c1, r2, c2;
bool pasture[MAXN][MAXM];
int dp[MAXN][MAXM][MAXT];

int travel(int r, int c, int time) {
	// printf("r: %d, c: %d, time: %d\n", r, c, time);
	if (!(r >= 0 && r < n && c >= 0 && c < m)) {
		return 0;
	}
	if (!pasture[r][c]) {
		dp[r][c][time] = 0;
		return 0;
	}
	if (dp[r][c][time] != -1) {
		return dp[r][c][time];
	}
	if (r == r1 && c == c1 && time == 0) {
		dp[r][c][time] = 1;
		return dp[r][c][time];
	}
	if ((r != r1 || c != c1) && time == 0) {
		dp[r][c][time] = 0;
		return dp[r][c][time];
	}
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int ret = 0;
	for (int i = 0; i < 4; ++i) {
		ret += travel(r+dx[i], c+dy[i], time-1);
	}
	dp[r][c][time] = ret;
	return dp[r][c][time];
}

int main() {
	scanf("%d%d%d", &n, &m, &t);
	// printf("%d %d %d\n", n, m, t);
	char in;
	for (int i = 0; i < n; ++i) {
		scanf("%c", &in);
		for (int j = 0; j < m; ++j) {
			// printf("i: %d, j: %d\n", i, j);
			scanf("%c", &in);
			pasture[i][j] = in == '.' ? true : false;
			// printf("%c", in);
		}
		// printf("\n");
	}
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	// printf("%d %d %d %d\n", r1, c1, r2, c2);
	--r1; --c1; --r2; --c2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k <= t; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}
	printf("%d\n", travel(r2, c2, t));
}