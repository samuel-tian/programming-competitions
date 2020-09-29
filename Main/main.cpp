#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define f first
#define s second

const ll INF = LLONG_MAX;
const int N = 100005;
const int M = 200005;

int n, m, s;
vector<pair<ll, int> > adj[N];
ll dis[N];
bool vis[N];

void dijkstra(int start) {
    priority_queue<pair<ll, int> > pq;
    fill(dis, dis + n, INF);
    dis[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        pair<ll, int> cur = pq.top();
        pq.pop();
        if (vis[cur.s])
            continue;
        vis[cur.s] = true;
        for (pair<ll, int> next : adj[cur.s]) {
            if (dis[cur.s] + next.f < dis[next.s]) {
                dis[next.s] = dis[cur.s] + next.f;
                pq.push(make_pair(-dis[next.s], next.s));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    s--;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }
    dijkstra(s);
    for (int i = 0; i < n; i++) {
        if (dis[i] == INF)
            cout << -1 << '\n';
        else
            cout << dis[i] << '\n';
    }
}
