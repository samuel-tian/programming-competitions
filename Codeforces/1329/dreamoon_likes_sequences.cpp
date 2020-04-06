#include <bits/stdc++.h>

using namespace std;

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

ll dp[33][33];

int main() {
	setIO("stdio");
	int t;
	cin >> t;
	dp[0][0] = 1;
	FOR (rv, 0, t) {
		ll d, m;
		cin >> d >> m;
		int sz = d ? 32 - __builtin_clz(d) : NINF;
		FOR (i, 1, sz + 1) {
			ll mul = 1;
			ll pre = 0;
			FOR (j, 1, sz + 1) {
				if (j == sz) {
					mul = d - (1<<(sz-1)) + 1;
				}
				pre = (pre + dp[i-1][j-1]) % m;
				dp[i][j] = (pre * mul) % m;
				mul *= 2;
			}
		}
		ll ans = 0;
		FOR (i, 1, sz + 1) {
			FOR (j, 1, sz + 1) {
				ans = (ans + dp[i][j]) % m;
			}
		}
		cout << ans << endl;
	}
}
