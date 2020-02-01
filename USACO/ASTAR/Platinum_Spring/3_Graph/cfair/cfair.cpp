#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> pii;
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

const int MAXN = 405;
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

int n;
pi p[MAXN];
int d[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
    setIO("stdio");
    cin >> n;
    FOR (i, 1, n+1) {
        cin >> p[i].first;
        p[i].second = i-1;
    }
    p[0] = mp(0, 0);
    sort(p, p + n + 1);
    /*FOR (i, 0, n+1) {
        cout << p[i].first << " " << p[i].second << endl;
    }*/
    FOR (i, 0, n) {
        FOR (j, 0, n) {
            cin >> d[i][j];
        }
    }
    FOR (i, 0, n) {
        FOR (j, 0, n+1) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    FOR (j, 0, n) {
        FOR (i, 0, n) {
            if (dp[i][j] == -1) continue;
            FOR (k, j+1, n+1) {
                int t = p[k].first;
                int next = p[k].second;
                if (p[j].first + d[i][next] <= t) {
                    dp[next][k] = max(dp[next][k], dp[i][j] + 1);
                }
            }
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
        }
    }
    /*FOR (i, 0, n) {
        FOR (j, 0, n+1) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    int ret = -1;
    FOR (i, 0, n) {
        ret = max(ret, dp[i][n]);
    }
    cout << ret << endl;
}