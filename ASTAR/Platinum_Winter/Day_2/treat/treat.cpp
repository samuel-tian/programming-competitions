#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'
#define MAXN 100000

int n;
int nextstall[MAXN];
vector<int> adj[MAXN];
int visited[MAXN];
int dist[MAXN];

int main() {
    cin >> n;
    fill(nextstall, nextstall + n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> nextstall[i];
        --nextstall[i];
        adj[i].push_back(nextstall[i]);
        adj[nextstall[i]].push_back(i);
    }
    int counter = 1;
    for (int i = 0; i < n; ++i) {
        int current = i;
        if (visited[current]) continue;
        visited[current] = counter;
        int start = -1;
        while (start == -1) {
            if (visited[nextstall[current]] == 0) {
                current = nextstall[current];
                visited[current] = counter;
            }
            else if (visited[nextstall[current]] != counter) {
                break;
            }
            else if (visited[nextstall[current]] == counter) {
                start = nextstall[current];
            }
        }
        if (start != -1) {
            int length = 1;
            int current = start;
            while (nextstall[current] != start) {
                current = nextstall[current];
                ++length;
            }
            current = start;
            dist[current] = length;
            while (nextstall[current] != start) {
                current = nextstall[current];
                dist[current] = length;
            }
        }
        ++counter;
    }
    fill(visited, visited + n, 0);
    for (int i = 0; i < n; ++i) {
        if (dist[i] && visited[i] == 0) {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                for (int i = 0; i < adj[current].size(); ++i) {
                    int next = adj[current][i];
                    if (dist[next] != 0 || visited[next] == 1) continue;
                    visited[next] = 1;
                    dist[next] = dist[current] + 1;
                    q.push(next);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << dist[i] << endl;
    }
}
