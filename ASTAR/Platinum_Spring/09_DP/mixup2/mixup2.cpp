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
#define max3(a, b, c) max(max((a), (b)), (c));

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

const int MAXN = 17;

int n, k;
int ser[MAXN];
ll dp[1<<MAXN][MAXN];

int main() {
	setIO();
	cin >> n >> k;
	FOR (i, 0, n) cin >> ser[i];
	dp[0][0] = 1;
	FOR (i, 0, n) {
		dp[1<<i][i+1] = 1;
	}
	FOR (b, 1, 1<<n) {
		FOR (i, 0, n) {
			if ((b & (1<<i)) == 0) continue;
			else {
				FOR (j, 0, n) {
					if ((b & (1<<j)) == 0) continue;
					if (i == j) continue;
					if (abs(ser[i] - ser[j]) <= k) continue;
					dp[b][i+1] += dp[b^(1<<i)][j+1];
				}
			}
		}
	}
	ll ret = 0;
	/*FOR (b, 0, 1<<n) {
		cout << b << ": ";
		FOR (i, 0, n+1) {
			cout << dp[b][i] << " ";
		}
		cout << endl;
	}*/
	FOR (i, 0, n) {
		ret += dp[(1<<n)-1][i+1];
	}
	cout << ret << endl;
}
