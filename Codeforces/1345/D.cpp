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

const int N = 1005;

int n, m;
char grid[N][N];
bool vis[N][N];

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
	cin >> n >> m;
	FOR (i, 0, n) {
		string s; cin >> s;
		FOR (j, 0, m) {
			grid[i][j] = s[j];
		}
	}
	queue<pair<pi, pi> > q; // coor, dist
	// 1, -1, 1, -1
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};
	int ret = 0;
	bool good = true;

	bool row[n]; fill(row, row + n, false);
	bool col[m]; fill(col, col + m, false);
	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (grid[i][j] == '#') {
				row[i] = true;
				col[j] = true;
			}
			else {
				bool go = true;
				FOR (k, 0, 4) {
					int ni = i + dx[k], nj = j + dy[k];
					if (ni <0 || ni >= n || nj < 0 || nj >= m) continue;
					if (grid[ni][nj] == '#') go = false;
				}
				if (go) {
					row[i] = true;
					col[j] = true;
				}
			}
		}
	}
	FOR (i, 0, n) good = good && row[i];
	FOR (j, 0, m) good = good && col[j];

    bool empty_row = false, empty_col = false;
    FOR (i, 0, n) {
        bool empty = true;
        FOR (j, 0, m) {
            if (grid[i][j] == '#') {
                empty = false; break;
            }
        }
        if (empty) empty_row = true;
    }
    FOR (j, 0, m) {
        bool empty = true;
        FOR (i, 0, n) {
            if (grid[i][j] == '#') {
                empty = false; break;
            }
        }
        if (empty) empty_col = true;
    }
    good = good && !(empty_row ^ empty_col);

	bool nice = false;
	bool good2 = true;
	FOR (i, 0, n) {
		nice = false;
		FOR (j, 0, m) {
			if (j != 0) {
				if (grid[i][j-1] != '#' && grid[i][j] == '#' && nice) {
					good2 = false;
				}
			}
			nice = nice || ((grid[i][j] == '#'));
		}
	}
	FOR (i, 0, m) {
		nice = false;
		FOR (j, 0, n) {
			if (j != 0) {
				if (grid[j-1][i] != '#' && grid[j][i] == '#' && nice) {
					good2 = false;
				}
			}
			nice = nice || ((grid[j][i] == '#'));
		}
	}
	good = good && good2;

	FOR (i, 0, n) {
		FOR (j, 0, m) {
			if (vis[i][j] || grid[i][j] == '.') continue;
			vis[i][j] = true;
			ret++;
			q.push(mp(mp(i, j), mp(0, 0)));
			while (!q.empty()) {
				pair<pi, pi> cur = q.front();
//				cout << "(" << cur.f.f << ", " << cur.f.s << ")" << endl;
				q.pop();
				FOR (k, 0, 4) {
					pi next = mp(cur.f.f + dx[k], cur.f.s + dy[k]);
					if (next.f < 0 || next.f >= n || next.s < 0 || next.s >= m) continue;
					pi nd = cur.s;
					if (vis[next.f][next.s]) continue;
					if (grid[next.f][next.s] == '.') continue;
					vis[next.f][next.s] = true;
					if (dx[k] != 0) {
						if (dx[k] * nd.f < 0) {
							good = false;
//							cout << "bad" << " " << next.f << " " << next.s << endl;
						}
						nd.f += dx[k];
					}
					else if (dy[k] != 0) {
						if (dy[k] * nd.s < 0) {
							good = false;
//							cout << "bad" << " " << next.f << " " << next.s << endl;
						}
						nd.s += dy[k];
					}
					if (!good) break;
					q.push(mp(next, nd));
				}
			}
			if (!good) break;
		}
		if (!good) break;
	}
	cout << ((good) ? ret : -1) << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

