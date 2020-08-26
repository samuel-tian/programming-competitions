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

int main() {
	setIO();
	ull d;
	cin >> d;
	factor(d);
	vector<ull> factors = factor(d);
}
