/*
 * Tarjan's Algorithm for Vertex Biconnected Components
 * ----------------------------------------------------
 * vertex biconnected component - connected set of nodes where if any one vertex is removed, the component remains
 * connected, implemented as a set of edges
 * articulation points - a node such that if it is removed, the graph is no longer connected
 * decomposition turns the graph into a bipartite graph consisting of articulation points and vertex-BCCs
 * 1) keep track of in[] and low[], which stores the time the node was visited in a DFS and the lowest in[] of the set
 * of nodes that can be reached, respectively
 * 2) DFS through the tree
 *      a) push traversed edges onto a stack
 *      b) after traversing all neighboring nodes, update low[]
 *      c) articulation point conditions
 *          i) in[] is greater than or equal to any of its children's low[]
 *          ii) it is the root and it has more than 1 child
 *      d) if an articulation point is found
 *          i) pop off all edges up to the current edge
 *          ii) the popped nodes are in the same vertex BCC
 * 3) iterate over all nodes and repeat the DFS procedure if in[] has not been initialized
 *      a) before doing so, empty the stack
 *      b) the edges in the stack are a vertex BCC
 *
 * time complexity: O(n)
 */

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
bool instack[MAXM];
int t = 0;
int vbcc[MAXM];
bool articulation[MAXN];
int num = 0;

int dfs(int v, int p = -1) {
    in[v] = low[v] = t++;
    int children = 0;
    FOR (i, 0, adj[v].size()) {
        int to = adj[v][i].f;
        if (to == p) continue;
        if (in[to] != -1) {
            low[v] = min(low[v], in[to]);
            if (in[to] < in[v]) {
                st.pb(adj[v][i].s);
                instack[adj[v][i].s] = true;
            }
        }
        else {
            if (p == -1 && children > 0) {
                articulation[v] = true;
                while (!st.empty()) {
                    int u = st[st.size() - 1]; st.pop_back();
                    vbcc[u] = num;
                    instack[u] = false;
                }
                num++;
            }
            st.pb(adj[v][i].s);
            instack[adj[v][i].s] = true;
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (p != -1 && low[to] >= in[v]) {
                articulation[v] = true;
                while (true) {
                    int u = st[st.size() - 1];
                    st.pop_back();
                    vbcc[u] = num;
                    instack[u] = false;
                    if (u == adj[v][i].s) break;
                }
                num++;
            }
            ++children;
        }
    }
}

void tarjans() {
    fill(in, in + n, -1);
    fill(low, low + n, -1);
    fill(vbcc, vbcc + m, -1);
    FOR (i, 0, n) {
        if (in[i] == -1) {
            dfs(i, -1);

            bool popped = false;
            while (!st.empty()) {
                popped = true;
                int u = st.back(); st.pop_back();
                vbcc[u] = num;
                instack[u] = false;
            }
            if (popped) ++num;
        }

    }
}

int main() {
    setIO("input");
    cin >> n >> m;
    int a, b;
    FOR (i, 0, m) {
        cin >> a >> b;
        adj[a].pb(mp(b, i));
        adj[b].pb(mp(a, i));
    }
    tarjans();
    int ret = 0;
    FOR (i, 0, n) {
        ret += articulation[i];
    }
    FOR (k, 0, 3) {
        cout << k << endl;
        FOR (i, 0, n) {
            FOR (j, 0, adj[i].size()) {
                if (vbcc[adj[i][j].s] == k)
                    cout << i << " " << adj[i][j].f << endl;
            }
        }
    }

}