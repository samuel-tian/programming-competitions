/*input
COW
XXO
ABC
*/
#include <iostream>

using namespace std;

#define endl '\n'

int main() {
	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);
	int grid[3][3];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			char c;
			cin >> c;
			grid[i][j] = c - 'A';
			// cout << grid[i][j] << " ";
		}
		// cout << endl;
	}

	int singlewins[26], wins[26][26];
	fill(singlewins, singlewins + 26, 0);
	for (int i = 0; i < 26; ++i)
		fill(wins[i], wins[i] + 26, 0);

	for (int i = 0; i < 3; ++i) {
		if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) singlewins[grid[0][i]]++;
		else if (grid[0][i] == grid[1][i]) {
			wins[grid[0][i]][grid[2][i]]++;
			wins[grid[2][i]][grid[0][i]]++;
		}
		else if (grid[1][i] == grid[2][i]) {
			wins[grid[1][i]][grid[0][i]]++;
			wins[grid[0][i]][grid[1][i]]++;
		}
		else if (grid[0][i] == grid[2][i]) {
			wins[grid[0][i]][grid[1][i]]++;
			wins[grid[1][i]][grid[0][i]]++;
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]) singlewins[grid[i][0]]++;
		else if (grid[i][0] == grid[i][1]) {
			wins[grid[i][0]][grid[i][2]]++;
			wins[grid[i][2]][grid[i][0]]++;
		}
		else if (grid[i][1] == grid[i][2]) {
			wins[grid[i][0]][grid[i][2]]++;
			wins[grid[i][2]][grid[i][0]]++;
		}
		else if (grid[i][0] == grid[i][2]) {
			wins[grid[i][0]][grid[i][1]]++;
			wins[grid[i][1]][grid[i][0]]++;
		}
	}
	if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) singlewins[grid[1][1]]++;
	else if (grid[0][0] == grid[1][1]) {
		wins[grid[0][0]][grid[2][2]]++;
		wins[grid[2][2]][grid[0][0]]++;
	}
	else if (grid[1][1] == grid[2][2]) {
		wins[grid[0][0]][grid[2][2]]++;
		wins[grid[2][2]][grid[0][0]]++;
	}
	else if (grid[0][0] == grid[2][2]) {
		wins[grid[1][1]][grid[2][2]]++;
		wins[grid[2][2]][grid[1][1]]++;
	}
	if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) singlewins[grid[1][1]]++;
	else if (grid[2][0] == grid[1][1]) {
		wins[grid[0][2]][grid[1][1]]++;
		wins[grid[1][1]][grid[0][2]]++;
	}
	else if (grid[2][0] == grid[0][2]) {
		wins[grid[1][1]][grid[0][2]]++;
		wins[grid[0][2]][grid[1][1]]++;
	}
	else if (grid[1][1] == grid[0][2]) {
		wins[grid[1][1]][grid[2][0]]++;
		wins[grid[2][0]][grid[1][1]]++;
	}

	int ret = 0;
	for (int i: singlewins)
		if (i > 0)
			++ret;
	cout << ret << endl;
	ret = 0;
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (wins[i][j] > 0 || wins[j][i] > 0) {
				++ret;
			}
		}
	}
	cout << ret << endl;
}