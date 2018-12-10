/*input
5 10
0
1
4
9
10
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 10000
#define MAXL 100000

int n, l, d;
int cowPositions[10000];
int dp[2][MAXL + 1];

pair<int, int> cowRange(int cow) {
	int bl = cow * (d + 1);
	int tl = cow * (d + 2);
	int br = l - (n - 1 - cow) * (d + 2);
	int tr = l - (n - 1 - cow) * (d + 1);
	return make_pair(max(bl, br), min(tl, tr));
}

int main() {
	scanf("%d%d", &n, &l);
	d = (l - n) / (n - 1);
	for (int i = 0; i < n; ++i)
		scanf("%d", &cowPositions[i]);

	fill(dp[0], dp[0] + MAXL + 1, INF);
	dp[0][0] = cowPositions[0];
	for (int i = 1; i < n; ++i) {
		pair<int, int> loopRange = cowRange(i - 1);
		pair<int, int> breakRange = cowRange(i);
		fill(dp[i % 2] + breakRange.first, dp[i % 2] + breakRange.second + 1, INF);
		/*
		printf("Before:  ");
		for (int j = 0; j <= l; ++j)
			printf("%-11d ", dp[i % 2][j]);
		printf("\n");
		*/
		for (int j = loopRange.first; j <= loopRange.second; ++j) {
			if (dp[(i + 1) % 2][j] != INF) {
				if (j + d + 1 > breakRange.second + 1) continue;
				dp[i % 2][j + d + 1] = min(dp[i % 2][j + d + 1], dp[(i + 1) % 2][j] + abs(cowPositions[i] - j - d - 1));
				if (j + d + 2 > breakRange.second + 1) continue;
				dp[i % 2][j + d + 2] = min(dp[i % 2][j + d + 2], dp[(i + 1) % 2][j] + abs(cowPositions[i] - j - d - 2));
			}
		}
		/*
		printf("After:   ");
		for (int j = 0; j <= l; ++j)
			printf("%-11d ", dp[i % 2][j]);
		printf("\n");
		*/
	}
	printf("%d\n", dp[(n - 1) % 2][l]);
}