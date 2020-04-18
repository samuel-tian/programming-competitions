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
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))

const int MAXN = 20005;
const int MAXK = 205;
const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);

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

int n, m, k, q;
vpi adj[MAXN];
set<int> hubs;
int hmap[MAXN];
bool visited[MAXN];
int distTo[MAXK][MAXN];

int main() {
	setIO("stdio");
	cin >> n >> m >> k >> q;
	int a, b, c;
	FOR (i, 0, m) {
		cin >> a >> b >> c;
		adj[a-1].pb(mp(b-1, c));
	}
	FOR (i, 0, k) {
		cin >> a;
		hubs.insert(a-1);
	}
	fill(hmap, hmap + n, -1);
	int it = 0;
	for (int i : hubs) {
		hmap[i] = it++;
	}
	int counter = 0;
	for (auto iter = hubs.begin(); iter != hubs.end(); ++iter) {
		int i = *iter;
		fill(visited, visited + n, false);
		fill(distTo[counter], distTo[counter] + n, INF);
		priority_queue<pi> pq;
		pq.push(mp(0, i));
		distTo[counter][i] = 0;
		while (!pq.empty()) {
			int cur = pq.top().s;
			pq.pop();
			if (visited[cur]) continue;
			visited[cur] = true;
			FOR (j, 0, adj[cur].size()) {
				pi next = adj[cur][j];
				if (distTo[counter][next.f] > distTo[counter][cur] + next.s) {
					distTo[counter][next.f] = distTo[counter][cur] + next.s;
					pq.push(mp(-distTo[counter][next.f], next.f));
				}
			}
		}
		++counter;
	}
	/*FOR (i, 0, k) {
		FOR (j, 0, n) {
			cout << distTo[i][j] << " ";
		}
		cout << endl;
	}*/
	int num = 0;
	int cost = 0;

	FOR (i, 0, q) {
		cin >> a >> b;
		--a;
		--b;
		if (hmap[a] != -1) { // starting point is a hub
			int ind = hmap[a];
			if (distTo[ind][b] != INF) {
				num++;
				cost += distTo[ind][b];
			}
		}
		else {
			int ret = INF;
			FOR (i, 0, adj[a].size()) {
				pi hub = adj[a][i];
				int ind = hmap[hub.f];
				if (distTo[ind][b] != INF) {
					ret = min(ret, distTo[ind][b] + hub.s);
				}
			}
			if (ret != INF) {
				cost += ret;
				num++;
			}
		}
	}
	cout << num << endl;
	cout << cost << endl;
}