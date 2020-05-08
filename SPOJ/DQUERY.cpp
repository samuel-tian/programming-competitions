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

const int N = 30005;
const int Q = 200005;

int n, q;
int a[N], blk[N];
pi qu[Q];
int ret[Q];
ppi mo[Q];

gp_hash_table<int, int> cnt;
int ans = 0;

void add(int i) {
    cnt[a[i]]++;
    if (cnt[a[i]] == 1) ans++;
}

void remove(int i) {
    cnt[a[i]]--;
    if (cnt[a[i]] == 0) ans--;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n;
    FOR (i, 0, n) { cin >> a[i]; }
    cin >> q;
    FOR (i, 0, q) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        qu[i] = mp(a, b);
    }
    int n_sqrt = (int) ceil(sqrt(n));
    FOR (i, 0, n) {
        blk[i] = i / n_sqrt;
    }
    FOR (i, 0, q) {
        pi x = mp(blk[qu[i].f], blk[qu[i].s]);
        mo[i] = mp(x, i);
    }
    sort(mo, mo + q);
    int l = 0, r = 0;
    FOR (i, 0, q) {
        pi intv = qu[mo[i].s];
        while (l < intv.f) { remove(l++); }
        while (l > intv.f) { add(--l); }
        while (r <= intv.s) { add(r++); }
        while (r > intv.s + 1) { remove(--r); }
        ret[mo[i].s] = ans;
        cout << l << " " << r << endl;
    }
    PRSP(ret, q);

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

