#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

#define INF INT_MAX
#define MAXN 2000

int n, a, b;
int cowPositions[MAXN];
double dp[MAXN + 1];

void printArray(double arr[]) {
	for (int i = 0; i <= n; ++i)
		printf("%-12.1f ", arr[i]);
	printf("\n");
}

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; ++i)
		scanf("%d", &cowPositions[i]);
	sort(cowPositions, cowPositions + n);

	fill(dp, dp + n + 1, INF);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] = min(dp[i], dp[j] + a + b * (cowPositions[i - 1] - cowPositions[j]) / 2.0);
		}
	}

	// printArray(dp);

	if ((int) dp[n] == dp[n]) printf("%d\n", (int) dp[n]);
	else printf("%.1f\n", dp[n]);

	return 0;
}