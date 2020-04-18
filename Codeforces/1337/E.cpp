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
#define REP(i, x) for (int (i) : (x))
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
const int MOD = 998244353;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

const int MAXN = 3005;

int n, m;
string s, t;
ll dp[MAXN][MAXN];

int main() {
	setIO();
	cin >> s >> t;
	n = s.size(); m = t.size();
	FOR (i, 0, n) {
		if (i >= m) {
			dp[0][i] = 2;
		}
		else if (s[0] == t[i]) {
			dp[0][i] = 2;
		}
	}
	FOR (i, 0, n-1) {
		FOR (j, 0, n) {
			if (i+j+1>=m || s[i+1] == t[i+j+1]) {
				dp[i+1][j] = (dp[i][j] + dp[i+1][j]) % MOD;
			}
			if (j-1>=m || (j-1>=0 && s[i+1] == t[j-1])) {
				dp[i+1][j-1] = (dp[i][j] + dp[i+1][j-1]) % MOD;
			}
		}
	}
	/*FOR (i, 0, n) {
		FOR (j, 0, n) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	ll ret = 0;
	FOR (i, m-1, n) {
		ret = (ret + dp[i][0]) % MOD;
	}
	cout << ret << endl;
}
