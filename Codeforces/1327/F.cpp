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
const int MOD = 998244353;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

const int MAXN = (int) 5e5 + 5;
const int MAXK = 32;

int n, m, k;
ll dp[MAXK][MAXN];
ppi restr[MAXN];
int l[MAXN];

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
	void update(int i, T v) {
		++i;
		while (i <= n) {
			arr[i] = (arr[i] + v) % MOD;
			i += i & (-i);
		}
	}
	T get(int i) {
		T ret = 0; ++i;
		while (i > 0) {
			ret = (ret + arr[i]) % MOD;
			i -= i & (-i);
		}
		return ret;
	}
	T query(int i, int j) { return (get(j) - get(i-1) + MOD) % MOD; }
};

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
	cin >> n >> k >> m;
	FOR (i, 0, m) { cin >> restr[i].f.f >> restr[i].f.s >> restr[i].s; --restr[i].f.f; --restr[i].f.s; }
	ll ret = 1;
	FOR (i, 0, k) {
		vi ones; ones.resize(n+1);
		vi l; l.resize(n+1);
		fill(l.begin(), l.end(), -1);
		int last = -1;
		FOR (j, 0, m) {
			if ((restr[j].s & (1<<i)) > 0) {
				ones[restr[j].f.f]++; ones[restr[j].f.s + 1]--;
			}
			else {
				l[restr[j].f.s + 1] = max(restr[j].f.f, l[restr[j].f.s + 1]);
				last = max(last, restr[j].f.f);
			}
		}
		FOR (j, 1, n) ones[j] += ones[j-1];
		FOR (j, 1, n) l[j] = max(l[j], l[j-1]);
//		PRSP(ones, ones.size()-1); PRSP(l, l.size()-1);
		dp[i][0] = 1;
		ll sum = 0, lp = 0;
		FOR (j, 0, n) {
			sum = (sum + dp[i][j]) % MOD;
			if (ones[j]) continue;
			while (lp < l[j] + 1) {
				sum = (sum - dp[i][lp] + MOD) % MOD;
				++lp;
			}
			dp[i][j+1] = sum;
		}
//		PRSP(dp[i], n+1);
//		cout << last.f << " " << last.s << endl;
//		cout << endl;
		ll temp = 0;
		FOR (j, last+1, n+1) {
			temp = (temp + dp[i][j]) % MOD;
		}
		ret = (ret * temp) % MOD;
	}
	cout << ret << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
