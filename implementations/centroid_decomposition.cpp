/*
 * Centroid Decomposition
 * ----------------------
 * - centroid - a node in a tree such that if that node is removed, then all the remaining subtrees will have at most half the size of the original tree
 * 		- there exists at least one and at most two centroids in any tree
 * 		- a centroid can be found by randomly selecting a node, and recursing on the subtree with size greater than n/2. If there exists no such subtree, then the current node is a centroid 
 * - decomposes a tree into a centroid tree
 * - properties
 * 		- there exists an edge from node A to node B (A is the parent of B) if B is the centroid of a subtree that is formed when removing centroid A
 * 		- height of the tree is O(log n)
 * 		- the path from A to B in the original tree will pass through node C, where C is the least common ancestor (LCA) of A and B in the centroid tree
 * 		- for each centroid, maintain paths to all of its children in the centroid tree (there will be n log n paths total). Then any path in the original tree can be represented by a concatenation of two of these paths
 */

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

const int MAXN = 100000;

int n, m;
vi adj[MAXN], decomp_adj[MAXN];
int c[MAXN], d[MAXN];
bool centroid[MAXN];
int par[MAXN][MAXLOG];

void calc_d(int a) {
	for (int b : adj[a]) {
		if (b == par[a][0]) continue;
		par[b][0] = a;
		d[b] = d[a] + 1;
		calc_d(b);
	}
}

void init_st(int a) {
	d[a] = 0;
	par[a][0] = a;
	calc_d(a);
	FOR (j, 1, MAXLOG) {
		FOR (i, 1, n) {
			par[i][j] = par[par[i][j-1]][j-1];
		}
	}
}

void dfs(int a) {
	if (adj[a].size()==1 && adj[a][0]==par[a][0]) {
		c[a] = 1;
	}
	else {
		int ret = 0;
		for (int b : adj[a]) {
			if (b == par[a][0]) continue;
			dfs(b);
			ret += c[b];
		}
		c[a] = ret + 1;
	}
}

int dfs2(int a, int sz) {
	int tot = 0;
	int max_size = 0, next;
	for (int b : adj[a]) {
		if (b == par[a][0] || centroid[b]) continue;
		if (c[b] > max_size) {
			max_size = c[b];
			next = b;
		}
		tot += c[b];
	}
	if (sz-tot-1 > max_size) {
		max_size = sz-tot-1;
		next = par[a][0];
	}
	return (max_size > sz/2) ? dfs2(next, sz) : a;
}

int decomp(int a, int sz) {
	if (sz == 0) return -1;
	if (sz == 1) return a;
	int centr = dfs2(a, sz);
	centroid[centr] = true;
	int tot = 0;
	for (int b : adj[centr]) {
		if (b == par[centr][0] || centroid[b]) continue;
		tot += c[b];
	}
	for (int b : adj[centr]) {
		if (centroid[b]) continue;
		int next;
		if (b == par[centr][0]) next = decomp(b, sz-tot-1);
		else next = decomp(b, c[b]);
		if (centr == next || next == -1) continue;
		decomp_adj[centr].pb(next);
		decomp_adj[next].pb(centr);
	}
	return centr;
}

int main() {
	setIO("input");
	cin >> n >> m;
	FOR (i, 0, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}
	init_st(0);
	dfs(0);
	decomp(0, n);
	FOR (i, 0, n) {
		cout << i+1 << ": ";
		for (int j : decomp_adj[i]) {
			cout << j+1 << " ";
		}
		cout << endl;
	}
}
