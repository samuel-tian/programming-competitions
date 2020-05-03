#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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

#define FOR(i, a, b) for (int (i) = (a); i < (b); ++i)
#define FORd(i, a, b) for (int (i) = (a); i >= (b); --i)
#define TRAV(i, x) for (auto& (i) : (x))
#define PRSP(x, a) for (int rv = 0; rv < a; ++rv) {cout << ((rv==0 ? "" : " ")) << x[rv];} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c))
#define min3(a, b, c) min(min((a), (b)), (c))

void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (name == "") return;
	if (name == "input") {freopen("input.txt","r",stdin);}
	else {freopen((name+".in").c_str(),"r",stdin); freopen((name+".out").c_str(),"w",stdout);}
}

const int INF = INT_MAX-1;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

const int N = 9;

int grid[N][N];
int rp[N+5];
int cp[N+5];
int sqr[N+5];
int dp[N][N][2][1<<N][1<<(N/3)];

int solve(int r, int c, int row_par, int col_par, int sqr_par) {
	if (r == N) {
		if (col_par) return INF;
		else return 0;
	}
	if (c == N) {
		if (row_par) return INF;
		if (r%3 == 2) {
			if (sqr_par) return INF;
			sqr_par = (sqr[(r+1)/3*3]) + (sqr[(r+1)/3*3+1]<<1) + (sqr[(r+1)/3*3+2]<<2);
		}
		return solve(r+1, 0, rp[r+1], col_par, sqr_par);
	}
	int& dpv = dp[r][c][row_par][col_par][sqr_par];
	if (dpv != -1) return dpv;
//	cout << r << " " << c << " " << row_par << " " << col_par << " " << sqr_par << endl;
	// toggle
	int t = solve(r, c+1, 1-row_par, col_par ^ (1<<c), sqr_par ^ (1<<(c/3)));
	// don't toggle
	int tn = solve(r, c+1, row_par, col_par, sqr_par);
	if (t==INF && tn==INF) dpv = INF;
	else dpv = min(t+1, tn);
	return dpv;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("input");
	FOR (i, 0, N) {
		string s; cin >> s;
		FOR (j, 0, N) {
			grid[i][j] = s[j] - '0';
			rp[i] += grid[i][j];
			cp[j] += grid[i][j];
			sqr[(i/3)*3 + j/3] += grid[i][j];
		}
		rp[i] %= 2;
	}
	FOR (j, 0, N) cp[j] %= 2;
	FOR (i, 0, N) sqr[i] %= 2;
	sqr[N] = sqr[N+1] = sqr[N+2] = 0;
//	PRSP(sqr, 12);
	FOR (i, 0, N) FOR (j, 0, N) FOR (k, 0, 2) FOR (x, 0, 1<<N) FOR (y, 0, 1<<(N/3)) dp[i][j][k][x][y] = -1;
	int init = 0;
	FORd (j, N-1, 0) {
		init = (init<<1) + cp[j];
	}
	int ret = solve(0, 0, rp[0], init, (sqr[0]) + (sqr[1]<<1) + (sqr[2]<<2));
	cout << ret << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
