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

const int N = 1e6 + 5;

int n, q;
int a[N];
int k[N];

bool go(int mid) {
    int lcnt = 0, rcnt = 0, cnt = 0;
    FOR (i, 0, n) {
        if (a[i] > mid) rcnt++;
        else if (a[i] < mid) lcnt++;
        else cnt++;
    }
    FOR (i, 0, q) {
        if (k[i] < 0) {
            k[i] *= -1;
            if (k[i] > lcnt + cnt) rcnt--;
            else if (k[i] <= lcnt) lcnt--;
            else cnt--;
            k[i] *= -1;
        }
        else {
            if (k[i] > mid) rcnt++;
            else if (k[i] < mid) lcnt++;
            else cnt++;
        }
    }
    // cout << "mid: " << mid << endl;
    // cout << "cnt: " << lcnt << " " << cnt << " " << rcnt << endl;
    if (lcnt == 0 && cnt == 0) return false;
    else return true;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> q;
    FOR (i, 0, n) cin >> a[i];
    FOR (i, 0, q) cin >> k[i];
    int sz = n;
    FOR (i, 0, q) sz += ((k[i] < 0) ? -1 : 1);
    if (sz == 0) {
        cout << 0 << endl;
    }
    else {

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            bool g = go(mid);
            if (g) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        cout << lo << endl;
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

