#include <iostream>
#include <cmath>
using namespace std;
#define endl "\n"
const int INF = (int)((1LL<<31)-1);
const int MAXN = 500;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, minsum = INF;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

void recurse(int r, int c, int counter, int sum) {
	cout << r << " " << c << " " << counter << " " << sum << endl;
	if (counter >= ceil((n * n)/2.0)) {
		if (minsum > sum) {
			sum = minsum;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];
		if (nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc]) {
			visited[nr][nc] = true;
			recurse(nr, nc, counter+1, sum+abs(grid[r][c]-grid[nr][nc]));
			visited[nr][nc] = false;
		}
	}
	return;

}

int main() {
	freopen("tractor2_cases\\1.in", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "start " << i << " " << j << endl;
			visited[i][j] = true;
			recurse(i, j, 1, 0);
			visited[i][j] = false;
		}
	}*/
	visited[0][0] = true;
	recurse(0, 0, 1, 0);
	cout << ceil((n * n)/2.0) << endl;
	cout << minsum << endl;

	fclose(stdin);
	return 0;
}
