#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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

int main() {
	setIO("stdio");
	vector<vector<int>> factors(2.1e5);
	for (int i = 1; i < int(factors.size()); i++) {
		for (int j = i; j < int(factors.size()); j += i) {
			factors[j].push_back(i);
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int p[n], c[n], inv[n];
		FOR (i, 0, n) cin >> p[i];
		FOR (i, 0, n) inv[--p[i]] = i;
		FOR (i, 0, n) cin >> c[i];
		bool v[n];
		fill(v, v + n, false);
		int ans = INF;
		bool success = false;
		FOR (i, 0, n) {
			vi cycles;
			int sz = 0;
			int next = p[i];
			if (v[inv[next]]) continue;
			v[inv[next]] = true;
			cycles.pb(inv[next]);
			sz++;
			while (p[next] != p[i]) {
				next = p[next];
				v[inv[next]] = true;
				cycles.pb(inv[next]);
				sz++;
			}
			for (int k : factors[cycles.size()]) {
				FOR (a, 0, k) {
					success = true;
					for (int x = a; x < cycles.size(); x += k) {
						success = success && c[cycles[a]] == c[cycles[x]];
					}
					if (success) {
						ans = min(ans, k);
						break;
					}
				}
				if (success) break;
			}
		}
		cout << ans << endl;
	}
}
