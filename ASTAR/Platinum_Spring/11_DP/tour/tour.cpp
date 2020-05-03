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
	int N, V;
	cin >> N >> V;
	vector<vi> adj;
	adj.resize(N);
	unordered_map<string, int> ump;
	FOR (i, 0, N) {
		string s;
		cin >> s;
		ump[s] = i;
	}
	FOR (i, 0, V) {
		string s, t;
		cin >> s >> t;
		adj[ump[s]].pb(ump[t]);
		adj[ump[t]].pb(ump[s]);
	}
	int dp[N][N];
	FOR (i, 0, N) {
		FOR (j, 0, N) {
			dp[i][j] = NINF;
		}
	}
	dp[0][0] = 1;
	FOR (i, 0, N) {
		FOR (j, 0, N) {
			if (i==j && i!=N-1) continue;
			if (i > j) dp[i][j] = dp[j][i];
			else {
				TRAV (k, adj[j]) {
					if (dp[i][k] == NINF) continue;
					dp[i][j] = max(dp[i][j], dp[i][k] + 1);
				}
			}
		}
	}
	/*FOR (i, 0, N) {
		FOR (j, 0, N) {
			if (dp[i][j] == NINF) cout << -1 << " ";
			else cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cout << ((dp[N-1][N-1]==NINF) ? 1 : dp[N-1][N-1]-1) << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
