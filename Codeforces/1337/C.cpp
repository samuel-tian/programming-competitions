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

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)
#define PRSP(x, a) for (int rv = 0; rv < a; ++rv) {cout << ((rv==0 ? "" : " ")) << x[rv];} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

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

const int MAXN = 200005;

int n, k;
vi adj[MAXN];
int d[MAXN];
bool ind[MAXN];
int dist[MAXN];
int c[MAXN];

int dfs(int a, int par) {
	if (adj[a].size() == 1 && adj[a][0] == par) {c[a] = 1; return c[a];}
	int tot = 0;
	for (int b : adj[a]) {
		if (b == par) continue;
		d[b] = d[a] + 1;
		tot += dfs(b, a);
	}
	c[a] = tot + 1;
	return c[a];
}

void dfs2(int a, int par) {
	if (adj[a].size() == 1 && adj[a][0] == par) return;
	for (int b : adj[a]) {
		if (b == par) continue;
		dist[b] = dist[a] + (int) (!ind[a]);
		dfs2(b, a);
	}
}

int main() {
	setIO();
	cin >> n >> k;
	FOR (i, 0, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}
	d[0] = 0;
	dfs(0, -1);
	vector<pi> v;
	FOR (i, 0, n) {
		v.pb(mp(c[i]-1-d[i], i));
	}
	sort(v.begin(), v.end());
	/*FOR (i, 0, n) {
		cout << v[i].f << " " << v[i].s << endl;
	}*/
	FOR (i, 0, k) {
		ind[v[i].s] = true;
	}
	dfs2(0, -1);
//	PRSP(dist, n);
	ll ret = 0;
	FOR (i, 0, n) {
		if (ind[i]) ret += dist[i];
	}
	cout << ret << endl;
}
