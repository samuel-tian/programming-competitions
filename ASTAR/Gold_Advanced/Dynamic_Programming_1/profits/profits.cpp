/*input
7
-3
4
9
-2
-5
8
-3
*/
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

#define endl '\n'
#define NINF INT_MIN
#define INF INT_MAX
#define MAXN 100000

int n;
int p[MAXN], tot[MAXN+1], maxTot[MAXN+2];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	tot[0] = 0;
	for (int i = 0; i < n; ++i) {
		tot[i+1] = tot[i] + p[i];
	}
	maxTot[n+1] = NINF;
	for (int i = n; i >= 0; --i) {
			maxTot[i] = max(maxTot[i+1], tot[i]);
	}

	/*
	for (int i = 0; i < n; ++i) {
		cout << p[i] << " ";
	} cout << endl;
	for (int i = 0; i < n+1; ++i) {
		cout << tot[i] << " ";
	} cout << endl;
	for (int i = 0; i < n+2; ++i) {
		cout << maxTot[i] << " ";
	} cout << endl;
	*/

	int ret = NINF;
	for (int i = 0; i < n; ++i) {
		ret = max(ret, maxTot[i+1] - tot[i]);
	}
	cout << ret << endl;
}