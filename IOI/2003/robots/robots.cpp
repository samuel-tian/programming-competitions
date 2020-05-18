#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpi;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (int (i) = (a); i < (b); ++i)
#define FORd(i, a, b) for (int (i) = (a); i >= (b); --i)
#define TRAV(i, x) for (auto& (i) : (x))
#define PRSP(x, a) for (int rv = 0; rv < a; ++rv) {cout << ((rv==0 ? "" : " ")) << x[rv];} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c))
#define min3(a, b, c) min(min((a), (b)), (c))

void setIO(string name = "") {
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (name == "") return;
	if (name == "input") {freopen("input.txt","r",stdin);}
	else {freopen((name+".in").c_str(),"r",stdin); freopen((name+".out").c_str(),"w",stdout);}
}

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash { ll operator()(ll x) const { return x ^ RANDOM; } };

const int N = 500;
const int G = 15;
const int T = 12;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
string ds[] = { "S", "E", "N", "W" };
pi dp[] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
unordered_map<char, int> car = { { 'S', 0 }, { 'E', 1 }, { 'N', 2 }, { 'W', 3 } };

int n[2], m[2], g[2];
char grid[2][N];
int st[2];
vi guards[2][G];

int d[N][N][T]; // robot 1, robot 2, time
bool vis[N][N][T];
// string path[N][N][T];

pi operator + (pi& a, pi& b) {
    return mp(a.f + b.f, a.s + b.s);
}

int go(pi x, int t) {
    return x.f * m[t] + x.s;
}

bool check(pi x, int t) {
    return !(x.f < 0 || x.f >= n[t] || x.s < 0 || x.s >= m[t]) && grid[t][go(x, t)] == '.';
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO("input");
    FOR (t, 0, 2) {
        cin >> n[t] >> m[t];
        n[t] += 2, m[t] += 2;
        FOR (i, 0, n[t]) {
            FOR (j, 0, m[t]) {
                grid[t][i * m[t] + j] = '.';
            }
        }
        FOR (i, 1, n[t] - 1) {
            string s; cin >> s;
            FOR (j, 1, m[t] - 1) {
                grid[t][i * m[t] + j] = s[j-1];
                if (grid[t][i * m[t] + j] == 'X') {
                    grid[t][i * m[t] + j] = '.';
                    st[t] = i * m[t] + j;
                }
            }
        }
        cin >> g[t];
        FOR (i, 0, g[t]) {
            int x, y, z; char c;
            cin >> x >> y >> z; cin >> c;
            int dir = car[c];
            FOR (j, 0, z) {
                guards[t][i].pb(x * m[t] + y);
                x += dx[dir]; y += dy[dir];
            }
            FOR (j, 0, z-2) {
                guards[t][i].pb(guards[t][i][z-2-j]);
            }
            z = guards[t][i].size();
            FOR (j, 0, T/z-1) {
                FOR (k, 0, z) {
                    guards[t][i].pb(guards[t][i][k]);
                }
            }
            // PRSP(guards[t][i], T);
        }
    }
    /*FOR (t, 0, 2) {
        cout << n[t] << " " << m[t] << endl;
        FOR (i, 0, n[t]) {
            FOR (j, 0, m[t]) {
                cout << grid[t][i * m[t] + j];
            }
            cout << endl;
        }
    }*/

    FOR (i, 0, N) {
        FOR (j, 0, N) {
            FOR (t, 0, T) {
                d[i][j][t] = -1;
                vis[i][j][t] = false;
            }
        }
    }

    queue<ppi> q; // < <robot1, robot2>, t>
    d[st[0]][st[1]][0] = 0;
    vis[st[0]][st[1]][0] = true;
    q.push(mppi(st[0], st[1], 0));
    // cout << "----" << endl;
    while (!q.empty()) {
        ppi cur = q.front();
        // string x = q.front().s;
        q.pop();
        pi pos[] = {
            { cur.f.f / m[0], cur.f.f % m[0] },
            { cur.f.s / m[1], cur.f.s % m[1] }
        };
        /*cout << "time: " << cur.s << endl;
        cout << pos[0].f << " " << pos[0].s << " " << cur.f.f << endl;
        cout << pos[1].f << " " << pos[1].s << " " << cur.f.s << endl;
        cout << "----" << endl;*/
        FOR (k, 0, 4) {
            pi npos[2];
            bool good[] = { true, true };
            FOR (i, 0, 2) {
                npos[i] = pos[i] + dp[k];
                if (pos[i].f == 0 || pos[i].f == n[i]-1 || pos[i].s == 0 || pos[i].s == m[i]-1) npos[i] = pos[i];
                else if (!check(npos[i], i)) npos[i] = pos[i];
                FOR (j, 0, g[i]) {
                    if (guards[i][j][(cur.s + 1) % T] == go(npos[i], i)) good[i] = false;
                    if (guards[i][j][(cur.s + 1) % T] == go(pos[i], i) &&
                        guards[i][j][cur.s % T] == go(npos[i], i)) good[i] = false;
                }
            }
            if (!good[0] || !good[1]) continue;
            int gopos[2]; FOR (i, 0, 2) gopos[i] = go(npos[i], i);
            if (vis[gopos[0]][gopos[1]][(cur.s + 1) % T]) continue;
            vis[gopos[0]][gopos[1]][(cur.s + 1) % T] = true;
            d[gopos[0]][gopos[1]][(cur.s + 1) % T] = cur.s + 1;
            // path[gopos[0]][gopos[1]][(cur.s + 1) % T] = x + ds[k];
            q.push(mppi(gopos[0], gopos[1], cur.s + 1));
        }
    }
    int ans = INF;
    string ans_path = "";
    FOR (i, 0, N) {
        FOR (j, 0, N) {
            FOR (t, 0, T) {
                int x1 = i / m[0], y1 = i % m[0];
                int x2 = j / m[1], y2 = j % m[1];
                if (d[i][j][t] == -1) continue;
                if ((x1==0 || y1==0 || x1==n[0]-1 || y1==m[0]-1) &&
                        (x2==0 || y2==0 || x2==n[1]-1 || y2==m[1]-1)) {
                    if (d[i][j][t] < ans) {
                        ans = d[i][j][t];
                        // ans_path = path[i][j][t];
                        // cout << "min: " << i << " " << j << " " << t << endl;
                    }
                }
            }
        }
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    // cout << ans_path << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}


