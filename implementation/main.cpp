#include <bits/stdc++.h>

using namespace std;

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
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;

const int MAXN = 1005;
const int INF = INT_MAX;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (name == "input") {
		freopen("input.txt","r",stdin);
	}
	else {
		freopen((name+".in").c_str(),"r",stdin);
		freopen((name+".out").c_str(),"w",stdout);
	}
}

int n, m;
vector<pip> adj[MAXN];
int d[MAXN];
int flows[MAXN];
bool v[MAXN];

int main() {
	setIO("input");
	cin >> n >> m;
	FOR (i, 0, m) {
		int a, b, c, fl;
		cin >> a >> b >> c >> fl;
		adj[a-1].pb(mp(b-1, mp(c, fl)));
		adj[b-1].pb(mp(a-1, mp(c, fl))); // node, cost, flow
		flows[i] = fl;
	}
	sort(flows, flows + m);
	int ret = 0;
	FOR (k, 0, m) {
		FOR (j, 0, n) {d[j] = INF; v[j] = false;}
		d[0] = 0;
		priority_queue<pip> pq; // cost, node, flow
		int minflow = INF;
		pq.push(mp(0, mp(0, INF)));
		while (!pq.empty()) {
			pip cur = pq.top(); pq.pop();
			if (v[cur.s.f]) continue;
			v[cur.s.f] = true;
			minflow = min(minflow, cur.s.s);
			FOR (j, 0, adj[cur.s.f].size()) {
				pip next = adj[cur.s.f][j];
				if (next.s.s < flows[k]) continue;
				if (d[next.f] > d[cur.s.f] + next.s.f) {
					d[next.f] = d[cur.s.f] + next.s.f;
					pq.push(mp(d[next.f], mp(next.f, next.s.s)));
				}
			}
		}
		if (d[n-1] == INF) continue;
		cout << (int) (((double) minflow / d[n-1]) * 1000000) << endl;
		ret = max(ret, (int) (((double) minflow / d[n-1]) * 1000000));
	}
	cout << ret << endl;
}