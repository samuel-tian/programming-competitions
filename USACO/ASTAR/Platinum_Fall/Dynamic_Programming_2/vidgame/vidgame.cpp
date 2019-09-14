#include <iostream>
#include <climits>
#include <algorithm>
#include <utility>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 50
#define MAXG 10
#define MAXV 100000

int n, v;
int consolePrice[MAXN];
int numberGames[MAXN];
pair<int, int> gameUncondensed[MAXN][MAXG];
// .first is the game price, .second is the game production value
bool games[MAXG];
pair<int, int> gameCondensed[MAXN][1<<MAXG];
// .first is the game price, .second is the game production value
int dp[MAXN + 1][MAXV + 1];
//	for dp[i][j]
//		i represents the current console, will run from 0 to N inclusive
//		j represents the price, will run from 0 to 100000 inclusive

void recurse(int console, int index) {
	if (index == numberGames[console]) {
		int insertIndex = 0, price = 0, production = 0, powerOfTwo = 1;
		for (int i = 0; i < numberGames[console]; ++i) {
			if (games[i]) {
				insertIndex = insertIndex + powerOfTwo;
				price = price + gameUncondensed[console][i].first;
				production = production + gameUncondensed[console][i].second;
			}
			powerOfTwo *= 2;
		}
		gameCondensed[console][insertIndex] = make_pair(price, production);
		return;
	}
	else {
		games[index] = false;
		recurse(console, index + 1);
		games[index] = true;
		recurse(console, index + 1);
		return;
	}
}

int main() {
//	freopen("input.txt", "r", stdin);
	cin >> n >> v;
	for (int i = 0; i < n; ++i) {
		cin >> consolePrice[i] >> numberGames[i];
		for (int j = 0; j < numberGames[i]; ++j) {
			cin >> gameUncondensed[i][j].first >> gameUncondensed[i][j].second;
		}
		recurse(i, 0);
//		cout << "console:    " << consolePrice[i] << endl;
		/*cout << "price:      ";
		for (int j = 1; j < (1 << numberGames[i]); ++j) {
			printf("%-2d ", gameCondensed[i][j].first);
		}
		cout << endl;*/
		/*cout << "production: ";
		for (int j = 1; j < (1 << numberGames[i]); ++j) {
			printf("%-2d ", gameCondensed[i][j].second);
		}
		cout << endl;*/
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= v; ++j) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= v; ++j) {
			if (dp[i][j] == -1) continue;
			for (int k = 1; k < (1 << numberGames[i]); ++k) {
				int next = j + gameCondensed[i][k].first + consolePrice[i];
				if (next > v) continue;
				dp[i + 1][next] = max(dp[i + 1][next], dp[i][j] + gameCondensed[i][k].second);
			}
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
		}
	}
	/*for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= 100; ++j) {
			if (dp[i][j] == -1) dp[i][j] = 0;
			printf("%-2d:%-2d ", j, dp[i][j]);
		}
		cout << endl;
	}*/
	int ret = -1;
	for (int j = 0; j <= v; ++j) {
		if (dp[n][j] > ret) {
			ret = dp[n][j];
		}
	}
	cout << ret << endl;
	return 0;
}
