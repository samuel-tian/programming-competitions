/*input
3 5 2 3
1
2
2
1
3
*/

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXT 1000

int t, a, s, b;
int ants[MAXT];
int dp[2][MAXT * 100 + 1];

int main() {
	cin >> t >> a >> s >> b;
	int q;
	for (int i = 0; i < a; ++i) {
		cin >> q;
		++ants[q - 1];
	}
	dp[0][0] = 1;
	for (int i = 0; i < t; ++i) {
		int prevRow = i % 2;
		int curRow = 1 - prevRow;
		dp[curRow][0] = 1;
		for (int j = 1; j <= a; ++j) {
			if (j <= ants[i]) {
				dp[curRow][j] = (dp[curRow][j - 1] + dp[prevRow][j]) % 1000000;
			}
			else {
				dp[curRow][j] = (dp[curRow][j - 1] + dp[prevRow][j] - dp[prevRow][j - ants[i] - 1]) % 1000000;
			}
		}
		for (int j = 0; j <= a; ++j) {
			dp[prevRow][j] = 0;
		}
	}
	long long ans = 0;
	for (int i = s; i <= b; ++i) {
		ans += dp[t % 2][i];
	}
	cout << (ans % 1000000 + 1000000) % 1000000 << endl;
}