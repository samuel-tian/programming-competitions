/*
 * Tarjan's Algorithm for Strongly Connected Components
 * ----------------------------------------------------
 * strongly connected components - in a directed graph, a strongly connected component is a set of nodes such that for
 * every pair of nodes u and v there exists a path from u to v and a path from v to u
 * 1) keep track of in[] and low[], which stores the time the node was visited in a DFS and the lowest in[] of the set
 * of nodes that can be reached, respectively
 * 2) DFS through the tree
 *      a) push the traversed nodes onto a stack
 *      b) after traversing all neighboring nodes, update low[]
 *      c) if low[] is the same as in[], a new SCC has been found
 *          i) pop off all nodes on the stack up to the current node
 *          ii) the popped nodes are in the same SCC
 * 3) SCC are returned in reverse topological order
 * 4) iterate over all nodes and repeat the DFS procedure if the current node is not part of an SCC yet
 *
 * time complexity: O(n)
 * memory: O(n)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
vi adj[MAXN];
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
    fill(low, low + n, -1);
    fill(in, in + n, -1);
    fill(scc, scc + n, -1);
    for (int i = 0; i < n; ++i) {
        if (scc[i] == -1) {
            dfs(i);
        }
    }
}

int main() {
    setIO("input");
    cin >> n;
    FOR (i, 0, n) {
        int a;
        cin >> a;
        adj[i].pb(a - 1);
    }
    tarjans();
    PRSP(i, n, scc);
    cout << num << endl;
}