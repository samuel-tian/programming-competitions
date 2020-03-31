#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))

const int MAXN = 1005;
const int MAXK = 105;
const int INF = INT_MAX;
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

int n, m, k;
vpi adj[MAXN];
int kshortest[MAXN][MAXK];
//int npath[MAXN];
//int inc[MAXN];

int main() {
    setIO("stdio");
    cin >> n >> m >> k;
    int a, b, c;
    FOR (i, 0, m) {
        cin >> a >> b >> c;
        adj[a-1].pb(mp(c, b-1));
    }
    FOR (i, 0, n) {
        FOR (j, 0, k) {
            kshortest[i][j] = INF;
        }
    }
    kshortest[0][0] = 0;
    FOR (i, 1, n) {
        priority_queue<int> pq;
//        fill(npath, npath + n, 0);
        /*FOR (j, 0, adj[i].size()) {
            int next = adj[i][j].s;
            pq.push(mp(-kshortest[next][0], next));
            inc[next] = adj[i][j].f;
        }
        FOR (j, 0, k) {
            if (pq.empty()) continue;
            pi next = pq.top();
            pq.pop();
            if (-next.f == INF) continue;
            kshortest[i][j] = -next.f + inc[next.s];
            npath[next.s]++;
            pq.push(mp(-kshortest[next.s][npath[next.s]], next.s));
        }*/
        FOR (j, 0, adj[i].size()) {
            FOR (l, 0, k) {
                int next = adj[i][j].s;
                if (kshortest[next][l] == INF) pq.push(-INF);
                else pq.push(-(kshortest[next][l] + adj[i][j].f));
            }
        }
        FOR (j, 0, k) {
            if (pq.size() == 0) break;
            kshortest[i][j] = -pq.top();
            pq.pop();
        }
    }
    /*FOR (i, 0, n) {
        FOR (j, 0, k) {
            cout << kshortest[i][j] << " ";
        }
        cout << endl;
    }*/
    FOR (i, 0, k) {
        cout << ((kshortest[n-1][i] == INF) ? -1 : kshortest[n-1][i]) << endl;
    }
}