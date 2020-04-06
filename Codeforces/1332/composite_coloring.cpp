#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

const int MAXN = 1005;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (name == "input") {
		freopen("input.txt","r",stdin);
	}
	else if (name == "stdio") {

	}
	else {
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
}

int t, n;
int vals[MAXN];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
vi equiv[11];

int main() {
	setIO("stdio");
	cin >> t;
	FOR (j, 0, t) {
		cin >> n;
		FOR (i, 0, 11) {
			equiv[i].clear();
		}
		FOR (i, 0, n) {
			cin >> vals[i];
			FOR (k, 0, 11) {
				if (vals[i] % primes[k] == 0) {
					equiv[k].pb(i);
					break;
				}
			}
		}
		/*FOR (i, 0, 11) {
			cout << primes[i] << ": ";
			for (int k : equiv[i]) {
				cout << vals[k] << " ";
			}
			cout << endl;
		}*/
		int m = 0;
		vi c[MAXN];
		int colors[MAXN], count[11];
		fill(colors, colors + n, 0);
		fill(count, count + 11, 0);
		FOR (i, 0, 11) {
			for (int k : equiv[i]) {
				if (colors[k] != 0) continue;
				else {
					c[i].pb(vals[k]);
					colors[k] = i;
					count[i]++;
				}
			}
		}
		/*FOR (i, 0, 11) {
			cout << primes[i] << ": ";
			for (int k : c[i]) {
				cout << k << " ";
			}
			cout << endl;
		}*/
		int remap[11] = {0};
		int iter = 0;
		FOR (i, 0, 11) {
			if (count[i] != 0) {
				remap[i] = ++iter;
				++m;
			}
		}
		cout << m << endl;
		FOR (i, 0, n) {
			if (i == 0) cout << remap[colors[i]];
			else cout << " " << remap[colors[i]];
		}
		cout << endl;
	}

}