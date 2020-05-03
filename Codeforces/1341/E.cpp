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

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();

	int n, m;
	cin >> n >> m;
	vi d(m);
	FOR (i, 0, m) cin >> d[i];
	sort(d.begin(), d.end());
	int g, r;
	cin >> g >> r;
	vector<vector<bool> > vis(m, vector<bool>(g));
	FOR (i, 0, m) {
		FOR (j, 0, g) {
			vis[i][j] = false;
		}
	}
	vi v; v.pb(0);
	int t = 0;
	int ans = INF;
	while (!v.empty()) {
		queue<pi> q;
//		PRSP(v, v.size());
		TRAV (i, v) {
			q.push(mp(i, 0));
		}
		v.clear();
		while (!q.empty()) {
			pi cur = q.front(); q.pop();
			if (vis[cur.f][cur.s]) continue;
			vis[cur.f][cur.s] = true;
			for (int j : {cur.f-1, cur.f+1}) {
				if (j >= m || j < 0) continue;
				int next_time = cur.s + abs(d[j] - d[cur.f]);
				if (next_time > g) continue;
				if (j == m-1) {
					ans = min(ans, next_time + t*(r+g));
					break;
				}
				if (next_time == g) {
					v.pb(j);
				}
				else {
					q.push(mp(j, next_time));
				}
			}
		}
		t++;
	}
	cout << (ans==INF ? -1 : ans) << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
