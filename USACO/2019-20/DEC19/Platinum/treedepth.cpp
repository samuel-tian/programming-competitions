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
#define eb emplace_back
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
// const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

const int N = 305;

int n, k, MOD;

template<class T>
struct mi {
    T val;
    mi() = default;
    mi(const T& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    mi& operator += (const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this;
    }
    mi& operator -= (const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this;
    }
};

template<class T>
using poly = vector<mi<T> >;

void mul(poly<ll>& a, int m) {
    a.resize(a.size() + m);
    FORd (i, a.size() - 1, 0) {
        if (i + m + 1 >= a.size()) continue;
        a[i + m + 1] -= a[i];
    }
    FOR (i, 1, a.size()) {
        a[i] += a[i-1];
    }
}

void div(poly<ll>& a, int m) {
    FORd (i, a.size()-1, 1) {
        a[i] -= a[i-1];
    }
    FOR (i, 0, a.size()) {
        if (i + m + 1 >= a.size()) break;
        a[i + m + 1] += a[i];
    }
    a.resize(a.size() - m);
}

void poly_print(poly<ll> p) {
	string ret;
	bool leading = true;
	for (int i = p.size() - 1; i >= 0; i--) {
		if (!p[i].val) continue;
		if (leading) ret += (p[i].val < 0 ? "-" : "");
		else ret += (p[i].val < 0 ? " - " : " + ");
		leading = false;
		if (abs(p[i].val) != 1 || i == 0) ret += to_string(abs(p[i].val));
		if (i) ret += (i == 1 ? "x" : "x^" + to_string(i));
	}
    cerr << ret << endl;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("treedepth");
    cin >> n >> k >> MOD;
    poly<ll> f, ans;
    f = {1};
    FOR (i, 0, n) mul(f, i);
    // poly_print(f);
    ans.resize(n);
    FOR (i, 0, n) {
        ans[i] += ((k < 0 || k >= f.size()) ? 0 : f[k]);
    }
    FOR (i, 1, n) {
        div(f, i);
        // poly_print(f);
        mi<ll> forward = ((k-i < 0 || k-i >= f.size()) ? 0 : f[k-i]);
        mi<ll> backward = ((k < 0 || k >= f.size()) ? 0 : f[k]);
        // cerr << forward.val << " " << backward.val << endl;
        FOR (j, 0, n) {
            if (j + i < n) {
                // cerr << j << " " << j + i << " " << forward.val << " " << backward.val << endl;
                ans[j] += forward;
                ans[j + i] += backward;
            }
        }
        mul(f, i);
    }
    FOR (i, 0, n) {
        if (i == n-1) cout << ans[i].val << endl;
        else cout << ans[i].val << " ";
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

