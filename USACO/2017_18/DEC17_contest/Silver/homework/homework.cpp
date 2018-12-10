/*input
5
3 1 9 2 7
*/
#include <iostream>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAXN 100000
#define INF (double)9223372036854775807;

int n;
int scores[MAXN];
double finalScore[2][MAXN];

int main() {
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> scores[i];
	}

	int minScore = scores[n-1];
	finalScore[0][n-1] = 0;
	finalScore[1][n-1] = minScore;
	for (int i = n-2; i >= 1; --i) {
		if (scores[i] < minScore) {
			minScore = scores[i];
		}
		finalScore[1][i] = minScore;
		finalScore[0][i] = ((finalScore[0][i+1] * (n-i-2) + finalScore[1][i+1]) + scores[i] - minScore) / (n-i-1);
	}

	double retMax = 0;
	for (int i = 1; i <= n-2; ++i) {
		if (finalScore[0][i] > retMax) {
			retMax = finalScore[0][i];
		}
	}
	for (int i = 1; i <= n-2; ++i) {
		if (finalScore[0][i] == retMax) {
			cout << i << endl;
		}
	}

	/*for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << finalScore[i][j] << " ";
		}
		cout << endl;
	}*/

	fclose(stdin);
	fclose(stdout);
}