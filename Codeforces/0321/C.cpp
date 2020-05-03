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

const int MAXN = (int)1e5 + 5;

int N;
vi adj[MAXN];
bool centr[MAXN];
int sz[MAXN], ans[MAXN];

void dfs(int a, int p) {
	sz[a] = 1;
	TRAV (b, adj[a]) {
		if (centr[b] || b == p) continue;
		dfs(b, a);
		sz[a] += sz[b];
	}
}

int dfs2(int a) {
	dfs(a, -1);
	int hi = sz[a] / 2;
	int p = -1;
	while (true) {
		bool found = false;
		TRAV (b, adj[a]) {
			if (centr[b] || b == p || sz[b] <= hi) continue;
			found = true;
			p = a; a = b; break;
		}
		if (!found) return a;
	}
}

void decomp(int a, int x) {
	int c = dfs2(a);
	centr[c] = true;
	ans[c] = x;
	TRAV (b, adj[c]) {
		if (centr[b]) continue;
		decomp(b, x + 1);
	}
}

int main() {
//	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();
	setIO();
	cin >> N;
	int a, b;
	FOR (i, 0, N-1) {
		cin >> a >> b;
		--a; --b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	fill(ans, ans + N, -1);
	decomp(0, 0);
	bool good = true;
	FOR (i, 0, N) if (ans[i] >= 26) good = false;
//	PRSP (ans, N);
	if (good) {
		FOR (i, 0, N) cout << ((char)('A' + ans[i])) << " ";
		cout << endl;
	}
	else cout << "Impossible!" << endl;
//	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << endl;
}
