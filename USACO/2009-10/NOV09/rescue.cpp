#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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
const int M = 10005;

int n, m;
pi s;
pi e[M];

int solve(pi a, pi b) {
    if (a.f > b.f) return solve(b, a);
    else if (a.f == b.f) return abs(a.s - b.s);
    if (a.s % 2 == 0) return 1 + min( solve(mp(a.f, a.s-1), b), solve(mp(a.f, a.s+1), b) );
    int l = a.s + 1, r = a.s + (b.f - a.f) * 2 - 1, d = (b.f - a.f) * 2 - 1;
    if (b.s >= r) return d + solve(mp(b.f, r), b);
    else if (b.s <= l) return d + solve(mp(b.f, l), b);
    else {
        if (b.s % 2) return d + 1;
        else return d;
    }
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n >> m;
    cin >> s.f >> s.s;
    FOR (i, 0, m) cin >> e[i].f >> e[i].s;
    int ret = INF;
    pi coor = mp(INF, INF);
    FOR (i, 0, m) {
        int d = 1 + solve(s, e[i]);
        if (d < ret) {
            ret = d; coor = e[i];
        }
        else if (d == ret) {
            if (e[i] < coor) coor = e[i];
        }
    }
    cout << coor.f << " " << coor.s << endl;
    cout << ret << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
