#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#include <chrono>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<long long> vll;
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

const int N = 2e5 + 100;

int n;
ll price[N];
vi adj[N];
ll dp[N][2];
ll before_self[N];

void dfs(int a, int p) {
	TRAV (b, adj[a]) {
		if (b == p) continue;
		dfs(b, a);
		dp[a][0] += dp[b][0];
	}
	if (adj[a].size()==1 && a!=0) { // leaf
		dp[a][0] = price[a];
		dp[a][1] = 0;
		return;
	}
	dp[a][1] = dp[a][0];
	TRAV (b, adj[a]) {
		if (b == p) continue;
		dp[a][1] = min(dp[a][1], dp[a][0] - dp[b][0] + dp[b][1]);
	}
	before_self[a] = dp[a][0];
	dp[a][0] = min(dp[a][0], dp[a][1] + price[a]);
}

set<int> answer;
bool ok[N][2], vis[N][2];

void dfs2(int a, int b, int p) {
	if (vis[a][b]) return;
	vis[a][b] = true;
	// cout << "checking " << a << " " << b << endl;
	if (b == 0) {
		if (dp[a][0] == dp[a][1] + price[a]) { // toggled self
			answer.insert(a);
			dfs2(a, 1, p);
		}
		if (before_self[a] == dp[a][0]) { // did not toggle self
			TRAV (x, adj[a]) {
				if (x == p) continue;
				dfs2(x, 0, a);
			}
		}
	}
	else {
		ll def = 0;
		TRAV (b, adj[a]) {
			if (b == p) continue;
			def += dp[b][0];
		}
		int ways = 0;
		TRAV (b, adj[a]) {
			if (b == p) continue;
			if (dp[a][1] == def - dp[b][0] + dp[b][1]) {
				ways++;
			}
		}
		if (ways == 1) {
			TRAV (b, adj[a]) {
				if (b == p) continue;
				if (dp[a][1] == def - dp[b][0] + dp[b][1]) {
					dfs2(b, 1, a);
				}
				else {
					dfs2(b, 0, a);
				}
			}
		}
		else {
			TRAV (b, adj[a]) {
				if (b == p) continue;
				dfs2(b, 0, a);
				if (dp[a][1] == def - dp[b][0] + dp[b][1]) {
					dfs2(b, 1, a);
				}
			}
		}
	}
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
	cin >> n;
	FOR (i, 0, n) {
		cin >> price[i];
	}
	FOR (i, 0, n-1) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, -1);
	/*FOR (i, 0, n) {
		cout << before_self[i] << " ";
		FOR (j, 0, 2) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	dfs2(0, 0, 0);
	cout << dp[0][0] << " " << answer.size() << endl;
	TRAV (x, answer) {
		cout << x+1 << " ";
	} cout << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
