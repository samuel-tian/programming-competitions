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

const int MAXN = 200005;
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

int t, n, k;
string s;
int par[MAXN];
int r[MAXN];

int find(int i) {
	if (par[i] != i) {
		par[i] = find(par[i]);
	}
	return par[i];
}

void unionRank(int aa, int bb) { // append b to a
	if (find(aa) == find(bb)) return;
	int a = find(aa);
	int b = find(bb);
	if (r[b] > r[a]) {
		unionRank(bb, aa);
		return;
	}
	par[b] = a;
	r[a] = max(r[a], r[b] + 1);
}

int main() {
	setIO("input");
	cin >> t;
	FOR (a, 0, t) {
		cin >> n >> k;
		cin >> s;
		FOR (i, 0, n) {
			par[i] = i;
		}
		fill(r, r + n, 0);
		FOR (i, 0, n) {
			if (i - k < 0) continue;
			unionRank(i, i - k);
		}
		FOR (i, 0, n/2) {
			unionRank(i, n - 1 - i);
		}
		int equiv[MAXN][26];
		FOR (i, 0, n) {
			FOR (j, 0, 26) {
				equiv[i][j] = 0;
			}
		}
		FOR (i, 0, n) {
			equiv[find(i)][s[i]-'a']++;
		}
		int ret = 0;
		FOR (i, 0, n) {
			int m = 0;
			int tot = 0;
			FOR (j, 0, 26) {
				m = max(m, equiv[i][j]);
				tot += equiv[i][j];
			}
			ret += (tot - m);
		}
		cout << ret << endl;
	}
}