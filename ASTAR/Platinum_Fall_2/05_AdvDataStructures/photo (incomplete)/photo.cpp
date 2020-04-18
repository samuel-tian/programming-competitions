#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef long long ll;

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

int n, m;
vpi adj[MAXN];
int p[MAXN];
int d[MAXN];
bool v[MAXN];

int main() {
	setIO("input");
	cin >> n >> m;
	int a, b;
	FOR (i, 0, m) {
		cin >> a >> b;
		adj[a-1].pb(mp(b, 1));
		adj[b].pb(mp(a-1, -1));
	}
	FOR (i, 0, n) {
		adj[i].pb(mp(i+1, 1));
		adj[i+1].pb(mp(i, 0));
	}
	fill(p, p + n + 1, 0);
	FORd (i, n, 1) {
		FOR (j, 0, adj[i].size()) {
			pi next = adj[i][j];
			p[next.f] = min(p[next.f], p[i] + next.s);
		}
	}
//	PRSP(i, n+1, p);
	FOR (i, 0, n+1) {
		printf("%d: ", i);
		FOR (j, 0, adj[i].size()) {
			adj[i][j].s += (p[i] - p[adj[i][j].f]);
			printf("(%d, %d) ", adj[i][j].f, adj[i][j].s);
			/*if (adj[i][j].s < 0) {
				cout << -1 << endl;
				return 0;
			}*/
		}
		printf("\n");
	}
	priority_queue<pi> pq;
	fill(d, d+n+1, INF);
	d[0] = 0;
	pq.push(mp(0, 0));
	while (!pq.empty()) {
		int cur = pq.top().s;
		pq.pop();
		if (v[cur]) continue;
		v[cur] = true;
		FOR (i, 0, adj[cur].size()) {
			pi next = adj[cur][i];
			if (d[cur] + next.s < d[next.f]) {
				d[next.f] = d[cur] + next.s;
				pq.push(mp(-d[next.f], next.f));
			}
		}
	}
	cout << d[n] + p[n] - p[0] << endl;
}