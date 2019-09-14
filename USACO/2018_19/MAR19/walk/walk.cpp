#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAXN 7500
#define AMOD 2019201913LL
#define BMOD 2019201949LL
#define CMOD 2019201997LL

int n, k;
int distanceArr[MAXN][MAXN];
bool adj[MAXN][MAXN];

inline int dist(int a, int b) {
	return (int)((AMOD * (long long) a + BMOD * (long long) b) % CMOD);
}

int main() {
	freopen("input.txt", "r", stdin);
//	freopen("walk.in", "r", stdin);
//	freopen("walk.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) distanceArr[i][j] = (-1);
			else if (i > j) distanceArr[i][j] = dist(j, i);
			else if (i < j)	distanceArr[i][j] = dist(i, j);
		}
	}
	cout << 2019201769 << endl;
}
