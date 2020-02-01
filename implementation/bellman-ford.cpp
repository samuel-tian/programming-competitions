/*
 * Bellman Ford Algorithm
 * ----------------------
 * 1) for n-1 times, perform relaxations on all the edges
 *      a) a relaxation for edge u-v is dist[v] = min(dist[v], dist[u] + weight)
 * 2) on the nth iteration, if edges are still being relaxed, then a negative cycle exists
 *
 * time complexity: O(E*V)
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define MAXN 100000
#define endl '\n'
#define INF INT_MAX
#define f first
#define s second
#define pb push_back
#define mp make_pair

int n, m;
vector<ppi> edges;
int d[MAXN];

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

void bellmanFord(int node = 0) {
    for (int i = 0; i < n; ++i) {
        d[i] = INF;
    }
    d[node] = 0;
    bool negativeCycle = false;
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i].f.f; int v = edges[i].f.s;
            int w = edges[i].s;
            if (d[u] != INF && d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (j == n-1) {
                    negativeCycle = true;
                }
            }
        }
    }
    cout << (negativeCycle ? "YES" : "NO") << endl;
}

int main() {
    setIO("input");
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        edges.pb(mp(mp(a-1, b-1), c));
    }
    bellmanFord();
}