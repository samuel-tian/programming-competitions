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
const int MOD = 998244353;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) {
		ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d;
	}
	return x = 1, y = 0, a;
}

ull mod_inv(ull a, ull m) {
	ll x, y, g = euclid(a, m, x, y);
	assert(g == 1);
	return ((ull) ((x + m) % m));
}

ull mod_mul(ull a, ull b, const ull m) {
	ll ret = a * b - m * ull(ld(a) * ld(b) / ld(m));
	return ret + m * (ret < 0) - m * (ret >= (ll)m);
}

ull mod_pow(ull b, ull e, const ull m) {
	ull ret = 1;
	for (; e; b = mod_mul(b, b, m), e /= 2) {
		if (e & 1) ret = mod_mul(ret, b, m);
	}
	return ret;
}

ull mod_fact(ull a, const ull m) {
	ull ret = 1;
	while (a > 1) {
		ret = mod_mul(ret, ((a/m) % 2 ? m-1 : 1), m);
		FOR (i, 2, a%m + 1) {
			ret = mod_mul(ret, i, m);
		}
		a = a / m;
	}
	return ret % m;
}

ull mod_multinom(vi& v, const ull m) {
	ull num, den = 1;
	ull tot = 0;
	for (int i : v) {
		tot += i;
		den = mod_mul(den, mod_fact(i, m), m);
	}
	num = mod_fact(tot, m);
	return mod_mul(num, mod_inv(den, m), m);
}

bool is_prime(ull n) {
	if (n < 2 || n % 6 % 4 != 1) return n < 4;
	ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	ull s = __builtin_ctzll(n-1), d = n >> s;
	for (ull a : A) {
		ull p = mod_pow(a, d, n), i = s;
		while (p != 1 && p != n-1 && a%n && i--) {
			p = mod_mul(p, p, n);
		}
		if (p != n-1 && i != s) return false;
	}
	return true;
}

ull pollard(ull n) {
	auto f = [n](ull x) {return (mod_mul(x, x, n) + 1) % n;};
	if (!(n & 1)) return 2;
	for (ull i = 2;; i++) {
		ull x = i, y = f(x), p;
		while ((p = __gcd(n + y - x, n)) == 1) {
			x = f(x), y = f(f(y));
		}
		if (p != n) return p;
	}
}

vector<ull> factor(ull n) {
	if (n == 1) return {};
	if (is_prime(n)) return {n};
	ull x = pollard(n);
	vector<ull> l = factor(x);
	vector<ull> r = factor(n / x);
	l.insert(l.end(), r.begin(), r.end());
	return l;
}

ull dist(ull a, ull b, vector<ull> &factors) {
	if (b > a) return dist(b, a, factors);
	vi sub_factors;
	sub_factors.resize(factors.size());
	FOR (i, 0, factors.size()) {
		while (a != 0 && a % factors[i] == 0) {
			a = a / factors[i];
			sub_factors[i]++;
		}
		while (b != 0 && b % factors[i] == 0) {
			b = b / factors[i];
			sub_factors[i]--;
		}
	}
	return mod_multinom(sub_factors, MOD);
}

int main() {
	setIO();
	ull d;
	cin >> d;
	factor(d);
	vector<ull> factors = factor(d);
	sort(factors.begin(), factors.end());
	FORd (i, factors.size() -1 , 0) {
		if (factors[i] == factors[i-1]) factors.erase(factors.begin() + i);
	}
//	PRSP(factors, factors.size());
	int q;
	cin >> q;
	while (q--) {
		ull a, b;
		cin >> a >> b;
		ull g = __gcd(a, b);
		ull ret = mod_mul(dist(a, g, factors), dist(b, g, factors), MOD);
		cout << ret << endl;
	}
}
