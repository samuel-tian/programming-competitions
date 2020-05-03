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

const int MAXN = 16;
bool adj[MAXN][MAXN];
vector<ll> dp[1<<MAXN][MAXN];

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
	int N;
	cin >> N;
	FOR (i, 0, N) {
		string s; cin >> s;
		FOR (j, 0, N) {
			adj[i][j] = (s[j] == '1');
		}
	}
	FOR (i, 0, 1<<N) {
		FOR (j, 0, N) {
			dp[i][j].resize(1<<max(0, __builtin_popcount(i)-1));
		}
	}
	dp[0][0][0] = 1;
	FOR (i, 0, N) {
		dp[1<<i][i][0] = 1;
	}
	FOR (i, 0, (1<<N)) {
		FOR (j, 0, N) {
			if ((i & (1<<j)) == 0) continue;
			int mask = (i ^ (1<<j));
			FOR (k, 0, N) {
				if ((mask & (1<<k)) == 0) continue;
				FOR (l, 0, dp[mask][k].size()) {
					if (adj[j][k]) {
						dp[i][j][(l<<1)+1] += dp[mask][k][l];
					}
					else {
						dp[i][j][l<<1] += dp[mask][k][l];
					}
				}
			}
		}
	}
	int final_mask = (1<<N) - 1;
	FOR (i, 0, 1<<(N-1)) {
		ll ret = 0;
		FOR (j, 0, N) {
			ret += dp[final_mask][j][i];
		}
		cout << ret << " ";
	} cout << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
