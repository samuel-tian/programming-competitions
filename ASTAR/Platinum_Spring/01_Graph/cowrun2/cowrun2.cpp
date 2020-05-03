#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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

int n, m, k;
vector<vi> cards;

ll run(int i, ll j, bool f, bool b) {
	return (j + j * cards[i][4*f+2*b] + cards[i][4*f+2*b+1]) % m;
}

bool solve_fj(int i, ll j);

bool solve_bessie(int i, ll j, bool f) {
	// f = true, FJ selected bottom half
	// f = false, FJ selected top half
	bool b = (bool)(rand() % 2);
	return solve_fj(i+1, run(i, j, f, b)) && solve_fj(i+1, run(i, j, f, !b));
}

bool solve_fj(int i, ll j) {
	if (i == n) {return j <= k || j >= m-k;}
	bool f = (bool)(rand() % 2);
	return solve_bessie(i, j, f) || solve_bessie(i, j, !f);
}

int main() {
	chrono::high_resolution_clock::time_point t0 = chrono::high_resolution_clock::now();

	setIO();
	cin >> n >> m >> k;
	string s; cin >> s;
	cards.assign(n, vi(8));
	FOR (i, 0, n) {
		FOR (j, 0, 8) {
			cin >> cards[i][j];
		}
	}
	ll j = 0;
	string ret = "";
	FOR (i, 0, n) {
		if (solve_bessie(i, j, true)) {
			ret += "B";
			j = run(i, j, true, s[i]=='B');
		}
		else {
			ret += "T";
			j = run(i, j, false, s[i]=='B');
		}
	}
	cout << ret << endl;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
//	cout << "TIME: " << chrono::duration_cast<chrono::milliseconds>(t1 - t0).count() << " ms" << endl;
}
