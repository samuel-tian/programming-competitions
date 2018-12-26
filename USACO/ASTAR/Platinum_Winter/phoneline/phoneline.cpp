#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 1000

typedef pair<int, int> Line;

int n, p, k;
vector<Line> adj[MAXN];
bool visited[MAXN];
int minValue = INF;
multiset<int> lineLength;

void dfs(int node) {
    // cerr << "NODE: " << node + 1 << endl;
    // for (multiset<int>::iterator it = lineLength.begin(); it != lineLength.end(); ++it) {
    //     cerr << *it << " ";
    // }
    // cerr << endl;
    if (node == n - 1) {
        cout << "PASS" << endl;
        if (lineLength.size() <= k) minValue = 0;
        else {
            multiset<int>::reverse_iterator it = lineLength.rbegin();
            for (int i = 0; i < k; ++i) ++it;
            minValue = min(minValue, *it);
        }
        return;
    }
    for (int i = 0; i < adj[node].size(); ++i) {
        Line currentLine = adj[node][i];
        if (visited[currentLine.first]) continue;
        // cerr << "LINE: " << node + 1 << " " << currentLine.first + 1 << endl;
        lineLength.insert(currentLine.second);
        visited[currentLine.first] = true;
        dfs(currentLine.first);
        visited[currentLine.first] = false;
        lineLength.erase(lineLength.find(currentLine.second));
    }
    return;
}

int main() {
    cin >> n >> p >> k;
    for (int i = 0; i < p; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back(Line{b - 1, c});
        adj[b - 1].push_back(Line{a - 1, c});
    }
    visited[0] = true;
    dfs(0);
    if (minValue == INF) cout << -1 << endl;
    else cout << minValue << endl;
}
