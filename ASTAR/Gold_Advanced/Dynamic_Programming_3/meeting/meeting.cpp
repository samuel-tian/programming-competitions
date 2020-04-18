/*input
3 3
1 3 1 2
1 2 1 2
2 3 1 2
*/
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 100
#define MAXT 10000

int n, m;
int bAdj[MAXN][MAXN];
int eAdj[MAXN][MAXN];
/* row is first field, col is second field */
bool bRet[MAXT+1], eRet[MAXT+1];

void bMeeting() {
	bool dp[MAXN][MAXT+1];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= 100 * n + 1; ++j) {
			dp[i][j] = false;
		}
	}
	dp[0][0] = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= 100 * n + 1; ++j) {
			if (!dp[i][j]) continue;
			for (int k = i + 1; k < n; ++k) {
				if (bAdj[i][k] != 0) {
					dp[k][j + bAdj[i][k]] = true;
				}
			}
		}
	}
	for (int i = 0; i < 100 * n + 1; ++i) {
		bRet[i] = dp[n-1][i];
	}
}

void eMeeting() {
	bool dp[MAXN][MAXT+1];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= 100 * n + 1; ++j) {
			dp[i][j] = false;
		}
	}
	dp[0][0] = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= 100 * n + 1; ++j) {
			if (!dp[i][j]) continue;
			for (int k = i + 1; k < n; ++k) {
				if (eAdj[i][k] != 0) {
					dp[k][j + eAdj[i][k]] = true;
				}
			}
		}
	}
	for (int i = 0; i < 100 * n + 1; ++i) {
		eRet[i] = dp[n-1][i];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int a, b, c, d;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		--a; --b;
		bAdj[min(a, b)][max(a, b)] = c;
		eAdj[min(a, b)][max(a, b)] = d;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (bAdj[i][j] != 0) {
				// printf("%d %d %d %d\n", i, j, bAdj[i][j], eAdj[i][j]);
			}
		}
	}
	bMeeting(); eMeeting();
	int ret = INF;
	for (int i = 0; i < 100 * n + 1; ++i) {
		// printf("%d %d\n", bRet[i], eRet[i]);
		if (bRet[i] && eRet[i]) {
			ret = i;
			break;
		}
	}
	if (ret == INF) printf("IMPOSSIBLE\n");
	else printf("%d\n", ret);
}