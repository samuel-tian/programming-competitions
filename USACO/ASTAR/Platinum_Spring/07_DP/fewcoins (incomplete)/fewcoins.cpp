#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
#define max3(a, b, c) max(max((a), (b)), (c));

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;

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

struct min_queue {
    int sz = 0;
    deque<pi> q;
    min_queue() {
        this->sz = 0;
    }
    min_queue(int sz) {
        this->sz = sz;
    }
    int eval(pi a, int i) {
        if (a.f == INF) return a.f;
        return a.f + (i - a.s);
    }
    void insert(pi a) {
        while (!q.empty() && eval(q.back(), a.s) >= eval(a, a.s)) {
            q.pop_back();
        }
        q.push_back(a);
    }
    int query(int i) {
        while (q.front().s < i - sz) {
            q.pop_front();
        }
        return eval(q.front(), i);
    }
    bool empty() {
        return q.empty();
    }
    string display() {
        string ret = "";
        for (pi i : q) {
            ret += "(" + to_string(i.f) + ", " + to_string(i.s) + ") ";
        }
        return ret;
    }
};

const int MAXN = 105;
const int MAXT = 10000;
const int MAXV = 120;
const int MAX = MAXT + 2*MAXV*MAXV;

int n, t;
int v[MAXN];
int c[MAXN];
int dpf[MAX], dpc[MAX];
min_queue mpq[MAXN][MAXV];

int main() {
    setIO("stdio");
    cin >> n >> t;
    int V = 0;
    FOR (i, 0, n) {
        cin >> v[i];
        V = max(V, v[i]);
    }
    FOR (i, 0, n) {
        cin >> c[i];
    }
    fill(dpf, dpf + t+2*V*V+1, INF);
    dpf[0] = 0;
    FOR (i, 0, n) {
        int dptemp[MAX];
        FOR (j, 0, t+2*V*V) {
            dptemp[j] = dpf[j];
        }
        FOR (j, 0, v[i]) {
            mpq[i][j] = min_queue(c[i]);
        }
//        mpq[i][0].insert(mp(dpf[0], 0));
        FOR (j, 0, t+2*V*V) {
            mpq[i][j % v[i]].insert(mp(dpf[j], j / v[i]));
//            if (mpq[i][j % v[i]].empty()) continue;
//            if (i == 2) cout << j << " " << mpq[i][0].display() << "| ";
            dptemp[j] = min(dptemp[j], mpq[i][j % v[i]].query(j / v[i]));
//            if (i == 2) cout << mpq[i][0].display() << endl;
        }
        FOR (j, 0, t+2*V*V) {
            dpf[j] = dptemp[j];
        }
    }
    fill(dpc, dpc + 2*V*V+1, INF);
    dpc[0] = 0;
    FOR (i, 1, 2*V*V) {
        FOR (j, 0, n) {
            if (i - v[j] < 0) continue;
            if (dpc[i - v[j]] == INF) continue;
            dpc[i] = min(dpc[i], dpc[i - v[j]] + 1);
        }
    }
//    PRSP(i, 100, dpf);
//    PRSP(i, 100, dpc);
    int ret = INF;
    FOR (i, t, t+2*V*V) {
        if (dpc[i - t] == INF || dpf[i] == INF) continue;
        ret = min(ret, dpc[i - t] + dpf[i]);
    }
    cout << ((ret == INF) ? -1 : ret) << endl;
}
