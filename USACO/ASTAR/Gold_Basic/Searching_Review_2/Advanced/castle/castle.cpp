#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ll long long
#define mp make_pair
#define endl '\n'
#define sp << ' ' <<
using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vii;
const int INF = 2000000000;
const int MAXN = 50, MAXM = 50;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1 , 0};
string dir[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

int n, m, counter = 0;
int castle[MAXN][MAXM];
int region[MAXN][MAXM];
int maxsingle = 0, maxdouble = 0;
map<int, int> area;
int floodfill(int r, int c) {
	region[r][c] = counter;
	int total = 1;
	for (int i = 0; i < 4; i++) {
		if (dir[castle[r][c]][i] == '0') {
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (nr>=0 && nr<n && nc>=0 && nc<m && region[nr][nc] == 0) {
				total += floodfill(nr, nc);
			}
		}
	}
	area[counter] = total;
	return total;
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> castle[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (region[i][j] == 0) {
				++counter;
				maxsingle = max(maxsingle, floodfill(i, j));
			}
		}
	}

	cout << counter << endl;
	cout << maxsingle << endl;

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m; j++) {
			if (region[i][j] == region[i+1][j]) maxdouble = max(maxdouble, area[region[i][j]]);
			else maxdouble = max(maxdouble, area[region[i][j]] + area[region[i+1][j]]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m-1; j++) {
			if (region[i][j] == region[i][j+1]) maxdouble = max(maxdouble, area[region[i][j]]);
			else maxdouble = max(maxdouble, area[region[i][j]] + area[region[i][j+1]]);
		}
	}
	cout << maxdouble << endl;
	return 0;
}
