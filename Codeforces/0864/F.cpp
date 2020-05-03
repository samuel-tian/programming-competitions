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

const int N = 3005;
const int M = 3005;
const int Q = 400005;

int n, m, t;
vi adj[N], rev[N], new_tree[N];
bool reach[N], good[N];
int par[N][MAXLOG];
int d[N];
vector<ppi> queries[N];

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
	cin >> n >> m >> t;
	int a, b, c;
	FOR (i, 0, m) {
		cin >> a >> b;
		--a, --b;
		adj[a].pb(b);
		rev[b].pb(a);
	}
	vi ans(t);
	FOR (i, 0, t) {
		cin >> a >> b >> c;
		--a, --b;
		queries[b].pb(mppi(a, c-1, i));
	}
	queue<int> q;
	FOR (i, 0, n) {
		fill(reach, reach + n, false);
		fill(good, good + n, false);
		fill(d, d + n, 0);
		FOR (j, 0, n) FOR (k, 0, MAXLOG) par[j][k] = INF;
		FOR (j, 0, n) new_tree[j].clear();
		q.push(i);
		reach[i] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			TRAV (x, rev[cur]) {
				if (reach[x]) continue;
				reach[x] = true;
				q.push(x);
			}
		}
		FOR (j, 0, n) {
			int min_vertex = INF;
			TRAV (x, adj[j]) {
				if (!reach[x]) continue;
				min_vertex = min(min_vertex, x);
			}
			par[j][0] = min_vertex;
			if (min_vertex != INF) new_tree[min_vertex].pb(j);
		}
		FOR (k, 1, MAXLOG) {
			FOR (j, 0, n) {
				int x = par[j][k-1];
				if (x == INF) par[j][k] = INF;
				else par[j][k] = par[x][k-1];
			}
		}
		q.push(i);
		good[i] = true;
		d[i] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			TRAV (x, new_tree[cur]) {
				if (x == INF || good[x]) continue;
				good[x] = true;
				d[x] = d[cur] + 1;
				q.push(x);
			}
		}
		/*cout << i << endl;
		cout << "good "; PRSP(good, n);
		cout << "reach "; PRSP(reach, n);
		cout << "d "; PRSP(d, n);
		cout << "par ";
		FOR (j, 0, n) cout << par[j][0] << " ";
		cout << endl;*/

		TRAV (x, queries[i]) {
			if (good[x.f.f] && reach[x.f.f]) {
				if (x.f.s > d[x.f.f]) ans[x.s] = -1;
				else {
					int ret = x.f.f;
					FOR (j, 0, MAXLOG) {
						if ((1<<j) & x.f.s) {
							ret = par[ret][j];
						}
					}
					ans[x.s] = ret+1;
				}
			}
			else ans[x.s] = -1;
		}
	}
	PRSP(ans, t);

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

