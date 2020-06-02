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

const int N = 5005;

int n, m;
vi adj[N];
int n1, n2, n3;
bool vis[N];
int color[N];
pair<vi, vi> comps[N];
pi sizes[N];
int dp[N][N];
int ans[N];

pi dfs(int a, int cnt) {
    vis[a] = true;
    pi ret = mp(0, 0);
    if (color[a]) {
        comps[cnt].s.pb(a);
        ret.s++;
    }
    else {
        comps[cnt].f.pb(a);
        ret.f++;
    } 
    TRAV (b, adj[a]) {
        if (vis[b]) {
            if (color[a] == color[b]) return mp(-1, -1);
        }
        else {
            vis[b] = true;
            color[b] = 1 - color[a];
            pi x = dfs(b, cnt);
            if (x.f == -1) return mp(-1, -1);
            else {
                ret.f += x.f;
                ret.s += x.s;
            }
        }
    }
    return ret;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> m;
    cin >> n1 >> n2 >> n3;
    FOR (i, 0, m) {
        int a, b; cin >> a >> b;
        --a, --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool good = true;
    FOR (i, 0, n+1) {
        FOR (j, 0, n+1) {
            dp[i][j] = -1;
        }
    }
    int cnt = 0;
    dp[0][0] = 0;
    FOR (i, 0, n) {
        if (!vis[i]) {
            color[i] = 0;
            pi q = dfs(i, cnt);
            sizes[cnt] = q;
            if (q.f == -1) good = false;
            FOR (j, 0, n) {
                if (dp[cnt][j] == -1) continue;
                if (j + q.f <= n) dp[cnt+1][j + q.f] = 0;
                if (j + q.s <= n) dp[cnt+1][j + q.s] = 1;
            }
            cnt++;
        }
    }
    /*FOR (i, 0, cnt) {
        TRAV (x, comps[i].f) {
            cout << x << " ";
        }
        cout << "| ";
        TRAV (x, comps[i].s) {
            cout << x << " ";
        }
        cout << endl;
    }*/
    if (dp[cnt][n2] == -1) good = false;
    else {
        int cur = n2;
        FORd (i, cnt, 1) {

            if (dp[i][cur] == 0) {
                cur -= sizes[i-1].f;
            }
            else {
                cur -= sizes[i-1].s;
                swap(comps[i-1].f, comps[i-1].s);
            }
            TRAV (x, comps[i-1].f) { ans[x] = 2; }
            TRAV (x, comps[i-1].s) { ans[x] = 1; }
        }
        FOR (i, 0, n) {
            if (ans[i] == 2) continue;
            if (n3) {
                ans[i] = 3;
                n3--;
            }
        }
    }
    if (!good) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        FOR (i, 0, n) cout << ans[i];
        cout << endl;
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

