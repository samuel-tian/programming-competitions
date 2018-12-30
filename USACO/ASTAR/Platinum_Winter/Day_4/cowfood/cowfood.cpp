#include <iostream>
#include <climits>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 12
#define MOD 100000000

int n, m;
bool grid[MAXN+1][MAXN+1];
int dp[MAXN+1][MAXN+1][1<<MAXN];
int temp[MAXN+1][MAXN+1];

int recurse(int r, int c) {
	if (r == n + 1) return 1;
	int nr = r, nc = c + 1;
	if (c > n) {
		++nr;
		nc = 1;
	}
	if (!grid[r][c]) {
		temp[r][c] = recurse(nr, nc);
		return temp[r][c];
	}
	grid[r][c] = 0;
	int ret = recurse(nr, nc);
	grid[r][c] = 1;
	if (grid[r-1][c] + grid[r][c-1] == 0)
		ret += recurse(nr, nc);
	temp[r][c] = ret;
	return ret;
}

int main() {
	cin >> n >> m;
	// one indexed grid
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i*j == 0) grid[i][j] = 0;
			else cin >> grid[i][j];
		}
	}
	cout << recurse(1, 1) << endl;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
}
