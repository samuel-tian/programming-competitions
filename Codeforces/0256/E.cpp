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
const int MOD = 777777777;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

const int N = 80000;

int n, m;
bool lucky[3][3];

template<class T>
struct segtree {
    int n;
    vector<T> t;
    segtree() = default;
    segtree(int n) {
        this->n = n;
        int sz = 2*n;
        t.resize(sz);
    }
    T comb(T l, T r) {
        T ret = {};
        if (l[0][0] == -1) return r;
        if (r[0][0] == -1) return l;
        FOR (i, 0, 3) {
            FOR (j, 0, 3) {
                FOR (x, 0, 3) {
                    FOR (y, 0, 3) {
                        if (lucky[x][y]) {
                            ret[i][j] = (ret[i][j] + (l[i][x] * r[y][j]) % MOD) % MOD;
                        }
                    }
                }
            }
        }
        return ret;
    }
    void set(int i, T& v) {
        t[i + n] = v;
    }
    void build() {
        FORd (i, n-1, 1) {
            t[i] = comb(t[i<<1], t[i<<1|1]);
        }
    }
    void update(int p, T& v) {
        p += n;
        t[p] = v;
        while (p != 1) {
            p >>= 1;
            t[p] = comb(t[p<<1], t[p<<1|1]);
        }
    }
    T query(int l, int r) {
        T resl = {}, resr = {};
        resl[0][0] = resr[0][0] = -1;
        l += n, r += n+1;
        while (l < r) {
            if (l & 1) resl = comb(resl, t[l++]);
            if (r & 1) resr = comb(t[--r], resr);
            l >>= 1, r >>= 1;
        }
        return comb(resl, resr);
    }
    void get(int l, int r) {
        ll ans = 0;
        if (t[1][0][0] != -1) {
            FOR (i, 0, 3) {
                FOR (j, 0, 3) {
                    ans = (ans + t[1][i][j]) % MOD;
                }
            }
        }
        cout << ans << endl;
        /*FOR (i, 1, 4) {
            FOR (j, 1, 4) {
                cout << q[i][j] << " ";
            }
            cout << endl;
        }*/
    }
};

template<class T, int S>
using mat = array<array<T, S>, S>;

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("");
    cin >> n >> m;
    FOR (i, 0, 3) {
        FOR (j, 0, 3) {
            cin >> lucky[i][j];
        }
    }
    segtree<mat<ll, 3> > seg(1<<17);
    mat<ll, 3> def[4];
    FOR (i, 0, 4) {
        FOR (j, 0, 3) {
            FOR (k, 0, 3) {
                def[i][j][k] = 0;
            }
        }
        FOR (j, 0, 3) {
            if (i == 0 || i-1 == j) {
                def[i][j][j] = 1;
            }
        }
    }
    mat<ll, 3> tmp = {};
    tmp[0][0] = -1;
    FOR (i, 0, 1<<17) {
        seg.set(i, tmp);
    }
    FOR (i, 0, n) {
        seg.set(i, def[0]);
    }
    seg.build();
    FOR (i, 0, m) {
        int v, t;
        cin >> v >> t;
        --v;
        seg.update(v, def[t]);
        seg.get(0, n-1);
        /*string print[] = {"", "", ""};
        FOR (j, 0, n) {
            auto q = seg.query(j, j);
            FOR (x, 1, 4) {
                FOR (y, 1, 4) {
                    print[x-1] += (to_string(q[x][y]) + " ");
                }
            }
            FOR (x, 1, 4)
                print[x-1] += " ";
        }
        FOR (j, 0, 3)
            cout << print[j] << endl;*/
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	// cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

