#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> pii;
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

const int MAXP = 30005;
const int INF = INT_MAX;
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

int p, c, n;
vi adj[MAXP];
bool damaged[MAXP];
bool visited[MAXP];

int main() {
    setIO("stdio");
    cin >> p >> c >> n;
    int a, b;
    FOR (i, 0, c) {
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    FOR (i, 0, n) {
        cin >> a;
        damaged[a-1] = true;
        FOR (j, 0, adj[a-1].size()) {
            damaged[adj[a-1][j]] = true;
        }
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (visited[cur] || damaged[cur]) continue;
        visited[cur] = true;
        FOR (i, 0, adj[cur].size()) {
            q.push(adj[cur][i]);
        }
    }
    int ret = 0;
    FOR (i, 0, p) {
        ret += visited[i];
    }
    cout << p - ret << endl;
}