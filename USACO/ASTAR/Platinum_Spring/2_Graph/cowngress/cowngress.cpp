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

const int MAXN = 100005;
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

int n, m;
vi adj[2 * MAXN]; // Y comes before N
int in[MAXN];
int low[MAXN];
vi st;
bool instack[MAXN];
int t = 0;
int scc[MAXN];
int num = 0;

void dfs(int node) {
    low[node] = in[node] = t++;
    st.pb(node);
    instack[node] = true;
    for (int i = 0; i < adj[node].size(); ++i) {
        int next = adj[node][i];
        if (in[next] == -1) {
            dfs(next);
            low[node] = min(low[node], low[next]);
        }
        else if (instack[next]) {
            low[node] = min(low[node], in[next]);
        }
    }
    if (low[node] == in[node]) {
        while (true) {
            int u = st[st.size() - 1]; st.pop_back();
            scc[u] = num;
            instack[u] = false;
            if (u == node) break;
        }
        num++;
    }
}

void tarjans() {
    fill(low, low + 2 * n, -1);
    fill(in, in + 2 * n, -1);
    fill(scc, scc + 2 * n, -1);
    for (int i = 0; i < 2 * n; ++i) {
        if (scc[i] == -1) {
            dfs(i);
        }
    }
}

bool visited[2 * MAXN];
vi nadj[2 * MAXN];
vi madj[2 * MAXN];
string traverse(int start, int end) {
    fill(visited, visited + 2 * n, false);
    queue<int> q;
    int s = max(scc[start], scc[end]); int e = min(scc[start], scc[end]);
    q.push(s);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        FOR (i, 0, nadj[cur].size()) {
            int next = nadj[cur][i];
            q.push(next);
        }
    }
    if (visited[e]) {
        if (s == scc[start]) return "N";
        else return "Y";
    }
    else {
        return "?";
    }
}

int main() {
    setIO("input");
    cin >> n >> m;
    int b, c; char bv, cv;
    FOR (i, 0, m) {
        cin >> b >> bv >> c >> cv;
        int bi = (bv == 'Y') ? 0 : 1;
        int ci = (cv == 'Y') ? 0 : 1;
        --b; --c;
        adj[2 * b  + (1 - bi)].pb(2 * c + ci);
//        cout << 2 * b  + (1 - bi) << " - " << 2 * c + ci << endl;
        adj[2 * c  + (1 - ci)].pb(2 * b + bi);
//        cout << 2 * c  + (1 - ci) << " - " << 2 * b + bi << endl;
    }
    tarjans();
//    PRSP(i, 2 * n, scc);
//    cout << num << endl;
    string ret = "";
    bool possible = true;
    FOR (i, 0, 2 * n) {
        FOR (j, 0, adj[i].size()) {
            int from = scc[i], to = scc[adj[i][j]];
            if (from == to) continue;
            nadj[from].pb(to);
            madj[to].pb(from);
        }
    }
    FOR (i, 0, n) {
        b = scc[2 * i]; c = scc[2 * i + 1];
        if (b == c) possible = false;
        else ret += traverse(2 * i, 2 * i + 1);
    }
    if (possible) cout << ret << endl;
    else cout << "IMPOSSIBLE" << endl;
}