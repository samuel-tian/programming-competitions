//
// Created by samue on 10/4/2019.
//

/*
 * Dijkstra's shortest path algorithm
 * ----------------------------------
 * 1) bfs through the graph, but traverse nodes with smaller path distance before nodes with larger distance
 * time complexity: O(E log V)
 */

#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define MAXN 100000
#define endl '\n'

int n, m, s;
vector<pair<int, int> > adj[MAXN];
bool visited[MAXN];
int dist[MAXN];

void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    fill(dist, dist + n, INF);
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (visited[cur.second]) continue;
        visited[cur.second] = true;
        for (int i = 0; i < adj[cur.second].size(); ++i) {
            pair<int, int> next = adj[cur.second][i];
            if (dist[cur.second] + next.first < dist[next.second]) {
                dist[next.second] = dist[cur.second] + next.first;
                pq.push(make_pair(-dist[next.second], next.second));
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }
    dijkstra(s-1);
    for (int i = 0; i < n; ++i) {
        cout << (dist[i] == INF ? -1 : dist[i]) << endl;
    }
}