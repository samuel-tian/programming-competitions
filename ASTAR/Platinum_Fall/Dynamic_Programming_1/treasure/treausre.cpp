/*input
4
30
25
10
35
*/

#include <iostream>

using namespace std;

#define endl '\n'
#define MAXN 5000

int main() {
	int n;
	int coins[MAXN];
	int total[MAXN + 1];
	int dp[MAXN];
	cin >> n;
	total[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
		total[i + 1] = total[i] + coins[i];
		dp[i] = coins[i];
	}
	/*for (int i = 0; i < n + 1; ++i) {
		cout << total[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout << dp[i] << " ";
	}
	cout << endl;*/
	for (int k = 1; k < n; ++k) {
		for (int i = 0; i + k < n; ++i) {
			dp[i] = total[i + k + 1] - total[i] - min(dp[i], dp[i + 1]);
			// cout << dp[i] << " ";
		}
		// cout << endl;
	}
	cout << dp[0] << endl;
}