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
	int n, k;
	cin >> n >> k;
	int display[] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
	int vals[n];
	FOR (i, 0, n) {
		string s; cin >> s;
		bitset<7> bm;
		FOR (i, 0, 7) {
			bm.set(6-i, s[i]-'0');
		}
		vals[i] = (int) bm.to_ulong();
	}
	int dist[n][10];
	FOR (i, 0, n) {
		FOR (j, 0, 10) {
			if (((display[j] | vals[i]) ^ display[j]) > 0) dist[i][j] = -1;
			else dist[i][j] = __builtin_popcount(display[j] ^ vals[i]);
		}
	}
	/*FOR (i, 0, n) {
		FOR (j, 0, 10) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}*/
	vector<vi> dp;
	dp.assign(2050, vi(2050));
	FOR (i, 0, 2050) {
		FOR (j, 0, 2050) {
			dp[i][j] = 0;
		}
	}
	dp[n][0] = 1;
	FORd (i, n-1, 0) {
		FOR (l, 0, 10) {
			if (dist[i][l] == -1) continue;
			FOR (j, dist[i][l], k+1) {
				dp[i][j] |= dp[i+1][j-dist[i][l]];
			}
		}
	}
	/*FOR (i, 0, n+1) {
		FOR (j, 0, k+1) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	if (dp[0][k]) {
		string ret = "";
		int counter = k;
		FOR (i, 0, n) {
			FORd (l, 9, 0) {
				if (dist[i][l] == -1) continue;
				if (counter - dist[i][l] < 0 || dp[i+1][counter - dist[i][l]] == 0) continue;
				counter = counter - dist[i][l];
				ret += (char)(l + '0');
				break;
			}
//			cout << "counter: " << counter << endl;
		}
		cout << ret << endl;
	}
	else cout << -1 << endl;
	/*FOR (i, 0, 3) {
		FOR (j, 0, 2050) {
			dp[i%3][j] = "";
		}
	}
	dp[0][0] = "";
	FOR (i, 0, n) {
		FOR (j, 0, 2005) {
			dp[(i+2)%3][j] = "";
		}
		FOR (j, 0, 2005) {
			if (dp[i%3][j].empty() && !(i==0 && j==0)) continue;
			FOR (l, 0, 10) {
				if (dist[i][l] == -1) continue;
				dp[(i+1)%3][j + dist[i][l]] = max(dp[(i+1)%3][j + dist[i][l]], dp[i%3][j] + to_string(l));
			}
		}
	}
	if (dp[n%3][k] == "") cout << -1 << endl;
	else {
		string t = (dp[n%3][k]);
		while (t.size() < n) t = "0" + t;
		cout << t << endl;
	}*/
//	cout << dp[n%3][k] << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
