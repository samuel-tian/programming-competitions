#include <iostream>
#include <queue>
#include <climits>

using namespace std;

#define endl '\n'
#define MAXT 25000
#define INF LONG_LONG_MAX

int t, r, p, s;
long long dist[MAXT];
vector<pair<int, int> > adj[MAXT];
priority_queue<pair<int, int> > pq;

void dijkstra(int start) {
    fill(dist, dist + t, INF);
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        long long current = pq.top().second;
        pq.pop();
        for (int i = 0; i < adj[current].size(); ++i) {
            pair<int, int> next = adj[current][i];
            if (dist[current] + next.first < dist[next.second]) {
                dist[next.second] = dist[current] + next.first;
                pq.push(make_pair(-dist[next.second], next.second));
            }
        }
    }
}

int main() {
    cin >> t >> r >> s >> p;
    int a, b, w;
    for (int i = 0; i < r; ++i) {
        cin >> a >> b >> w;
        adj[a-1].push_back(make_pair(w, b-1));
        adj[b-1].push_back(make_pair(w, a-1));
    }
    for (int i = 0; i < s; ++i) {
        cin >> a >> b >> w;
        adj[a-1].push_back(make_pair(w, b-1));
    }
    dijkstra(p - 1);
    for (int i = 0; i < t; ++i) {
        if (dist[i] == INF) cout << "NO PATH" << endl;
        else cout << dist[i] << endl;
    }
}
