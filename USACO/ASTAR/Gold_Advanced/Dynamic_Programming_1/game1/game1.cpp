/*input
6
4 7 2 9
5 2
*/

#include <iostream>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAXN 100

int n;
int s[MAXN][MAXN];

int rec(int a, int b) {
	if (a == b) return s[a][a];
	if (a > b) return 0;
	if (s[a][b] != -1) return s[a][b];
	s[a][b] = max(min(rec(a+2, b), rec(a+1, b-1))+s[a][a], min(rec(a+1, b-1), rec(a, b-2))+s[b][b]);
	return s[a][b];
}

int main() {
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		fill(s[i], s[i] + n, -1);
		cin >> s[i][i];
		sum += s[i][i];
	}
	/*
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
	*/
	int ret = rec(0, n-1);
	cout << ret << " " << sum - ret << endl;

}