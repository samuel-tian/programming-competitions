/*input
3 800
300 2 30 50 25 80
600 1 50 130
400 3 40 70 30 40 35 60
*/

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <utility>

using namespace std;

#define endl '\n'
#define MAXN 50
#define MAXG 10
#define MAXP 100
#define MAXV 100000
#define INF INT_MAX

int n, v;
int consoleprice[MAXN][2];
int gameprice[MAXN][MAXG][2];
int dpgames[MAXN][MAXG + 1][MAXP * MAXG + 1];
int dpconsole[MAXN + 1][MAXV + 1];

int main() {
	cin >> n >> v;
	for (int i = 0; i < n; ++i) {
		cin >> consoleprice[i][0] >> consoleprice[i][1];
		for (int j = 0; j < consoleprice[i][1]; ++j) {
			cin >> gameprice[i][j][0] >> gameprice[i][j][1];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= consoleprice[i][1]; ++j) {
			for (int k = 0; k <= consoleprice[i][1] * MAXP + 1; ++k) {
				if (j == 0 || k == 0) {
					dpgames[i][j][k] = 0;
				}
				else if (gameprice[i][j - 1][0] <= k) {
					dpgames[i][j][k] = max(dpgames[i][j - 1][k], dpgames[i][j - 1][k - gameprice[i][j - 1][0]] + gameprice[i][j - 1][1]);
				}
				else {
					dpgames[i][j][k] = dpgames[i][j - 1][k];
				}
			}
		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= consoleprice[i][1]; ++j) {
			for (int k = 0; k <= consoleprice[i][1] * MAXP + 1; ++k) {
				printf("%-3d ", dpgames[i][j][k]);
			}
			cout << endl << endl;;
		}
		cout << endl;
	}*/
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= v; ++j) {
			if (i == 0 || j == 0) {
				dpconsole[i][j] = 0;
			}
			else {
				for (int k = 0; k <= consoleprice[i][1] * MAXP + 1; ++k) {
					if (k + consoleprice[i][0] <= j) {
						dpconsole[i][j] = max(dpconsole[i - 1][j], dpconsole[i - 1][j - (k + consoleprice[i][0])] + dpgames[i][consoleprice[i][1]][k]);
					}
				}
				if (dpconsole[i][j] == 0) {
					dpconsole[i][j] = dpconsole[i - 1][j];
				}
			}
			/*if ((j == 0) ^ (i == 0)) {
				dpconsole[i][j] = 0;
			}
			else { 
				if ((i != 0 && j != 0) && dpconsole[i][j] == 0) {
					dpconsole[i][j] = dpconsole[i - 1][j];
				}
				for (int k = 0; k <= consoleprice[i][1] * MAXP + 1; ++k) {
					if (j + k + consoleprice[i][0] <= v) {
						dpconsole[i + 1][j + k + consoleprice[i][0]] = max(dpconsole[i + 1][j + k + consoleprice[i][0]], dpconsole[i][j] + dpgames[i][consoleprice[i][1]][k]);
					}
				}
			}*/
		}
	}
	/*for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= v; ++j) {
			cout << dpconsole[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dpconsole[n][v] << endl;
}