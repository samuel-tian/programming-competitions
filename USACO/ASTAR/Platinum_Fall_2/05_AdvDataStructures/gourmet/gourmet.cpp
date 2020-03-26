#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;
typedef pair<int, pair<int, int> > pip;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef long long ll;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a); i >= (b); --i)
#define PRSP(i, a, x) for (int i = 0; i < (a); ++i) {cout << x[i] << " ";} cout << endl;
#define mppi(a, b, c) mp(mp((a), (b)), (c))
#define mpip(a, b, c) mp((a), mp((b), (c)))

const int MAXN = 100005;
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
pi c[MAXN];
pi g[MAXN];
vector<ppi> com;

int main() {
	setIO("input");
	cin >> n >> m;
	FOR (i, 0, n) {
		cin >> c[i].f >> c[i].s;
		com.pb(mp(mp(c[i].s, c[i].f), 0));
	}
	FOR (i, 0, m) {
		cin >> g[i].f >> g[i].s;
		com.pb(mp(mp(g[i].s, g[i].f), 1));
	}
	sort(com.begin(), com.end());
	multiset<int> s;
	ll ret = 0;
	FORd (i, com.size() - 1, 0) {
		ppi cur = com[i];
		if (cur.s == 1) {
			s.insert(cur.f.s);
		}
		else {
			auto r = s.upper_bound(cur.f.s);
			if (r == s.end()) {
				cout << -1 << endl;
				return 0;
			}
			if (r != s.begin() && *prev(r) == cur.f.s) {
				ret += *prev(r);
				s.erase(*prev(r));
			}
			else {
				ret += *r;
				s.erase(r);
			}
//			printf("(%d, %d) %d\n", cur.f.s, cur.f.f, *r);
		}
	}
	cout << ret << endl;
}