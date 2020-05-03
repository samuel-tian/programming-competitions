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

const int dx[] = {2, 2, 1, -1, -2, -2, -1, 1};
const int dy[] = {1, -1, -2, -2, -1, 1, 2, 2};


int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
	int n, m;
	pi start, dest;
	vector<vi> grid;
	cin >> n >> m;
	grid.assign(n, vi(m));
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			cin >> grid[i][j];
			if (grid[i][j] == 3) start = mp(i, j);
			if (grid[i][j] == 4) dest = mp(i, j);
			if (grid[i][j] >= 3) grid[i][j] = 1;
		}
	}
	// condense
	vector<vector<bool> > vis; vis.assign(n, vector<bool>(m));
	vector<vector<bool> > adj_mat(n*m, vector<bool>(n*m));
	vpi check;
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (grid[i][j] != 1) continue;
			vpi l;
			queue<pi> q;
			q.push(mp(i, j));
			if (mp(i, j) == start) {
				l.pb(start);
			}
			bool good = false, good2 = false;
			FOR (x, 0, n) FOR (y, 0, m) vis[x][y] = false;
			vis[i][j] = true;
			while (!q.empty()) {
				pi cur = q.front(); q.pop();
				if (cur == dest) good = true;
				if (cur == start) good2 = true;
				FOR (k, 0, 8) {
					pi next = {cur.f + dx[k], cur.s + dy[k]};
					if (next.f<0 || next.f>=n || next.s<0 || next.s>=m) continue;
					if (vis[next.f][next.s]) continue;
					vis[next.f][next.s] = true;
					if (grid[next.f][next.s] == 1) q.push(next);
					else if (grid[next.f][next.s] == 0) l.pb(next);
				}
			}
			FOR (x, 0, l.size()) {
				FOR (y, x+1, l.size()) {
					pi lx = l[x], ly = l[y];
					adj_mat[lx.f * m + lx.s][ly.f * m + ly.s] = true;
					adj_mat[ly.f * m + ly.s][lx.f * m + lx.s] = true;
				}
			}
//			if (good) cout << i << " " << j << endl;
			if (good) swap(check, l);
			if (good && good2) {
				cout << 0 << endl;
				cout << 1 << endl;
				return 0;
			}
		}
	}

	vector<vector<ll> > dist, cnt;
	dist.resize(n, vector<ll>(m)); cnt.resize(n, vector<ll>(m));
	FOR (i, 0, n) FOR (j, 0, m) dist[i][j] = -1;
	dist[start.f][start.s] = 0; cnt[start.f][start.s] = 1;
	queue<pi> q;
	q.push(start);
	while (!q.empty()) {
		pi cur = q.front(); q.pop();
		FOR (k, 0, 8) {
			pi next = {cur.f + dx[k], cur.s + dy[k]};
			if (next.f<0 || next.f>=n || next.s<0 || next.s>=m) continue;
			if (dist[next.f][next.s] != -1) {
				if (next != start && dist[next.f][next.s] == dist[cur.f][cur.s]-1) {
					cnt[cur.f][cur.s] += cnt[next.f][next.s];
				}
				continue;
			}
			if (grid[next.f][next.s] != 0) continue;
			dist[next.f][next.s] = dist[cur.f][cur.s] + 1;
			q.push(next);
		}
		FOR (i, 0, n*m) {
			int x = i / m, y = i % m;
			if (adj_mat[cur.f*m+cur.s][x*m+y]) {
				if (dist[x][y] != -1) {
					if (dist[x][y] == dist[cur.f][cur.s] - 1) {
						cnt[cur.f][cur.s] += cnt[x][y];
					}
					continue;
				}
				dist[x][y] = dist[cur.f][cur.s] + 1;
				q.push(mp(x, y));
			}
		}
	}
	/*FOR (i, 0, n) {
		FOR (j, 0, m) {
			cout << dist[i][j] << " ";
		}cout << endl;
	}
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			cout << cnt[i][j] << " ";
		}cout << endl;
	}*/
	ll min_dist = INF;
	TRAV (x, check) {
		if (dist[x.f][x.s] == -1) continue;
		min_dist = min(min_dist, dist[x.f][x.s]);
	}
	if (min_dist == INF) cout << -1 << endl;
	else {
		cout << min_dist << endl;
		ll cnt_tot = 0;
		TRAV (x, check) {
			if (dist[x.f][x.s] == min_dist) cnt_tot += cnt[x.f][x.s];
		}
		cout << cnt_tot << endl;
	}

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
