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
#define REP(i, x) for (auto (i) : (x))
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

struct DSU {
	vi par;
	vi r;
	DSU(int n) {
		par.resize(n);
		r.resize(n);
		FOR (i, 0, n) { par[i] = i; r[i] = 0; }
	}
	int find(int i) {
		if (par[i] != i) par[i] = find(par[i]);
		return par[i];
	}
	bool same_set(int a, int b) {
		return find(a) == find(b);
	}
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (r[a] < r[b]) swap(a, b);
		par[b] = a;
		r[a] = max(r[a], r[b] + 1);
	}
};

int main() {
	setIO();
	int t;
	cin >> t;
	unordered_map<char, int> ump = {{'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
	while (t--) {
		int n, m;
		cin >> n >> m;
		auto f = [m](int i, int j) { return i * m + j; };
		DSU sets(n*m);
		vector<vi> par;
		vector<bool> bw;
		bw.resize(n*m);
		FOR (i, 0, n) {
			string s;
			cin >> s;
			FOR (j, 0, m) {
				bw[f(i, j)] = s[j] == '0';
			}
		}
		int depth = 1;
		for (int i = 1; i < n*m; i *= 2) depth++;
		par.resize(depth);
		FOR (i, 0, depth) {
			par[i].resize(n*m);
		}
		FOR (i, 0, n) {
			string s;
			cin >> s;
			FOR (j, 0, m) {
				par[0][f(i, j)] = f(i + dx[ump[s[j]]], j + dy[ump[s[j]]]);
			}
		}
		FOR (i, 0, depth-1) {
			FOR (j, 0, n*m) {
				par[i+1][j] = par[i][par[i][j]];
			}
		}
		vector<vi> equiv;
		equiv.resize(n*m);
		FOR (i, 0, depth) {
			FOR (j, 0, n*m) {
				equiv[j].clear();
			}
			FOR (j, 0, n*m) {
				equiv[par[i][j]].pb(j);
			}
			REP(v, equiv) {
				if (v.size() <= 1) continue;
				FOR (i, 0, v.size() - 1) {
					sets.join(v[i], v[i+1]);
				}
			}
		}
		/*FOR (i, 0, depth) {
			FOR (j, 0, n) {
				FOR (k, 0, m) {
					cout << par[i][f(j, k)] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}*/
		vector<bool> used_sets, black_sets;
		used_sets.resize(n*m); black_sets.resize(n*m);
		FOR (i, 0, n*m) {
			int s = sets.find(i);
			used_sets[s] = true;
			if (bw[i]) black_sets[s] = true;
		}
		pi ans = mp(0, 0);
		FOR (i, 0, n*m) {
			ans.f += used_sets[i];
			ans.s += black_sets[i];
		}
		cout << ans.f << " " << ans.s << endl;
	}
}
