/*input
5
Ab3bd
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'
#define MAXN 5000

int main() {
	int n;
	cin >> n;
	char s[MAXN];
	scanf("%c", &s[0]);
	for (int i = 0; i < n; ++i) {
		scanf("%c", &s[i]);
	}
	int dp[n][3];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			dp[i][j] = 0;
		}
	}
	for (int gap = 1; gap < n; ++gap) {
		int k = gap % 3;
		for (int i = 0; i + gap < n; ++i) {
			int j = i + gap;
			if (s[i] == s[j]) {
				dp[i][k] = dp[i + 1][(k + 1) % 3];
			}
			else {
				dp[i][k] = min(dp[i][(k + 2) % 3], dp[i + 1][(k + 2) % 3]) + 1;
			}
			// cout << dp[i][k] << " ";
		}
		// cout << endl;
	}
	cout << dp[0][(n + 2) % 3] << endl;
	/*int dp[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = 0;
		}
	}
	for (int k = 1; k < n; ++k) {
		for (int i = 0; i + k < n; ++i) {
			int j = i + k;
			if (s[i] == s[j]) {
				dp[i][j] = dp[i + 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
}