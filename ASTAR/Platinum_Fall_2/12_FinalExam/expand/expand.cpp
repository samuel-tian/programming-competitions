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

const int N = 25005;

int n;
struct rect {
    int a, b, c, d;
    int id;
    rect() = default;
    rect(int x, int y, int z, int w, int i) {
        a = x, b = y, c = z, d = w;
        id = i;
    }
} rects[N];
bool bad[N];
vector<ppi> events[2*N];
ordered_set<int> st;
vi comp;
unordered_map<int, int> inv;

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n;
    FOR (i, 0, n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        rects[i] = rect(a, b, c, d, i);
    }
    FOR (t, 0, 2) {
        comp.clear();
        comp.resize(2*n);
        FOR (i, 0, n) {
            comp.pb(rects[i].a);
            comp.pb(rects[i].c);
        }
        sort(comp.begin(), comp.end());
        FORd (i, comp.size()-1, 1) {
            if (comp[i] == comp[i-1]) {
                comp.erase(comp.begin() + i);
            }
        }
        // PRSP(comp, comp.size());
        FOR (i, 0, comp.size()) inv[comp[i]] = i;
        FOR (i, 0, 2*n) events[i].clear();
        FOR (i, 0, n) {
            events[inv[rects[i].a]].pb(mppi(rects[i].b, 0, rects[i].id));
            events[inv[rects[i].a]].pb(mppi(rects[i].d, 1, rects[i].id));
            events[inv[rects[i].c]].pb(mppi(rects[i].b, 0, rects[i].id));
            events[inv[rects[i].c]].pb(mppi(rects[i].d, 1, rects[i].id));
        }
        FOR (i, 0, comp.size()) {
            sort(events[i].begin(), events[i].end());
        }
        int first = -1;
        FOR (i, 0, comp.size()) {
            // cout << "coordinate " << comp[i] << endl;
            FOR (j, 0, events[i].size()) {
                ppi& x = events[i][j];
                if (x.f.s == 0) { // add
                    // cout << "add " << x.s << endl;
                    st.insert(x.s);
                    if (st.size() > 1) {
                        assert(first != -1);
                        bad[first] = true;
                        bad[x.s] = true;
                    }
                    else {
                        first = x.s;
                    }
                }
                else {
                    // cout << "remove " << x.s << endl;
                    auto iter = st.find(x.s);
                    assert(iter != st.end());
                    st.erase(iter);
                    if (st.empty()) first = -1;
                }
            }
        }
        FOR (i, 0, n) {
            rects[i] = rect(rects[i].b, rects[i].a, rects[i].d, rects[i].c, rects[i].id);
        }
    }
    int cnt = n;
    // PRSP(bad, n);
    FOR (i, 0, n) {
        if (bad[i]) cnt--;
    }
    cout << cnt << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

