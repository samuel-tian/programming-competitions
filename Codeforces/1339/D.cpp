#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
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
#define PRSP(x, a) for (int rv = 0; rv < a; ++rv) {cout << ((rv==0 ? "" : " ")) << x[rv];} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

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

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;

const int MAXN = (int)1e5 + 5;

int n;
vi adj[MAXN];
pi c[MAXN];
bool leaf[MAXN];
int cz[MAXN];

void dfs(int a, int par) {
	if (adj[a].size() == 1 && adj[a][0] == par) {
		leaf[a] = true;
		c[a] = mp(1, 0);
		return;
	}
	pi tot = mp(0, 0);
	for (int b : adj[a]) {
		if (b == par) continue;
		dfs(b, a);
		if (leaf[b]) cz[a]++;
		tot.f += c[b].s;
		tot.s += c[b].f;
	}
	c[a] = tot;
}

int main() {
	setIO("stdio");
	cin >> n;
	FOR (i, 0, n-1) {
		int a, b;
		cin >> a >> b;
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
	}
	int root;
	FOR (i, 0, n) {
		if (adj[i].size() >= 2) {
			root = i;
			break;
		}
	}
	dfs(root, -1);
	bool odd = false;
	FOR (i, 0, n) {
		if ((c[i].f * c[i].s) > 0) {
			odd = true;
			break;
		}
	}
	/*FOR (i, 0, n) {
		cout << c[i].f << " " << c[i].s << endl;
	}*/
	cout << ((odd) ? 3 : 1) << " ";
	int ret = n-1;
	FOR (i, 0, n) {
		if (cz[i] <= 1) continue;
		ret -= cz[i]-1;
	}
	cout << ret << endl;
}
