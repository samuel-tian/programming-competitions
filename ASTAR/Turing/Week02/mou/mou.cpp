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

void setIO(string name = "") {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	if (name == "")
        return;
    if (name == "input") {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
	else {
        freopen((name+".in").c_str(),"r",stdin);
        freopen((name+".out").c_str(),"w",stdout);
    }
}

const ll INF = LLONG_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    ll operator()(ll x) const {
        return x ^ RANDOM;
    }
};

const int N = 400005;

int n;
vi comp;
unordered_map<int, int> inv;

int sz;
vll sum, height, lazy;

void propagate(int node, int a, int b) {
    if (lazy[node] != INF) {
        sum[node] = lazy[node] * (comp[b+1] - comp[a]);
        height[node] = lazy[node] * (comp[b+1] - comp[a]);
        if (a != b) {
            lazy[2*node+1] = lazy[node];
            lazy[2*node+2] = lazy[node];
        }
        lazy[node] = INF;
    }
}

void updateUtil(int node, int a, int b, int i, int j, int val) {
    propagate(node, a, b);
    if (a > b || a > j || b < i)
        return;
    if (a >= i && b <= j) {
        sum[node] = val * (comp[b+1] - comp[a]);
        height[node] = val * (comp[b+1] - comp[a]);
        if (a != b) {
            lazy[2*node+1] = val;
            lazy[2*node+2] = val;
        }
        return;
    }
    int mid = (a + b) / 2;
    updateUtil(2*node+1, a, mid, i, j, val);
    updateUtil(2*node+2, mid+1, b, i, j, val);
    sum[node] = sum[2*node+1] + sum[2*node+2];
    height[node] = max(height[2*node+1], sum[2*node+1] + height[2*node+2]);
}

void update(int i, int j, int val) {
    updateUtil(0, 0, comp.size()-1, i, j, val);
}

/*
ll queryUtil(int node, int a, int b, int i, int j) {
    propagate(node, a, b);
    if (a > b || a > j || b < i)
        return 0;
    if (a >= i && b <= j)
        return sum[node];
    int mid = (a + b) / 2;
    ll l = queryUtil(2*node+1, a, mid, i, j);
    ll r = queryUtil(2*node+2, mid+1, b, i, j);
    return l + r;
}

ll query(int i, int j) {
    return queryUtil(0, 0, comp.size()-1, i, j);
}
*/

ll ansUtil(int node, int a, int b, ll h) {
    if (a == b) {
        // cerr << "ans done" << '\n';
        ll v = sum[node] / (comp[a+1] - comp[a]);
        ll ans1;
        if (v == 0)
            ans1 = INF;
        else
            ans1 = comp[a] + h / v;
        ll ans2 = a==comp.size()-1 ? n : comp[a+1]-1;
        // cerr << "ans: " << ans1 << " " << ans2 << '\n';
        return min(ans1, ans2);
    }
    int mid = (a + b) / 2;
    propagate(2*node+1, a, mid);
    if (height[2*node+1] <= h) {
        propagate(2*node+2, mid+1, b);
        return ansUtil(2*node+2, mid+1, b, h - sum[2*node+1]);
    }
    else
        return ansUtil(2*node+1, a, mid, h);
}

ll ans(ll h) {
    propagate(0, 0, comp.size()-1);
    return ansUtil(0, 0, comp.size()-1, h);
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n;
    set<int> tmp;
    vector<pair<char, ppi> > q;
    while (true) {
        char c;
        cin >> c;
        if (c == 'E')
            break;
        if (c == 'Q') {
            int h;
            cin >> h;
            q.pb(mp(c, mppi(0, 0, h)));
        }
        else {
            int a, b, d;
            cin >> a >> b >> d;
            a--, b--;
            q.pb(mp(c, mppi(a, b, d)));
            tmp.insert(a);
            tmp.insert(a+1);
            tmp.insert(b);
            tmp.insert(b+1);
        }
    }
    tmp.insert(0);
    tmp.insert(n);
    TRAV (i, tmp) {
        comp.pb(i);
    }
    FOR (i, 0, comp.size()) {
        inv[comp[i]] = i;
    }
    sum.resize(4*N);
    height.resize(4*N);
    lazy.resize(4*N);
    FOR (i, 0, 4*N) {
        sum[i] = 0;
        height[i] = 0;
        lazy[i] = INF;
    }
    TRAV (i, q) {
        if (i.f == 'Q') {
            cout << ans(i.s.s) << '\n';
        }
        else {
            update(inv[i.s.f.f], inv[i.s.f.s], i.s.s);
        }
    }


	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

