/*input
4 100 200 1
1 4
2 3
3 2
4 0
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
#define MAXAB 10

int n, insertCost, removeCost, replaceCost;
int start[MAXN * MAXAB], finish[MAXN * MAXAB];
int dp[MAXN * MAXAB +1][MAXN * MAXAB +1];

int MIN(int a, int b, int c) {
	return min(min(a, c), b);
}

int editDistance(int startCounter, int finishCounter) {
	/*
	printf("Counters: %d, %d\n", startCounter, finishCounter);
	for (int i = 0; i <= startCounter; ++i)
		printf("%d, ", start[i]);
	printf("\n");
	for (int i = 0; i <= finishCounter; ++i)
		printf("%d, ", finish[i]);
	printf("\n\n");
	*/
	if (startCounter == 0) return insertCost * finishCounter;
	if (finishCounter == 0) return removeCost * startCounter;
	if (dp[startCounter][finishCounter] != -1) return dp[startCounter][finishCounter];
	if (start[startCounter] == finish[finishCounter]) {
		dp[startCounter][finishCounter] = editDistance(startCounter - 1, finishCounter - 1);
		return dp[startCounter][finishCounter];
	}

	int ins = insertCost + editDistance(startCounter, finishCounter - 1);
	int rem = removeCost + editDistance(startCounter - 1, finishCounter);
	int rep = replaceCost * abs(start[startCounter] - finish[finishCounter]) + editDistance(startCounter - 1, finishCounter - 1);
	dp[startCounter][finishCounter] = MIN(ins, rem, rep);
	return dp[startCounter][finishCounter];
}

int main() {
	scanf("%d%d%d%d", &n, &insertCost, &removeCost, &replaceCost);
	int a, b, al = -1, bl = -1;	
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		for (int j = 0; j < a; ++j) {
			++al;
			start[al] = i + 1;
		}
		for (int j = 0; j < b; ++j) {
			++bl;
			finish[bl] = i + 1;
		}
	}
	for (int i = 0; i <= al; ++i)
		for (int j = 0; j <= bl; ++j)
			dp[i][j] = -1;
	printf("%d\n", editDistance(al, bl));
}