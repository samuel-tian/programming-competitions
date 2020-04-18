#include <iostream>

using namespace std;

#define endl '\n'
#define MAXN 10000

int main() {
	int n, m;
	int rundist[MAXN];
	int dp[MAXN + 1];
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> rundist[i];
	}
	for (int i = 0; i <= n; ++i) {
		dp[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		dp[i + 1] = max(dp[i], dp[i + 1]);
		for (int j = 1; j <= (n - i) / 2 && j <= m; ++j) {
			int sum = 0;
			for (int k = i; k < i + j; ++k) {
				sum += rundist[k];
			}
			dp[i + 2 * j] = max(dp[i + 2 * j], dp[i] + sum);
		}
		// for (int j = 0; j <= n; ++j) {
		// 	cout << dp[j] << " ";
		// }
		// cout << endl;
	}
	cout << dp[n] << endl;
}