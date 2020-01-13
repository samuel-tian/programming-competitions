#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 10000

int n;
int c[MAXN];
int psum[MAXN];
int dp[MAXN][2];

int prefix(int i, int j) {
	return psum[j + 1] - psum[i];
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		psum[i + 1] = psum[i] + c[i];
	}
	for (int i = 0; i < n; ++i) {
		dp[i][1] = c[i];
	}
//	for (int i = 0; i < n; ++i) {
//		cout << dp[i][1] << " ";
//	}
//	cout << endl;
	for (int j = 2; j <= n; ++j) {
		for (int i = 0; i < n; ++i) {
			dp[i][j % 2] = 0;
		}
		for (int i = 0; i < n; ++i) {
			if (i + j - 1 >= n) continue;
			dp[i][j % 2] = max(c[i] + prefix(i+1, i+j-1) - dp[i+1][(j-1) % 2], c[i+j-1] + prefix(i, i+j-2) - dp[i][(j-1)%2]);
		}
//		for (int i = 0; i < n; ++i) {
//			cout << dp[i][j % 2] << " ";
//		}
//		cout << endl;
	}
	cout << dp[0][n % 2] << endl;
}
