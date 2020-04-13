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
const int MOD = 998244353;

ll mod_inv(ll a, ll m) {
	ll b0 = m, t, q;
	ll x0 = 0, x1 = 1;
	if (m == 1) return 1;
	while (a > 1) {
		q = a / m;
		t = m, m = a % m, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

ll mod_binom(int n, int k, ll m) {
	ll numer = 1, denom = 1;
	for (int i = 1, j = n; i <= k; ++i, --j) {
		denom = (denom * i) % m;
		numer = (numer * j) % m;
	}
	return (numer * mod_inv(denom, m)) % m;
}

ll mod_pow(int b, int e, ll m) {
	if (e == 0) return 1;
	else if (e == 1) return b;
	else {
		ll t = mod_pow(b, e / 2, m);
		ll ret = (t * t) % m;
		return (e % 2 == 1) ? (ret * b) % m : ret;
	}
}

int main() {
	setIO("stdio");
	int n, m;
	cin >> n >> m;
	ll ret = (((n-2) * mod_binom(m, n-1, MOD)) % MOD * mod_pow(2, n-3, MOD)) % MOD;
	cout << ret << endl;
}
