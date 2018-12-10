/*input

*/
#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 40000
#define MAXO 50
#define MAXF 50
#define MAXM 100

int n, o, f, m;
int candyOptions[MAXO];
int favoriteNumber[MAXF];
int dp[MAXN+MAXM+1];
int visited[MAXN+MAXM+1];
bool toBreak = false;

bool favoriteFind(int a) {
	return binary_search(favoriteNumber, favoriteNumber+f, a);
}

int knapsack(int candiesLeft) {
	// printf("Candies Left: %d\n", candiesLeft);
	if (toBreak) return -1;
	if (dp[candiesLeft] != -1) {
		return dp[candiesLeft];
	}
	if (candiesLeft == 0) {
		dp[candiesLeft] = 0;
		return dp[candiesLeft];
	}
	
	if (favoriteFind(candiesLeft)) {
		if (visited[candiesLeft] > 2*MAXF) {
			toBreak = true;
			return -1;
		}
		++visited[candiesLeft];
		return knapsack(candiesLeft+m);
		if (toBreak) return -1;
	}

	int ret = 0;
	for (int i = 0; i < o; ++i) {
		if (candiesLeft - candyOptions[i] < 0) continue;
		ret = max(ret, knapsack(candiesLeft - candyOptions[i]) + candyOptions[i]);
		if (toBreak) return -1;
	}
	dp[candiesLeft] = ret;
	return dp[candiesLeft];
}

int main() {
	scanf("%d%d%d%d", &n, &o, &f, &m);
	for (int i = 0; i < o; ++i) 
		scanf("%d", &candyOptions[i]);
	for (int i = 0; i < f; ++i) {
		int a;
		scanf("%d", &a);
		if (a != n)
			favoriteNumber[i] = a;
		else {
			--f;
			--i;
		}

	}
	sort(favoriteNumber, favoriteNumber+f);

	fill(dp, dp+n+m+1, -1);
	int ans = knapsack(n);
	if (toBreak) printf("-1\n");
	else printf("%d\n", ans);

	return 0;
}