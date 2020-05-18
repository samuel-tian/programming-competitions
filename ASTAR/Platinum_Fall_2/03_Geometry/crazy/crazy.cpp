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

const int N = 1005;

struct DSU {
    vi par, r;
    DSU(int n) {
        par.resize(n);
        r.resize(n);
        FOR (i, 0, n) { par[i] = i; r[i] = 0; }
    }
    int find(int i) {
        if (par[i] != i) par[i] = find(par[i]);
        return par[i];
    }
    bool same_set(int i, int j) {
        return find(i) == find(j);
    }
    void join(int a, int b) {
        a = find(a), b = find(b);
        if (r[a] < r[b]) swap(a, b);
        par[b] = a;
        r[a] = max(r[a], r[b] + 1);
    }
};

int n, c;
pi cows[N];
map<pi, vi> inc;
int cnt[N];
ll area[N];
vpi vert[N];
bool in[N][N];

int ccw(pi a, pi b, pi c) {
    ll x = (ll) (b.f - a.f) * (ll) (c.s - a.s);
    ll y = (ll) (c.f - a.f) * (ll) (b.s - a.s);
    if (x - y < 0) return -1;
    else if (x - y == 0) return 0;
    else return 1;
}

struct Line {
    pi f, s;
    int id;
    Line() = default;
    Line(int a, int b, int c, int d, int i) {
        f = mp(a, b), s = mp(c, d);
        id = i;
    }
    bool intersect(Line &o) {
        return (ccw(f, s, o.f) * ccw(f, s, o.s) <= 0) &&
               (ccw(o.f, o.s, f) * ccw(o.f, o.s, s) <= 0);
    }
} fences[N];

bool comp(pi a, pi b) {
    if (a.f == 0 && a.s == 0) return true;
    else if (b.f == 0 && b.s == 0) return false;
    double ang1 = atan2(a.s + 1, a.f + 1);
    double ang2 = atan2(b.s + 1, b.f + 1);
    return ang1 < ang2;
}

int main() {
    chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

    setIO("crazy");
    cin >> n >> c;
    FOR (i, 0, n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        fences[i] = Line(a, b, c, d, i);
        inc[mp(a, b)].pb(i);
        inc[mp(c, d)].pb(i);
    }
    DSU dsu(n);
    TRAV (x, inc) {
        assert(x.s.size() == 2);
        dsu.join(x.s[0], x.s[1]);
    }
    FOR (i, 0, n) {
        vert[dsu.find(i)].pb(fences[i].f);
        vert[dsu.find(i)].pb(fences[i].s);
    }
    FOR (i, 0, n) {
        if (vert[i].empty()) continue;
        pi min_vertex = mp(INF, INF);
        TRAV (j, vert[i]) {
            min_vertex = min(min_vertex, j);
        }
        FORd (j, vert[i].size()-1, 0) {
            vert[i][j] = mp(vert[i][j].f - min_vertex.f, vert[i][j].s - min_vertex.s);
            if (vert[i][j].f == 0 && vert[i][j].s == 0) vert[i].erase(vert[i].begin() + j);
        }
        vert[i].pb(mp(0, 0));
        sort(vert[i].begin(), vert[i].end(), comp);
        FORd (j, vert[i].size()-1, 1) {
            if (vert[i][j] == vert[i][j - 1]) {
                vert[i].erase(vert[i].begin() + j);
            }
        }
        /*cout << "polygon " << i << endl;
        TRAV (j, vert[i]) {
            cout << "(" << j.f << ", " << j.s << "), ";
        } cout << endl;*/
        FOR (j, 0, vert[i].size()) {
            int k = (j == 0) ? vert[i].size()-1 : j-1;
            area[i] += (ll) (vert[i][k].f + vert[i][j].f) * (ll) (vert[i][k].s - vert[i][j].s);
        }
        assert(area[i] < 0);
        area[i] = abs(area[i]);
        // cout << "area " << area[i] << endl;
    }

    mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    FOR (i, 0, c) {
        int a, b;
        cin >> a >> b;
        cows[i] = mp(a, b);
        Line t = Line(a, b, generator()%MOD, generator()%MOD, -1);
        FOR (j, 0, n) {
            if (t.intersect(fences[j])) {
                in[i][dsu.find(j)] ^= 1;
            }
        }
        ll min_area = LLONG_MAX, ind = n;
        FOR (j, 0, n) {
            if (in[i][j]) {
                if (area[dsu.find(j)] < min_area) {
                    min_area = area[dsu.find(j)];
                    ind = dsu.find(j);
                }
            }
        }
        cnt[ind]++;
    }
    int ans = -1;
    FOR (i, 0, n+1) {
        ans = max(ans, cnt[i]);
    }
    cout << ans << endl;

    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//  cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

