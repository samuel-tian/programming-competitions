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

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

const int MAXN = 505;

int N, X;
vi adj[MAXN];
int v[MAXN];
vi roots;
int sz[MAXN];
int dp[MAXN][MAXN][2];

void dfs(int a, int p) {

	sz[a] = 1;
	TRAV (b, adj[a]) {
		if (b == p) continue;
		dfs(b, a);
		sz[a] += sz[b];
	}
	FOR (i, 0, N) {
		dp[a][i][0] = NINF; dp[a][i][1] = NINF;
	}
	dp[a][0][0] = 0; dp[a][0][1] = v[a];
	TRAV (b, adj[a]) {
		FOR (j, 0, sz[b]) {
			FORd (i, sz[a]-1, 0) {
				if (i-j>=0 && dp[a][i-j][0] != NINF && (dp[b][j][0] != NINF || dp[b][j][1] != NINF)) {
					dp[a][i][0] = max(dp[a][i][0], dp[a][i-j][0] + max(dp[b][j][0], dp[b][j][1]));
				}
				if (i-j>=0 && dp[a][i-j][0] != NINF && dp[b][i][0] != NINF) {
					dp[a][i][1] = max(dp[a][i][1], dp[a][i-j][1] + dp[b][j][0]);
				}
				if (i-j-1>=0 && dp[a][i-j-1][1] != NINF) {
					dp[a][i][1] = max(dp[a][i][1], dp[a][i-j-1][1] + dp[b][j][1]);
				}
			}
		}
	}
	cout << ">>> " << a << " <<<" << endl;
	FOR (k, 0, 2) {
		FOR (i, 0, N) {
			FOR (j, 0, N) {
				if (dp[i][j][k] == NINF) cout << "NINF ";
				else cout << dp[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("input");
	cin >> N >> X;
	FOR (i, 0, N) {
		int a, b;
		cin >> a >> b;
		v[i] = a;
		if (b != 0) { adj[i].pb(b-1); adj[b-1].pb(i); }
		else roots.pb(i);
	}
	TRAV (a, roots) {
		dfs(a, -1);
	}
	PRSP(sz, N);
	FOR (k, 0, 2) {
		FOR (i, 0, N) {
			FOR (j, 0, N) {
				if (dp[i][j][k] == NINF) cout << "NINF ";
				else cout << dp[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}