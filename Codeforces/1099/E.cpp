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

void rotate(vector<vector<char> >& grid) {
	vector<vector<char> > temp;
	int n = grid.size(), m = grid[0].size();
	temp.resize(m); FOR (i, 0, m) temp[i].resize(n);
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			temp[j][i] = grid[i][j];
		}
	}
	grid = temp;
}

int main() {
	setIO();
	int n, m;
	cin >> n >> m;
	vector<vector<char> > grid;
	grid.resize(n); FOR (i, 0, n) grid[i].resize(m);
	FOR (i, 0, n) {
		string s;
		cin >> s;
		FOR (j, 0, m) {
			grid[i][j] = s[j];
		}
	}
	vector<char> perm = {'A', 'C', 'G', 'T'};
	int ret = INF;
	vector<vector<char> > ans;
	bool rot = false;
	FOR (iteration, 0, 2) {
		do {
//			PRSP(perm, perm.size());
			vector<vector<char> > temp;
			temp.resize(grid.size()); FOR (i, 0, temp.size()) temp[i].resize(grid[i].size());
			int diff = 0;
			FOR (i, 0, grid.size()) {
				int rdif = INF;
				vector<char> finalrow(grid[i].size());
				FOR (k, 0, 2) {
					int tdif = 0;
					FOR (j, 0, grid[i].size()) {
						temp[i][j] = perm[2 * (i % 2) + j % 2];
						tdif += (temp[i][j] != grid[i][j]);
					}
					if (tdif < rdif) {
						rdif = tdif;
						swap(finalrow, temp[i]);
					}
					swap(perm[2 * (i % 2)], perm[2 * (i % 2) + 1]);
				}
				temp[i] = finalrow;
				diff += rdif;
			}
			/*FOR (i, 0, grid.size()) {
				FOR (j, 0, grid[i].size()) {
					diff += (grid[i][j] != temp[i][j]);
				}
			}*/
			if (diff < ret) {
				ret = diff; ans = temp;
				rot = (bool) iteration;
			}
		} while (next_permutation(perm.begin(), perm.end()));
		rotate(grid);
	}
	if (rot) rotate(ans);
	FOR (i, 0, ans.size()) {
		FOR (j, 0, ans[i].size()) {
			cout << ans[i][j];
		}
		cout << endl;
	}
	/*rotate(ans);
	FOR (i, 0, ans.size()) {
		FOR (j, 0, ans[i].size()) {
			cout << ans[i][j];
		}
		cout << endl;
	}*/
}
