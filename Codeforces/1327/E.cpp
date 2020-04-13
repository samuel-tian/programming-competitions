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

ll mod_pow(int base, int exp) {
	if (exp == 0) return 1;
	else if (exp == 1) return base;
	else {
		ll t = mod_pow(base, exp / 2);
		ll ret = (t * t) % MOD;
		return (exp % 2 == 1) ? (ret*base)%MOD : ret;
	}
}

int main() {
	setIO("stdio");
	int n;
	cin >> n;
	FOR (i, 1, n+1) {
		if (i == n) cout << 10 << endl;
		else {
			ll type1 = (810*((n-i-1)*mod_pow(10, n-i-2))%MOD)%MOD;
			ll type2 = (180*mod_pow(10, n-i-1))%MOD;
			cout << ((type1 + type2) % MOD) << endl;
		}
	}
}
