/*input
8
14
2
5
15
8
9
20
4
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 20
#define MAXS 100

int n, baleSum = 0;
int baleSizes[MAXN];
bool canDivide[2][MAXS*MAXN+1][MAXS*MAXN+1];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &baleSizes[i]);
		baleSum += baleSizes[i];
	}
	canDivide[0][0][0] = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < MAXS*n+1; ++j) {
			for (int k = 0; k < MAXS*n+1; ++k) {
				if (canDivide[i%2][j][k]) {
					canDivide[(i+1)%2][j][k] = true;
					canDivide[(i+1)%2][j+baleSizes[i]][k] = true;
					canDivide[(i+1)%2][j][k+baleSizes[i]] = true;
				}
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < MAXS*n+1; ++i) {
		for (int j = 0; j < MAXS*n+1; ++j) {
			if (canDivide[(n-1)%2][i][j]) {
				int arr[] = {i, j, baleSum - i - j};
				int a = *max_element(arr, arr+3);
				ans = min(ans, a);
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}