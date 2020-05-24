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

const int N = 10005;

int n;
pi coor[N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n;
    FOR (i, 0, n) {
        cin >> coor[i].f >> coor[i].s;
    }
    vi x, y;
    FOR (i, 0, n) {
        x.pb(coor[i].f);
        y.pb(coor[i].s);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    pi xb, yb;
    if (n % 2) {
        xb = mp(x[n/2], x[n/2]);
        yb = mp(y[n/2], y[n/2]);
    }
    else {
        xb = mp(x[n/2 - 1], x[n/2]);
        yb = mp(y[n/2 - 1], y[n/2]);
    }
    int tot = (xb.s - xb.f + 1) * (yb.s - yb.f + 1);
    FOR (i, 0, n) {
        if (coor[i].f >= xb.f && coor[i].f <= xb.s &&
                coor[i].s >= yb.f && coor[i].s <= yb.s) {
            tot--;
        }
    }
    if (tot == 0) {
        assert(xb.f == xb.s && yb.f == yb.s);
        int ans = INF;
        vi temp;
        FOR (i, 0, 4) {
            int x = xb.f + dx[i], y = yb.f + dy[i];
            int t = 0;
            FOR (j, 0, n) {
                t += abs(coor[j].f - x) + abs(coor[j].s - y);
            }
            temp.pb(t);
            ans = min(ans, t);
        }
        FOR (i, 0, temp.size()) {
            if (temp[i] == ans) tot++;
        }
        cout << ans << " " << tot << endl;
    }
    else {
        int ans = 0;
        FOR (i, 0, n) {
            ans += abs(coor[i].f - xb.f) + abs(coor[i].s - yb.f);
        }
        cout << ans << " " << tot;
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

