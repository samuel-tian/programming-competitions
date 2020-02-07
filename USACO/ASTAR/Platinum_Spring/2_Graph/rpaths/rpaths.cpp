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
const int MAXM = 100005;
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
vector<pi> adj[MAXN];
int in[MAXN];
int low[MAXN];
vi st;
bool instack[MAXN];
int t = 0;
int ebcc[MAXN];
int bridges[MAXM];
int num = 0;
set<int> decomp[MAXN];

void dfs(int v, int p = -1) {
    in[v] = low[v] = t++;
    st.pb(v);
    instack[v] = true;
    FOR (i, 0, adj[v].size()) {
        int to = adj[v][i].f;
        if (to == p) continue;
        if (in[to] != -1) {
            low[v] = min(low[v], in[to]);
        }
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > in[v]) {
                bridges[adj[v][i].s] = true;
                while (true) {
                    int u = st[st.size() - 1];
                    st.pop_back();
                    ebcc[u] = num;
                    instack[u] = false;
                    if (u == to) break;
                }
                num++;
            }
        }
    }
}

void tarjans() {
    fill(in, in + n, -1);
    fill(low, low + n, -1);
    fill(ebcc, ebcc + n, -1);
    FOR (i, 0, n) {
        if (in[i] == -1) {
            dfs(i);
            bool popped = false;
            while (!st.empty()) {
                popped = true;
                int u = st.back(); st.pop_back();
                ebcc[u] = num;
                instack[u] = false;
            }
            if (popped) ++num;
        }
    }
}

int main() {
    setIO("stdio");
    cin >> n >> m;
    int a, b;
    FOR (i, 0, m) {
        cin >> a >> b;
        adj[a-1].pb(mp(b-1, i));
        adj[b-1].pb(mp(a-1, i));
    }
    tarjans();
    /*FOR (i, 0, n) {
        FOR (j, 0, adj[i].size()) {
            if (bridges[adj[i][j].s]) {
                cout << i << " " << adj[i][j].f << endl;
            }
        }
    }
    PRSP(i, n, ebcc);*/
    FOR (i, 0, n) {
        FOR (j, 0, adj[i].size()) {
            if (ebcc[i] == ebcc[adj[i][j].f]) continue;
            decomp[ebcc[i]].insert(ebcc[adj[i][j].f]);
            decomp[ebcc[adj[i][j].f]].insert(ebcc[i]);
        }
    }
    int ret = 0;
    FOR (i, 0, n) {
        /*for (int j : decomp[i]) {
            cout << j << " ";
        } cout << endl;*/
        if (decomp[i].size() == 1) {
            ++ret;
        }
    }
    cout << (ret + 1) / 2 << endl;
}