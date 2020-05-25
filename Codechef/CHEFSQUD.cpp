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
const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

const int N = 100005;

template <class T>
struct fenwick {
	int n;
	vector<T> arr;
	fenwick() {
		n = 0; arr = {};
	}
	fenwick(int n) {
		this->n = n; arr.resize(n + 1);
        fill(arr.begin(), arr.end(), 0);
	}
	void resize(int n) { this->n = n; fill(arr.begin(), arr.begin() + n, 0); }
	void clear() { FOR (i, 0, arr.size()) arr[i] = 0; }
	void update(int i, T v) {
		++i;
		while (i <= n) {
			arr[i] = (arr[i] + v);
			i += i & (-i);
		}
	}
	T get(int i) {
		T ret = 0; ++i;
		while (i > 0) {
			ret = (ret + arr[i]);
			i -= i & (-i);
		}
		return ret;
	}
	T query(int i, int j) { return get(j) - get(i-1); }
};

ll n;
int a[N];
vi comp;
fenwick<int> bit(N);

ll go(ll mid) {
    ll cnt = 0;
    int r = -1;
    ll tot = 0;
    bit.clear();
    FOR (i, 0, n) {
        while (r+1 < n) {
            ll q = bit.query(a[r+1]+1, n-1);
            if (cnt + q >= mid) break;
            r++;
            cnt += q;
            bit.update(a[r], 1);
        }
        tot += (ll)(r - i + 1);
        cnt -= bit.query(0, a[i]-1);
        bit.update(a[i], -1);
    }
    return tot;
}

void solve() {
    cin >> n;
    FOR (i, 0, n) cin >> a[i];
    ordered_set<int> s;
    FOR (i, 0, n) s.insert(a[i]);
    FOR (i, 0, n) a[i] = s.order_of_key(a[i]);
    bit.resize(n);
    ll lo = 0, hi = n*n;
    ll med = ((n*(n+1LL))/2LL-1LL)/2LL;
    while (lo < hi) {
        ll mid = (lo + hi + 1LL) / 2LL;
        ll v = go(mid);
        if (v <= med) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << lo << endl;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	// cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

