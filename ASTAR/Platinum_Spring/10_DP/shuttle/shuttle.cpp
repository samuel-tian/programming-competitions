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

#define FOR(i, a, b) for (int (i) = (a); i < (b); ++i)
#define FORd(i, a, b) for (int (i) = (a); i >= (b); --i)
#define TRAV(i, x) for (int (i) : (x))
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

const int MAXN = 20005;

int k, n, c;
vpi groups[MAXN];

int main() {
	setIO();
	cin >> k >> n >> c;
	FOR (i, 0, k) {
		int s, e, m;
		cin >> s >> e >> m;
		--s; --e;
		groups[s].pb(mp(e, m));
	}
	FOR (i, 0, n) {
		sort(groups[i].begin(), groups[i].end());
	}
	int shuttle[c];
	fill(shuttle, shuttle + c, INF);
	int ret = 0;
	FOR (i, 0, n) {
		FOR (j, 0, c) {
			if (shuttle[j] == i) {
				ret++;
				shuttle[j] = INF;
			}
		}
		sort(shuttle, shuttle + c);
		int new_shuttle[c];
		int shuttle_iter = 0, stop_iter = 0;
		FOR (j, 0, c) {
			if (stop_iter >= groups[i].size() || shuttle[shuttle_iter] < groups[i][stop_iter].f) {
				new_shuttle[j] = shuttle[shuttle_iter++];
			}
			else {
				new_shuttle[j] = groups[i][stop_iter].f;
				groups[i][stop_iter].s--;
				if (groups[i][stop_iter].s <= 0) stop_iter++;
			}
		}
		FOR (j, 0, c) {
			shuttle[j] = new_shuttle[j];
		}
	}
	cout << ret << endl;
}
