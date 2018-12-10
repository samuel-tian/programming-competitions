/*input
5 6
......
..X..X
X..X..
......
..X...
*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

#define endl '\n'
#define MAXN 200

int n, m;
bool grid[MAXN][MAXN];
/* (x coor, vertical length) */

bool check(int x, int y, int verticalLength) {
	for (int i = x; i <= x + verticalLength; ++i) {
		if (!grid[i][y]) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string g;
		cin >> g;
		for (int j = 0; j < m; ++j) {
			grid[i][j] = g[j] == '.';
		}
	}
	int ret = 0;
	for (int x = 0; x < n; ++x) {
		for (int verticalLength = 0; verticalLength + x < n; ++verticalLength) {
			vector<int> valid;
			for (int i = 0; i < m; ++i) {
				if (grid[x][i] && grid[x + verticalLength][i]) {
					valid.push_back(i);
				}
			}
			/* find longest consecutive subarray with the ends satisfying check() */
			int maxlength = 0;
			int start = 0;
			while (true) {
				while (start < valid.size() && !check(x, valid[start], verticalLength)) ++start;
				if (start >= valid.size()) break;
				int finish = start;
				while (finish + 1 < valid.size() && valid[finish + 1] == valid[finish] + 1) ++finish;
				while (!check(x, valid[finish], verticalLength)) --finish;
				maxlength = max(maxlength, finish - start + 1);
				start = finish + 1;
			}
			ret = max(ret, maxlength * (verticalLength + 1));
		}
	}
	cout << ret << endl;
}