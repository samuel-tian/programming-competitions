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

const int N = 100005;
const int K = 105;

int n, k;
pi itv[N];
pi events[2*N];
int dp[N][K][2];
bool used[N], bad[N];
int lefts[N];

bool comp(pi a, pi b) {
    if (a.f == b.f) return a.s > b.s;
    return a.f < b.f;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("lifeguards");
    cin >> n >> k;
    FOR (i, 0, n) {
        cin >> itv[i].f >> itv[i].s;
    }
    sort(itv, itv + n, comp);
    FOR (i, 0, n) {
        events[2*i] = mp(itv[i].f, i);
        events[2*i+1] = mp(itv[i].s, i);
    }
    sort(events, events + 2*n);
    deque<int> st;
    int sz = 0;
    FOR (i, 0, 2*n) {
        while (!st.empty() && used[st.front()]) st.pop_front();
        if (events[i].f == itv[events[i].s].f) {
            st.pb(events[i].s);
            sz++;
        }
        else {
            used[events[i].s] = true;
            if (events[i].s != st.front() && sz != 1) {
                bad[events[i].s] = true;
                k--;
            }
            sz--;
        }
    }
    int iter = 0;
    FOR (i, 0, n) {
        if (!bad[i]) {
            itv[iter++] = itv[i];
        }
    }
    n = iter;
    k = max(k, 0);
    /*cout << endl;
    FOR (i, 0, n) {
        cout << itv[i].f << " " << itv[i].s << endl;
    }
    cout << endl;*/
    FOR (i, 0, n+1) {
        FOR (j, 0, k+1) {
            FOR (l, 0, 2) {
                dp[i][j][l] = -1;
            }
        }
    }
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    st.clear();
    FOR (i, 0, n) {
        while (!st.empty() && itv[st.front()].s <= itv[i].f) st.pop_front();
        int l = (st.empty()) ? i : st.front();
        FOR (j, 0, k+1) {
            if (j != 0) {
                dp[i+1][j][0] = max(dp[i][j-1][0], dp[i][j-1][1]);
            }
            if (i != l) { // remove all but the leftmost
                if (j - (i-l-1) >= 0) {
                    int ad = itv[i].s - itv[l].s;
                    if (dp[l][j - (i-l-1)][0] != -1) {
                        dp[i+1][j][1] = max(dp[i+1][j][1], dp[l+1][j - (i-l-1)][0] + ad);
                    }
                    if (dp[l][j - (i-l-1)][1] != -1) {
                        dp[i+1][j][1] = max(dp[i+1][j][1], dp[l+1][j - (i-l-1)][1] + ad);
                    }
                }
            }
            if (j - (i-l) >= 0) {
                if (dp[l][j - (i-l)][0] != -1) {
                    dp[i+1][j][1] = max(dp[i+1][j][1], dp[l][j - (i-l)][0] + itv[i].s - itv[i].f);
                }
                if (dp[l][j - (i-l)][1] != -1) {
                    dp[i+1][j][1] = max(dp[i+1][j][1], dp[l][j - (i-l)][1] + itv[i].s - itv[i].f);
                }
            }
        }
        st.pb(i);
    }
    /*FOR (l, 0, 2) {

        FOR (i, 0, n+1) {
            FOR (j, 0, k+1) {
                cout << dp[i][j][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }*/
    int ans = max(dp[n][k][0], dp[n][k][1]);
    cout << ans << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

