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
const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

template <class T> struct fenwick {
	int n;
	vector<T> arr;
	fenwick() {
		n = 0; arr = {};
	}
	fenwick(int n) {
		this->n = n; arr.resize(n + 1);
	}
	void clear() { arr.clear(); }
	void update(ll i, T v) {
		++i;
		while (i <= n) {
			arr[i] = (arr[i] + v) % MOD;
			i += i & (-i);
		}
	}
	T get(ll i) {
		if (i == -1) return 0;
		T ret = 0; ++i;
		while (i > 0) {
			ret = (ret + arr[i]) % MOD;
			i -= i & (-i);
		}
		return ret;
	}
	T query(ll i, ll j) { return (get(j) - get(i-1) + MOD) % MOD; }
};

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("input");
	ll n, x;
	cin >> n >> x;
	vector<ll> h(n), p(n+1);
	FOR (i, 0, n) cin >> h[i];
	FOR (i, 0, n) p[i+1] = (h[i]>=x) ? 1 : -1;
	FOR (i, 1, n+1) p[i] += p[i-1];
	FOR (i, 0, n+1) p[i] += n+1;
	reverse(p.begin(), p.end());
//	PRSP(p, p.size());
	fenwick<ll> f(2*n+100);
	ll ans = 0;
	FOR (i, 0, n+1) {
		ans += f.query(0, p[i]-1);
		f.update(p[i], 1);
	}
	cout << (n*(n+1))/2 - ans << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	// cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1-t0).count << " ms" << endl;
}