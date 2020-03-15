#include <bits/stdc++.h>

using namespace std;

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
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))

const int MAXN = 2005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);

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

int n;
int c[MAXN];
int suf[MAXN];
int dp[MAXN][MAXN];

int main() {
	setIO("input");
	cin >> n;
	FOR (i, 0, n) {
		cin >> c[i];
	}
	FORd (i, n-1, 0) {
		if (i == n-1) {
			suf[i] = c[i];
		}
		else {
			suf[i] = c[i] + suf[i+1];
		}
	}
	FOR (i, 0, n+2) {
		FOR (j, 0, n) {
			dp[i][j] = INF;
			if (i == n) {
				dp[i][j] = 0;
			}
		}
	}
	FORd (i, n-1, 0) {
		FOR (k, 1, n) {
			if (i + 2*k - 1 > n) {
				dp[i][k] = dp[i][k-1]; continue;
			}
			if (k == 1) {
				dp[i][k] = suf[i] - min(dp[i+k][k], dp[i+k+1][k+1]);
			}
			else {
				dp[i][k] = max(dp[i][k-1], suf[i] - min(dp[i+2*k-1][2*k-1], dp[i+2*k][2*k]));
			}
		}
	}
	/*FOR (i, 0, n) {
		FOR (j, 0, n) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << dp[0][1] << endl;
}