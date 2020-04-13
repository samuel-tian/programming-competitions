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
	int n;
	cin >> n;
	int a[n];
	FOR (i, 0, n) cin >> a[i];
	int dp[n+5][n+5];
	FOR (i, 0, n) {
		FOR (j, 0, n) {
			if (i == j) dp[i][j] = a[i];
			else dp[i][j] = 0;
		}
	}
	FOR (len, 2, n+1) {
		FOR (i, 0, n) {
			int j = i + len - 1;
			FOR (k, i, j) {
				if (dp[i][k] == 0 || dp[k+1][j] == 0) continue;
				if (dp[i][k] == dp[k+1][j]) {
					dp[i][j] = dp[i][k] + 1;
				}
			}
		}
	}
	/*FOR (i, 0, n) {
		FOR (j, 0, n) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	int dp2[n];
	fill(dp2, dp2+n, INF);
	dp2[0] = 1;
	FOR (i, 1, n) {
		FOR (j, 0, i+1) {
			if (dp[j][i]) {
				if (j == 0) dp2[i] = min(dp2[i], 1);
				else dp2[i] = min(dp2[i], 1 + dp2[j-1]);
			}
		}
	}
	cout << dp2[n-1] << endl;
}
