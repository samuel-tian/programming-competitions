/*input
5 2
5
3
4
2
10
*/
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define NINF INT_MIN
#define MAXN 10000

int n, m;
int run[MAXN], dis[MAXN+1];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> run[i];
	}

	for (int i = 0; i < n; ++i) {
		dis[i+1] = max(dis[i], dis[i+1]);
		int sum = dis[i];
		for (int j = 1; j <= m; ++j) {
			if (i + 2 * j > n) break;
			sum += run[i+j-1];
			dis[i + 2 * j] = max(dis[i + 2 * j], sum);
		}		
		/*
		for (int j = 0; j <= n; ++j) {
			cout << dis[j] << " ";
		}
		cout << endl;
		*/
	}

	cout << dis[n] << endl;
}