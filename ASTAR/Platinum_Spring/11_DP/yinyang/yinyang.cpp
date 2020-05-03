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
vpi adj[MAXN];
bool centr[MAXN];
int sz[MAXN];
unordered_map<int, ll> cnt, good, track, uniq;

void dfs(int a, int p) {
	sz[a] = 1;
	TRAV (b, adj[a]) {
		if (centr[b.f] || b.f == p) continue;
		dfs(b.f, a);
		sz[a] += sz[b.f];
	}
}

int dfs2(int a) {
	dfs(a, -1);
	int hi = sz[a] / 2;
	int p = -1;
	while (true) {
		bool found = false;
		TRAV (b, adj[a]) {
			if (centr[b.f] || b.f == p || sz[b.f] <= hi) continue;
			found = true;
			p = a; a = b.f; break;
		}
		if (!found) return a;
	}
}

void dfs3(int a, int p, int v) {
	if (track[v] > 0) good[v]++;
	if (track[v] == 0) uniq[v]++;
	cnt[v]++; track[v]++;
	TRAV (b, adj[a]) {
		if (centr[b.f] || p == b.f) continue;
		dfs3(b.f, a, v + b.s);
	}
	track[v]--;
}

ll decomp(int a) {
	int c = dfs2(a);
	ll ret = 0;
	centr[c] = true;
	unordered_map<int, ll> total, divided;
	TRAV (b, adj[c]) {
		if (centr[b.f]) continue;
		cnt.clear(); good.clear(); track.clear(); uniq.clear();
		dfs3(b.f, c, b.s);
		TRAV (v, uniq) {
			if (v.f == 0) { ret += total[-v.f] * v.s; }
			else { ret += divided[-v.f] * v.s; }
		}
		TRAV (v, good) {
			if (v.f == 0) { ret += (1 + total[-v.f]) * v.s; }
			else { ret += total[-v.f] * v.s; }
		}
		TRAV (v, cnt) total[v.f] += v.s;
		TRAV (v, good) divided[v.f] += v.s;
	}
	TRAV (b, adj[c]) {
		if (centr[b.f]) continue;
		ret += decomp(b.f);
	}
	return ret;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
	cin >> N;
	int a, b, t;
	FOR (i, 0, N-1) {
		cin >> a >> b >> t;
		if (t == 0) t = -1;
		--a; --b;
		adj[a].pb(mp(b, t));
		adj[b].pb(mp(a, t));
	}
	ll ret = decomp(0);
	cout << ret << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
