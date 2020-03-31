#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define sp <<" "<<

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))

const int MAXN = 55;
const int INF = INT_MAX;
const int NINF = INT_MIN;
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

int r, c;
int grid[MAXN][MAXN];
int islandflood[MAXN][MAXN];
int dist[MAXN][MAXN];
int shallowflood[MAXN][MAXN];
bool visited[MAXN][MAXN];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dp[1<<16][16];

int main() {
    setIO("stdio");
    cin >> r >> c;
    string in;
    FOR (i, 0, r) {
        cin >> in;
        FOR (j, 0, c) {
            if (in[j] == '.') grid[i][j] = 0;
            else if (in[j] == 'X') grid[i][j] = 1;
            else if (in[j] == 'S') grid[i][j] = 2;
        }
    }
    /*FOR (i, 0, r) {
        FOR (j, 0, c) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }*/
    // island floodfill
    FOR (i, 0, r) {
        FOR (j, 0, c) {
            islandflood[i][j] = -1;
        }
    }
    int counter = 0;
    queue<pi> q;
    FOR (i, 0, r) {
        FOR (j, 0, c) {
            if (grid[i][j] == 1 && islandflood[i][j] == -1) {
                q.push(mp(i, j));
                while (!q.empty()) {
                    pi cur = q.front();
                    q.pop();
                    islandflood[cur.f][cur.s] = counter;
                    FOR (k, 0, 4) {
                        pi next = mp(cur.f+dx[k], cur.s+dy[k]);
                        if (next.f >= r || next.f < 0 || next.s >= c || next.s < 0) continue;
                        if (islandflood[next.f][next.s] != -1) continue;
//                        cout << next.f << " " << next.s << " " << grid[next.f][next.s] << endl;
                        if (grid[next.f][next.s] == 1) {
//                            cout << "pass" << endl;
                            q.push(next);
                        }
                    }
                }
                ++counter;
            }
        }
    }
    /*FOR (i, 0, r) {
        FOR (j, 0, c) {
            if (islandflood[i][j] == -1) cout << 'N' << " ";
            else cout << islandflood[i][j] << " ";
        }
        cout << endl;
    }*/
    // shallow floodfill
    bool done = false;
    FOR (i, 0, counter) {
        FOR (j, 0, r) {
            FOR (k, 0, c) {
                if (islandflood[j][k] == i) {
                    FOR (a, 0, r) {
                        FOR (b, 0, c) {
                            shallowflood[a][b] = INF;
                            visited[a][b] = false;
                        }
                    }
                    shallowflood[j][k] = 0;
                    queue<pi> q;
                    q.push(mp(j, k));
                    while (!q.empty()) {
                        pi cur = q.front();
                        q.pop();
                        if (visited[cur.f][cur.s]) continue;
                        visited[cur.f][cur.s] = true;
                        FOR (l, 0, 4) {
                            pi next = mp(cur.f + dx[l], cur.s + dy[l]);
                            if (next.f >= r || next.f < 0 || next.s >= c || next.s < 0) continue;
                            if (grid[next.f][next.s] == 2) {
                                shallowflood[next.f][next.s] = min(shallowflood[next.f][next.s],
                                                                   shallowflood[cur.f][cur.s] + 1);
                                q.push(next);
                            }
                            else if (grid[next.f][next.s] == 1) {
                                shallowflood[next.f][next.s] = min(shallowflood[next.f][next.s],
                                                                   shallowflood[cur.f][cur.s]);
//                                dist[i][islandflood[next.f][next.s]] = shallowflood[cur.f][cur.s];
                                q.push(next);
                            }
                        }
                    }
                    /*cout << "new " << i sp j sp k << endl;
                    FOR (x, 0, r) {
                        FOR (y, 0, c) {
                            if (shallowflood[x][y] == INF) cout << "INF ";
                            else cout << "  " << shallowflood[x][y] << " ";
                        }
                        cout << endl;
                    }*/
                    FOR (x, 0, r) {
                        FOR (y, 0, c) {
                            if (grid[x][y] == 1) {
                                dist[i][islandflood[x][y]] = shallowflood[x][y];
                            }
                        }
                    }
                    done = true;
                    break;
                }
            }
            if (done) break;
        }
        done = false;
    }
    for (int k = 0; k < counter; ++k) {
        for (int i = 0; i < counter; ++i) {
            for (int j = 0; j < counter; ++j) {
                if (dist[i][k] == INF || dist[k][j] == INF) continue;
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    /*FOR (i, 0, counter) {
        FOR (j, 0, counter) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }*/
    FOR (i, 0, 1<<counter) {
        FOR (j, 0, counter) {
            dp[i][j] = INF;
        }
    }
    FOR (i, 0, counter) {
        dp[1<<i][i] = 0;
    }
    FOR (i, 1, 1<<counter) {
        FOR (j, 0, counter) {
            if (i & (1<<j) == 0) continue;
            FOR (k, 0, counter) {
                if (i & (1<<k) == 0) continue;
                if (dist[j][k] == 0) continue;
                if (dp[i^(1<<j)][k] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i^(1<<j)][k] + dist[j][k]);
            }
        }
    }
    int ret = INF;
    FOR (i, 0, counter) {
        ret = min(ret, dp[(1<<counter) - 1][i]);
    }
    cout << ret << endl;
}