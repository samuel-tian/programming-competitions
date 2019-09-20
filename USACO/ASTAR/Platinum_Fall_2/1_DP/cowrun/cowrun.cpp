#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 10000

int n, m;
int d[MAXN + 1];
int psum[MAXN + 1];
int dp[MAXN + 1];

int main() {
//	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
		psum[i + 1] = psum[i] + d[i];
	}
	for (int i = 1; i <= n; ++i) {
		/*for (int i = 0; i <= n; ++i) {
			cout << dp[i] << " ";
		}
		cout << endl;*/
		dp[i] = max(dp[i], dp[i - 1]);
		for (int j = 1; i - 2*j >= 0; ++j) {
			dp[i] = max(dp[i], dp[i - 2*j] + psum[i - j] - psum[i - 2*j]);
		}
	}
	/*for (int i = 0; i <= n; ++i) {
		cout << dp[i] << " ";
	}
	cout << endl;*/
	cout << dp[n] << endl;
}
