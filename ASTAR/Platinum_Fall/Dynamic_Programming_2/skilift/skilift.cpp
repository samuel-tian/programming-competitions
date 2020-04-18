/*input
13 4
0
1
0
2
4
6
8
6
8
8
9
11
12
*/

#include <iostream>
#include <climits>

using namespace std;

#define endl '\n'
#define MAXN 5000
#define INF INT_MAX

int main() {
	int n, k;
	int heights[MAXN];
	int dp[MAXN];
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> heights[i];
	}
	for (int i = 0; i < n; ++i) {
		dp[i] = INF;
	}
	dp[0] = 1;
	for (int i = 0; i < n - 1; ++i) {
		/*for (int j = 0; j < n; ++j) {
			printf("%-11d ", dp[j]);
		}
		cout << endl;*/
		double maxslope = -1 * INF;
		for (int j = 1; j <= k && i + j < n; ++j) {
			if ((heights[i + j] - heights[i]) / ((double) j) < maxslope) continue;
			else maxslope = (heights[i + j] - heights[i]) / ((double) j);
			dp[i + j] = min(dp[i + j], dp[i] + 1);
			
		}
	}
	cout << dp[n - 1] << endl;
}