#include <bits/stdc++.h>

using namespace std;

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

const int MAXC = 1005;
const int MAXK = 65;

int N, M, K;

int main() {
	setIO("stdio");
	cin >> N >> M >> K;
	pi cows[N], hay[M];
	bool haypos[MAXC][MAXC];
	FOR (i, 0, MAXC) {
		FOR (j, 0, MAXC) {
			haypos[i][j] = false;
		}
	}
	FOR (i, 0, N) {
		cin >> cows[i].f >> cows[i].s;
	}
	FOR (i, 0, M) {
		cin >> hay[i].f >> hay[i].s;
		haypos[hay[i].f-1][hay[i].s-1] = true;
	}
	int upd[61][61];
	FOR (x, -30, 31) {
		FOR (y, -30, 31) {
			int ret = 0;
			FOR (i, 0, N) {
				int nx = cows[i].f-1 + x;
				int ny = cows[i].s-1 + y;
				if (nx < 0 || nx >= MAXC || ny < 0 || ny >= MAXC) continue;
				if (haypos[nx][ny]) {
					ret++;
				}
			}
			upd[x+30][y+30] = ret;
		}
	}
	int dp[2][MAXK][MAXK];
	string path[2][MAXK][MAXK];
	FOR (i, 0, MAXK) {
		FOR (j, 0, MAXK) {
			dp[0][i][j] = -1;
			path[0][i][j] = "";
		}
	}
	dp[0][30][30] = 0;
	int dx[] = {1, 0, 0, -1};
	int dy[] = {0, 1, -1, 0};
	string a[] = {"W", "S", "N", "E"};
	FOR (i, 1, K+1) {
		FOR (j, 0, 61) {
			FOR (k, 0, 61) {
				dp[i%2][j][k] = -1;
				path[i%2][j][k] = "";
				string app = "";
				pi dir;
				FORd (l, 3, 0) {
					int nx = j + dx[l];
					int ny = k + dy[l];
					if (nx < 0 || nx >= 61 || ny < 0 || ny >= 61) continue;
					if (dp[(i+1)%2][nx][ny] == -1) continue;
//					dp[i][j][k] = max(dp[i][j][k], dp[i-1][nx][ny] + upd[j][k]);
					if (dp[(i+1)%2][nx][ny] + upd[j][k] >= dp[i%2][j][k]) {
						if (path[i%2][j][k].empty() || path[(i+1)%2][nx][ny] + a[l] > path[i%2][j][k]) {
							dp[i%2][j][k] = dp[(i+1)%2][nx][ny] + upd[j][k];
							app = a[l];
							dir = mp(nx, ny);
						}
					}
				}
				path[i % 2][j][k] = path[(i+1)%2][dir.f][dir.s] + app;
			}
		}
		/*FOR (j, 27, 34) {
			FOR (k, 27, 34) {
				if (path[i%2][j][k] == "") cout << "." << " ";
				else cout << path[i%2][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}
	int ret = 0;
	string ans = "";
	FOR (i, 0, 61) {
		FOR (j, 0, 61) {
//			cout << dp[K][i][j] << " ";
			if (dp[K%2][i][j] >= ret) {
				if (dp[K%2][i][j] == ret) {
					if (path[K%2][i][j] > ans) {
						continue;
					}
				}
				ret = dp[K%2][i][j];
				ans = path[K%2][i][j];
			}
		}
//		cout << endl;
	}
	cout << ret << endl;
	cout << ans << endl;
}
