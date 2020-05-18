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

const int N = 205;

int n, m;
string s;
int pre[N];
int dp[2 * N][N][N][2];

void compute_prefix(string s, int pre[N]) {
    int n = s.size();
    FOR (i, 1, n) {
        int j = pre[i];
        while (j > 0 && s[i] != s[j]) {
            j = pre[j];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pre[i+1] = j;
    }
    pre[0] = -1;
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
    cin >> n;
    cin >> s;
    m = s.size();
    compute_prefix(s, pre);
    FOR (i, 0, n+1) {
        FOR (j, 0, m+1) {
            FOR (k, 0, n) {
                FOR (l, 0, 2) {
                    dp[i][j][k][l] = 0;
                }
            }
        }
    }
    dp[0][0][0][0] = 1;
    FOR (i, 0, 2*n) {
        FOR (j, 0, m+1) {
            FOR (k, 0, n+1) {
                FOR (l, 0, 2) {
                    if (dp[i][j][k][l] == 0) continue;
                    if (l == 1) {
                        if (k < n) dp[i+1][j][k+1][l] = (dp[i+1][j][k+1][l] + dp[i][j][k][l]) % MOD; // '('
                        if (k > 0) dp[i+1][j][k-1][l] = (dp[i+1][j][k-1][l] + dp[i][j][k][l]) % MOD; // ')'
                    }
                    else {
                        // '('
                        if (k < n) {
                            int iter = j;
                            while (iter != -1 && s[iter] != '(') iter = pre[iter];
                            iter++;
                            if (iter == m) dp[i+1][iter][k+1][1-l] = (dp[i+1][iter][k+1][1-l] + dp[i][j][k][l]) % MOD;
                            else dp[i+1][iter][k+1][l] = (dp[i+1][iter][k+1][l] + dp[i][j][k][l]) % MOD;
                        }

                        // ')'
                        if (k > 0) {
                            int iter = j;
                            while (iter != -1 && s[iter] != ')') iter = pre[iter];
                            iter++;
                            if (iter == m) dp[i+1][iter][k-1][1-l] = (dp[i+1][iter][k-1][1-l] + dp[i][j][k][l]) % MOD;
                            else dp[i+1][iter][k-1][l] = (dp[i+1][iter][k-1][l] + dp[i][j][k][l]) % MOD;
                        }
                    }
                }
            }
        }
    }
    /*cout << "not good" << endl;
    FOR (k, 0, n+1) {
        cout << k << endl;
        FOR (i, 0, 2*n+1) {
            FOR (j, 0, m+1) {
                cout << dp[i][j][k][0] << " ";
            }
            cout << endl;
        }
    }
    cout << "good" << endl;
    FOR (k, 0, n+1) {
        cout << k << endl;
        FOR (i, 0, 2*n+1) {
            FOR (j, 0, m+1) {
                cout << dp[i][j][k][1] << " ";
            }
            cout << endl;
        }
    }*/
    cout << dp[2*n][m][0][1] << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}

