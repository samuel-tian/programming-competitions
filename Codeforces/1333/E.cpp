#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)
#define PRSP(x, a) for (int rv = 0; rv < a; ++rv) {cout << ((rv==0 ? "" : " ")) << x[rv];} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (name == "input") {
		freopen("input.txt","r",stdin);
	}
	else if (name == "stdio") {

	}
	else {
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
}

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;

int grid[][3] = {{1, 2, 5}, {3, 4, 8}, {9, 6, 7}};
/*pi inv[10];

void dfs(int a) {
	if (a == 10) {
		int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
		int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
		int rook = 0;
		bool visited[10];
		fill(visited, visited + 10, false);
		visited[1] = true;
		pi cur = inv[1], next;
		FOR (iteration, 0, 8) {
			bool is_good = false;
			FOR (i, 1, 10) {
				if (visited[i]) continue;
				next = inv[i];
				break;
			}
			FOR (i, 1, 10) {
				if (visited[i]) continue;
				int nx = inv[i].f - cur.f, ny = inv[i].s - cur.s;
				FOR (j, 0, 4) {
					if (dx[j] == 0 && nx != 0) continue;
					if (dy[j] == 0 && ny != 0) continue;
					int mx = dx[j] ? nx / dx[j] : 0;
					int my = dy[j] ? ny / dy[j] : 0;
					if (mx < 0 || my < 0) continue;
					if (mx == 0 && my == 0) continue;
					if (mx == 0 || my == 0) is_good = true;
					else if (mx == my) is_good = true;
					if (is_good) break;
				}
				if (is_good) {
					next = inv[i];
					break;
				};
			}
			if (!is_good) rook += 1;
			cur = next;
			visited[grid[cur.f][cur.s]] = true;
		}
		int queen = 0;
		cur = inv[1];
		fill(visited, visited + 10, false);
		visited[1] = true;
		FOR (iteration, 0, 8) {
			bool is_good = false;
			FOR (i, 1, 10) {
				if (visited[i]) continue;
				next = inv[i];
				break;
			}
			FOR (i, 1, 10) {
				if (visited[i]) continue;
				int nx = inv[i].f - cur.f, ny = inv[i].s - cur.s;
				FOR (j, 0, 8) {
					if (dx[j] == 0 && nx != 0) continue;
					if (dy[j] == 0 && ny != 0) continue;
					int mx = dx[j] ? nx / dx[j] : 0;
					int my = dy[j] ? ny / dy[j] : 0;
					if (mx < 0 || my < 0) continue;
					if (mx == 0 && my == 0) continue;
					if (mx == 0 || my == 0) is_good = true;
					else if (mx == my) is_good = true;
					if (is_good) break;
				}
				if (is_good) {
					next = inv[i];
					break;
				};
			}
			if (!is_good) queen += 1;
			cur = next;
			visited[grid[cur.f][cur.s]] = true;
		}
		if (rook < queen) {
			FOR (i, 0, 3) {
				FOR (j, 0, 3) {
					cout << grid[i][j] << " ";
				}
				cout << endl;
			}
		}
		return;
	}
	FOR (i, 0, 3) {
		FOR (j, 0, 3) {
			if (grid[i][j]) continue;
			grid[i][j] = a;
			inv[a] = mp(i, j);
			dfs(a+1);
			grid[i][j] = 0;
			inv[a] = mp(0, 0);
		}
	}
}*/

int main() {
	setIO("stdio");
	int n;
	cin >> n;
	if (n <= 2) {
		cout << -1 << endl;
	}
	else {
		int ret[n][n];
		FOR (i, 0, n) {
			FOR (j, 0, n) {
				ret[i][j] = 0;
			}
		}
		FOR (i, 0, 3) {
			FOR (j, 0, 3) {
				ret[i][j] = n*n - 3*3 + grid[i][j];
			}
		}
		pi iter = mp(n-1, 0);
		int dxu[] = {0, 1, -1, 0}, dxl[] = {0, 1, 0, -1};
		int dyu[] = {1, 0, 0, -1}, dyl[] = {1, 0, -1, 0};
		bool left = false;
		FOR (i, 0, n*n - 3*3) {
			ret[iter.f][iter.s] = i+1;
			if (left)
				FOR (j, 0, 4) {
					int nx = iter.f + dxl[j], ny = iter.s + dyl[j];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n || ret[nx][ny] != 0) continue;
					iter = mp(nx, ny);
					left = (j == 2);
					break;
				}
			else
				FOR (j, 0, 4) {
					int nx = iter.f + dxu[j], ny = iter.s + dyu[j];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n || ret[nx][ny] != 0) continue;
					iter = mp(nx, ny);
					left = (j == 3);
					break;
				}
		}
		FOR (i, 0, n) {
			FOR (j, 0, n) {
				cout << ret[i][j] << " ";
			}
			cout << endl;
		}
	}
}
