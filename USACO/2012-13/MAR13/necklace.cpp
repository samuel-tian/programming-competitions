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
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

const int MAXN = 10005;
const int MAXM = 1005;

int n, m;
string s, p;
int dp[3][MAXM];
vi pre;

void prefix_function(string s) {
	int n = s.size();
	pre.resize(n+1);
	FOR (i, 1, n) {
		int j = pre[i];
		while (j > 0 && s[i] != s[j]) {
			j = pre[j];
		}
		if (s[i] == s[j]) {
			++j;
		}
		pre[i+1] = j;
	}
	pre[0] = -1;
}

int main() {
	setIO();
	cin >> s >> p;
	n = s.size(); m = p.size();
	prefix_function(p);
	FOR (i, 0, n+1) {
		FOR (j, 0, m+1) {
			dp[i%3][j] = INF;
		}
	}
	dp[0][0] = 0;
//	PRSP(pre, pre.size());
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			dp[(i+2)%3][j] = INF;
		}
		FOR (j, 0, m) {
			if (dp[i%3][j] == INF) continue;
			int k = j;
			while (k != -1 && p[k] != s[i]) {
				k = pre[k];
			}
			k++;
			dp[(i+1)%3][k] = min(dp[(i+1)%3][k], dp[i%3][j]);
			dp[(i+1)%3][j] = min(dp[(i+1)%3][j], dp[i%3][j] + 1);
		}
	}
	int ret = INF;
	/*FOR (i, 0, n+1) {
		FOR (j, 0, m) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	FOR (i, 0, m) {
		ret = min(dp[n%3][i], ret);
	}
	cout << ret << endl;
}
