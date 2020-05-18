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

ll ccw(pi a, pi b, pi c) {
    ll x = (ll) (b.f - a.f) * (c.s - a.s);
    ll y = (ll) (c.f - a.f) * (b.s - a.s);
    return x - y;
}

int n;
struct Line {
    pi a, b;
    int id;
    Line() = default;
    Line(int a, int b, int c, int d, int id) {
        this->a = mp(a, b);
        this->b = mp(c, d);
        this->id = id;
    }
    friend bool operator < (const Line& l1, const Line& l2);
    friend bool operator == (const Line& l1, const Line& l2);
};
bool operator < (const Line& l1, const Line& l2) {
    /*ll x = ccw(l1.a, l1.b, l2.a);
    ll y = ccw(l1.a, l1.b, l2.b);
    if (x * y <= 0) return !(l2 < l1);
    return x > 0;*/
    if (l1.b.f < l2.b.f) {
        return (ll)(l1.b.s - l2.a.s) * (ll)(l2.b.f - l2.a.f) <
            (ll)(l2.b.s - l2.a.s) * (ll)(l1.b.f - l2.a.f);
    }
    else {
        return (ll)(l2.b.s - l1.a.s) * (ll)(l1.b.f - l1.a.f) >
            (ll)(l1.b.s - l1.a.s) * (ll)(l2.b.f - l1.a.f);
    }
}
bool operator == (const Line& l1, const Line& l2) {
    return l1.id == l2.id;
}
Line hills[N];

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n;
    vector<ppi> go; go.resize(2*n);
    FOR (i, 0, n) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        hills[i] = Line(a, b, c, d, i);
        go[2*i] = mppi(a, b, i);
        go[2*i+1] = mppi(c, d, i);
    }
    FOR (i, 0, n) {
        int a = hills[i].a.f, b = hills[i].a.s, c = hills[i].b.f, d = hills[i].b.s;
        // printf("\\left(%d+\\left(%d-%d\\right)\\cdot t, %d+\\left(%d-%d\\right)\\cdot t\\right)\n", a, c, a, b, d, b);
    }
    sort(go.begin(), go.end());
    int cur_hill = 0;
    int ans = 1;
    ordered_set<Line> s;
    FOR (i, 0, go.size()) {
        if (go[i].f == hills[go[i].s].a) { // adding a line
            // cout << "add " << hills[go[i].s].id << endl;
            s.insert(hills[go[i].s]);
        }
        else { // removing a line
            // cout << "erase " << hills[go[i].s].id << endl;
            auto iter = s.find(hills[go[i].s]);
            assert(iter != s.end());
            s.erase(iter);
            if (go[i].s == cur_hill) {
                if (s.empty()) break;
                int pos = s.order_of_key(hills[go[i].s]);
                if (pos == 0) break;
                cur_hill = s.find_by_order(pos-1)->id;
                ans++;
            }
        }
        /*TRAV (x, s) cerr << x.id << " ";
        cerr << endl;*/
    }
    cout << ans << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

