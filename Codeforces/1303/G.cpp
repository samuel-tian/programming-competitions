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

template<class T>
struct li_chao {
    struct L {
        T m, b;
        L() = default;
        L(T m, T b) { this->m = m, this->b = b; }
        T dot(L other) { return m * other.m + b * other.b; }
    };
    vector<L> tree;
    vector<bool> used;
    int n;
    li_chao() = default;
    li_chao(int n) {
        this->n = n;
        int sz = 4*n;
        tree.resize(sz);
        used.resize(sz);
        FOR (i, 0, sz) {
            tree[i] = L(0, 0);
            used[i] = false;
        }
    }
    T f(L l, int x) { return l.dot(L(x, 1)); } // change f() for if you want a non-linear function
    T min(T a, T b) { return (a < b) ? a : b; }
    void add(T m, T x) { add_util(0, 0, n, L(m, x)); }
    void add_util(int node, int l, int r, L line) {
        used[node] = true;
        int mid = (l + r) / 2;
        bool on_left = (f(line, l) > f(tree[node], l));
        bool on_right = (f(line, mid) > f(tree[node], mid));
        if (on_right) swap(tree[node], line);
        if (r - l <= 1) return;
        else if (on_left ^ on_right) add_util(2*node+1, l, mid, line);
        else add_util(2*node+2, mid, r, line);
    }
    T query(int x) { return query_util(0, 0, n-1, x); }
    T query_util(int node, int l, int r, int x) {
        int mid = (l + r) / 2;
        T ret = f(tree[node], x);
        if (r - l <= 1) ret = ret;
        else if (x < mid) ret = max(ret, query_util(2*node+1, l, mid, x));
        else ret = max(ret, query_util(2*node+2, mid, r, x));
        return ret;
    }
    void clear() { clear_util(0, 0, n); }
    void clear_util(int node, int l, int r) {
        if (!used[node]) return;
        used[node] = false;
        tree[node] = L(0, 0);
        if (r - l <= 1) return;
        int mid = (l + r) / 2;
        clear_util(2*node+1, l, mid);
        clear_util(2*node+2, mid, r);
    }
};

const int N = 150005;

int n;
vi adj[N];
ll v[N];
bool centr[N];
int sz[N];
ll ans = 0;

void dfs(int a, int p) {
    sz[a] = 1;
    TRAV (b, adj[a]) {
        if (centr[b] || b == p) continue;
        dfs(b, a);
        sz[a] += sz[b];
    }
}

int dfs2(int a) {
    dfs(a, -1);
    int hi = sz[a] / 2;
    int p = -1;
    while (true) {
        bool found = false;
        TRAV (b, adj[a]) {
            if (centr[b] || b==p || sz[b] <= hi) continue;
            found = true;
            p = a; a = b; break;
        }
        if (!found) return a;
    }
}

ll dep[N];
ll sum[N], forward_sum[N], backward_sum[N]; // prefix sum, weighted sum with higher weights at deeper depths, higher weights at shallower depths
int cnt = 0;

void dfs3(int a, int p, ll s1, ll s2, ll s3, ll d) {
    // s1 is the prefix sum, s2 is forward weighted, s3 is reverse weighted
    // updates: s3 = s3 + s1
    //          s2 = s2 + (cnt + 1) * v[a]
    sum[cnt] = s1;
    forward_sum[cnt] = s2;
    backward_sum[cnt] = s3;
    dep[cnt] = d;
    cnt++;
    TRAV (b, adj[a]) {
        if (b == p || centr[b]) continue;
        // s1 += v[b];
        // s2 += (d+1) * v[b];
        // s3 += s1;
        dfs3(b, a, s1 + v[b], s2 + (d + 1) * v[b], s3 + s1 + v[b], d + 1);
    }
}

li_chao<ll> tr;
void decomp(int a) {
    int c = dfs2(a);
    // cout << "centroid " << c << endl;
    centr[c] = true;
    FOR (t, 0, 2) {
        tr.clear();
        TRAV (b, adj[c]) {
            if (centr[b]) continue;
            // cout << "-----" << endl;
            // cout << "b: " << b << endl;
            cnt = 0;
            dfs3(b, c, v[b], v[b], v[b], 1);
            FOR (i, 0, cnt) sum[i] += v[c];
            FOR (i, 0, cnt) {
                ans = max(ans, forward_sum[i] + sum[i]);
                ans = max(ans, backward_sum[i] + v[a] * (dep[i]+1));
                ll q = tr.query(dep[i] + 1);
                ans = max(ans, backward_sum[i] + q);
            }
            // cout << "sum: "; PRSP(sum, cnt);
            // cout << "forward sum: "; PRSP(forward_sum, cnt);
            // cout << "backward sum: "; PRSP(backward_sum, cnt);
            FOR (i, 0, cnt) {
                // cout << sum[i] << "x + " << forward_sum[i] << endl;
                tr.add(sum[i], forward_sum[i]);
            }
            // cout << tr.query(0) << " " << tr.query(1) << " " << tr.query(2) << endl;
        }
        reverse(adj[c].begin(), adj[c].end());
    }
    TRAV (b, adj[c]) {
        if (centr[b]) continue;
        decomp(b);
    }
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n;
    FOR (i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].pb(b); adj[b].pb(a);
    }
    FOR (i, 0, n) cin >> v[i];
    tr = li_chao<ll>(n);
    decomp(0);
    cout << ans << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}


