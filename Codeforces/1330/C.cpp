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

int main() {
	setIO("stdio");
	int n, m;
	cin >> n >> m;
	ll l[m];
	FOR (i, 0, m) {
		cin >> l[i];
	}
	ll ssum[m];
	FORd (i, m-1, 0) {
		if (i == m-1) ssum[i] = l[i];
		else ssum[i] = ssum[i+1] + l[i];
	}
	ll max_colored = -1;
	ll last_colored = -1;
	vector<ll> ans;
	FOR (i, 0, m) {
		ll ret = max(last_colored + 1, n - ssum[i]);
		if (ret > max_colored + 1) break;
		if (ret > n - l[i]) break;
		ans.pb(ret + 1);
		last_colored = ret;
		max_colored = ret + l[i] - 1;
	}
	if (ans.size() < m || max_colored < m-1) {
		cout << -1 << endl;
	}
	else {
		PRSP(ans, ans.size());
	}
}
