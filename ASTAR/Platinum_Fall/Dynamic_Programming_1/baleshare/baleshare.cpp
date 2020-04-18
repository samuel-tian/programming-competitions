/*input
20
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
100
20
94
*/

#include <iostream>
#include <climits>

using namespace std;

#define endl '\n'
#define MAXN 20
#define MAXS 701
#define INF INT_MAX

int n;
int bales[MAXN];
bool dp[MAXN + 1][MAXS][MAXS];

int main() {
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> bales[i];
		sum += bales[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < MAXS; ++j) {
			for (int k = 0; k < MAXS; ++k) {
				dp[i][j][k] = false;
			}
		}
	}
	dp[0][0][0] = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < MAXS; ++j) {
			for (int k = 0; k < MAXS; ++k) {
				if (dp[i][j][k] == true && j + bales[i] < MAXS && k + bales[i] < MAXS) {
					dp[i + 1][j][k] = true;
					dp[i + 1][j + bales[i]][k] = true;
					dp[i + 1][j][k + bales[i]] = true;
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < MAXS; ++i) {
		for (int j = 0; j < MAXS; ++j) {
			if (dp[n][i][j]) {
				ans = min(ans, max(sum - i - j, max(i, j)));
			}
		}
	}
	cout << ans << endl;;
}