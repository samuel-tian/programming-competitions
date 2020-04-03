#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

const int MAXN = 100005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 998244353;

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

int n;
vi adj[MAXN];
int dp[MAXN][5];

void dfs(int cur, int par) {
	if (adj[cur].size() == 1 && adj[cur][0] == par) {
		dp[cur][0] = 0;
		dp[cur][1] = 0;
		dp[cur][2] = 1;
		dp[cur][3] = 1;
		dp[cur][4] = 1;
		return;
	}
	int prod3 = 1;
	fill(dp[cur], dp[cur] + 5, 1);
	FOR (i, 0, adj[cur].size()) {
		int next = adj[cur][i];
		if (next == par) continue;
		dfs(next, cur);
		prod3 = (prod3 * dp[next][3]) % MOD;
		dp[cur][0] *= (dp[next][0] + dp[next][1] + dp[next][2] + dp[next][3] + dp[next][4]);
		dp[cur][1] *= (dp[next][0] + dp[next][2] + dp[next][3]);
		dp[cur][2] *= (dp[next][0] + dp[next][1] + dp[next][2]);
		dp[cur][3] *= dp[next][2];
		dp[cur][4] *= dp[next][2];
	}
	dp[cur][0] -= prod3;
	dp[cur][1] -= prod3;
	return;
}

int main() {
	setIO("input");
	cin >> n;
	FOR (i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}
	FOR (i, 0, n) {
		cout << i << ":";
		for (int j : adj[i]) {
			cout << " " << j;
		}
		cout << endl;
	}
	int k = 5;
	dfs(k, -1);
	FOR (i, 0, n) {
		FOR (j, 0, 5) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[k][0] + dp[k][1] + dp[k][2] - 1 << endl;
}