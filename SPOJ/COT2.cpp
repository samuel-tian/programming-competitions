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

const int N = 40005;
const int M = 100005;
const int BLK = (int) ceil(sqrt(2 * N));

int n, m;
int w[N];
vi adj[N];
int st[N], en[N];
pi ord[2*N];
int d[N], par[N][MAXLOG];
pi op[M];

inline ll hilbert_order(int x, int y, int pow, int rotate) {
    if (pow == 0) return 0;
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? 
        ((y < hpow) ? 0 : 3) :
        ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotate_delta[4] = { 3, 0, 0, 1 };
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotate_delta[seg]) & 3;
    ll sub_square_size = ll(1) << (2*pow - 2);
    ll ans = seg * sub_square_size;
    ll add = hilbert_order(nx, ny, pow-1, nrot);
    ans += (seg==1 || seg==2) ? add : (sub_square_size - add - 1);
    return ans;
}

struct query {
    int l, r, idx;
    int lca = -1;
    ll ord = -1;
    inline void calc_ord() {
        this->ord = hilbert_order(this->l, this->r, MAXLOG, 0);
    }
    inline bool operator < (const query &o) {
        return this->ord < o.ord;
    }
} q[M];

/*
struct query {
    int l, r, idx;
    int lca = -1;
    inline pair<int, int> to_pair() const {
        return mp(l / BLK, ((l / BLK) & 1) ? -r : +r);
    }
    inline bool operator < (const query& o) {
        return this->to_pair() < o.to_pair()
    }
} q[M];
*/

void dfs(int a, int p, int dep, int& x) {
    par[a][0] = p;
    ord[x] = mp(w[a], a);
    st[a] = x++;
    d[a] = dep;
    TRAV (b, adj[a]) {
        if (b == p) continue;
        dfs(b, a, dep+1, x);
    }
    ord[x] = mp(w[a], a);
    en[a] = x++;
}

int lca(int a, int b) {
    int dif = d[a] - d[b];
    if (dif < 0) {
        swap(a, b);
        dif = -dif;
    }
    FOR (i, 0, MAXLOG) {
        if (dif & (1<<i)) {
            a = par[a][i];
        }
    }
    FORd (i, MAXLOG-1, 0) {
        if (par[a][i] == par[b][i]) continue;
        a = par[a][i];
        b = par[b][i];
    }
    if (a != b) return par[a][0];
    else return a;
}

gp_hash_table<int, int> cnt;
gp_hash_table<int, bool> vis;

void go(int i, int &ans) {
    if (vis[ord[i].s] && --cnt[ord[i].f] == 0) {
        ans--;
//        if (vis[ord[i].s]) cout << "duplicate " << ord[i].s << " " << ord[i].f << endl;
//        else cout << "remove " << ord[i].s << " " << ord[i].f << endl;
    } 
    else if (!vis[ord[i].s] && ++cnt[ord[i].f] == 1) {
        ans++;
//        cout << "add " << ord[i].s << " " << ord[i].f << endl;
    }
    vis[ord[i].s] ^= 1;
    
}

int main() {
    chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

    setIO();
    int n, m;
    cin >> n >> m;
    FOR (i, 0, n) cin >> w[i];
    FOR (i, 0, n-1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int x = 0;
    dfs(0, 0, 0, x);
    /*cout << endl;
    FOR (i, 0, 2*n) cout << ord[i].f << " ";
    cout << endl;
    PRSP(st, n);
    PRSP(en, n);*/
    FOR (i, 1, MAXLOG) {
        FOR (j, 0, n) {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    FOR (i, 0, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        op[i] = mp(a, b);
    }
    FOR (i, 0, m) {
        if (st[op[i].f] > st[op[i].s]) swap(op[i].f, op[i].s);
        int anc = lca(op[i].f, op[i].s);
        if (anc == op[i].f) {
            q[i] = { st[op[i].f], st[op[i].s], i, -1 };
        }
        else {
            q[i] = { en[op[i].f], st[op[i].s], i, st[anc] };
        }
        q[i].calc_ord();
    }
    sort(q, q + m);
    int ret[m];
    int l = 0, r = -1, ans = 0;
    FOR (i, 0, m) {
        int l_int = q[i].l, r_int = q[i].r;
//        cout << "query " << l_int << " " << r_int << endl;
        while (l < l_int) go(l++, ans);
        while (l > l_int) go(--l, ans);
        while (r < r_int) go(++r, ans);
        while (r > r_int) go(r--, ans);
//        cout << "before " << ans << " ";
        if (q[i].lca != -1) go(q[i].lca, ans);
//        cout << "after " << ans << endl;
        ret[q[i].idx] = ans;
        if (q[i].lca != -1) go(q[i].lca, ans);
    } 
    FOR (i, 0, m) {
        cout << ret[i] << endl;
    }

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//  cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}


