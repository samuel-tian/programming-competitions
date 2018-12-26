#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 1000

int n, p, k;
vector<pair<int, int> > adj[MAXN];
bool visited[MAXN];
int dist[MAXN];

bool dijkstra(int bound) {
    fill(dist, dist + n, INF);
    dist[0] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();
        visited[current] = true;
        for (int i = 0; i < adj[current].size(); ++i) {
            pair<int, int> next = adj[current][i];
            int original = next.first;
            if (next.first >= bound) next.first = 1;
            else next.first = 0;
            if (dist[current] + next.first < dist[next.second]) {
                dist[next.second] = dist[current] + next.first;
                pq.push(make_pair(-dist[next.second], next.second));
            }
            next.first = original;
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     cout << dist[i] << " ";
    // }
    // cout << endl;
    if (dist[n - 1] > k) return false;
    return true;
}

int main() {
    cin >> n >> p >> k;
    for (int i = 0; i < p; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back(make_pair(c, b - 1));
        adj[b - 1].push_back(make_pair(c, a - 1));
    }
    int low = 0;
    int high = 1000000;
    while (low < high) {
        int mid = (low + high) / 2;
        if (dijkstra(mid)) {
            // cout << "pass " << mid << endl;
            high = mid;
        }
        else {
            // cout << "fail " << mid << endl;
            low = mid + 1;
        }
    }
    if (low == 0) {
        cout << 0 << endl;
    }
    else if (low == 1000000) {
        cout << -1 << endl;
    }
    else {
        cout << low - 1 << endl;
    }
}
