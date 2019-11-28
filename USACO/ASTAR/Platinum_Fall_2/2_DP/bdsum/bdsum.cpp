#include <bits/stdc++.h>

using namespace std;

#define MAXN 10
#define INF INT_MAX
#define endl '\n'

int n, s;
int dp[MAXN][MAXN];
int perm[MAXN];

int calcSum() {
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += perm[i] * dp[n - 1][i];
	}
	return ret;
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		perm[i] = i + 1;
	}
	while (calcSum() != s) {
		next_permutation(perm, perm + n);
	}
	for (int i = 0; i < n; ++i) {
		cout << perm[i];
		i == n-1 ? cout << endl : cout << " ";
	}
}