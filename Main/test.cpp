#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const int MX = 1000001;

int n,k, sz[MX], nex[MX][20];
ll m;

int get(int x, int lef) {
    F0Rd(i,20) if (lef&(1<<i)) x = nex[x][i];
    return x;
}

void solve(int x) {
    if (m <= n) cout << get(x,m) << " ";
    else {
        x = get(x,n);
        cout << get(x,(m-n)%sz[x]) << " ";
    }
}

ll p[MX];

void genNex() {
    pii cur = {1,k+1};
    FOR(i,1,n+1) {
        while (cur.s < n && p[cur.s+1]-p[i] < p[i]-p[cur.f]) cur.f ++, cur.s ++;
        if (p[i]-p[cur.f] >= p[cur.s]-p[i]) nex[i][0] = cur.f;
        else nex[i][0] = cur.s;
    }
}

int visit[MX];

void cycSize() {
    FOR(i,1,n+1) {
        int I = i;
        for (;visit[I] == 0; I = nex[I][0]) visit[I] = i;
        if (visit[I] != i) continue;
        
        int cur = 0;
        for (;visit[I] == i; I = nex[I][0]) { cur ++; visit[I] += n; }
        for (;visit[I] == i+n; I = nex[I][0]) { sz[I] = cur; visit[I] += n; }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> m;
    FOR(i,1,n+1) cin >> p[i];
    genNex();
    FOR(i,1,20) FOR(j,1,n+1) nex[j][i] = nex[nex[j][i-1]][i-1];
    cycSize();
    FOR(i,1,n+1) solve(i);
}
