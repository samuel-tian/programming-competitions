#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)
#define PRSP(x, a) for (int rv = 0; rv < a; ++rv) {cout << ((rv==0 ? "" : " ")) << x[rv];} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))
#define max3(a, b, c) max(max((a), (b)), (c));

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

const int INF = INT_MAX;
const int NINF = INT_MIN;
const int MAXLOG = 21;
const int MAXSEG = (1<<18);
const int MUL = 1000001;
const int MOD = 1000000007;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

int main() {
	setIO("stdio");
	int n;
	cin >> n;
	int a[n];
	FOR (i, 0, n) {
		cin >> a[i];
	}
	gp_hash_table<ll, vi, chash> m;
	ll tot = 0;
	m[0].pb(0);
	FOR (i, 1, n+1) {
		tot = tot + a[i-1];
		m[tot].pb(i);
	}
	int right_bound[n];
	fill(right_bound, right_bound + n, n);
	for (auto i : m) {
		sort(i.s.begin(), i.s.end());
		FOR (j, 0, i.s.size() - 1) {
			right_bound[i.s[j]] = min(right_bound[i.s[j]], i.s[j+1]-1);
		}
	}
	FORd (i, n-2, 0) {
		right_bound[i] = min(right_bound[i], right_bound[i+1]);
	}
//	PRSP(right_bound, n);
	ll ret = 0;
	FOR (i, 0, n) {
		ret += right_bound[i] - i;
	}
	cout << ret << endl;
}
