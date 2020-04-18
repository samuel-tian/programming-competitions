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
typedef vector<pair<int, int> > vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)
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

ppi search(vector<ll> & v, double val) {
	int lo = 0;
	int hi = v.size() - 1;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (v[mid] < val) lo = mid + 1;
		else hi = mid;
	}
	int a = hi - 1, b = hi + 1;
	if (a < 0) a = 0;
	if (b >= v.size()) b = v.size() - 1;
	vector<pair<double, int> > temp = {mp(abs(v[hi]-val), hi), mp(abs(v[a]-val), a), mp(abs(v[b]-val), b)};
	sort(temp.begin(), temp.end());
	return mppi(temp[0].s, temp[1].s, temp[2].s);
}

int main() {
	setIO();
	int t;
	cin >> t;
	while (t--) {
		int nr, ng, nb;
		cin >> nr >> ng >> nb;
		vector<ll> red(nr), green(ng), blue(nb);
		FOR (i, 0, nr) cin >> red[i];
		sort(red.begin(), red.end());
		FOR (i, 0, ng) cin >> green[i];
		sort(green.begin(), green.end());
		FOR (i, 0, nb) cin >> blue[i];
		sort(blue.begin(), blue.end());
		ll ret = LLONG_MAX;
		FOR (i, 0, nr) {
			ll ans = 0;
			ppi gp = search(green, red[i]);
			vi gv = {gp.f.f, gp.f.s, gp.s};
			ppi bp = search(blue, red[i]);
			vi bv = {bp.f.f, bp.f.s, bp.s};
			FOR (x, 0, 3) {
				FOR (y, 0, 3) {
					int g = gv[x]; int b = bv[y];
					if (abs(green[g] - red[i]) >= abs(blue[b] - red[i])) {
						b = search(blue, (red[i] + green[g]) / 2.0).f.f;
					}
					else {
						g = search(green, (red[i] + blue[b]) / 2.0).f.f;
					}
					ans = (ll)pow(red[i] - green[g], 2) + (ll)pow(red[i] - blue[b], 2) + (ll)pow(blue[b] - green[g], 2);
					ret = min(ret, ans);
				}
			}
		}
		cout << ret << endl;

	}
}
