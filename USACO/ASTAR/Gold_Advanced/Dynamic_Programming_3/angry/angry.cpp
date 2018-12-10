/*input
5
8
10
3
11
1
*/

#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 50000

int n;
int position[MAXN];
int dp[2][MAXN];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> position[i];
	sort(position, position + n);

	dp[0][0] = 0;
	int tracker = 0;
	for (int i = 1; i < n; ++i) {
		while (tracker + 1 < i && position[i] - position[tracker] > dp[0][tracker] + 1) {
			++tracker;
		}
		dp[0][i] = max(position[i] - position[tracker], dp[0][tracker] + 1);
	}
	dp[1][n - 1] = 0;
	tracker = n - 1;
	for (int i = n - 2; i >= 0; --i) {
		while (tracker - 1 > i && position[tracker] - position[i] > dp[1][tracker] + 1) {
			--tracker;
		}
		dp[1][i] = max(position[tracker] - position[i], dp[1][tracker] + 1);
	}

	/*
	for (int i = 0; i < n; ++i) {
		cerr << dp[0][i] << " ";
	}
	cerr << endl;
	for (int i = 0; i < n; ++i) {
		cerr << dp[1][i] << " ";
	}
	cerr << endl;
	*/

	double ans = INF;
	int i = 0, j = n - 1;
	while (i < j) {
		int distance = position[j] - position[i];
		double ret = max(distance / 2.0, (double)(1 + max(dp[0][i], dp[1][j])));
		ans = min(ans, ret);
		if (dp[0][i + 1] < dp[1][j - 1]) ++i;
		else --j;
	}
	printf("%.1f\n", ans);
	return 0;
}