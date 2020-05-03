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

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<set<int> > permutation(n-1);
		vector<set<int> > per(n-1);
		FOR (i, 0, n-1) {
			int k; cin >> k;
			while (k--) { int x; cin >> x; permutation[i].insert(x); }
		}
		vi ans;
		FOR (i, 0, n-1) {
			FOR (j, 0, n-1) {
				per[j].clear();
				TRAV (k, permutation[j]) {
					per[j].insert(k);
				}
			}
			ans.clear();
			bool good = false;
			if (per[i].size() != 2) continue;
			TRAV (j, per[i]) {
				ans.pb(j);
				FOR (k, 0, n-1) {
					if (per[k].empty()) continue;
					auto it = per[k].find(j);
					if (it == per[k].end()) continue;
					per[k].erase(it);
				}
			}
			while (true) {
				good = false;
				FOR (j, 0, n-1) {
					if (per[j].size() != 1) continue;
					good = true;
					int v = *per[j].begin();
					ans.pb(v);
					FOR (k, 0, n-1) {
						if (per[k].empty()) continue;
						auto it = per[k].find(v);
						if (it == per[k].end()) continue;
						per[k].erase(it);
					}
					break;
				}
				if (!good) break;
			}
//			PRSP(ans, ans.size());
			if (ans.size() != n) continue;
			bool cont = false;
			FOR (x, 0, 2) {
				good = false;
				FOR (j, 1, n) {
					set<int> c;
					good = false;
					FORd (k, j, 0) {
						c.insert(ans[k]);
						TRAV (s, permutation) {
							if (s == c) { good = true; break; }
						}
						if (good) break;
					}
					if (!good) break;
				}
				if (!good) swap(ans[0], ans[1]);
				if (!good && x) cont = true;
			}
			if (cont) continue;
			break;
		}
		PRSP(ans, ans.size());
	}

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
