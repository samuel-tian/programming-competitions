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
const int C = 2505;

struct rect {
    pi f, s;
    int color, t;
    rect() = default;
    rect(int a, int b, int c, int d, int e, int i) {
        f = mp(a, b), s = mp(c, d);
        color = e;
        t = i;
    }
} r[N];
int a, b, n;
int cnt[C];

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> a >> b >> n;
    vector<ppi> events;
    events.resize(2*n+2); // y-coordinate, add/remove, index
    FOR (i, 0, n) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        r[i] = rect(a, b, c, d, e, i);
    }
    r[n] = rect(0, 0, a, b, 1, -1);
    /*FOR (i, 0, n+1) {
        cout << r[i].f.f << " " << r[i].f.s << " " << r[i].s.f << " " << r[i].s.s << " " << r[i].color << " " << r[i].t << endl;
    }*/
    FOR (i, 0, n+1){
        events[2*i] = mppi(r[i].f.s, 0, i);
        events[2*i+1] = mppi(r[i].s.s, 1, i);
    }
    sort(events.begin(), events.end());
    ordered_set<ppi> sweep; // x-coordinate, add/remove, index
    FOR (i, 0, events.size()) {
        int ind = events[i].s;
        if (events[i].f.s) { // remove
            // cout << "remove rectangle " << ind << endl;
            auto iter = sweep.find(mppi(r[ind].f.f, 0, ind));
            sweep.erase(iter);
            assert(iter != sweep.end());
            iter = sweep.find(mppi(r[ind].s.f, 1, ind));
            sweep.erase(iter);
            assert(iter != sweep.end());
        }
        else {
            // cout << "add rectangle " << ind << endl;
            sweep.insert(mppi(r[ind].f.f, 0, ind));
            sweep.insert(mppi(r[ind].s.f, 1, ind));
        }
        /*TRAV (x, sweep) {
            cout << "(" << x.f.f << ", " << x.f.s << ", " << x.s << ") ";
        } cout << endl;*/
        if (i == events.size()-1) continue;
        int w = events[i+1].f.f - events[i].f.f;
        ordered_set<pi> sweep2; // time, color
        FOR (j, 0, sweep.size()) {
            auto& x = *sweep.find_by_order(j);
            if (x.f.s) { // remove
                auto iter = sweep2.find(mp(r[x.s].t, r[x.s].color));
                assert(iter != sweep2.end());
                sweep2.erase(iter);
            }
            else {
                sweep2.insert(mp(r[x.s].t, r[x.s].color));
            }
            if (j != sweep.size()-1 && !sweep2.empty()) {
                int h = sweep.find_by_order(j+1)->f.f - x.f.f;
                // cout << "top color " << sweep2.find_by_order(sweep2.size()-1)->s << endl;
                cnt[sweep2.find_by_order(sweep2.size()-1)->s] += w * h;
            }
        }
    }
    FOR (i, 0, C) {
        if (cnt[i]) {
            cout << i << " " << cnt[i] << endl;
        }
    }

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

