/*
 * Rabin-Karp Algorithm (Rolling Hash)
 * -----------------------------------
 * 1) if s is a string, n is the length of that string, MUL is a constant multiplier, and MOD is the modulus, let the polynomial hash be defined as follows
 * 		H(s) = (MUL^(n-1)*s[0] + MUL^(n-2)*s[1] + ... + MUL^2*s[n-3] + MUL*s[n-2] + s[n-1]) % MOD
 * 2) hashes of all substrings of length p can be calculated in constant time by
 * 		H_i = ((H_(i-1) - MUL^(p-1)*s[i-1])*MUL + s[i+p-1]) % MOD
 * 3) pattern matching
 * 		a) compute the hash of the pattern
 * 		b) compute the hash of every substring of the text of length k using a rolling hash
 * 		c) if a rolled hash equals the pattern hash, then there exists a match
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef long long ll;

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

const int MAXN = 100005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;

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

string str, pattern;
vi matches;

ll mod_pow(int exp) {
	if (exp == 0) return 1;
	else if (exp == 1) return MUL;
	else {
		ll t = mod_pow(exp / 2);
		ll ret = (t * t) % MOD;
		return (exp % 2 == 1) ? (ret*MUL)%MOD : ret;
	}
}

void rolling_hash() {
	int n = str.size(), p = pattern.size();
	ll h = 0;
	FOR (i, 0, p) {
		h = (h * MUL + (ll)(pattern[i] - 'A')) % MOD;
	}
	ll rh = 0;
	FOR (i, 0, n) {
		if (i == 0) {
			FOR (j, 0, p) {
				rh = (rh * MUL + (str[j] - 'A')) % MOD;
			}
		}
		else {
			ll power = mod_pow(p - 1);
			rh = ((rh - power * (str[i-1]-'A')) * MUL + (str[i+p-1]-'A')) % MOD;
			if (rh < 0) rh += MOD;
		}
		if (rh == h) matches.pb(i);
	}
}

int main() {
	setIO("input");
	cin >> str >> pattern;
	rolling_hash();
	cout << matches.size() << endl;
	for (int i : matches) {
		cout << i << endl;
	}
}