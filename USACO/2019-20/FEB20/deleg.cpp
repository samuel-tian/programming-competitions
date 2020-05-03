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

const int N = 100005;

int n, k;
vi adj[N];
int dbg[N];

void check(int a, int p) {
	TRAV (b, adj[a]) {
		if (b == p) continue;
		cout << a << " - " << b << " " << dbg[b] << endl;
		check(b, a);

	}
}

int dfs(int a, int p) {
	multiset<int> c;
	TRAV (b, adj[a]) {
		if (b == p) continue;
		int v = dfs(b, a);
		if (v == -1) {
			dbg[a] = -1;
			return -1;
		}
		c.insert(v+1);
	}
	int cnt = 0, ret = 0;
	multiset<int> cpy = c;
	while (!c.empty()) {
		int v = *c.begin();
		c.erase(c.begin());
		if (v >= k) {
			ret = max(ret, v);
			break;
		}
		if (c.empty()) {
			ret = max(ret, v);
			cnt++;
		}
		else {
			if (c.size()==1 && *c.begin() >= k && cnt == 0) {
				ret = max(ret, *c.begin());
				cnt++;
				c.erase(c.begin());
			}
			else {
				auto it = c.upper_bound(k - v - 1);
				if (it == c.end()) {
					assert(v + *c.rbegin() < k);
					cnt++;
					ret = max(ret, v);
				}
				else {
					assert(v + *it >= k);
					c.erase(it);
				}
			}
		}
	}
	if (cnt > 1) {
//		cout << k << ": ";
//		TRAV (x, cpy) {cout << x << " ";} cout << endl;
		dbg[a] = -1;
		return -1;
	}
	else {
		dbg[a] = ret;
		return ret;
	}
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("deleg");
	cin >> n;
	int a, b;
	FOR (i, 0, n-1) {
		cin >> a >> b;
		--a, --b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int lo = 1, hi = n-1;
//	k = 18;
//	fill(dbg, dbg + n, 0);
//	cout << dfs(0, -1) << endl;
//	check(6627, 82809);
	while (lo < hi) {
		fill(dbg, dbg + n, 0);
//		cout << lo << " "<< hi << endl;
		int mid = (lo + hi + 1) / 2;
		k = mid;
		int v = dfs(0, -1);
		if (v == 0 || v >= k) lo = mid;
		else hi = mid - 1;
	}
	cout << lo << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

