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

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)
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
const int MOD = 10000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

int main() {
	setIO();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vi a(n);
		vector<vi> inv;
		inv.resize(200);
		FOR (i, 0, n) {
			cin >> a[i];
			a[i]--;
			inv[a[i]].pb(i);
		}
		vector<vi> pre(200);
		FOR (i, 0, 200) pre[i].resize(n+1);
		FOR (i, 0, n+1) {
			FOR (j, 0, 200) {
				if (i == 0) {
					pre[j][i] = 0;
				}
				else {
					pre[j][i] = (pre[j][i-1] + (a[i-1] == j));
				}
			}
		}
		int ret = 0;
		FOR (i, 0, 200) {
			ret = max(ret, pre[i][n]);
			FOR (j, 0, inv[i].size() / 2) {
				int l = inv[i][j], r = inv[i][inv[i].size() - j - 1];
				FOR (k, 0, 200) {
					ret = max(ret, 2*(j+1) + pre[k][r] - pre[k][l+1]);
				}
			}
		}
		cout << ret << endl;
	}
}
