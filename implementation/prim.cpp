//
// Created by samue on 10/2/2019.
//

/*
 * Prim's minimum spanning tree algorithm
 * --------------------------------------
 * 1) start at an arbitrary node, and append all incident edges to a fibonacci heap
 * 2) greedily select edges with the lowest weight from the heap, then append the incident edges to that neighboring node
 * 3) repeat the process until n-1 edges have been selected
 * time complexity: O(E log V)
 */

#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define MAXN 100000
#define endl '\n'

int n, m;
vector<pair<int, int> > adj[MAXN];
bool visited[MAXN];

int prims() {
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, 0));
    int ret = 0;
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (visited[cur.second]) continue;
        visited[cur.second] = true;
        ret += (-1 * cur.first);
        for (int i = 0; i < adj[cur.second].size(); ++i) {
            pair<int, int> next = adj[cur.second][i];
            pq.push(make_pair(-1*next.first, next.second));
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }
    cout << prims() << endl;
}