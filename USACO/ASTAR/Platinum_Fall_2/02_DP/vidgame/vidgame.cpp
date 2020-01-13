#include <bits/stdc++.h>

using namespace std;

#define MAXN 600
#define MAXV 100005

struct item {
    int cost;
    int prod;
    bool console;
    int numGames;
};

int n, v;
vector<item> items;
int dp[2][MAXV];

int main() {
    cin >> n >> v;
    for (int i = 0; i < n; ++i) {
        item it;
        it.prod = 0; it.console = true;
        cin >> it.cost >> it.numGames;
        items.push_back(it);
        for (int j = 0; j < it.numGames; ++j) {
            cin >> it.cost >> it.prod;
            it.console = false;
            items.push_back(it);
        }
    }
    /*for (int i = 0; i < items.size(); ++i) {
        item cur = items[i];
        cout << cur.cost << " " << cur.prod << " " << cur.console << " " << cur.numGames << endl;
    }*/
    for (int i = 0; i < 2; ++i) {
        fill(dp[i % 2], dp[i % 2] + MAXV, -1);
    }
    dp[0][0] = 0;
    int nextGame = -1;
    queue<pair<int, int> > updates;
    for (int i = 0; i <= items.size(); ++i) {
        fill(dp[(i + 1) % 2], dp[(i + 1) % 2] + MAXV, -1);
        if (i == nextGame) {
            while (!updates.empty()) {
                pair<int, int> cur = updates.front();
                updates.pop();
                if (cur.first > v) continue;
                dp[i % 2][cur.first] = max(dp[i % 2][cur.first], cur.second);
            }
            nextGame = -1;
        }
        for (int j = 0; j <= v; ++j) {
            if (dp[i % 2][j] == -1) continue;
            item cur = items[i];
            if (cur.console) {
//                dp[i + cur.numGames + 1][j] = max(dp[i + cur.numGames + 1][j], dp[i][j]);
                nextGame = i + cur.numGames + 1;
                updates.push(make_pair(j, dp[i % 2][j]));
                if (j + cur.cost > v) continue;
                dp[(i + 1) % 2][j + cur.cost] = max(dp[(i + 1) % 2][j + cur.cost], dp[i % 2][j]);
            }

            else {
                dp[(i + 1) % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j]);
                if (j + cur.cost > v) continue;
                dp[(i + 1) % 2][j + cur.cost] = max(dp[(i + 1) % 2][j + cur.cost], dp[i % 2][j] + cur.prod);
            }
        }
        /*cout << "--- " << i << " ---" << endl;
        for (int j = 0; j < MAXV; ++j) {
            if (dp[i % 2][j] != -1) {
                cout << j << ": " << dp[i % 2][j] << endl;
            }
        }*/
    }
    /*cout << "--- " << items.size() << " ---" << endl;
    for (int j = 0; j < MAXV; ++j) {
        if (dp[items.size() % 2][j] != -1) {
            cout << j << ": " << dp[items.size() % 2][j] << endl;
        }
    }*/
    int ret = 0;
    for (int i = 0; i <= v; ++i) {
        ret = max(dp[items.size() % 2][i], ret);
    }
    cout << ret << endl;
}