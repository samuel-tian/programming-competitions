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

const int MAXN = 50000;

int n, k;
vi adj[MAXN];
bool centroid[MAXN];
int c[MAXN], par[MAXN];

void dfs(int a) {
	if (adj[a].size() == 1 && adj[a][0] == par[a]) {
		c[a] = 1;
		return;
	}
	int ret = 0;
	FOR (i, 0, adj[a].size()) {
		int b = adj[a][i];
		if (b == par[a] || centroid[b]) continue;
		par[b] = a;
		dfs(b);
		ret += c[b];
	}
	c[a] = ret + 1;
}

int dfs2(int a, int s) {
	int tot = 0;
	int max_size = 0, next;
	FOR (i, 0, adj[a].size()) {
		int b = adj[a][i];
		if (b == par[a] || centroid[b]) continue;
		if (c[b] > max_size) {
			max_size = c[b];
			next = b;
		}
		tot += c[b];
	}
	if (s-tot-1 > max_size) {
		max_size = s-tot-1;
		next = par[a];
	}
	if (max_size > s/2) {
		return dfs2(next, s);
	}
	else {
		return a;
	}
}

ll decomp(int a, int s) {
	if (s == 1) return 0;
	if (s == 2) return ((k==1) ? 1 : 0);
	int ret = 0;
	par[a] = -1;
	dfs(a);
	int centr = dfs2(a, s);
	centroid[centr] = true;
	int subtree_size[n];
	fill(subtree_size, subtree_size + n, -1);
	int tot = 0;
	FOR (i, 0, adj[centr].size()) {
		int b = adj[centr][i];
		if (b == par[centr] || centroid[b]) continue;
		subtree_size[b] = c[b];
		tot += c[b];
	}
	if (par[centr] != -1) {
		subtree_size[par[centr]] = s-tot-1;
	}
	FOR (i, 0, adj[centr].size()) {
		int b = adj[centr][i];
		if (centroid[b]) continue;
		ret += decomp(b, subtree_size[b]);
	}
	queue<pip> q;
	ll tot_d[k+1], d[k+1];
	fill(tot_d, tot_d + k + 1, 0);
	q.push(mpip(0, centr, -1));
	while (!q.empty()) {
		pip cur = q.front();
		q.pop();
		if (cur.f > k) continue;
		tot_d[cur.f]++;
		FOR (i, 0, adj[cur.s.f].size()) {
			int b = adj[cur.s.f][i];
			if (b == cur.s.s || centroid[b]) continue;
			q.push(mpip(cur.f + 1, b, cur.s.f));
		}
	}
	ll merge_val = 0;
	ll root_val = 0;
	FOR (i, 0, adj[centr].size()) {
		int b = adj[centr][i];
		if (centroid[b]) continue;
		fill(d, d + k + 1, 0);
		q.push(mpip(1, b, -1));
		while (!q.empty()) {
			pip cur = q.front();
			q.pop();
			if (cur.f > k) continue;
			d[cur.f]++;
			FOR (j, 0, adj[cur.s.f].size()) {
				int x = adj[cur.s.f][j];
				if (x == cur.s.s || centroid[x]) continue;
				q.push(mpip(cur.f + 1, x, cur.s.f));
			}
		}
		FOR (i, 0, k) {
			merge_val += d[i] * (tot_d[k-i] - d[k-i]);
		}
		root_val += d[k] * (tot_d[0] - d[0]);
	}
	centroid[centr] = false;
	return ret + merge_val / 2 + root_val;
}

int main() {
	setIO("stdio");
	cin >> n >> k;
	FOR (i, 0, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}
	int ans = decomp(0, n);
	cout << ans << endl;
}
