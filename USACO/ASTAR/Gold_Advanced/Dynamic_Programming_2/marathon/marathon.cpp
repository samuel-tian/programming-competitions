/*input

*/
#include <iostream>
#include <utility>
#include <cmath>
#include <climits>

using namespace std;

#define INF (int)((1LL<<31)-1);
#define endl '\n'
#define MAXN 500

int n, k;
int dis[MAXN][MAXN], dp[MAXN][MAXN];
pair<int, int> points[MAXN];

int dist(pair<int, int> a, pair<int, int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> points[i].first >> points[i].second;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dis[i][j] = dist(points[i], points[j]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (dp[i][j] == INT_MAX) continue;
			for (int m = 1; m+i < n && m <= k-j+1; ++m) {
				int nextPoint = i+m;
				int nextSkip = m-1+j;
				dp[nextPoint][nextSkip] = min(dp[nextPoint][nextSkip], dp[i][j] + dis[nextPoint][i]);
			}
			/*
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <= k; ++j) {
					if (dp[i][j] == INT_MAX) cout << "INF" << " ";
					else cout << dp[i][j] << "\t";
				}
				cout << endl;
			}
			cout << endl;
			*/
		}
	}

	/*
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j < n; ++j) {
			if (dp[j][i] == INF) continue;
			for (int m = 1; m <= k-i+1; ++m) {
				int nextPoint = j+m;
				int nextSkip = m-1; 
				dp[nextPoint][nextSkip] = min(dp[nextPoint][nextSkip], dp[j][i] + dis[nextPoint][j]);
			}
		}
	}
	*/

	cout << dp[n-1][k] << endl;
}