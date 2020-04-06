#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
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
#define max3(a, b, c) max(max((a), (b)), (c));
 
const int MAXN = 100005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 998244353;
 
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
 
ll n, m, l, r;
 
ll mod_pow(ll base, ll exp) {
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
	cin >> n >> m >> l >> r;
	if (n % 2 == 1 && m % 2 == 1) {
		cout << mod_pow(r - l + 1, n*m);
	}
	else {
		ll evens, odds;
		if ((l % 2) != (r % 2)) {
			evens = odds = (r - l + 1) / 2;
		}
		else if (l % 2 == 0) {
			evens = (r - l + 1) / 2 + 1;
			odds = (r - l + 1) / 2;
		}
		else {
			odds = (r - l + 1) / 2 + 1;
			evens = (r - l + 1) / 2;
		}
		ll ans = (mod_pow(evens + odds, n * m) + mod_pow(evens - odds, n * m)) % MOD;
		if (ans % 2 == 0) {
			cout << ans /2 << endl;
		}
		else {
			cout << (ans + MOD) / 2;
		}
	}
}