#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<long long, long long> pll;
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
#define smax(a, b) a < b ? a = b, 1 : 0
#define smin(a, b) a > b ? a = b, 1 : 0

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

const int N = 1e5 + 100;

ll n, k;
vll n_factors;
unordered_map<ll, int> inv;
unordered_map<ll, vll> factors;
int pos[N];

vll get_factors(ll n) {
    vll ret;
    if (n_factors.empty()) {
        FOR (i, 1, ceil(sqrt(n)+1)) {
            if (n % i == 0) {
                ll x = n / i;
                if (x < i) continue;
                ret.pb(i);
                if (i < x) ret.pb(x);
            }
        }
        sort(ret.begin(), ret.end());
    }
    else {
        FOR (i, 0, n_factors.size()) {
            if (n < n_factors[i]) break;
            if (n % n_factors[i] == 0) {
                ret.pb(n_factors[i]);
            }
        }
    }
    return ret;
}

void adv(vll& cur) {
    vll tmp;
    int cnt = 0;
    FOR (i, 0, cur.size()) {
        FOR (j, 0, factors[cur[i]].size()) {
            tmp.pb(factors[cur[i]][j]);
            cnt++;
            if (cnt >= 100000) break;
        }
        if (cnt >= 100000) break;
    }
    swap(tmp, cur);
}

void dbl(vll& cur) {
    vll cpy, tmp;
    cpy.resize(cur.size());
    FOR (i, 0, cur.size())
        cpy[i] = cur[i];
    // cerr << "pass" << endl;
    int cnt = 0;
    FOR (j, 0, cur.size()) {
        if (n_factors[cnt] == cur[j]) {
            pos[cnt] = j;
            cnt++;
        }
    }
    adv(cur);
    int cnt2 = 0;
    FOR (i, 0, cur.size()) {
        int v = inv[cur[i]];
        int lb = (v == 0 ? 0 : pos[v-1]+1);
        FOR (j, lb, pos[v]+1) {
            tmp.pb(cpy[j]);
            cnt2++;
            if (cnt2 >= 100000) break;
        }
        if (cnt2 >= 100000) break;
    }
    swap(tmp, cur);
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> k;
    n_factors = get_factors(n);
    FOR (i, 0, n_factors.size()) {
        ll x = n_factors[i];
        vll tmp = get_factors(x);
        factors[x] = tmp;
        inv[x] = i;
    }
    vll cur = {n};
    if (k != 0) {
        int sz = 64 - __builtin_clzll(k);
        FORd (i, sz - 1, 0) {
            if (k & (1<<(ll)i)) {
                adv(cur);
            }
            if (i != 0) dbl(cur);
        }
    }
    PRSP(cur, cur.size());

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
    //cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

