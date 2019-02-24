#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define endl '\n'
#define MAXN 10000
#define INF INT_MAX

int main() {
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);
	int n, k;
	int skill[MAXN];
	int dp[MAXN + 1];
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> skill[i];
	}
	fill(dp, dp + n + 1, 0);
	dp[0] = 0;
	// watch out for when k > n
	for (int i = 0; i < n; ++i) {
		int maxskill = 0;
		for (int j = 1; j <= k; ++j) {
			if (i + j - 1 > n) continue;
			maxskill = max(maxskill, skill[i + j - 1]);
			dp[i + j] = max(dp[i + j], dp[i] + maxskill * j);
		}
	}
	/*for (int i = 0; i <= n; ++i) {
		cout << dp[i] << " ";
	}
	cout << endl;*/
	cout << dp[n] << endl;
}