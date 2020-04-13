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
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;

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

const int MAXN = 100005;

int n;
vi adj[MAXN];
int color[MAXN];
pair<ll, ll> dp[MAXN];

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
	// Base Case
	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}

	ll x1, y1; // To store results of recursive call
	ll gcd = gcdExtended(b%a, a, &x1, &y1);

	// Update x and y using results of recursive
	// call
	*x = y1 - (b/a) * x1;
	*y = x1;

	return gcd;
}

ll modInverse(ll a, ll m)
{
	ll x, y;
	ll g = gcdExtended(a, m, &x, &y);
	return (x%m + m) % m;
}

void dfs(int cur, int par) {
	if (adj[cur].size() == 1 && adj[cur][0] == par) {
		if (color[cur]) {
			dp[cur] = mp(0, 1);
		}
		else {
			dp[cur] = mp(1, 0);
		}
		return;
	}
	ll child_tot = 1;
	FOR (i, 0, adj[cur].size()) {
		int next = adj[cur][i];
		if (next == par) continue;
		dfs(next, cur);
		child_tot = (child_tot * (dp[next].f + dp[next].s)) % MOD;
	}
	if (color[cur]) {
		dp[cur].f = 0;
		dp[cur].s = child_tot;
	}
	else if (!color[cur]) {
		dp[cur].f = child_tot;
		FOR (i, 0, adj[cur].size()) {
			int next = adj[cur][i];
			if (next == par) continue;
			dp[cur].s = (dp[cur].s + (((child_tot * modInverse((dp[next].f + dp[next].s), MOD)) % MOD) * dp[next].s)) % MOD;
		}
	}
}

int main() {
	setIO("stdio");
	cin >> n;
	int a;
	FOR (i, 0, n - 1) {
		cin >> a;
		adj[i+1].pb(a);
		adj[a].pb(i+1);
	}
	FOR (i, 0, n) {
		cin >> color[i];
	}
	int k = 0;
	dfs(k, -1);
	/*FOR (i, 0, n) {
		cout << dp[i].f << " " << dp[i].s << endl;
	}*/
	cout << dp[k].s << endl;
}
