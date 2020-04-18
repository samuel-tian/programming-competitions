/*input

*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

#define INF INT_MAX
#define MAXN 248

int n;
int sequence[MAXN];
int dp[MAXN][MAXN];
/*
int game(int start, int finish) {
	if (dp[start][finish] != -1) return dp[start][finish];
	if (start == finish) {
		dp[start][finish] = sequence[start];
		return sequence[start];
	}

	for (int i = start; i < finish; ++i) {
		int a = game(start, i);
		int b = game(i + 1, finish);
		if (a == b && a != -1) {
			dp[start][finish] = max(dp[start][finish], a + 1);
		}
	}
	return dp[start][finish];
}
*/
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &sequence[i]);

	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j)
			dp[i][j] = -1;


	for (int length = 1; length <= n; ++length) {
		for (int start = 0; start <= n - length; ++start) {
			int finish = start + length - 1;
			if (length == 1) dp[start][finish] = sequence[finish];
			for (int i = 0; i <= finish - start; ++i) {
				if (dp[start][start + i] == dp[start + i + 1][finish] && dp[start][start + i] != -1) {
					dp[start][finish] = max(dp[start][finish], dp[start][start + i] + 1);
				}
			}
		}
	}

	/*
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			printf("%3d ", dp[i][j]);
		printf("\n");
	}
	*/

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			ret = max(ret, dp[i][j]);
		}
	}
	printf("%d\n", ret);

	return 0;
}