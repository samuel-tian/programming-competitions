/*input
3 5
7 23 -5 -24 16
5 21 -4 10 23
-21 5 -4 -20 20
*/
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define endl '\n'
#define MAXF 100
#define INF INT_MAX

int main() {
	int f, v;
	int aesthetic[MAXF][MAXF];
	int dp[MAXF][MAXF];
	cin >> f >> v;
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < v; ++j) {
			cin >> aesthetic[i][j];
		}
	}
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < v; ++j) {
			dp[i][j] = 0;
		}
	}
	for (int i = 0; i < f; ++i) {
		for (int j = i; j <= v - f + i; ++j) {
			int a = -INF;
			if (i == 0) a = 0;
			else {
				for (int k = 0; k < j; ++k) {
					a = max(a, dp[i - 1][k]);
				}
			}
			dp[i][j] = a + aesthetic[i][j];
		}
	}
	/*for (int i = 0; i < f; ++i) {
		for (int j = 0; j < v; ++j) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	int ans = 0;
	for (int i = 0; i < v; ++i) {
		ans = max(ans, dp[f - 1][i]);
	}
	cout << ans << endl;
}