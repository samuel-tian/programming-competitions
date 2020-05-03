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

const int MAXN = 40005;
const int MAXM = 100005;
const int MOD = 1000000007;
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

int n, m;
vector<pip> edges;
int par[MAXN];
int r[MAXN];
bool used[MAXM];

int find(int i) {
    if (par[i] != i) {
        par[i] = find(par[i]);
    }
    return par[i];
}

void unionRank(int x, int y) {
    int a = find(x); int b = find(y);
    if (r[b] > r[a]) {
        unionRank(y, x);
        return;
    }
    par[b] = a;
    r[a] = max(r[a], r[b] + 1);
}

int main() {
    setIO();
    cin >> n >> m;
    int a, b, c;
    FOR (i, 0, m) {
        cin >> a >> b >> c;
        if (a > b) edges.pb(mpip(c, a-1, b-1));
        else edges.pb(mpip(c, b-1, a-1));
    }
    sort(edges.begin(), edges.end());
    FOR (i, 0, n) {
        par[i] = i;
    }
    int len = 0;
    ll count = 1;
    FOR (i, 0, m) {
        if (used[i]) continue;
        pi &edge = edges[i].s;
        set<pip> candidates;
        set<pi> t;
        int tot = 0;
        FOR (j, i, m) {
            if (edges[i].f == edges[j].f) {
                int x = find(edges[j].s.f), y = find(edges[j].s.s);
                if (x == y) continue;
//                if (edges[j].s.f > edges[j].s.s) candidates.insert(mpip(edges[j].f, edges[j].s.s, edges[j].s.f));
                candidates.insert(edges[j]);
                tot++;
                if (x > y) swap(x, y);
                t.insert(mp(x, y));
            }
            else break;
        }
        int candidatesUsed = 0;
        for (pip k : candidates) {
            if (find(k.s.f) == find(k.s.s)) continue;
            unionRank(k.s.f, k.s.s);
            candidatesUsed++;
            len += k.f;
        }
        if (tot == 3) {
            if (candidatesUsed == 1 || (candidatesUsed == 2 && t.size() == 3)) count = (count * 3) % MOD;
            if (candidatesUsed == 2 && t.size() == 2) count = (count * 2) % MOD;
        }
        if (tot == 2) {
            if (candidatesUsed == 1) count = (count * 2) % MOD;
        }
        /*if(tot == 3) {
            if(num == 1 || num == 2 && st.size() == 3) cnt = (cnt * 3) % MOD;
            if(num == 2 && st.size() == 2) cnt = (cnt * 2) % MOD;
        }
        if(tot == 2 && num == 1) cnt = (cnt * 2) % MOD;*/
        FOR (j, i, i + candidates.size()) {
            used[j] = true;
        }
    }
    cout << len << " " << count << endl;
}