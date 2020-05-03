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

const int MAXN = (int) 2e5 + 5;

int n, m;
int a, b, c;
vpi adj[MAXN];

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cin >> a >> b >> c; --a, --b, --c;
		int p[m];
		FOR (i, 0, m) cin >> p[i];
		sort(p, p + m);
		ll psum[m+1]; psum[0] = 0;
		FOR (i, 0, m) psum[i+1] = psum[i] + p[i];
		FOR (i, 0, n) adj[i].clear();
		FOR (i, 0, m) {
			int x, y;
			cin >> x >> y; --x, --y;
			adj[x].pb(mp(y, 1)); adj[y].pb(mp(x, 1));
		}

		vector<vector<ll> > d; d.resize(3);
		FOR (i, 0, 3) {
			d[i].resize(n);
			FOR (j, 0, n) d[i][j] = INF;
		}
		queue<int> q;
		int source[] = {a, b, c};
		FOR (i, 0, 3) {
			q.push(source[i]); d[i][source[i]] = 0;
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				TRAV (b, adj[cur]) {
					int x = b.f;
					if (d[i][x] == INF) {
						d[i][x] = min(d[i][x], d[i][cur] + 1);
						q.push(x);
					}
				}
			}
		}
		ll ret = LLONG_MAX;
		FOR (i, 0, n) {
			if (d[0][i] + d[1][i] + d[2][i] > m) continue;
			ll temp = 0;
			temp += psum[d[1][i]];
			temp += psum[d[0][i] + d[1][i] + d[2][i]];
			ret = min(ret, temp);
		}
		cout << ret << endl;
	}

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
