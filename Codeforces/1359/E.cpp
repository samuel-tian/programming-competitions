#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (int (i) = (a); i < (b); ++i)
#define FORd(i, a, b) for (int (i) = (a); i >= (b); --i)
#define TRAV(i, x) for (auto& (i) : (x))
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

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) {
		ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d;
	}
	return x = 1, y = 0, a;
}

ll mod_inv(ll a, ll m) {
	ll x, y, g = euclid(a, m, x, y);
	assert(g == 1);
	return (x + m) % m;
}

ll mod_mul(ll a, ll b, const ll m) {
	ll ret = a * b - m * ull(ld(a) * ld(b) / ld(m));
	return ret + m * (ret < 0) - m * (ret >= (ll)m);
}

ll mod_pow(ll b, ll e, const ll m) {
	ll ret = 1;
	for (; e; b = mod_mul(b, b, m), e /= 2) {
		if (e & 1) ret = mod_mul(ret, b, m);
	}
	return ret;
}

ll mod_fact(ll a, const ll m) {
	ll ret = 1;
	while (a > 1) {
		ret = mod_mul(ret, ((a/m) % 2 ? m-1 : 1), m);
		FOR (i, 2, a%m + 1) {
			ret = mod_mul(ret, i, m);
		}
		a = a / m;
	}
	return ret % m;
}

ll mod_multinom(vi& v, const ll m) {
	ll num, den = 1;
	ll tot = 0;
	for (int i : v) {
		tot += i;
		den = mod_mul(den, mod_fact(i, m), m);
	}
	num = mod_fact(tot, m);
	return mod_mul(num, mod_inv(den, m), m);
}

ll mod_pow(int b, int e, const ll m) {
	if (e == 0) return 1;
	else if (e == 1) return b;
	else {
		ll t = mod_pow(b, e / 2, m);
		ll ret = (t * t) % m;
		return (e % 2 == 1) ? (ret * b) % m : ret;
	}
}

ll mod_binom(ll n, ll k, const ll m) {
	ll num = mod_fact(n, m);
	ll den = mod_inv(mod_mul(mod_fact(k, m), mod_fact(n-k, m), m), m);
	return mod_mul(num, den, m);
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    int n, k;
    cin >> n >> k;
    if (n < k) cout << 0 << endl;
    else {
        ll x = mod_binom(n-1, k-1, MOD);
        FOR (i, 2, n / k + 1) {
            int v = n / i;
            if (k > v) continue;
            x = (x + mod_binom(v-1, k-1, MOD)) % MOD;
        }
        cout << x << endl;
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

