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
const int MAXM = 15, MAXN = 15;

int m, n;
int tiles[MAXM][MAXN];
bool ans[MAXM][MAXN];
bool flipped[MAXM][MAXN];
int mincount = INF;
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, -1, 0, 1};

pii next(int r, int c) {
	c++;
	if (c == n) {
		c = 0;
		r++;
	}
	return mp(r, c);
}

void flip(int r, int c) {
	for (int i = 0; i < 5; i++) {
		int dr = r + dx[i];
		int dc = c + dy[i];
		if (dr>=0 && dr<m && dc>=0 && dc<n)
			tiles[dr][dc] = (tiles[dr][dc] + 1) % 2;
	}
}

void recurse(int r, int c, int counter) {
	if (r == m) {
		if (counter >= mincount) return;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (tiles[i][j] != 0)
					return;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				ans[i][j] = flipped[i][j];
		mincount = counter;
		return;
	}
	if (c>=2 && r>=1 && tiles[r-1][c-2] == 1) return;
	if (c==0 && r>=2 && (tiles[r-2][n-1]==1 || tiles[r-2][n-2]==1)) return;
	int nr = next(r, c).f;
	int nc = next(r, c).s;
	recurse(nr, nc, counter);

	flip(r, c);
	flipped[r][c] = true;
	recurse(nr, nc, counter+1);
	flipped[r][c] = false;
	flip(r, c);
	return;
}

int main() {
	/*string input;
	freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Searching_Review_2/Challenge_Problems/fliptile/fliptile_cases/fliptile.1.out", "r", stdin);
	while (!cin.eof()) {
		getline(cin, input);
		cout << input << endl;
	}
	fclose(stdin);
	getline(cin, input);*/
	freopen("/mnt/c/Users/Samuel/Documents/Programs/USACO/ASTAR/Gold_Basic/Searching_Review_2/Challenge_Problems/fliptile/fliptile_cases/fliptile.1.in", "r", stdin);
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> tiles[i][j];
	recurse(0, 0, 0);
	if (mincount == INF) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	fclose(stdin);
	return 0;
}
